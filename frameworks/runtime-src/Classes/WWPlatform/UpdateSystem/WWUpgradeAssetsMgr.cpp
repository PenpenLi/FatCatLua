#include "WWUpgradeAssetsMgr.h"
#include "../LogSystem/WWLogMaros.h"
#include "../EngineSystem/IPhoneTool.h"
#include "../VariateSystem/WWConfigManager.h"

#include "../Tools/WWUtil.h"
#include "UpGradeConst.h"
#include "../Tools/MD5.h"
#include "../DBSystem/WWGameData.h"
USING_NS_CC;

#define DEFAULT_CONNECTION_TIMEOUT 8

std::mutex	LuaModuleMutex;

std::mutex  g_checkLock;

std::unordered_map<std::string, bool> g_IsFinishDownloadThread;

UpgradeDescInfo::UpgradeDescInfo()
{

}

UpgradeDescInfo::~UpgradeDescInfo()
{

}

void WWUpgradeAssetsMgr::onInitUserData(const std::string & key, const std::string& value)
{
	if (userData.find(key) == userData.end())
	{
		userData.emplace(std::make_pair(key, value));
	} else
	{

		userData[key] = value;
	}
	if (m_Downloader) 
	{
		m_Downloader->onInitUserData(key, value);
	}
	

}
WWUpgradeAssetsMgr::WWUpgradeAssetsMgr():
m_Downloader(nullptr), m_upEventDelegate(nullptr)
{
	m_Downloader = std::make_shared<WWDownloader>();
	m_Downloader->setConnectionTimeout(DEFAULT_CONNECTION_TIMEOUT);

	//onGetDownloadJsonInfo();



	//onInitModuleIDCfg();

	//onInitModuleNameCfg();
}




WWUpgradeAssetsMgr::~WWUpgradeAssetsMgr()
{
}

void WWUpgradeAssetsMgr::onInitModuleIDCfg()
{
	//m_LuaModuleIDs.push_back(UpGradeConst::g_LuaGameID);

	//m_LuaModuleIDs.push_back(g_ChatGameID);
	//m_LuaModuleIDs.push_back(g_ChargeGameID);
	//m_LuaModuleIDs.push_back(g_HongBaoGameID);
	//m_LuaModuleIDs.push_back(g_CouponGameID);
	//m_LuaModuleIDs.push_back(g_ExtraGameID);
	//m_LuaModuleIDs.push_back(g_Tiger100GameID);
}

//"XML/DownLoadModuleConfig.plist"
void WWUpgradeAssetsMgr::onInitModuleInfo(const std::string& plistFile, const std::string& storePath)
{
	std::string	storagePath = storePath;// FileUtils::getInstance()->getWritablePath() + "Resources/";


	if (FileUtils::getInstance()->isFileExist(plistFile))
	{
		auto downLoadValueMap = FileUtils::getInstance()->getValueMapFromFile(plistFile);
		for (std::unordered_map<std::string, cocos2d::Value>::iterator iter = downLoadValueMap.begin(); iter != downLoadValueMap.end(); iter++)
		{
			auto keyID = iter->first;
			auto valueArr = iter->second.asValueVector();
			auto keyIDint = stringToint(keyID);

			WWDownloader::resInfo	resInfo;
			if (valueArr.size() >= 6)
			{
				resInfo.gameId = keyIDint;
				resInfo.state = (WWDownloader::DownloadState)(stringToint(valueArr[0].asString()));
				resInfo.resName = valueArr[1].asString();
				resInfo.storagePath = storagePath + valueArr[2].asString();
				resInfo.priority = stringToint(valueArr[3].asString());
				resInfo.downloadId = keyIDint;
				m_DownloadCfg[keyIDint] = resInfo;


				if (valueArr[5].asInt() == 1)
				{
					//m_LuaModuleIDs.push_back(keyIDint);
					this->addModuleIdCfg(keyIDint);
				}

				//m_ModuleNameCfg[keyIDint] = valueArr[4].asString();
				auto moduleName = valueArr[4].asString();
				auto moduleNames = splitStr(moduleName, ",");

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

				this->addModuleNameCfg(keyIDint, moduleNames[0]);
#else
	
				this->addModuleNameCfg(keyIDint,moduleNames.size() > 1 ? moduleNames[1]: moduleNames[0]);
				
#endif
			}

		}

	}
}

bool WWUpgradeAssetsMgr::isLuaRelateModule(int gameID)
{
	for (int i = 0; i < m_LuaModuleIDs.size(); ++i)
	{
		if (gameID == m_LuaModuleIDs[i])
		{
			return true;
		}
	}

	return false;
}

