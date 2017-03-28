#include "WWDownloader.h"
#include "cocos2d.h"
#include "../EngineSystem/IPhoneTool.h"
#include "../LogSystem/WWLogMaros.h"
#include "UpgradeConst.h"
#include "../Tools/WWUtil.h"
#include "UpgradeEvent.h"
#include <cstdio>
#include <cerrno>

#include "unzip/unzip.h"


std::atomic<bool> g_downloadPause(false);
std::atomic<bool> g_downloading(false);
std::atomic<bool> g_downloadError(false);

std::mutex              g_DownloadLock;
std::condition_variable g_DownloadConVar;
std::mutex				batchDownloadMutex;
std::mutex				g_DataLock;

//#define LUAHOTUPDATE_TOPDIC "Res/"		

#define LOW_SPEED_LIMIT     1L
#define LOW_SPEED_TIME      5L
#define MAX_REDIRS          2
#define DEFAULT_TIMEOUT     5
#define HTTP_CODE_SUPPORT_RESUME    206

#define TEMP_EXT            ".temp"

#define BUFFER_SIZE    8192
#define MAX_FILENAME   512
#define MAX_DOWNLOAD_COUNT	10

extern std::unordered_map<std::string, bool> g_IsFinishDownloadThread;
extern std::mutex	LuaModuleMutex;

USING_NS_CC;

static std::unordered_map<std::string, std::string> userInfoData;

std::string basename(const std::string& path);
bool decompress(const std::string &zip);

int cmp(const std::pair<int, WWDownloader::DownloadUnit>& x, const std::pair<int, WWDownloader::DownloadUnit>& y)
{
	return x.second.priority < y.second.priority;
}

void sortMapByValue(const WWDownloader::DownloadUnits& tMap, std::vector<std::pair<int, WWDownloader::DownloadUnit> >& tVector)
{
	for (auto curr = tMap.begin(); curr != tMap.end(); curr++)
	{
		tVector.push_back(std::make_pair(curr->first, curr->second));
	}

	std::sort(tVector.begin(), tVector.end(), cmp);
}

size_t fileWriteFunc(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE*)userdata;
    size_t written = fwrite(ptr, size, nmemb, fp);
    return written;
}

size_t controlfileWriteFunc(void *ptr, size_t size, size_t nmemb, void *userdata)
{
	WWDownloader::FileDescriptor* fd = (WWDownloader::FileDescriptor*)userdata;
	if (fd->stopSign)
	{
		FILE *fp = (FILE*)fd->fp;
		fclose(fp);
		return CURL_WRITEFUNC_PAUSE;
	} else
	{
		FILE *fp = (FILE*)fd->fp;
		size_t written = fwrite(ptr, size, nmemb, fp);
		return written;
	}
	

}


size_t bufferWriteFunc(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    WWDownloader::StreamData *streamBuffer = (WWDownloader::StreamData *)userdata;
    size_t written = size * nmemb;
    // Avoid pointer overflow
    if (streamBuffer->offset + written <= streamBuffer->total)
    {
        memcpy(streamBuffer->buffer + streamBuffer->offset, ptr, written);
        streamBuffer->offset += written;
        return written;
    }
    else return 0;
}

// This is only for batchDownload process, will notify file succeed event in progress function
int batchDownloadProgressFunc(WWDownloader::ProgressData *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    if (ptr->totalToDownload == 0)
    {
        ptr->totalToDownload = totalToDownload;
    }
    
    if (ptr->downloaded != nowDownloaded)
    {
        ptr->downloaded = nowDownloaded;
        
        WWDownloader::ProgressData data = *ptr;
        
        if (nowDownloaded == totalToDownload)
        {

			batchDownloadMutex.lock();
			auto downloader = data.downloader.lock();
			if (downloader->getUpgradeEventDelegate())
			{

				log("Game Module %s is downloaded succ.", data.customId.c_str());

				int gameID = atoi(data.customId.c_str());
				WWDownloader::ProgressData eventData;
				eventData.customId = data.customId;
				eventData.gameId = gameID;
				eventData.downloaded = nowDownloaded + data.offsetLen;
				eventData.totalToDownload = totalToDownload+ data.offsetLen;
				downloader->getUpgradeEventDelegate()->onUpgradeEvent(UPGRADE_FINISH_MODULE_DOWNLOAD, &eventData);
			}


			batchDownloadMutex.unlock();

   
        }
        else
        {

			batchDownloadMutex.lock();
			auto downloader = data.downloader.lock();
			
			
			if (downloader->getUpgradeEventDelegate()) 
			{
				int gameID = atoi(data.customId.c_str());
				WWDownloader::ProgressData eventData;
				eventData.customId = data.customId;
				eventData.gameId = gameID;
				eventData.downloaded = nowDownloaded + data.offsetLen;
				eventData.totalToDownload = totalToDownload + data.offsetLen;
				downloader->getUpgradeEventDelegate()->onUpgradeEvent(UPGRADE_DOWNLOADING_PROGRESS, &eventData);
			}
			

			batchDownloadMutex.unlock();
			
			
        }
    }

	
	return ptr->stopFlag?1:0;
}

// Compare to batchDownloadProgressFunc, this only handles progress information notification
int downloadProgressFunc(WWDownloader::ProgressData *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    if (ptr->totalToDownload == 0)
    {
        ptr->totalToDownload = totalToDownload;
    }
    
    if (ptr->downloaded != nowDownloaded)
    {
        ptr->downloaded = nowDownloaded;
        WWDownloader::ProgressData data = *ptr;

		batchDownloadMutex.lock();
		auto downloader = data.downloader.lock();
		if (downloader->getUpgradeEventDelegate())
		{

			WWDownloader::ProgressData pData;
			pData.downloaded = nowDownloaded;
			pData.gameId = data.gameId;
			pData.totalToDownload = totalToDownload;
			downloader->getUpgradeEventDelegate()->onUpgradeEvent(UPGRADE_DOWNLOADING_PROGRESS, &pData);
		}


		batchDownloadMutex.unlock();

   //     Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{

			//std::shared_ptr<WWDownloader> downloader = data.downloader.lock();

			//EventCustom event(EVENT_DOWNLOAD_PROGRESS);
			//WWDownloader::ProgressData pData;
			//pData.downloaded = nowDownloaded;
			//pData.totalToDownload = totalToDownload;
			//event.setUserData(&pData);
			//Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
			//
			//


   //     });
    }

    g_downloading = true;

    while(g_downloadPause)
    {
    	std::unique_lock<std::mutex> locker(g_DownloadLock);

    	g_downloading = false;
    	g_DownloadConVar.wait(locker);
    }

    return 0;
}

