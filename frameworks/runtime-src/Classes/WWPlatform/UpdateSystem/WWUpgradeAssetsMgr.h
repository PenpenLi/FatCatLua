#ifndef __UPGRADE_ASSETS_MGR_H__
#define __UPGRADE_ASSETS_MGR_H__


/*! @file
********************************************************************************
<PRE>
模块名       :  更新工具类
文件名       :  WWUpgradeAssetsMgr.h
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
#include "json/document.h"
#include "WWDownloader.h"
#include "../WWMacros.h"
class UpgradeDescInfo
{
public:

	UpgradeDescInfo();

	virtual ~UpgradeDescInfo();

	SINGLE_INSTANCE_FUNC(UpgradeDescInfo);

	CC_SYNTHESIZE(std::string, mTitleDesc, TitleDesc);

	CC_SYNTHESIZE(std::string, mDownloadDesc, DownloadDesc);

	CC_SYNTHESIZE(std::string, mDownloadingDesc, DownloadingDesc);

	CC_SYNTHESIZE(std::string, mDownloadingTitle, DownloadingTitle);

	CC_SYNTHESIZE(std::string, mUnzipDesc, UnzipDesc);
};

class WWUpgradeAssetsMgr
{
public:

    struct RemoteFileInfo:public EventData
    {
      
        long fileSize;
		RemoteFileInfo()
		{
			eType = EventData::Event_GotRemoteFileInfo;
		}
    };

	struct RemoteFileAddr :public EventData
	{
		std::string resModule;
		std::string resAddr;
		std::string resDesc;
		int owerId;
		RemoteFileAddr()
		{
			owerId = 0;
			eType = EventData::Event_GotRemoteAddr;
		}
	};
	struct CheckResInfo :public EventData
	{
		bool resExist;
		
		CheckResInfo()
		{
			eType = EventData::Event_CheckRes;
		
			resExist = false;
		}
	};


    enum DownloadType
    {
    	SilenceDownload,	
    	ManualDownload,		
    };

public:

	WWUpgradeAssetsMgr();

	~WWUpgradeAssetsMgr();

	void onInitModuleIDCfg();

	void addModuleIdCfg(int moduleId);
	void onInitUserData(const std::string & key,const std::string& value);
	bool isLuaRelateModule(int gameID);	

	
	void onInitModuleNameCfg();
	void addModuleNameCfg(int moduleId, std::string moduleName);
	std::string onGetModuleName(int gameID);

	std::vector<WWDownloader::resInfo> onGetDownloadCfgInfo(std::vector<int>& downloadModule);
	//返回资源下载地址
	std::string onGetJointDownloadAddress(const std::string& resName);

	WWDownloader::DownloadUnits onGetDownloadUnitInfo(std::vector<WWDownloader::resInfo>& vecRes);

	void onStartSilenceDownloading(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType, int batchId = 0);

	void onCancleSilenceDownloading(const std::vector<WWDownloader::resInfo>& vecRes);

	//开始apk下载
	void onStartAPKDownload(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers);

	bool onCheckDownloadResExist(int gameID);	
	//下载的配置文件
	void onInitDownloadJsonInfo(const std::string& jsonFile);
	//plistFile  storePath 存储地址
	void onInitModuleInfo(const std::string& plistFile, const std::string& storePath);

	void onGetDownloadModuleInfo(int gameID, std::string& plistName, std::string& plistKey);

	void onSetUpdateAssetLayerDesc(int gameID);		

	long onGetLocalDownloadFileSize(WWDownloader::DownloadUnits& group);	

	long onGetRemoteDownloadFileSize(WWDownloader::DownloadUnits& group, int gameID);	

	void onClearDownloadThread(const std::string& customId, const WWDownloader::DownloadUnits &units);

	void onManagerASyncThreadNum(int num);	

	void onThreadHandleRemoteDownloadFileSize(WWDownloader::DownloadUnits info, int gameID);

	int onGetDownloadID(int gameID);	
	//添加热更模块下载信息
	void onSetHotUpdateUnitInfo(WWDownloader::DownloadUnits& group, int unitsNum, enum DownloadType downloadType);	

	void onGenerateLuaHotUpdateUnitInfo(WWDownloader::DownloadUnits& group);

	void onFinishOtherLuaDownloadThread(int gameID);	

	void onSetLuaCommonDownloadID(int gameID);

	WWDownloader::DownloadUnits onGetDownloadUnits(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType);

	//获取模块热更下载地址
	void onHttpRequestDownloadAddress(int gameId,std::string& moduleName, std::string &stname, int sourceType, enum DownloadType downtype);

	bool onIsModuleThreadRunning();

	


	
	void setDelegate(UpgradeEventDelegate* pDelegate) 
	{
		m_upEventDelegate = pDelegate; 
		if (m_Downloader)
		{
			m_Downloader->setDelegate(pDelegate);
		}
	}
	UpgradeEventDelegate* getUpgradeEventDelegate(){ return m_upEventDelegate; }
private:

	std::shared_ptr<WWDownloader> 					m_Downloader;

	rapidjson::Document 							m_JsonDoc;

	std::unordered_map<int, WWDownloader::resInfo>	m_DownloadCfg;

	WWDownloader::DownloadUnits						m_RecordDownUnits;

	std::vector<int>								m_LuaModuleIDs;

	std::unordered_map<int, std::string>			m_ModuleNameCfg;

	std::unordered_map<std::string, std::string> userData; 

	UpgradeEventDelegate* m_upEventDelegate; 
};



class UpgradeAssetsMgrContainer
{
public:

	UpgradeAssetsMgrContainer();

	virtual ~UpgradeAssetsMgrContainer(){}

	static UpgradeAssetsMgrContainer* getInstance()
	{
		if (!m_ContainerInst)
		{
			m_ContainerInst = new UpgradeAssetsMgrContainer();
		}
		return m_ContainerInst;
	}

	static void release()
	{
		if (m_ContainerInst)
		{
			delete m_ContainerInst;
			m_ContainerInst = nullptr;
		}
	}

	void onSetUpAssetMgr(int gameID, WWUpgradeAssetsMgr* mgr);

	WWUpgradeAssetsMgr* onGetUpAssetMgr(int gameID);
	void setUpdateUrl(std::string& url);
	//监测资源是否存在
	void onCheckGameResExist(const std::vector<std::string>& gameResArr);
	//设置下载的地址 资源下载地址和热更地址
	void setDownloadURL(const std::string &key,const std::string & value);
protected:
	void initUpdateCfg();
private:

	std::map<int, WWUpgradeAssetsMgr*>	m_UpAssetMgrMap;

	static UpgradeAssetsMgrContainer*	m_ContainerInst;
};

#endif // __UPGRADE_ASSETS_MGR_H__