void WWUpgradeAssetsMgr::onInitModuleNameCfg()
{
	//m_ModuleNameCfg[UpGradeConst::g_LuaGameID] = "src";
	//m_ModuleNameCfg[g_ChatGameID] = "Chat";
	//m_ModuleNameCfg[g_ChargeGameID] = "ExtraGame";
	//m_ModuleNameCfg[g_HDGameID] = "Activity";
	//m_ModuleNameCfg[g_CCGameID] = "guess";
	//m_ModuleNameCfg[g_DNGameID] = "DN";
	//m_ModuleNameCfg[g_DuoBaoGameID] = "DN";
	//m_ModuleNameCfg[g_HotUpdateBatchID] = "Res";

	//m_ModuleNameCfg[g_HongBaoGameID] = "HongBao";
	//m_ModuleNameCfg[g_CouponGameID] = "Exchange";
	//m_ModuleNameCfg[g_ExtraGameID] = "ExtraGame";

	//m_ModuleNameCfg[g_MatchGameID] = "MatchGame";
	//m_ModuleNameCfg[g_Tiger100GameID] = "tiger100";
}

void WWUpgradeAssetsMgr::addModuleIdCfg(int moduleId)
{
	auto module = std::find(m_LuaModuleIDs.begin(), m_LuaModuleIDs.end(), moduleId);
	if (module == m_LuaModuleIDs.end())
	{
		m_LuaModuleIDs.push_back(moduleId);

	}
}

void WWUpgradeAssetsMgr::addModuleNameCfg(int moduleId,std::string moduleName)
{
	DownloadThreadState::getInstance()->addModuleNameCfg(moduleId, moduleName);
	if (m_ModuleNameCfg.find(moduleId) == m_ModuleNameCfg.end()) 
	{
		m_ModuleNameCfg.emplace(std::make_pair(moduleId, moduleName));

	} else
	{
		m_ModuleNameCfg[moduleId] = moduleName;
	}
	
}


std::string WWUpgradeAssetsMgr::onGetModuleName(int gameID)
{
	auto iter = m_ModuleNameCfg.find(gameID);
	if (iter != m_ModuleNameCfg.end())
	{
		return iter->second;
	}
	else
	{
		return "";
	}
}

std::vector<WWDownloader::resInfo> WWUpgradeAssetsMgr::onGetDownloadCfgInfo(std::vector<int>& downloadModule)
{
	std::vector<WWDownloader::resInfo> downloadCfgInfo;

	for (int i = 0; i < downloadModule.size(); ++i)
	{
		downloadCfgInfo.push_back(m_DownloadCfg[downloadModule[i]]);
	}

	return downloadCfgInfo;
}

std::string WWUpgradeAssetsMgr::onGetJointDownloadAddress(const std::string& resName)
{
	//std::string url = WWConfigManager::getInstance()->getValue("res_dl_url")->getCString();
	std::string url = UpGradeConst::res_dl_url;

	int userid = 0;
	if (userData.find("userid") != userData.end() && isnum(userData.at("userid")))
	{
		userid = atoi(userData.at("userid").c_str());
	}

	int isp = 0;
	if (userData.find("SP") != userData.end() && isnum(userData.at("SP")))
	{
		isp = atoi(userData.at("SP").c_str());
	}
	int gmid = 0;
	if (userData.find("GAME_ID") != userData.end() && isnum(userData.at("GAME_ID")))
	{
		gmid = atoi(userData.at("GAME_ID").c_str());
	}
	int hallid = 0;
	if (userData.find("GAME_HALLID") != userData.end() && isnum(userData.at("GAME_HALLID")))
	{
		hallid = atoi(userData.at("GAME_HALLID").c_str());
	}
	int pflag = 0;
	if (userData.find("g_package_winsize") != userData.end() && isnum(userData.at("g_package_winsize")))
	{
		pflag = atoi(userData.at("g_package_winsize").c_str());
	}
	std::string gameVersion;
	if (userData.find("GAME_VERSION") != userData.end())
	{
		gameVersion = (userData.at("GAME_VERSION").c_str());
	}
	int vt = 1; //预留
	int st = 11001001;//资源类型  11001001标识客户端资源下载
	int uid = userid; //蛙号
	int sp = isp; //用户所属sp
	int gid = gmid;//游戏ID  惯蛋是1017
	int hid = hallid; //游戏大厅ID 
	std::string clientver = gameVersion;//客户端版本号
	int packageFlag = pflag; //当st=11001001 客户端资源下载时  mst=1 取大图资源包 mst = 2 取小图资源包，针对特定渠道
	
	//picname   静态资源文件名  文件名，想要直接拉取文件名 当st = 11001001 客户端资源下载时 传路径及文件名，eg : sounds / game / aaa.ogg



	std::string strUrl = StringUtils::format("%s?vt=%d&st=%d&uid=%d&sp=%d&gid=%d&hid=%d&clientver=%s&mst=%d&picname=Resources/%s",
			url.c_str(), vt, st, uid, sp, gid, hid, clientver.c_str(), packageFlag, resName.c_str());

	log("onGetJointDownloadAddress strUrl = %s", strUrl.c_str());

	return strUrl;
}

void WWUpgradeAssetsMgr::onInitDownloadJsonInfo(const std::string& jsonFile)
{
	//"XML/DownloadCfg.json"
	std::string loadCfgstr = FileUtils::getInstance()->getStringFromFile(jsonFile);
	m_JsonDoc.Parse<rapidjson::kParseDefaultFlags>(loadCfgstr.c_str());

	if (m_JsonDoc.HasParseError())
	{
		WW_LOG_INFO("onInitDownloadJsonInfo Json Parse Error.");
	}
}