WWDownloader::WWDownloader()
: _onError(nullptr)
, _onProgress(nullptr)
, _onSuccess(nullptr)
, _connectionTimeout(DEFAULT_TIMEOUT)
, _supportResuming(false)
,_headers(nullptr)
,m_tmpFileLen(0)
,m_finishDownloadThread(false)
,m_ThreadNum(1)
, m_upEventDelegate(nullptr)
{
    _fileUtils = FileUtils::getInstance();
	userInfoData.clear();
}

WWDownloader::~WWDownloader()
{
	if (_headers)
		curl_slist_free_all(_headers);
	userInfoData.clear();
}

int WWDownloader::getConnectionTimeout()
{
    return _connectionTimeout;
}

void WWDownloader::setConnectionTimeout(int timeout)
{
    if (timeout >= 0)
        _connectionTimeout = timeout;
}

void WWDownloader::onInitUserData(const std::string & key, const std::string& value)
{
	if (userInfoData.find(key) == userInfoData.end())
	{
		userInfoData.emplace(std::make_pair(key, value));
	} else
	{

		userInfoData[key] = value;
	}
	
	
}

void WWDownloader::notifyError(ErrorCode code, const std::string &msg/* ="" */, const std::string &customId/* ="" */, int curle_code/* = CURLE_OK*/, int curlm_code/* = CURLM_OK*/)
{
    //std::weak_ptr<WWDownloader> ptr = shared_from_this();
    g_downloadError = true;
    //m_finishDownloadThread = true;
    LuaModuleMutex.lock();
    g_IsFinishDownloadThread[customId] = true;
    LuaModuleMutex.unlock();


	if (m_upEventDelegate) 
	{
		Error err;
		err.code = code;
		err.curle_code = curle_code;
		err.curlm_code = curlm_code;
		err.message = msg;
		err.customId = customId;
		if (isnum(customId.c_str())) 
		{
			
			err.gameId = atoi(customId.c_str());
		}
		
	
		m_upEventDelegate->onUpgradeEvent(UPGRADE_DOWNLOAD_ERROR, &err);

	}
	
   // Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
   //     //if (!ptr.expired())
   //     {
   //     	DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(customId.c_str()), DownloadThreadState::ThreadState::DOWNLOAD_ERROR);
   //         WW_LOG_ERROR("WWDownloader::notifyError customId = %s, message = %s", customId.c_str(), msg.c_str());
   //         EventCustom event(EVENT_DOWNLOAD_ERROR);
   //         Error err;
			//err.code = code;
			//err.curle_code = curle_code;
			//err.curlm_code = curlm_code;
			//err.message = msg;
			//err.customId = customId;
			//event.setUserData(&err);
			//Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
   //     }
   // });
}

void WWDownloader::notifyError(const std::string &msg, int curlm_code, const std::string &customId/* = ""*/)
{
    notifyError(ErrorCode::CURL_MULTI_ERROR, msg, customId, CURLE_OK, curlm_code);
}

void WWDownloader::notifyError(const std::string &msg, const std::string &customId, int curle_code)
{
    notifyError(ErrorCode::CURL_EASY_ERROR, msg, customId, curle_code);
}

std::string WWDownloader::getFileNameFromUrl(const std::string &srcUrl)
{
    // Find file name and file extension
    std::string filename;
    unsigned long found = srcUrl.find_last_of("/\\");
    if (found != std::string::npos)
        filename = srcUrl.substr(found+1);
    return filename;
}

void WWDownloader::clearBatchDownloadData()
{
    while (_progDatas.size() != 0) {
        delete _progDatas.back();
        _progDatas.pop_back();
    }
    
    while (_files.size() != 0) {
        delete _files.back();
        _files.pop_back();
    }
}

void WWDownloader::prepareDownload(const std::string &srcUrl, const std::string &storagePath, const std::string &customId, bool resumeDownload,
									FileDescriptor *fDesc, ProgressData *pData, DownloadType type)
{
	//if (type == DownloadType::SINGLE_DOWNLOAD)
	{
		std::shared_ptr<WWDownloader> downloader = shared_from_this();
		pData->downloader = downloader;
	}
    pData->customId = customId;
    pData->url = srcUrl;
    pData->downloaded = 0;
    pData->totalToDownload = 0;
	pData->offsetLen = 0;

    fDesc->fp = nullptr;
    fDesc->curl = nullptr;
	fDesc->stopSign = false; 
	
    Error err;
    err.customId = customId;
    
    // Asserts
    // Find file name and file extension
    unsigned long found = storagePath.find_last_of("/\\");
    if (found != std::string::npos)
    {
        pData->name = storagePath.substr(found+1);
        pData->path = storagePath.substr(0, found+1);
    }
    else
    {
        err.code = ErrorCode::INVALID_URL;
        err.message = "Invalid url or filename not exist error: " + srcUrl;
        //if (this->_onError) this->_onError(err);
        notifyError(err.code, err.message, customId);
        return;
    }
    
    // Create a file to save file.
	const std::string outFileName = storagePath + TEMP_EXT;
	if (resumeDownload)
	{
		m_tmpFileLen = getLocalFileLength(outFileName.c_str());
	}
	else
	{
		m_tmpFileLen = 0;
	}

    if (resumeDownload && FileUtils::getInstance()->isFileExist(outFileName))
    {
        fDesc->fp = fopen(outFileName.c_str(), "ab+");
    }
    else
    {
        fDesc->fp = fopen(outFileName.c_str(), "wb");
    }

    if (!fDesc->fp)
    {
        err.code = ErrorCode::CREATE_FILE;
        err.message = StringUtils::format("Can not create file %s: errno %d", outFileName.c_str(), errno);
        //if (this->_onError) this->_onError(err);

        notifyError(err.code, err.message, customId);
    }
    else
    {
    	fseek(fDesc->fp, 0, SEEK_END);
    }
}
size_t save_header(const void *ptr, size_t size, size_t nmemb, const void *stream)
{

	return size*nmemb;
}
bool WWDownloader::prepareHeader(void *curl, const std::string &srcUrl)
{
    curl_easy_setopt(curl, CURLOPT_URL, srcUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, save_header);
	int userid = 0;
	if (userInfoData.find("userid") != userInfoData.end() && isnum(userInfoData.at("userid")))
	{
		
		userid = atoi(userInfoData.at("userid").c_str());
	}
	
	std::string userAgentInfo = StringUtils::format("model/%s userid/%d", IPhoneTool::getInstance()->getPhoneMANUFACTURER().c_str(), userid);
    WW_LOG_INFO("prepareHeader userAgentInfo = %s", userAgentInfo.c_str());
    curl_easy_setopt(curl, CURLOPT_USERAGENT, userAgentInfo.c_str());
	CURLcode retCode = curl_easy_perform(curl);
	WW_LOG_INFO("prepareHeader retCode = %d", retCode);
	if (retCode == CURLE_OK)
        return true;
    else
        return false;
}

