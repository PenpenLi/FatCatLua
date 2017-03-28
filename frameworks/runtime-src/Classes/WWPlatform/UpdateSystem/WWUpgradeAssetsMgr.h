#ifndef __UPGRADE_ASSETS_MGR_H__
#define __UPGRADE_ASSETS_MGR_H__


/*! @file
********************************************************************************
<PRE>
ģ����       :  ���¹�����
�ļ���       :  WWUpgradeAssetsMgr.h
�ļ�ʵ�ֹ��� :  ģ�� ��Դ���ع�����
����         :  cruelogre  546761316@qq.com
�汾         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
�޸ļ�¼ :
�� ��        �汾     �޸���              �޸�����
2016/11/1   1.0     cruelogre		      ��ֲ
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
	//������Դ���ص�ַ
	std::string onGetJointDownloadAddress(const std::string& resName);

	WWDownloader::DownloadUnits onGetDownloadUnitInfo(std::vector<WWDownloader::resInfo>& vecRes);

	void onStartSilenceDownloading(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType, int batchId = 0);

	void onCancleSilenceDownloading(const std::vector<WWDownloader::resInfo>& vecRes);

	//��ʼapk����
	void onStartAPKDownload(const std::string &srcUrl, const std::string &storagePath, std::vector<std::string>& headers);

	bool onCheckDownloadResExist(int gameID);	
	//���ص������ļ�
	void onInitDownloadJsonInfo(const std::string& jsonFile);
	//plistFile  storePath �洢��ַ
	void onInitModuleInfo(const std::string& plistFile, const std::string& storePath);

	void onGetDownloadModuleInfo(int gameID, std::string& plistName, std::string& plistKey);

	void onSetUpdateAssetLayerDesc(int gameID);		

	long onGetLocalDownloadFileSize(WWDownloader::DownloadUnits& group);	

	long onGetRemoteDownloadFileSize(WWDownloader::DownloadUnits& group, int gameID);	

	void onClearDownloadThread(const std::string& customId, const WWDownloader::DownloadUnits &units);

	void onManagerASyncThreadNum(int num);	

	void onThreadHandleRemoteDownloadFileSize(WWDownloader::DownloadUnits info, int gameID);

	int onGetDownloadID(int gameID);	
	//����ȸ�ģ��������Ϣ
	void onSetHotUpdateUnitInfo(WWDownloader::DownloadUnits& group, int unitsNum, enum DownloadType downloadType);	

	void onGenerateLuaHotUpdateUnitInfo(WWDownloader::DownloadUnits& group);

	void onFinishOtherLuaDownloadThread(int gameID);	

	void onSetLuaCommonDownloadID(int gameID);

	WWDownloader::DownloadUnits onGetDownloadUnits(std::vector<WWDownloader::resInfo>& vecRes, enum DownloadType downloadType);

	//��ȡģ���ȸ����ص�ַ
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
	//�����Դ�Ƿ����
	void onCheckGameResExist(const std::vector<std::string>& gameResArr);
	//�������صĵ�ַ ��Դ���ص�ַ���ȸ���ַ
	void setDownloadURL(const std::string &key,const std::string & value);
protected:
	void initUpdateCfg();
private:

	std::map<int, WWUpgradeAssetsMgr*>	m_UpAssetMgrMap;

	static UpgradeAssetsMgrContainer*	m_ContainerInst;
};

#endif // __UPGRADE_ASSETS_MGR_H__