void WWUpgradeAssetsMgr::onGetDownloadModuleInfo(int gameID, std::string& plistName, std::string& plistKey)
{
	if (!m_JsonDoc.HasMember("downloadCfg"))
	{
		WW_LOG_INFO("onGetDownloadJsonInfo Json has no member downloadCfg.");
		return;
	}

	//const char* strGameID = StringUtils::format("%d", gameID).c_str();
	char strGameID[10] = "";
	sprintf(strGameID, "%d", gameID);

	WW_LOG_INFO("strGameID = %s", strGameID);
	const rapidjson::Value &downloadArray = m_JsonDoc["downloadCfg"];
	for (rapidjson::SizeType i = 0; i < downloadArray.Size(); ++i)
	{
		const rapidjson::Value &vals = downloadArray[i];
		if (vals.HasMember(strGameID))
		{
			const rapidjson::Value &valInfo = vals[strGameID];
			plistName = valInfo["plistName"].GetString();
			plistKey = valInfo["plistKey"].GetString();

			break;
		}
	}
}

bool WWUpgradeAssetsMgr::onCheckDownloadResExist(int gameID)
{
	std::string plistName = "";
	std::string plistKey = "";

	onGetDownloadModuleInfo(gameID, plistName, plistKey);

	auto allResExists = true;
	if (plistName == "" || plistKey == "")
	{
		WW_LOG_ERROR("onCheckDownloadResExist get the wrong info.");
		allResExists = false;

	}
	
	if (allResExists)
	{
		auto resMap = FileUtils::getInstance()->getValueMapFromFile(plistName);
		auto valueRes = resMap.at(plistKey).asValueVector();
		for (auto val : valueRes)
		{
			if (!FileUtils::getInstance()->isFileExist(val.asString()))
			{
				WW_LOG_ERROR("val.asString().c_str() = %s", val.asString().c_str());
				allResExists = false;
				break;
			}
		}

	}
	

	return allResExists;
}

WWDownloader::DownloadUnits WWUpgradeAssetsMgr::onGetDownloadUnitInfo(std::vector<WWDownloader::resInfo>& vecRes)
{
	WWDownloader::DownloadUnits group;

	for (int i = 0; i < vecRes.size(); ++i)
	{
		if (vecRes.at(i).state == WWDownloader::DownloadState::UN_DOWNLOAD)
		{
			if (onCheckDownloadResExist(vecRes.at(i).gameId))
			{
				
				vecRes.at(i).state = WWDownloader::DownloadState::DOWNLOADED;
				continue;
			}

			WWDownloader::DownloadUnit unit;
			unit.srcUrl = DownloadThreadState::getInstance()->onGetModuleHttpAddr(m_ModuleNameCfg[vecRes.at(i).gameId]);
			unit.storagePath = vecRes.at(i).storagePath;
			unit.customId = StringUtils::format("%d", vecRes.at(i).gameId);
			unit.priority = vecRes.at(i).priority;
			unit.resName = vecRes.at(i).resName;

			if (isLuaRelateModule(vecRes.at(i).gameId))
			{
				unit.resumeDownload = false;
			}
			else
			{
				unit.resumeDownload = true;
			}

			group.emplace(vecRes.at(i).gameId, unit);
		}
	}

	return group;
}

void WWUpgradeAssetsMgr::onStartSilenceDownloading(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType, int batchId)
{
	WWDownloader::DownloadUnits group = onGetDownloadUnits(vecRes, downloadType);
	onSetLuaCommonDownloadID(batchId);

	if (m_Downloader && group.size() > 0)
	{
		WW_LOG_INFO("WWUpgradeAssetsMgr::onStartSilenceDownloading is running.");
		m_RecordDownUnits = group;
		m_Downloader->batchDownloadAsync(group, StringUtils::format("%d", batchId));
	}
	else
	{
		WW_LOG_INFO("WWUpgradeAssetsMgr::onStartSilenceDownloading is stopping.");
	}
}

void WWUpgradeAssetsMgr::onCancleSilenceDownloading(const std::vector<WWDownloader::resInfo>& vecRes)
{

}

void WWUpgradeAssetsMgr::onStartAPKDownload(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers)
{
	if (m_Downloader) 
	{
		m_Downloader->downloadAsync(srcUrl, storagePath, headers);
	}
}