long WWDownloader::getContentSize(const std::string &srcUrl)
{
    double contentLength = -1;
    CURL *header = curl_easy_init();

    curl_easy_setopt(header, CURLOPT_FOLLOWLOCATION, true);

    if (prepareHeader(header, srcUrl))
    {
        curl_easy_getinfo(header, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &contentLength);
    }
    curl_easy_cleanup(header);
    
    return contentLength;
}

void WWDownloader::downloadToBufferAsync(const std::string &srcUrl, unsigned char *buffer, const long &size, const std::string &customId/* = ""*/)
{
    if (buffer != nullptr)
    {
        std::shared_ptr<WWDownloader> downloader = shared_from_this();
        ProgressData pData;
        pData.customId = customId;
        pData.url = srcUrl;
        pData.downloader = downloader;
        pData.downloaded = 0;
        pData.totalToDownload = 0;
        
        StreamData streamBuffer;
        streamBuffer.buffer = buffer;
        streamBuffer.total = size;
        streamBuffer.offset = 0;
        
        auto t = std::thread(&WWDownloader::downloadToBuffer, this, srcUrl, customId, streamBuffer, pData);
        t.detach();
    }
}

void WWDownloader::downloadToBufferSync(const std::string &srcUrl, unsigned char *buffer, const long &size, const std::string &customId/* = ""*/)
{
    if (buffer != nullptr)
    {
        std::shared_ptr<WWDownloader> downloader = shared_from_this();
        ProgressData pData;
        pData.customId = customId;
        pData.url = srcUrl;
        pData.downloader = downloader;
        pData.downloaded = 0;
        pData.totalToDownload = 0;
        
        StreamData streamBuffer;
        streamBuffer.buffer = buffer;
        streamBuffer.total = size;
        streamBuffer.offset = 0;
        
        downloadToBuffer(srcUrl, customId, streamBuffer, pData);
    }
}

void WWDownloader::downloadToBuffer(const std::string &srcUrl, const std::string &customId, const StreamData &buffer, const ProgressData &data)
{
    std::weak_ptr<WWDownloader> ptr = shared_from_this();
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        this->notifyError(ErrorCode::CURL_EASY_ERROR, "Can not init curl with curl_easy_init", customId);
        return;
    }
    
    // Download pacakge
    curl_easy_setopt(curl, CURLOPT_URL, srcUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bufferWriteFunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, downloadProgressFunc);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &data);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
    if (_connectionTimeout) curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, _connectionTimeout);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, LOW_SPEED_LIMIT);
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, LOW_SPEED_TIME);
    
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        _fileUtils->removeFile(data.path + data.name + TEMP_EXT);
        std::string msg = StringUtils::format("Unable to download file: [curl error]%s", curl_easy_strerror(res));
        this->notifyError(msg, customId, res);
    }
    
    curl_easy_cleanup(curl);
    
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
        if (!ptr.expired())
        {
            std::shared_ptr<WWDownloader> downloader = ptr.lock();
            
            auto successCB = downloader->getSuccessCallback();
            if (successCB != nullptr)
            {
                successCB(data.url, "", data.customId);
            }
        }
    });
}

void WWDownloader::downloadAsync(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers,const std::string &customId/* = ""*/)
{
    FileDescriptor fDesc;
    ProgressData pData;
    prepareDownload(srcUrl, storagePath, customId, true, &fDesc, &pData);
    if (fDesc.fp != NULL)
    {
    	WW_LOG_INFO("WWDownloader::downloadAsync ");
    	m_downloadThread = std::thread(&WWDownloader::download, this, srcUrl, customId, fDesc, pData, headers);
    	m_downloadThread.detach();
    }
}

void WWDownloader::downloadSync(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers,const std::string &customId/* = ""*/)
{
    FileDescriptor fDesc;
    ProgressData pData;
    prepareDownload(srcUrl, storagePath, customId, true, &fDesc, &pData);
    if (fDesc.fp != NULL)
    {
        download(srcUrl, customId, fDesc, pData, headers);
    }
}

void WWDownloader::download(const std::string &srcUrl, const std::string &customId, const FileDescriptor &fDesc, const ProgressData &data, std::vector<std::string> headers)
{
    std::weak_ptr<WWDownloader> ptr = shared_from_this();
    g_downloadError = false;

    CURL *curl = curl_easy_init();
    if (!curl)
    {
        this->notifyError(ErrorCode::CURL_EASY_ERROR, "Can not init curl with curl_easy_init", customId);
        return;
    }

    WW_LOG_INFO("================ m_tmpFileLen = %d", m_tmpFileLen);

    // Download pacakge
    curl_easy_setopt(curl, CURLOPT_URL, srcUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fileWriteFunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fDesc.fp);
    curl_easy_setopt(curl, CURLOPT_RESUME_FROM, m_tmpFileLen);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, downloadProgressFunc);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &data);
    //curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
    if (_connectionTimeout) curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, _connectionTimeout);
    //curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    //curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, LOW_SPEED_LIMIT);
    //curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, LOW_SPEED_TIME);
    //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);


   if(!headers.empty())
   {

	   for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); ++it)
		   _headers = curl_slist_append(_headers,it->c_str());

	    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, _headers);
   }
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
    	g_downloadPause = false;
    	g_downloading = false;
    	g_downloadError = true;

        //_fileUtils->removeFile(data.path + data.name + TEMP_EXT);
        std::string msg = StringUtils::format("Unable to download file: [curl error]%s", curl_easy_strerror(res));
        this->notifyError(msg, customId, res);
    }
    
    fclose(fDesc.fp);
    curl_easy_cleanup(curl);

    // This can only be done after fclose
    if (res == CURLE_OK)
    {
    	g_downloadPause = false;
    	g_downloading = false;
    	g_downloadError = false;

        _fileUtils->renameFile(data.path, data.name + TEMP_EXT, data.name);

		WW_LOG_INFO("======================== CURLE_Succ");
	//	EventCustom event(EVENT_DOWNLOAD_SUCCESS);
		WWDownloader::SuccessData pData;
		pData.srcUrl = data.url;
		pData.storagePath = data.path + data.name;
		pData.customId = data.customId;
		if (isnum(data.customId.c_str())) 
		{
			pData.gameId = atoi(data.customId.c_str());
		}
		
	
		if (this->m_upEventDelegate) 
		{
			m_upEventDelegate->onUpgradeEvent(UpgradeEvent::UPGRADE_FINISH_DOWNLOAD, &pData);
		}

	//	std::string fileName = FileUtils::getInstance()->getWritablePath() + WWConfigManager::getInstance()->getValue("game_version")->getCString() + ".apk";
		IPhoneTool::getInstance()->updateLatestApkPackage(pData.storagePath);



   //     Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{

			//WW_LOG_INFO("======================== CURLE_Succ");
			//std::shared_ptr<WWDownloader> downloader = ptr.lock();

			////SystemFuncHandler::getInstance()->onInstallUpdateVer(data);

			///*
			//auto successCB = downloader->getSuccessCallback();
			//if (successCB != nullptr)
			//{
			//	successCB(data.url, data.path + data.name, data.customId);
			//}*/
   //     });
    }
}

