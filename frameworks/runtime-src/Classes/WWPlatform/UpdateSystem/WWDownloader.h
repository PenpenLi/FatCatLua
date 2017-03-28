
/*! @file
********************************************************************************
<PRE>
模块名       :  下载工具类
文件名       :  WWDownloader.h
文件实现功能 :  模块 资源下载工具类
作者         :  cruelogre  546761316@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/11/1   1.0     cruelogre		      移植
</PRE>
*******************************************************************************/

#pragma once
#include "platform/CCFileUtils.h"
#include "cocos2d.h"
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include "curl/curl.h"
#include "curl/easy.h"
#include "UpGradeDelegate.h"

extern std::atomic<bool> g_downloadPause;	
extern std::atomic<bool> g_downloading;		
extern std::atomic<bool> g_downloadError;	

extern std::mutex              g_DownloadLock;
extern std::condition_variable g_DownloadConVar;

class DownloadThreadState
{
public:

	enum class ThreadState
	{
		UNKNOWN,

		DOWNLOADING,

		DOWNLOADED,

		UNZIPING,

		THREAD_END,

		DOWNLOAD_ERROR,
	};

	DownloadThreadState();

	virtual ~DownloadThreadState();

    static DownloadThreadState* getInstance()
    {
        if (!mDownloadThreadState)
        {
        	mDownloadThreadState = new DownloadThreadState();
        }
        return mDownloadThreadState;
    }

    static void release()
    {
        if (mDownloadThreadState)
        {
            delete mDownloadThreadState;
            mDownloadThreadState = nullptr;
        }
    }

	void onSetDownloadThreadState(int gameID, ThreadState state);

	ThreadState onGetDownloadThreadState(int gameID);

	void onSetLocalFileSize(int gameID, long size);

	long onGetLocalFileSize(int gameID);

	void onSetModuleHttpAddr(std::string module, std::string addr);

	std::string onGetModuleHttpAddr(std::string module);

	void onSetRemoteFileSizeMap(int gameID, long size);

	long onGetRemoteFileSize(int gameID);

	void onSetIsRequestRemoteFileSize(int gameID, bool flag);

	bool onGetIsRequestRemoteFileSize(int gameID);

	void onInitModuleNameCfg();

	std::string onGetModuleName(int gameID);

	void onAddSilentDownloadCount();

	bool isSilentDownloadMaxCount();

	void addModuleNameCfg(int moduleId,std::string moduleName);
private:

	static DownloadThreadState*	mDownloadThreadState;

	std::map<int, ThreadState>	mStateMap;	

	std::map<int, long>	mLocalFileSizeMap;	

	std::map<std::string, std::string> mModuleHttpAddr;	

	std::map<int, bool>	mIsRequestRemoteFileSizeMap;

	std::map<int, long>	mRemoteFileSizeMap;

	std::unordered_map<int, std::string> mModuleNameCfg;

	int		mSilentDownloadCount;
};

class WWDownloader : public std::enable_shared_from_this<WWDownloader>
{
public:

	enum class DownloadType
	{
		SINGLE_DOWNLOAD,

		BATCH_DOWNLOAD,
	};

    enum ErrorCode
    {
        CREATE_FILE,

        NETWORK,

        NO_NEW_VERSION,

        UNCOMPRESS,

        CURL_UNINIT,
        
        CURL_MULTI_ERROR,
        
        CURL_EASY_ERROR,

        INVALID_URL,

        INVALID_STORAGE_PATH
    };

    enum class DownloadState
    {
    	UN_DOWNLOAD,		

    	DOWNLOADED,			

    	CANCLE_DOWNLOAD,	
    };

    struct resInfo
    {
    	int 				gameId;			
    	DownloadState		state;			
    	std::string			resName;		
    	std::string			storagePath;	
    	int					priority;		
    	int					downloadId;		
    };


	struct Error :public EventData
    {
        ErrorCode code;
        int curlm_code;
        int curle_code;
        std::string message;
        std::string customId;
        std::string url;
		Error()
		{
			eType = EventData::Event_Error;
		}
	
    };

	struct ProgressData :public EventData
    {
        std::weak_ptr<WWDownloader> downloader;
        std::string customId;
        std::string url;
        std::string path;
        std::string name;
        double downloaded;
        double totalToDownload;
		bool stopFlag;
		long offsetLen; //初始长度
		ProgressData()
		{
			eType = EventData::Event_Progress;
			stopFlag = false;//停止标志
			offsetLen = 0;
		}
    };

	struct SuccessData :public EventData
    {
    	std::string srcUrl;
    	std::string storagePath;
    	std::string customId;
		SuccessData()
		{
			eType = EventData::Event_Success;
		}
    };

	struct UnzipingData :public EventData
	{

		std::string customId;
		UnzipingData()
		{
			eType = EventData::Event_Unzip;
		}
	};
	struct UnzipOverData :public EventData
	{

		std::string customId;
		UnzipOverData()
		{
			eType = EventData::Event_UnzipOver;
		}
	};