void WWUpgradeAssetsMgr::onSetUpdateAssetLayerDesc(int gameID)
{
	//const char* strGameID = StringUtils::format("%d", gameID).c_str();
	char strGameID[10] = "";
	sprintf(strGameID, "%d", gameID);

	const rapidjson::Value &downloadArray = m_JsonDoc["downloadCfg"];
	for (rapidjson::SizeType i = 0; i < downloadArray.Size(); ++i)
	{
		const rapidjson::Value &vals = downloadArray[i];
		if (vals.HasMember(strGameID))
		{
			const rapidjson::Value &valInfo = vals[strGameID];

			UpgradeDescInfo::getInstance()->setTitleDesc(valInfo["dialogTitle"].GetString());
			UpgradeDescInfo::getInstance()->setDownloadDesc(valInfo["dialogDesc1"].GetString());
			UpgradeDescInfo::getInstance()->setDownloadingDesc(valInfo["dialogDesc2"].GetString());
			UpgradeDescInfo::getInstance()->setDownloadingTitle(valInfo["dialogDesc3"].GetString());
			UpgradeDescInfo::getInstance()->setUnzipDesc(valInfo["dialogDesc4"].GetString());

			break;
		}
	}
}

long WWUpgradeAssetsMgr::onGetLocalDownloadFileSize(WWDownloader::DownloadUnits& group)
{
	if (m_Downloader)
	{
		long localFileSize = 0;
		for (auto iter = group.begin(); iter != group.end(); ++iter)
		{
			if (iter->second.resumeDownload)
			{
				
				if (FileUtils::getInstance()->isFileExist(iter->second.storagePath))
				{
					localFileSize += m_Downloader->getLocalFileLength(iter->second.storagePath.c_str());
				}
				else
				{
					std::string filePath = iter->second.storagePath + ".temp";
					localFileSize += m_Downloader->getLocalFileLength(filePath.c_str());
				}
			}
		}
		return localFileSize;
	}
	else
	{
		WW_LOG_ERROR("onGetLocalDownloadFileSize m_Downloader is NULL");
		return 0;
	}
}

long WWUpgradeAssetsMgr::onGetRemoteDownloadFileSize(WWDownloader::DownloadUnits& group, int gameID)
{
	if (!DownloadThreadState::getInstance()->onGetIsRequestRemoteFileSize(gameID))
	{
		DownloadThreadState::getInstance()->onSetIsRequestRemoteFileSize(gameID, true);
		auto sizeThread = std::thread(&WWUpgradeAssetsMgr::onThreadHandleRemoteDownloadFileSize, this, group, gameID);
		sizeThread.detach();
	}
	return 0;
}

void WWUpgradeAssetsMgr::onThreadHandleRemoteDownloadFileSize(WWDownloader::DownloadUnits group, int gameID)
{
	long remoteFileSize = 0;
	for (auto iter = group.begin(); iter != group.end(); ++iter)
	{
		std::string moduleName = DownloadThreadState::getInstance()->onGetModuleName(atoi(iter->second.customId.c_str()));
		remoteFileSize += WWDownloader::getContentSize(DownloadThreadState::getInstance()->onGetModuleHttpAddr(moduleName));
	}

	RemoteFileInfo fileInfo;
	fileInfo.gameId = gameID;
	fileInfo.fileSize = remoteFileSize;

	DownloadThreadState::getInstance()->onSetIsRequestRemoteFileSize(gameID, false);
	DownloadThreadState::getInstance()->onSetRemoteFileSizeMap(gameID, remoteFileSize);

	if (m_upEventDelegate)
	{
		m_upEventDelegate->onUpgradeEvent(UPGRADE_GETREMOVE_FILEZIE, &fileInfo);
	}
	//Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_GET_REMOTEFILESIZE, &fileInfo);



	//Director::getInstance()->getScheduler()->performFunctionInCocosThread([remoteFileSize, gameID]{
	//	RemoteFileInfo fileInfo;
	//	fileInfo.gameId = gameID;
	//	fileInfo.fileSize = remoteFileSize;
	//	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_GET_REMOTEFILESIZE, &fileInfo);

	//	DownloadThreadState::getInstance()->onSetIsRequestRemoteFileSize(gameID, false);
	//	DownloadThreadState::getInstance()->onSetRemoteFileSizeMap(gameID, remoteFileSize);
	//});
}

void WWUpgradeAssetsMgr::onClearDownloadThread(const std::string& customId, const WWDownloader::DownloadUnits &units)
{
	if (m_Downloader)
	{
		//m_Downloader->onSetFinishDownload(true);
		
		
		
	    LuaModuleMutex.lock();
	    g_IsFinishDownloadThread[customId] = true;
	    LuaModuleMutex.unlock();

		DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
		/*
		for (auto it = m_RecordDownUnits.cbegin(); it != m_RecordDownUnits.cend(); ++it)
		{
			DownloadThreadState::getInstance()->onSetDownloadThreadState(atoi(it->second.customId.c_str()), DownloadThreadState::ThreadState::THREAD_END);
		}
		*/
		m_Downloader->stopDownload(units);
		m_RecordDownUnits.clear();
		WW_LOG_INFO("m_RecordDownUnits size = %d", m_RecordDownUnits.size());
	}
}

void WWUpgradeAssetsMgr::onManagerASyncThreadNum(int num)
{
	if (m_Downloader)
	{
		m_Downloader->onSetASyncThreadNum(num);
	}
}

int WWUpgradeAssetsMgr::onGetDownloadID(int gameID)
{
	WWDownloader::resInfo info = m_DownloadCfg[gameID];
	return info.downloadId;
}