bool WWDownloader::downloadHandle(const char* path, const FileDescriptor &fDesc, const ProgressData &data)
{
	CURL *handle = curl_easy_init();

	curl_easy_setopt(handle, CURLOPT_URL, path);
	//curl_easy_setopt(handle, CURLOPT_TIMEOUT, timeout);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, fileWriteFunc);  
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, fDesc.fp); 
	curl_easy_setopt(handle, CURLOPT_RESUME_FROM, m_tmpFileLen); 
	curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, downloadProgressFunc); 
	curl_easy_setopt(handle, CURLOPT_PROGRESSDATA, &data); 

	CURLcode res = curl_easy_perform(handle);
	fclose(fDesc.fp);
	return res == CURLE_OK;
}

long WWDownloader::getLocalFileLength(const char* filePath) {

    FILE *fp = fopen(filePath, "r");
    long length = 0;
    if (fp)
    {
    	fseek(fp, 0, SEEK_END);
    	length = ftell(fp);
    	fclose(fp);
    }
    else
    {
    	WW_LOG_INFO("%s is not exist", filePath);
    }

    return length;
}

void WWDownloader::batchDownloadAsync(const DownloadUnits &units, const std::string &batchId/* = ""*/)
{
	m_batchDownloadThread = std::thread(&WWDownloader::batchDownloadSync, this, units, batchId);
	m_batchDownloadThread.detach();
}