    struct DownloadUnit
    {
        std::string srcUrl;
        std::string storagePath;
        std::string customId;
        bool resumeDownload;
        int priority;
        std::string resName;
    };
    
    struct StreamData
    {
        long offset;
        long total;
        unsigned char *buffer;
    };
    
    typedef std::unordered_map<int, DownloadUnit> DownloadUnits;
    
    typedef std::function<void(const WWDownloader::Error &)> ErrorCallback;
    typedef std::function<void(double, double, const std::string &, const std::string &)> ProgressCallback;
    typedef std::function<void(const std::string &, const std::string &, const std::string &)> SuccessCallback;

    int getConnectionTimeout();

    void setConnectionTimeout(int timeout);
    
    void setErrorCallback(const ErrorCallback &callback) { _onError = callback; };
    
    void setProgressCallback(const ProgressCallback &callback) { _onProgress = callback; };
    
    void setSuccessCallback(const SuccessCallback &callback) { _onSuccess = callback; };

    ErrorCallback getErrorCallback() const { return _onError; };

    ProgressCallback getProgressCallback() const { return _onProgress; };

    SuccessCallback getSuccessCallback() const { return _onSuccess; };
    
    static long getContentSize(const std::string &srcUrl);
    
    void downloadToBufferAsync(const std::string &srcUrl, unsigned char *buffer, const long &size, const std::string &customId = "");
    
    void downloadToBufferSync(const std::string &srcUrl, unsigned char *buffer, const long &size, const std::string &customId = "");

    void downloadAsync(const std::string &srcUrl, const std::string &storagePath,std::vector<std::string>& headers, const std::string &customId = "");

    void downloadSync(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers, const std::string &customId = "");
    
    void batchDownloadAsync(const DownloadUnits &units, const std::string &batchId = "");
    
    void batchDownloadSync(const DownloadUnits &units, const std::string &batchId = "");

	void stopDownload(const DownloadUnits &units);
    /**
     *  The default constructor.
     */
    WWDownloader();

    ~WWDownloader();

    long getLocalFileLength(const char* filePath);

    void onSetFinishDownload(bool flag);

    bool onGetFinishDownload();

    void onSetASyncThreadNum(int num);

	void onInitUserData(const std::string & key, const std::string& value);
	
	void setDelegate(UpgradeEventDelegate* pDelegate) { m_upEventDelegate = pDelegate; }
	UpgradeEventDelegate* getUpgradeEventDelegate(){ return m_upEventDelegate; }

	struct FileDescriptor
	{
		FILE *fp;
		void *curl;
		void* multi_handle;
		bool stopSign;
		std::string batchId;
		DownloadUnits units; //下载的标识符 现在用下载的集合来标识
	};

protected:
    


    void prepareDownload(const std::string &srcUrl, const std::string &storagePath, const std::string &customId, bool resumeDownload,
    						FileDescriptor *fDesc, ProgressData *pData, DownloadType type = DownloadType::SINGLE_DOWNLOAD);
    
    static bool prepareHeader(void *curl, const std::string &srcUrl);
    
    void downloadToBuffer(const std::string &srcUrl, const std::string &customId, const StreamData &buffer, const ProgressData &data);

    void download(const std::string &srcUrl, const std::string &customId, const FileDescriptor &fDesc, const ProgressData &data, std::vector<std::string> headers);
    
    void groupBatchDownload(const DownloadUnits &units, const std::string &batchId = "");

    void notifyError(ErrorCode code, const std::string &msg = "", const std::string &customId = "", int curle_code = 0, int curlm_code = 0);
    
    void notifyError(const std::string &msg, int curlm_code, const std::string &customId = "");
    
    void notifyError(const std::string &msg, const std::string &customId, int curle_code);

    bool downloadHandle(const char* path, const FileDescriptor &fDesc, const ProgressData &data);

    void onUncompressRes(const DownloadUnits &units, const std::string &batchId);
	//解压资源包 包括查分包 整包 模块包
    bool decompress(const std::string &zip, std::string customId, const std::string &batchId);
	//解压整包中的zip
	bool uncompressZip(const char * pOutFileName, bool topDir = true);

    std::string basename(const std::string& path);

private:

    int _connectionTimeout;

    ErrorCallback _onError;

    ProgressCallback _onProgress;

    SuccessCallback _onSuccess;

    std::string getFileNameFromUrl(const std::string &srcUrl);
    
    void clearBatchDownloadData();
    
    std::vector<FileDescriptor *> _files;
    
    std::vector<ProgressData *> _progDatas;
    
    cocos2d::FileUtils *_fileUtils;
    
    bool _supportResuming;

    curl_slist *_headers;

    long m_tmpFileLen;

    std::thread m_downloadThread;

    std::thread m_batchDownloadThread;

    bool m_finishDownloadThread;		

    int		m_ThreadNum;

	UpgradeEventDelegate* m_upEventDelegate; 

	std::vector<int> stopDownloadIds;
	
};

int downloadProgressFunc(WWDownloader::ProgressData *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);