void WWUpgradeAssetsMgr::onSetHotUpdateUnitInfo(WWDownloader::DownloadUnits& group, int unitsNum, enum DownloadType downloadType)
{
	if (IPhoneTool::getInstance()->is2GNetWork())
	{
		WW_LOG_INFO("onSetHotUpdateUnitInfo is 2G NetWork.");
		return;
	}
	bool isHotupdate = false; 
	if (userData.find("HotUpdate") != userData.end() && isnum(userData.at("HotUpdate")))
	{
		isHotupdate = (atoi(userData.at("HotUpdate").c_str()) == 1);
	}
	WW_LOG_INFO("getIsHotUpdate = %d, group.size() = %d", isHotupdate, group.size());
	if (isHotupdate)
	{
		onGenerateLuaHotUpdateUnitInfo(group);
		/*
		if (downloadType == SilenceDownload)
		{



			if (group.size() == unitsNum || group.size() != 0)
			{
				onGenerateLuaHotUpdateUnitInfo(group);
			}
		}
		else if (downloadType == ManualDownload)
		{

			if (group.size() == unitsNum || group.size() == 0)
			{
				onGenerateLuaHotUpdateUnitInfo(group);
			}
		}
		else
		{
			WW_LOG_INFO("onSetHotUpdateUnitInfo is wrong downloadType.");
		}
		*/
	}
}

void WWUpgradeAssetsMgr::onGenerateLuaHotUpdateUnitInfo(WWDownloader::DownloadUnits& group)
{
	std::string luaHotUpdateAddr = DownloadThreadState::getInstance()->onGetModuleHttpAddr(m_ModuleNameCfg[UpGradeConst::g_HotUpdateBatchID]);
	WW_LOG_INFO("onGenerateLuaHotUpdateUnitInfo Addr = %s", luaHotUpdateAddr.c_str());

	WWDownloader::resInfo info = m_DownloadCfg[UpGradeConst::g_HotUpdateBatchID];

	WWDownloader::DownloadUnit unit;

	std::string gameVersion;
	if (userData.find("GAME_VERSION") != userData.end())
	{
		gameVersion = (userData.at("GAME_VERSION").c_str());
	}
	int subVersion;
	if (userData.find("subVersion") != userData.end() && isnum(userData.at("subVersion")))
	{
		subVersion = atoi(userData.at("subVersion").c_str());
	}

	std::string key = StringUtils::format(UpGradeConst::key_hotupdate_subversion.c_str(), gameVersion.c_str());
	std::string resName = StringUtils::format("Res_%d_%d.zip", WWGameData::getInstance()->getIntegerForKey(key.c_str(), 1), subVersion);
	unit.srcUrl = luaHotUpdateAddr;
	unit.storagePath = info.storagePath + resName;
	unit.customId = StringUtils::format("%d", UpGradeConst::g_HotUpdateBatchID);
	unit.priority = info.priority;
	unit.resumeDownload = true;
	unit.resName = resName;
	if (group.find(UpGradeConst::g_HotUpdateBatchID)==group.end())
	{
		group.emplace(UpGradeConst::g_HotUpdateBatchID, unit);
	} else
	{
		group[UpGradeConst::g_HotUpdateBatchID] = unit;
	}
	
}

void WWUpgradeAssetsMgr::onFinishOtherLuaDownloadThread(int gameID)
{
	WW_LOG_INFO("onFinishOtherLuaDownloadThread gameID = %d", gameID);
	if (!isLuaRelateModule(gameID))
	{
		return;
	}
	
	LuaModuleMutex.lock();
	for (int i = 0; i < m_LuaModuleIDs.size(); ++i)
	{
		if (gameID == m_LuaModuleIDs[i])
		{
			continue;
		}
		else
		{
			g_IsFinishDownloadThread[StringUtils::format("%d", m_LuaModuleIDs[i])] = true;
			DownloadThreadState::getInstance()->onSetDownloadThreadState(m_LuaModuleIDs[i], DownloadThreadState::ThreadState::THREAD_END);
		}
	}
	LuaModuleMutex.unlock();
}

void WWUpgradeAssetsMgr::onSetLuaCommonDownloadID(int gameID)
{
	if (isLuaRelateModule(gameID))
	{
		m_DownloadCfg[UpGradeConst::g_LuaGameID].downloadId = gameID;
		m_DownloadCfg[UpGradeConst::g_HotUpdateBatchID].downloadId = gameID;
	}
}

WWDownloader::DownloadUnits WWUpgradeAssetsMgr::onGetDownloadUnits(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType)
{
	WWDownloader::DownloadUnits group = onGetDownloadUnitInfo(vecRes);
	bool has = false;
	for (auto& vec:vecRes) 
	{
		if (vec.gameId==UpGradeConst::g_LuaGameID)
		{
			has = true; //有lua脚本 就是下载 不是热更
		}

	}
	for (auto& vec : vecRes)
	{
		if (vec.gameId == UpGradeConst::g_SilenceDownload)
		{
			has = true; //整包更新 不是热更
		}

	}
	if (!has) 
	{
		onSetHotUpdateUnitInfo(group, group.size(), downloadType);
	}
	
	return group;
}