void WWDownloader::batchDownloadSync(const DownloadUnits &units, const std::string &batchId/* = ""*/)
{

	//m_finishDownloadThread = false;
	LuaModuleMutex.lock();
	g_IsFinishDownloadThread[batchId] = false;
	LuaModuleMutex.unlock();

    if (units.size() == 0)
    {
        return;
    }

    DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(batchId.c_str()), DownloadThreadState::ThreadState::DOWNLOADING);

    // Make sure downloader won't be released
    std::weak_ptr<WWDownloader> ptr = shared_from_this();
    
    // Test server download resuming support with the first unit
    _supportResuming = false;
    CURL *header = curl_easy_init();
    // Make a resume request
    //curl_easy_setopt(header, CURLOPT_RESUME_FROM_LARGE, 0);
    curl_easy_setopt(header, CURLOPT_RANGE, "0-");
    if (prepareHeader(header, units.begin()->second.srcUrl))
    {
        long responseCode;
        curl_easy_getinfo(header, CURLINFO_RESPONSE_CODE, &responseCode);
        if (responseCode == HTTP_CODE_SUPPORT_RESUME)
        {
            _supportResuming = true;
        }
    }
    curl_easy_cleanup(header);
    
    int count = 0;
    DownloadUnits group;
    vector<pair<int, DownloadUnit> > tVector;
    sortMapByValue(units, tVector);

    for (auto it = tVector.cbegin(); it != tVector.cend(); ++it, ++count)
    {
    	if (g_IsFinishDownloadThread[batchId])
    	{
    		Director::getInstance()->getScheduler()->performFunctionInCocosThread([units]{
    			for (auto it = units.cbegin(); it != units.cend(); ++it)
    			{
    				DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(it->second.customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
    			}
    		});
    		return;
    	}

        //if (count == FOPEN_MAX)
    	//if (count == 1)
    	if (count == m_ThreadNum)
        {
            groupBatchDownload(group, batchId);
            group.clear();
            count = 0;
        }
		
		//这儿下载完成后，需要释放打开的文件

		

        if (FileUtils::getInstance()->isFileExist(it->second.storagePath) && it->second.resumeDownload)
        {
        	
			decompress(it->second.storagePath, it->second.customId, batchId);
			FileUtils::getInstance()->removeFile(it->second.storagePath);
        }
        else
        {
			int key = it->first;
			const DownloadUnit &unit = it->second;
			group.emplace(key, unit);
        }
    }

    if (g_IsFinishDownloadThread[batchId])
	{
    	Director::getInstance()->getScheduler()->performFunctionInCocosThread([units]{
    		for (auto it = units.cbegin(); it != units.cend(); ++it)
    		{
    			DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(it->second.customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
    		}
    	});
		return;
	}

    if (group.size() > 0)
    {
        groupBatchDownload(group, batchId);
    }
    onUncompressRes(units, batchId);

    _supportResuming = false;

  
	batchDownloadMutex.lock();
	for (auto it = units.cbegin(); it != units.cend(); ++it)
	{
		DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(it->second.customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
	}
	batchDownloadMutex.unlock();
 //   Director::getInstance()->getScheduler()->performFunctionInCocosThread([units]{
	//	for (auto it = units.cbegin(); it != units.cend(); ++it)
	//	{
	//		DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(it->second.customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
	//	}
	//});
    if (g_IsFinishDownloadThread[batchId])
    {
    	return;
    }

	batchDownloadMutex.lock();

	int moduleID = atoi(batchId.c_str());



	DownloadThreadState::getInstance()->onSetDownloadThreadState(moduleID, DownloadThreadState::ThreadState::THREAD_END);
	if (moduleID == UpGradeConst::g_SilenceDownload)
	{
		DownloadThreadState::getInstance()->onAddSilentDownloadCount();
	}
	//std::shared_ptr<WWDownloader> downloader = ptr.lock();
	// final succ
	log("====================== getSuccessCallback batchId = %s", batchId.c_str());
	// Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_FINISH_DOWNLOAD_UNZIP_TOLAYER);
	// Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_START_SILENCE_DOWNLOAD);
	
	if (this->m_upEventDelegate)
	{
		UnzipOverData pdata;
		pdata.customId = batchId;
		if (isnum(pdata.customId.c_str()))
		{
			pdata.gameId = atoi(pdata.customId.c_str());
		}
		m_upEventDelegate->onUpgradeEvent(UpgradeEvent::UPGRADE_FINISH_DOWNLOAD_UNZIP_TOLAYER, &pdata);
		//m_upEventDelegate->onUpgradeEvent(UpgradeEvent::UPGRADE_START_SILENCE_DOWNLOAD, &pdata);
	}

	batchDownloadMutex.unlock();

}

void WWDownloader::groupBatchDownload(const DownloadUnits &units, const std::string &batchId/* = ""*/)
{
    CURLM* multi_handle = curl_multi_init();
    int still_running = 0;
    
    std::vector<ProgressData *> tmpProgDatas;
    std::vector<FileDescriptor *> tmpFiles;

    for (auto it = units.cbegin(); it != units.cend(); ++it)
    {
        DownloadUnit unit = it->second;
        std::string srcUrl = unit.srcUrl;
        std::string storagePath = unit.storagePath;
        std::string customId = unit.customId;
        if (atoi(batchId.c_str()) == UpGradeConst::g_SilenceDownload)
        {
			customId = StringUtils::format("%d", UpGradeConst::g_SilenceDownload);
        }
        
        FileDescriptor *fDesc = new FileDescriptor();
		fDesc->batchId = batchId;
        ProgressData *data = new ProgressData();
        prepareDownload(srcUrl, storagePath, customId, unit.resumeDownload, fDesc, data, DownloadType::BATCH_DOWNLOAD);

		auto removeFileSize = DownloadThreadState::getInstance()->onGetRemoteFileSize(atoi(customId.c_str()));
		if (removeFileSize==m_tmpFileLen) 
		{
			if (fDesc->fp != NULL)
			{
				fclose(fDesc->fp);
			}
			//已经下载完毕
			if (_fileUtils->isFileExist(data->path + data->name + TEMP_EXT))
			{
				
				_fileUtils->renameFile(data->path, data->name + TEMP_EXT, data->name);
			}
			
			continue;
		}
		

        if (fDesc->fp != NULL)
        {
            CURL* curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, srcUrl.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, controlfileWriteFunc);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fDesc);
			

            if (_supportResuming)
            {
				//data->offsetLen = m_tmpFileLen;
				auto rang = StringUtils::format("%d", m_tmpFileLen)+"-";
				CCLOG("从%s开始下载",rang.c_str());
				curl_easy_setopt(curl, CURLOPT_RANGE, rang.c_str());
            	curl_easy_setopt(curl, CURLOPT_RESUME_FROM, m_tmpFileLen);
				
            }
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, batchDownloadProgressFunc);
            curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, data);
            curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
            if (_connectionTimeout) curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, _connectionTimeout);
            curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, LOW_SPEED_LIMIT);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, LOW_SPEED_TIME);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);
            curl_easy_setopt(curl, CURLOPT_MAXREDIRS, MAX_REDIRS);
            
            /*
            // Resuming download support
            if (_supportResuming && unit.resumeDownload)
            {
                // Check already downloaded size for current download unit
                long size = _fileUtils->getFileSize(storagePath + TEMP_EXT);
                if (size != -1)
                {
                    curl_easy_setopt(curl, CURLOPT_RESUME_FROM_LARGE, size);
                }
            }
            */
            fDesc->curl = curl;
			fDesc->multi_handle = multi_handle;
			fDesc->units = units;
			fDesc->stopSign = false;
            CURLMcode code = curl_multi_add_handle(multi_handle, curl);
            if (code != CURLM_OK)
            {
                // Avoid memory leak
                fclose(fDesc->fp);
                delete data;
                delete fDesc;
                std::string msg = StringUtils::format("Unable to add curl handler for %s: [curl error]%s", customId.c_str(), curl_multi_strerror(code));
                this->notifyError(msg, code, batchId);
            }
            else
            {
                // Add to list for tracking
                _progDatas.push_back(data);
                _files.push_back(fDesc);

                tmpProgDatas.push_back(data);
                tmpFiles.push_back(fDesc);
            }
        }
    }

    // Query multi perform
    CURLMcode curlm_code = CURLM_CALL_MULTI_PERFORM;
    while(CURLM_CALL_MULTI_PERFORM == curlm_code) {
        curlm_code = curl_multi_perform(multi_handle, &still_running);
    }
    if (curlm_code != CURLM_OK) {
        std::string msg = StringUtils::format("Unable to continue the download process: [curl error]%s", curl_multi_strerror(curlm_code));
        this->notifyError(msg, curlm_code, batchId);
    }
    else
    {
        bool failed = false;
		
		while (still_running > 0 && !failed && g_IsFinishDownloadThread.find(batchId) != g_IsFinishDownloadThread.end())
        {
            // set a suitable timeout to play around with
            struct timeval select_tv;
            long curl_timeo = -1;
            select_tv.tv_sec = 1;
            select_tv.tv_usec = 0;
            
            curl_multi_timeout(multi_handle, &curl_timeo);
            if(curl_timeo >= 0) {
                select_tv.tv_sec = curl_timeo / 1000;
                if(select_tv.tv_sec > 1)
                    select_tv.tv_sec = 1;
                else
                    select_tv.tv_usec = (curl_timeo % 1000) * 1000;
            }
            
            int rc;
            fd_set fdread;
            fd_set fdwrite;
            fd_set fdexcep;
            int maxfd = -1;
            FD_ZERO(&fdread);
            FD_ZERO(&fdwrite);
            FD_ZERO(&fdexcep);
            curl_multi_fdset(multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);
            rc = select(maxfd + 1, &fdread, &fdwrite, &fdexcep, &select_tv);
            
            switch(rc)
            {
                case -1:
                    failed = true;
                    break;
                case 0:
                default:
                    curlm_code = CURLM_CALL_MULTI_PERFORM;
                    while(CURLM_CALL_MULTI_PERFORM == curlm_code) {
                        curlm_code = curl_multi_perform(multi_handle, &still_running);
                    }
                    if (curlm_code != CURLM_OK) {
                        std::string msg = StringUtils::format("Unable to continue the download process: [curl error]%s", curl_multi_strerror(curlm_code));
                        this->notifyError(msg, curlm_code, batchId);
                    }
                    break;
            }
        }
    }

/*
    // Clean up and close files
    for (auto it = _files.begin(); it != _files.end(); ++it)
    {
        FILE *f = (*it)->fp;
        fclose(f);
        auto single = (*it)->curl;
        curl_multi_remove_handle(multi_handle, single);
        curl_easy_cleanup(single);
    }
    curl_multi_cleanup(multi_handle);

    // Check unfinished files and notify errors, succeed files will be renamed from temporary file name to real name
    for (auto it = _progDatas.begin(); it != _progDatas.end(); ++it) {
        ProgressData *data = *it;
        if (data->downloaded < data->totalToDownload || data->totalToDownload == 0)
        {
            this->notifyError(ErrorCode::NETWORK, "Unable to download file", data->customId);
        }
        else
        {
            _fileUtils->renameFile(data->path, data->name + TEMP_EXT, data->name);
        }
    }
    
    clearBatchDownloadData();
    */

    for (auto it = tmpFiles.begin(); it != tmpFiles.end(); ++it)
	{
		FILE *f = (*it)->fp;
		fclose(f);
		auto single = (*it)->curl;
		curl_multi_remove_handle(multi_handle, single);
		curl_easy_cleanup(single);
	}
	curl_multi_cleanup(multi_handle);

	if (g_IsFinishDownloadThread[batchId])
	{
		return;
	}

	// Check unfinished files and notify errors, succeed files will be renamed from temporary file name to real name
	for (auto it = tmpProgDatas.begin(); it != tmpProgDatas.end(); ++it) {
		ProgressData *data = *it;
		if (data->downloaded < data->totalToDownload || data->totalToDownload == 0)
		{
			this->notifyError(ErrorCode::NETWORK, "Unable to download file", batchId);
		}
		else
		{
			_fileUtils->renameFile(data->path, data->name + TEMP_EXT, data->name);
		}
	}

	//clearBatchDownloadData();

    while (tmpProgDatas.size() != 0) {
        delete tmpProgDatas.back();
        tmpProgDatas.pop_back();
		_progDatas.pop_back();
    }

    while (tmpFiles.size() != 0) {
        delete tmpFiles.back();
        tmpFiles.pop_back();
		_files.pop_back();
    }
	
}

void WWDownloader::stopDownload(const DownloadUnits &units)
{

	for (auto& unit:units)
	{
		
		if (std::find(stopDownloadIds.begin(), stopDownloadIds.end(), unit.first) == stopDownloadIds.end())
		{
			stopDownloadIds.push_back(unit.first);
		}

	}
	


	for (auto downloadFileDes:this->_files) 
	{
		if (units.size() != downloadFileDes->units.size()) 
		{
			break;
		}
		bool isEq = true;
		for (auto funit:downloadFileDes->units) 
		{
			
			
			if (units.find(funit.first) != units.end()) 
			{
				
				isEq = false;
				downloadFileDes->stopSign = true;
				//fclose(downloadFileDes->fp);
				CCLOG("%d 停止下载", funit.first);

				for (auto& prog:_progDatas) 
				{
					
					if (atoi(prog->customId.c_str())== funit.first)
					{
						CCLOG("%d 停止下载2", funit.first);
						prog->stopFlag = true;
						
						break;
					}
					
				}
				
				break;
			}
			
		}

		

	}
	
}

void WWDownloader::onUncompressRes(const DownloadUnits &units, const std::string &batchId)
{
	for (auto it = units.cbegin(); it != units.cend(); ++it)
	{
		const DownloadUnit &unit = it->second;
		if (decompress(unit.storagePath, unit.customId, batchId))
		{
			FileUtils::getInstance()->removeFile(unit.storagePath);
		}
	}
}

bool WWDownloader::decompress(const std::string &zip, std::string customId, const std::string &batchId)
{
	bool isHotUpdateZip = false;
	if (UpGradeConst::g_HotUpdateBatchID == atoi(customId.c_str()) || UpGradeConst::g_SilenceDownload == atoi(customId.c_str()))
	{
		isHotUpdateZip = true;
	}

    
    size_t pos = zip.find_last_of("/\\");
    if (pos == std::string::npos)
    {
        CCLOG("decompress : no root path specified for zip file %s\n", zip.c_str());
        return false;
    }
    CCLOG("decompress Zip = %s", zip.c_str());
    const std::string rootPath = zip.substr(0, pos+1);
    CCLOG("decompress rootPath = %s", rootPath.c_str());

   
    unzFile zipfile = unzOpen(zip.c_str());
    if (! zipfile)
    {
        CCLOG("decompress : can not open downloaded zip file %s\n", zip.c_str());
        return false;
    }

  
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
    {
        CCLOG("decompress : can not read file global info of %s\n", zip.c_str());
        unzClose(zipfile);
        return false;
    }

	if (this->m_upEventDelegate)
	{
		int gameID = atoi(customId.c_str());
		UnzipingData udata;
		udata.customId = customId;
		if (isnum(udata.customId.c_str()))
		{
			udata.gameId = atoi(udata.customId.c_str());
		}
		this->m_upEventDelegate->onUpgradeEvent(UPGRADE_UNZIPING_PROGRESS, &udata);
	}
	DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(customId.c_str()), DownloadThreadState::ThreadState::UNZIPING);
	//Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
	//	int gameID = atoi(customId.c_str());

	//	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UNZIPING_PROGRESS, &gameID);
	//	DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(customId.c_str()), DownloadThreadState::ThreadState::UNZIPING);
	//});

    char readBuffer[BUFFER_SIZE];
    uLong i;
	bool stopIt = false;
	for (i = 0; i <global_info.number_entry; ++i)
    {
		
		for (auto stopId : stopDownloadIds)
		{
			if (isnum(customId))
			{
				if (stopId == atoi(customId.c_str()))
				{
					stopIt = true;

				}
			}
		}
		if (stopIt) {
			stopDownloadIds.erase(std::find(stopDownloadIds.begin(), stopDownloadIds.end(), atoi(customId.c_str())));
			break;
		}
		
		
    	//if (g_IsFinishDownloadThread[batchId])
		{
    		Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
    			int gameID = atoi(customId.c_str());
    			DownloadThreadState::getInstance()->onSetDownloadThreadState(gameID, DownloadThreadState::ThreadState::THREAD_END);
    		});
			//return false;
		}

       
        unz_file_info fileInfo;
        char fileName[MAX_FILENAME];
        if (unzGetCurrentFileInfo(zipfile,
                                  &fileInfo,
                                  fileName,
                                  MAX_FILENAME,
                                  NULL,
                                  0,
                                  NULL,
                                  0) != UNZ_OK)
        {
            CCLOG("decompress : can not read compressed file info\n");
            unzClose(zipfile);
            return false;
        }
		
		
        if (isHotUpdateZip) //热更模块解压 先要截断里边的顶层目录结构
        {
			//UpGradeConst::g_SilenceDownload
			std::string topDic = UpGradeConst::LUAHOTUPDATE_TOPDIC;
			if (UpGradeConst::g_SilenceDownload == atoi(customId.c_str())) 
			{
				topDic = UpGradeConst::LUAWHOLEPACKAGE_TOPDIC;
			}
			
			
			if (strcmp(fileName, topDic.c_str()) == 0 /*|| strcmp(fileName, "Res/Resources/") == 0*/)
            {
                unzGoToNextFile(zipfile);
                continue;
            }

			int step = strlen(topDic.c_str());
            int ii = step;
            while (fileName[ii])
            {
                fileName[ii - step] = fileName[ii];
                ++ii;
            }
            fileName[ii - step] = '\0';
        }
        const std::string fullPath = rootPath + fileName;
		
        size_t pos = fullPath.find_last_of("/\\");
        const std::string directoryPath = fullPath.substr(0, pos+1);
        //CCLOG("decompress : directoryPath = %s", directoryPath.c_str());
		std::string extensionStr = FileUtils::getInstance()->getFileExtension(fileName);
		if (extensionStr.empty())
		{
			unzGoToNextFile(zipfile);
			continue;
		};
		CCLOG("decompress : create directory %s", fullPath.c_str());
        if (!FileUtils::getInstance()->isDirectoryExist(directoryPath))
        {
        	FileUtils::getInstance()->createDirectory(basename(fullPath));
        }

		
		
        const size_t filenameLength = strlen(fileName);
        if (fileName[filenameLength-1] == '/')
        {
            if ( !FileUtils::getInstance()->createDirectory(basename(fullPath)) )
            {
                CCLOG("decompress : can not create directory %s\n", fullPath.c_str());
                unzClose(zipfile);
                return false;
            }
        }
        else
        {
            if (unzOpenCurrentFile(zipfile) != UNZ_OK)
            {
                CCLOG("decompress : can not extract file %s\n", fileName);
                unzClose(zipfile);
                return false;
            }

            FILE *out = fopen(fullPath.c_str(), "wb");
            //CCLOG("fullPath.c_str() = %s", fullPath.c_str());
            if (!out)
            {
                CCLOG("decompress : can not create decompress destination file %s\n", fullPath.c_str());
                unzCloseCurrentFile(zipfile);
                unzClose(zipfile);
                return false;
            }

            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
                if (error < 0)
                {
                    CCLOG("decompress : can not read zip file %s, error code is %d\n", fileName, error);
                    fclose(out);
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    return false;
                }

                if (error > 0)
                {
                    fwrite(readBuffer, error, 1, out);
                }
            } while(error > 0);

            fclose(out);
        }

        unzCloseCurrentFile(zipfile);

        if (i+1<global_info.number_entry)
        {
            if (unzGoToNextFile(zipfile) != UNZ_OK)
            {
                CCLOG("decompress : can not read next file for decompressing\n");
                unzClose(zipfile);
                return false;
            }
        }

		std::string::size_type pos3 = fullPath.rfind(".");
		std::string ext = fullPath.substr(pos3 == std::string::npos ? fullPath.length() : pos3 + 1);

		if (ext.compare("zip") == 0)
		{
			uncompressZip(fullPath.c_str(), false);
		}

    }

    unzClose(zipfile);

	int gameID = atoi(customId.c_str());
	if (this->m_upEventDelegate && !stopIt)
	{
		UnzipingData udata;
		udata.customId = gameID;
		if (isnum(udata.customId.c_str()))
		{
			udata.gameId = atoi(udata.customId.c_str());
		}
		this->m_upEventDelegate->onUpgradeEvent(UPGRADE_UNZIP_MODULE_SUCCESS, &udata);
	}
	

	//Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
	//	int gameID = atoi(customId.c_str());
	//	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UNZIP_MODULE_SUCC, &gameID);
	//});

    return true;
}