void WWUpgradeAssetsMgr::onHttpRequestDownloadAddress(int gameId,std::string& moduleName, std::string &stname1, int sourceType, enum DownloadType downtype)
{
	if (moduleName.empty())
	{
		return;
	}
	WW_LOG_INFO("onHttpRequestDownloadAddress moduleName = %s, sourceType = %d, downtype = %d", moduleName.c_str(), sourceType, downtype);

	//const char* httpHead = WWConfigManager::getInstance()->getValue(g_lua_hotupdate_url)->getCString();

	std::string gameVersion;
	if (userData.find("GAME_VERSION") != userData.end())
	{
		gameVersion = (userData.at("GAME_VERSION").c_str());
	}
	int isp = 0;
	if (userData.find("SP") != userData.end() && isnum(userData.at("SP")))
	{
		isp = atoi(userData.at("SP").c_str());
	}

	int userid = 0;
	if (userData.find("userid") != userData.end() && isnum(userData.at("userid")))
	{
		userid = atoi(userData.at("userid").c_str());
	}

	int subVersion;
	if (userData.find("subVersion") != userData.end() && isnum(userData.at("subVersion")))
	{
		subVersion = atoi(userData.at("subVersion").c_str());
	}
	std::string configStr = UpGradeConst::lua_hotupdate_url;
	const char* httpHead = configStr.c_str(); //下载的地址
	const char* clientver = gameVersion.c_str(); //客户端真实版本号
	int sp = isp;//客户端对应的sp
	int uid = userid;//登录用户的uid
	const char* module = moduleName.c_str();	//需要更新模块对应的模块名(差分包会按模块名进行命名分类)

	std::string key = StringUtils::format(UpGradeConst::key_hotupdate_subversion.c_str(), clientver);
	int vcurrent = WWGameData::getInstance()->getIntegerForKey(key.c_str(), 1); //当前正在应用的版本号(lua内部版本号，约定为数值类型)
	int vtarget = subVersion;  //升级目标的版本号(lua内部版本号，约定为数值类型)

	if (sourceType == 1) //请求资源类型，1 zip模块文件  2 资源的差分文件
	{
		
		vcurrent = vtarget; //当vcurrent=vtarget时
	}

	const char* stname = "";
	if (sourceType == 1)
	{
		stname = stname1.c_str(); //当sourcetype=1时，传如guess、DN等文件名
	}
	else
	{
		stname = module;//当sourcetype=2时，传跟module同样值即可
	}


	time_t rawtime;
	time(&rawtime);
	long rtime = rawtime; //请求的时间戳

	
	std::string md5 = StringUtils::format("%s%d%s%d%ld", clientver, sp, module, uid, rtime);
	MD5 iMD5;
	iMD5.GenerateMD5((unsigned char *)md5.c_str(), md5.length());
	std::string sign = iMD5.ToString(); //请求的签名,MD5(clientver+sp+ module+uid+rtime).toLowerCase()
	transform(sign.begin(), sign.end(), sign.begin(), (int (*)(int))tolower);

	int hid = 0;
	if (userData.find("GAME_HALLID") != userData.end() && isnum(userData.at("GAME_HALLID")))
	{
		hid = atoi(userData.at("GAME_HALLID").c_str());

	}
	int hallid = hid; //大厅ID，大厅ID下面会有不同系列的差分版本

	std::string url = StringUtils::format("%s?clientver=%s&sp=%d&uid=%d&module=%s&vcurrent=%d&vtarget=%d&rtime=%ld&sign=%s&hallid=%d&sourcetype=%d&stname=%s",
			httpHead, clientver, sp, uid, module, vcurrent, vtarget, rtime, sign.c_str(), hallid, sourceType, stname);
	WW_LOG_INFO("onHttpRequestDownloadAddress url = %s", url.c_str());

	cocos2d::network::HttpRequest *request = new cocos2d::network::HttpRequest();
	std::vector<std::string> headers;
	std::string userAgentInfo = StringUtils::format("User-Agent:model/%s userid/%d", IPhoneTool::getInstance()->getPhoneMANUFACTURER().c_str(), userid);
	WW_LOG_INFO("onHttpRequestDownloadAddress userAgentInfo = %s", userAgentInfo.c_str());
	headers.push_back(userAgentInfo);
	request->setHeaders(headers);
	request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
	request->setUrl(url.c_str());
	request->setResponseCallback([gameId,downtype, this](cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response) {

		if (!response)
		{
			WW_LOG_ERROR("onHttpResponseDownloadAddress response is null");
			return;
		}

		if (!response->isSucceed()) {
			WW_LOG_ERROR("onHttpResponseDownloadAddress fail to get the response");

			WW_LOG_ERROR("ResponseCode = %d, ResponseDataString = %s, ErrorBuffer = %s",
					response->getResponseCode(),
					response->getResponseDataString(),
					response->getErrorBuffer());

			return;
		}

		WW_LOG_INFO("onHttpResponseDownloadAddress downtype = %d, getResponseDataString = %s", downtype, response->getResponseDataString());
		auto respData = response->getResponseData();
		std::string jsonData;
		std::copy(respData->begin(), respData->end(), std::insert_iterator<std::string>(jsonData, jsonData.begin()));
		rapidjson::Document jsonDoc;
		jsonDoc.Parse<rapidjson::kParseDefaultFlags>(jsonData.c_str());
		if (jsonDoc.HasParseError())
		{
			WW_LOG_ERROR("onHttpResponseDownloadAddress Parse Error.");
			RemoteFileAddr rdata;
			rdata.gameId = gameId;
			rdata.isSuccess = false;
			if (m_upEventDelegate)
			{
				m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_SILENT_CALLBACK, &rdata);
			}
			return;
		}

		if (!jsonDoc.HasMember("retcode"))
		{
			RemoteFileAddr rdata;
			rdata.gameId = gameId;
			rdata.isSuccess = false;
			if (m_upEventDelegate)
			{
				m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_SILENT_CALLBACK, &rdata);
			}
			WW_LOG_ERROR("onHttpResponseDownloadAddress retcode is not member.");
			return;
		}
		else if (jsonDoc["retcode"].GetInt() != 1)
		{
			RemoteFileAddr rdata;
			rdata.gameId = gameId;
			rdata.isSuccess = false;
			if (m_upEventDelegate)
			{
				m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_SILENT_CALLBACK, &rdata);
			}
			WW_LOG_ERROR("onHttpResponseDownloadAddress retcode = %d", jsonDoc["retcode"].GetInt());
			return;
		}

		if (!jsonDoc.HasMember("module"))
		{
			RemoteFileAddr rdata;
			rdata.gameId = gameId;
			rdata.isSuccess = false;
			if (m_upEventDelegate)
			{
				m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_SILENT_CALLBACK, &rdata);
			}
			WW_LOG_ERROR("onHttpResponseDownloadAddress module is not member.");
			return;
		}
		else
		{
			WW_LOG_INFO("onHttpResponseDownloadAddress module = %s", jsonDoc["module"].GetString());
		}

		if (!jsonDoc.HasMember("msg"))
		{
			WW_LOG_ERROR("onHttpResponseDownloadAddress MSG is not member.");
		}
		else
		{
			//
			std::string resAddr = jsonDoc["msg"].GetString();
			std::string resModule = jsonDoc["module"].GetString();
			std::string resDesc = jsonDoc["desc"].GetString();
			int index = resAddr.find("?", 0);
			if (index != -1)
			{
				resAddr = resAddr.substr(0, index);
			}

			WW_LOG_INFO("onHttpResponseDownloadAddress resAddr = %s, resModule = %s", resAddr.c_str(), resModule.c_str());
			DownloadThreadState::getInstance()->onSetModuleHttpAddr(resModule, resAddr);

			RemoteFileAddr rdata;
			rdata.resModule = resModule;
			rdata.resAddr = resAddr;
			rdata.owerId = gameId;
			rdata.gameId = gameId;
			rdata.resDesc = resDesc;
			rdata.isSuccess = true;
			if (downtype == SilenceDownload)
			{
				if (m_upEventDelegate)
				{
					m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_SILENT_CALLBACK, &rdata);
				}

				//Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_RESDOWNLOADADDR_SILENCE_CALLBACK, &resModule);
			}
			else if (downtype == ManualDownload)
			{
				if (m_upEventDelegate)
				{
					m_upEventDelegate->onUpgradeEvent(UPGRADE_RESDOWNLOADADDR_MANUAL_CALLBACK, &rdata);
				}
				//Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_RESDOWNLOADADDR_MANUAL_CALLBACK, &resModule);
			}
		}
	});

	cocos2d::network::HttpClient::getInstance()->sendImmediate(request);
	request->release();
}