bool WWDownloader::uncompressZip(const char * pOutFileName, bool topDir/* = true*/)
{
	//outFileName为要解压缩的文件名
	//就是D:\\cocos2dx-xtc\\projects\\dlStudy0\\proj.win32\\Debug.win32\\A.zip
	//即CCFileUtils::sharedFileUtils()->getWritablePath() + “A.zip"
	std::string outFileName = pOutFileName;

	// 打开压缩文件
	unzFile zipfile = unzOpen(outFileName.c_str());
	if (!zipfile)
	{
		CCLOG("can not open downloaded zip file %s", outFileName.c_str());
		return false;
	}

	// 获取zip文件信息
	unz_global_info global_info;
	if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
	{
		CCLOG("can not read file global info of %s", outFileName.c_str());
		unzClose(zipfile);
		return false;
	}

	// 临时缓存，用于从zip中读取数据，然后将数据给解压后的文件
	// BUFFER_SIZE == 8192
	char readBuffer[BUFFER_SIZE];

	//开始解压缩
	CCLOG("start uncompressing");

	//创建解压缩后的文件夹


	std::string storageDir;

	if (true) //即在A.zip路径下当前路径
	{
		int pos1 = outFileName.find_last_of("/");
		int pos2 = outFileName.find_last_of("\\");
		int pos = std::max(pos1, pos2);

		storageDir = outFileName.substr(0, pos).append("\\");
	}



	FileUtils::getInstance()->createDirectory(storageDir.c_str());

	//CCLOG("decompress : directoryPath = %s", directoryPath.c_str());




	// 循环提取压缩包内文件
	// global_info.number_entry为压缩包内文件个数
	uLong i;
	for (i = 0; i < global_info.number_entry; ++i)
	{
		// 获取压缩包内的文件名
		unz_file_info fileInfo;
		char fileName[MAX_FILENAME];    // MAX_FILENAME == 512
		if (unzGetCurrentFileInfo(zipfile,
			&fileInfo,
			fileName,
			MAX_FILENAME,
			NULL,
			0,
			NULL,
			0) != UNZ_OK)
		{
			CCLOG("can not read file info");
			unzClose(zipfile);
			return false;
		}

		if (topDir)
		{
			std::string topDic = UpGradeConst::LUAWHOLEPACKAGE_TOPDIC;

			if (strcmp(fileName, topDic.c_str()) == 0 /*|| strcmp(fileName, "Res/Resources/") == 0*/)
			{
				unzGoToNextFile(zipfile);
				continue;
			}

			int step = strlen(topDic.c_str());
			int i = step;
			while (fileName[i])
			{
				fileName[i - step] = fileName[i];
				++i;
			}
			fileName[i - step] = '\0';
		}

		//该文件最终存放路径
		std::string fullPath = storageDir + fileName;

		// 检测路径是文件夹还是文件
		const size_t filenameLength = strlen(fileName);
		if (fileName[filenameLength - 1] == '/')
		{
			// 该文件是一个文件夹，那么就创建它			
			if (!FileUtils::getInstance()->createDirectory(fullPath.c_str()))
			{
				CCLOG("can not create directory %s", fullPath.c_str());
				unzClose(zipfile);
				return false;
			}
		}
		else
		{
			// 该文件是一个文件，那么就提取创建它



			size_t pos2 = fullPath.find_last_of("/\\");
			const std::string directoryPath2 = fullPath.substr(0, pos2 + 1);
			//CCLOG("decompress : directoryPath = %s", directoryPath.c_str());
			if (!FileUtils::getInstance()->isDirectoryExist(directoryPath2))
			{
				FileUtils::getInstance()->createDirectory(basename(fullPath));
			}

			// 打开压缩文件
			if (unzOpenCurrentFile(zipfile) != UNZ_OK)
			{
				CCLOG("can not open file %s", fileName);
				unzClose(zipfile);
				return false;
			}

			// 创建目标文件
			FILE *out = fopen(fullPath.c_str(), "wb");
			if (!out)
			{
				CCLOG("can not open destination file %s", fullPath.c_str());
				unzCloseCurrentFile(zipfile);
				unzClose(zipfile);
				return false;
			}

			// 将压缩文件内容写入目标文件
			int error = UNZ_OK;
			do
			{
				error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
				if (error < 0)
				{
					CCLOG("can not read zip file %s, error code is %d", fileName, error);
					unzCloseCurrentFile(zipfile);
					unzClose(zipfile);
					return false;
				}

				if (error > 0)
				{
					fwrite(readBuffer, error, 1, out);
				}
			} while (error > 0);

			fclose(out);

		}

		//关闭当前被解压缩的文件
		unzCloseCurrentFile(zipfile);

		// 如果zip内还有其他文件，则将当前文件指定为下一个待解压的文件
		if ((i + 1) < global_info.number_entry)
		{
			if (unzGoToNextFile(zipfile) != UNZ_OK)
			{
				CCLOG("can not read next file");
				unzClose(zipfile);
				return false;
			}
		}
		std::string::size_type pos3 = fullPath.rfind(".");
		std::string ext = fullPath.substr(pos3 == std::string::npos ? fullPath.length() : pos3 + 1);

		if (ext.compare("zip") == 0)
		{
			

			uncompressZip(fullPath.c_str(), false);
		}
	}

	//压缩完毕
	CCLOG("end uncompressing");

	//压缩完毕删除zip文件，删除前要先关闭
	unzClose(zipfile);
	if (remove(outFileName.c_str()) != 0)
	{
		CCLOG("can not remove downloaded zip file %s", outFileName.c_str());
	}

	return true;
}