bool WWUpgradeAssetsMgr::onIsModuleThreadRunning()
{
	for (auto item : m_ModuleNameCfg)
	{
		DownloadThreadState::ThreadState state = DownloadThreadState::getInstance()->onGetDownloadThreadState(item.first);
		if (state == DownloadThreadState::ThreadState::DOWNLOADING ||
			state == DownloadThreadState::ThreadState::DOWNLOADED ||
			state == DownloadThreadState::ThreadState::UNZIPING)
		{
			return true;
		}
	}

	return false;
}


std::mutex	g_UpAssetMgrLock;

UpgradeAssetsMgrContainer* UpgradeAssetsMgrContainer::m_ContainerInst = nullptr;

UpgradeAssetsMgrContainer::UpgradeAssetsMgrContainer()
{

	this->initUpdateCfg();
}

void  UpgradeAssetsMgrContainer::setDownloadURL(const std::string &key, const std::string & value)
{
	if (key.compare("res_dl_url")==0) 
	{
		UpGradeConst::res_dl_url = value;
	}
	else if (key.compare("lua_hotupdate_url") == 0)
	{
		UpGradeConst::lua_hotupdate_url = value;
	}
}

void UpgradeAssetsMgrContainer::initUpdateCfg()
{
	std::vector<WWSystemItem*> items = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_UPGRADE).items;

	auto item = findSystemItemByName(items, "g_SilenceDownload");
	if (item&&item->values.size() > 0 && isnum(item->values[0]))
	{
		UpGradeConst::g_SilenceDownload = atoi(item->values[0].c_str());

	} else
	{
		UpGradeConst::g_SilenceDownload = 10000;
	}

	item = findSystemItemByName(items, "g_HotUpdateBatchID");
	if (item&&item->values.size() > 0 && isnum(item->values[0]))
	{
		UpGradeConst::g_HotUpdateBatchID = atoi(item->values[0].c_str());

	} else
	{
		UpGradeConst::g_HotUpdateBatchID = 9999;
	}
	item = findSystemItemByName(items, "g_LuaGameID");
	if (item&&item->values.size() > 0 && isnum(item->values[0]))
	{
		UpGradeConst::g_LuaGameID = atoi(item->values[0].c_str());

	} else
	{
		UpGradeConst::g_LuaGameID = 2003;
	}

	item = findSystemItemByName(items, "key_hotupdate_subversion");
	if (item&&item->values.size() > 0)
	{
		UpGradeConst::key_hotupdate_subversion = item->values[0].c_str();

	} else
	{
		UpGradeConst::key_hotupdate_subversion = "key_hotupdate_subversion_%s";
	}


	item = findSystemItemByName(items, "lua_hotupdate_url");
	if (item&&item->values.size() > 0)
	{
		UpGradeConst::lua_hotupdate_url = item->values[0].c_str();

	} else
	{
		UpGradeConst::lua_hotupdate_url = "http://api.wawagame.cn:80/common/luapatchapi.jsp";
	}
	item = findSystemItemByName(items, "res_dl_url");
	if (item&&item->values.size() > 0)
	{
		UpGradeConst::res_dl_url = item->values[0].c_str();

	} else
	{
		UpGradeConst::res_dl_url = "http://192.168.10.91:8585/gamesrc/getsrc.jsp";
	}

	item = findSystemItemByName(items, "luahoteupdate_topdic");
	if (item&&item->values.size() > 0)
	{
		UpGradeConst::LUAHOTUPDATE_TOPDIC = item->values[0].c_str();

	} 
	item = findSystemItemByName(items, "luawholepackage_topdic");
	if (item&&item->values.size() > 0)
	{
		UpGradeConst::LUAWHOLEPACKAGE_TOPDIC = item->values[0].c_str();

	}

}

void UpgradeAssetsMgrContainer::onCheckGameResExist(const std::vector<std::string>& gameResArr)
{

	std::thread t([gameResArr, this]
	{
		auto allResExists = true;
		for (auto val : gameResArr)
		{
			if (!FileUtils::getInstance()->isFileExist(val))
			{
				WW_LOG_ERROR("val.c_str() = %s", val.c_str());
				allResExists = false;
				break;
			}
		}
		for (auto upMgr : m_UpAssetMgrMap) 
		{
			if (upMgr.second->getUpgradeEventDelegate())
			{
				WWUpgradeAssetsMgr::CheckResInfo cinfo;
				cinfo.resExist = allResExists;
			
				upMgr.second->getUpgradeEventDelegate()->onUpgradeEvent(UPGRADE_CHECK_MODULE_EXISTS, &cinfo);
				break;
			}
		}
		


	});
	t.detach();

	//std::string plistName = "XML/MatchGame_res.plist";
	//std::string plistKey = "MatchGame_res";

	//auto resMap = FileUtils::getInstance()->getValueMapFromFile(plistName);
	//auto valueRes = resMap.at(plistKey).asValueVector();
	//for (auto val : valueRes)
	//{
	//	if (!FileUtils::getInstance()->isFileExist(val.asString()))
	//	{
	//		WW_LOG_ERROR("val.asString().c_str() = %s", val.asString().c_str());
	//		
	//	}
	//}

	
}



void UpgradeAssetsMgrContainer::onSetUpAssetMgr(int gameID, WWUpgradeAssetsMgr* mgr)
{
	std::unique_lock<std::mutex> locker(g_UpAssetMgrLock);
	m_UpAssetMgrMap[gameID] = mgr;
}

void UpgradeAssetsMgrContainer::setUpdateUrl(std::string& url)
{
	if (url.length() > 0)
	{
		UpGradeConst::lua_hotupdate_url = url;
	}

}

WWUpgradeAssetsMgr* UpgradeAssetsMgrContainer::onGetUpAssetMgr(int gameID)
{
	std::unique_lock<std::mutex> locker(g_UpAssetMgrLock);
	std::map<int, WWUpgradeAssetsMgr*>::iterator it = m_UpAssetMgrMap.find(gameID);
	if (it != m_UpAssetMgrMap.end())
	{
		return it->second;
	} else
	{
		return nullptr;
	}
}