std::string WWDownloader::basename(const std::string& path)
{
    size_t found = path.find_last_of("/\\");

    if (std::string::npos != found)
    {
        return path.substr(0, found);
    }
    else
    {
        return path;
    }
}

void WWDownloader::onSetFinishDownload(bool flag)
{
	m_finishDownloadThread = flag;
}

bool WWDownloader::onGetFinishDownload()
{
	return m_finishDownloadThread;
}

void WWDownloader::onSetASyncThreadNum(int num)
{
	if (num > FOPEN_MAX)
	{
		num = FOPEN_MAX;
	}

	m_ThreadNum = num;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DownloadThreadState* DownloadThreadState::mDownloadThreadState = nullptr;

DownloadThreadState::DownloadThreadState():
		mSilentDownloadCount(0)
{
	onInitModuleNameCfg();
}

DownloadThreadState::~DownloadThreadState()
{

}

void DownloadThreadState::onSetDownloadThreadState(int gameID, ThreadState state)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	mStateMap[gameID] = state;
}

DownloadThreadState::ThreadState DownloadThreadState::onGetDownloadThreadState(int gameID)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	std::map<int, ThreadState>::iterator it = mStateMap.find(gameID);
	if (it != mStateMap.end())
	{
		return it->second;
	}
	else
	{
		return ThreadState::UNKNOWN;
	}
}

void DownloadThreadState::onSetLocalFileSize(int gameID, long size)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	mLocalFileSizeMap[gameID] = size;
}

long DownloadThreadState::onGetLocalFileSize(int gameID)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	std::map<int, long>::iterator it = mLocalFileSizeMap.find(gameID);
	if (it != mLocalFileSizeMap.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

void DownloadThreadState::onSetModuleHttpAddr(std::string moduleName, std::string addr)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	mModuleHttpAddr[moduleName] = addr;
}

std::string DownloadThreadState::onGetModuleHttpAddr(std::string moduleName)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	auto iter = mModuleHttpAddr.find(moduleName);
	if (iter != mModuleHttpAddr.end())
	{
		return iter->second;
	}
	else
	{
		return "";
	}
}

void DownloadThreadState::onSetRemoteFileSizeMap(int gameID, long size)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	mRemoteFileSizeMap[gameID] = size;
}

long DownloadThreadState::onGetRemoteFileSize(int gameID)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	std::map<int, long>::iterator it = mRemoteFileSizeMap.find(gameID);
	if (it != mRemoteFileSizeMap.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

void DownloadThreadState::onSetIsRequestRemoteFileSize(int gameID, bool flag)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	mIsRequestRemoteFileSizeMap[gameID] = flag;
}

bool DownloadThreadState::onGetIsRequestRemoteFileSize(int gameID)
{
	std::unique_lock<std::mutex> locker(g_DataLock);
	std::map<int, bool>::iterator it = mIsRequestRemoteFileSizeMap.find(gameID);
	if (it != mIsRequestRemoteFileSizeMap.end())
	{
		return it->second;
	}
	else
	{
		return false;
	}
}

void DownloadThreadState::addModuleNameCfg(int moduleId, std::string moduleName)
{
	if (mModuleNameCfg.find(moduleId) == mModuleNameCfg.end())
	{
		mModuleNameCfg.emplace(std::make_pair(moduleId, moduleName));

	} else
	{
		mModuleNameCfg[moduleId] = moduleName;
	}

}

void DownloadThreadState::onInitModuleNameCfg()
{
	//mModuleNameCfg[UpGradeConst::g_LuaGameID] = "src";
	//mModuleNameCfg[UpGradeConst::g_HotUpdateBatchID] = "Res";
	//mModuleNameCfg[g_ChatGameID] = "Chat";
	//mModuleNameCfg[g_ChargeGameID] = "ExtraGame";
	//mModuleNameCfg[g_HDGameID] = "Activity";
	//mModuleNameCfg[g_CCGameID] = "guess";
	//mModuleNameCfg[g_DNGameID] = "DN";
	//mModuleNameCfg[g_DuoBaoGameID] = "DN";
	//mModuleNameCfg[g_HotUpdateBatchID] = "Res";

	//mModuleNameCfg[g_HongBaoGameID] = "HongBao";
	//mModuleNameCfg[g_CouponGameID] = "Exchange";
	//mModuleNameCfg[g_ExtraGameID] = "ExtraGame";

 //   mModuleNameCfg[g_MatchGameID] = "MatchGame";
 //   mModuleNameCfg[g_Tiger100GameID] = "tiger100";
}

std::string DownloadThreadState::onGetModuleName(int gameID)
{
	auto iter = mModuleNameCfg.find(gameID);
	if (iter != mModuleNameCfg.end())
	{
		return iter->second;
	}
	else
	{
		return "";
	}
}

void DownloadThreadState::onAddSilentDownloadCount()
{
	++mSilentDownloadCount;
}

bool DownloadThreadState::isSilentDownloadMaxCount()
{
	if (mSilentDownloadCount < MAX_DOWNLOAD_COUNT)
	{
		return false;
	}
	else
	{
		return true;
	}
}
