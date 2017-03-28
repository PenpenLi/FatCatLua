#include "WWMsgManager.h"
#include "MsgLuaFilter.h"
#include "../NetSystem/WWInetAddress.h"
#include "../NetSystem/WWIPPool.h"
#include "../Tools/WWUtil.h"
#include "../VariateSystem/WWConfigManager.h"
#include "../UpdateSystem/WWUpgradeAssetsMgr.h"
#include "../LogSystem/WWLog.h"

USING_NS_CC;
WWMsgManager::WWMsgManager() 
:_hasConnected(false), 
enterbackground(false), 
backTime(0), 
reConnectedTime(0)
{
	m_network.setDelegate(this);
}

WWMsgManager::~WWMsgManager()
{
	m_network.setDelegate(nullptr);
}

void WWMsgManager::onExceptionCaught(WWNetStatus eStatus)
{
	CCLOG("WWMsgManager onExceptionCaught");
	cocos2d::LuaValue lv;
	lv = LuaValue::intValue(eStatus);
	MsgLuaFilter::getInstance()->onNetEvent(NetEvent::Event_onExceptionCaught,lv);
}

void WWMsgManager::onConnected()
{
	CCLOG("WWMsgManager onConnected");
	cocos2d::LuaValue lv;
	MsgLuaFilter::getInstance()->onNetEvent(NetEvent::Event_onConnected, lv);
}

WWBuffer* WWMsgManager::onRequestLogonInfo()
{
	CCLOG("WWMsgManager onRequestLogonInfo");
	cocos2d::LuaValue lv;
	MsgLuaFilter::getInstance()->onNetEvent(NetEvent::Event_onRequestLogonInfo, lv);
	return nullptr;
}

void WWMsgManager::reConnect(float delayTime /*= 2.f*/)
{
	CCLOG("WWMsgManager reConnect");
	cocos2d::LuaValue lv;
	lv = LuaValue::floatValue(delayTime);
	MsgLuaFilter::getInstance()->onNetEvent(NetEvent::Event_reConnect, lv);
}

void WWMsgManager::onUpgradeEvent(UpgradeEvent eState, EventData* eData)
{
	cocos2d::LuaValue lv;
	LuaValueDict dic;
	dic.emplace(make_pair("eType", LuaValue::intValue(eData->eType)));
	dic.emplace(make_pair("isSuccess", LuaValue::intValue(eData->isSuccess)));
	dic.emplace(make_pair("gameId", LuaValue::intValue(eData->gameId)));
	switch (eData->eType)
	{
	case EventData::Event_Empty:
		break;
	case EventData::Event_Error:
	{
		WWDownloader::Error* er = (WWDownloader::Error*)eData;

		dic.emplace(make_pair("code", LuaValue::intValue(er->code)));
		dic.emplace(make_pair("curlm_code", LuaValue::intValue( er->curlm_code)));
		dic.emplace(make_pair("curle_code", LuaValue::intValue(er->curle_code)));
		dic.emplace(make_pair("message", LuaValue::stringValue(er->message.c_str())));
		dic.emplace(make_pair("customId", LuaValue::stringValue( er->customId.c_str())));
		dic.emplace(make_pair("url", LuaValue::stringValue( er->url.c_str())));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);

	}
		break;
	case EventData::Event_Progress:
	{
		WWDownloader::ProgressData* pd = (WWDownloader::ProgressData*)eData;

		dic.emplace(make_pair("customId", LuaValue::stringValue(pd->customId.c_str())));
		dic.emplace(make_pair("url", LuaValue::stringValue( pd->url.c_str())));
		dic.emplace(make_pair("path", LuaValue::stringValue( pd->path.c_str())));
		dic.emplace(make_pair("name", LuaValue::stringValue( pd->name.c_str())));
		dic.emplace(make_pair("downloaded", LuaValue::floatValue(pd->downloaded)));
		dic.emplace(make_pair("totalToDownload", LuaValue::floatValue(pd->totalToDownload)));


	}
		break;
	case EventData::Event_Success:
	{
		WWDownloader::SuccessData* sd = (WWDownloader::SuccessData*)eData;

		dic.emplace(make_pair("customId", LuaValue::stringValue( sd->customId.c_str())));
		dic.emplace(make_pair("storagePath", LuaValue::stringValue( sd->storagePath.c_str())));
		dic.emplace(make_pair("srcUrl", LuaValue::stringValue( sd->srcUrl.c_str())));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);

	}
		break;
	case EventData::Event_Unzip:
	{
		WWDownloader::UnzipingData* ud = (WWDownloader::UnzipingData*)eData;
		dic.emplace(make_pair("customId", LuaValue::stringValue(ud->customId.c_str())));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);

	}
		break;
	case EventData::Event_GotRemoteFileInfo:
	{

		WWUpgradeAssetsMgr::RemoteFileInfo* rf = (WWUpgradeAssetsMgr::RemoteFileInfo*)eData;
		CCLOG("WWMsgManager RemoteFileInfo:gameid %d,fileSize:%ld", rf->gameId, rf->fileSize);
		//dic.emplace(make_pair("gameId", LuaValue::intValue(rf->gameId)));
		dic.emplace(make_pair("fileSize", LuaValue::floatValue( rf->fileSize)));
		
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);
	}
		break;
	case EventData::Event_GotRemoteAddr:
	{
		WWUpgradeAssetsMgr::RemoteFileAddr* rfa = (WWUpgradeAssetsMgr::RemoteFileAddr*)eData;
		CCLOG("WWMsgManager Event_GotRemoteAddr:isSuccess %d,resModule:%s", rfa->isSuccess, rfa->resModule.c_str());
		dic.emplace(make_pair("resModule", LuaValue::stringValue( rfa->resModule.c_str())));
		dic.emplace(make_pair("resAddr", LuaValue::stringValue(rfa->resAddr.c_str())));
		dic.emplace(make_pair("resDesc", LuaValue::stringValue(rfa->resDesc.c_str())));
		dic.emplace(make_pair("owerId", LuaValue::intValue(rfa->owerId)));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);
	}
		break;
	case EventData::Event_CheckRes:
	{
		WWUpgradeAssetsMgr::CheckResInfo* ch = (WWUpgradeAssetsMgr::CheckResInfo*)eData;
		CCLOG("WWMsgManager Event_CheckRes:gameid %d,resExist:%d", ch->gameId,ch->resExist);
		//dic.emplace(make_pair("gameId", LuaValue::intValue(ch->gameId)));
		dic.emplace(make_pair("resExist", LuaValue::intValue( ch->resExist)));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);
	}
		break;
	case EventData::Event_UnzipOver:
	{
		WWDownloader::UnzipOverData* ud = (WWDownloader::UnzipOverData*)eData;
		dic.emplace(make_pair("customId", LuaValue::stringValue(ud->customId.c_str())));
		CCLOG("WWMsgManager onUpgradeEvent:UpgradeEvent %d,EventData:%d", eState, eData->eType);
	}
	default:
		break;
	}

	
	lv = LuaValue::dictValue(dic);
	MsgLuaFilter::getInstance()->onUpdateEvent(eState, lv);
}

void WWMsgManager::onReceivedData(WWBuffer * buffer)
{
	CCLOG("WWMsgManager onReceivedData");
	do
	{
		CC_BREAK_IF(!buffer);
		buffer->resetReaderIndex();
		buffer->markReaderIndex();
		int luamsgType = buffer->readChar3ToInt();
		buffer->resetReaderIndex();
		CCLOG("WWMsgManager onReceivedData:%d", luamsgType);
		if (luamsgType == 0)
		{
			buffer->markReaderIndex();
			buffer->readChar3ToInt();
			int type = buffer->readChar3ToInt();
			buffer->resetReaderIndex();
			buffer->markReaderIndex();
			buffer->readChar3ToInt();
			buffer->resetReaderIndex();
			int msgType = buffer->readChar3ToInt();
			Director::getInstance()->getScheduler()->performFunctionInCocosThread([type, buffer]()
			{
				MsgLuaFilter::getInstance()->onRootMessageReceived(type, buffer);
				buffer->toRelease();
			});
		} 
		else
		{
			buffer->markReaderIndex();
			buffer->resetReaderIndex();
		//	Director::getInstance()->getScheduler()->performFunctionInCocosThread([luamsgType, buffer]()
		//	{
				MsgLuaFilter::getInstance()->onMessageReceived(luamsgType, buffer);
				//buffer->toRelease();
		//	});
		}
	} 
	while (0);
}

void WWMsgManager::parallelConnect(const std::vector<std::string> &ips, const std::vector<int> &ports)
{
	IPPoolData data;
	//if (!WWIPPool::loadPool(data))
	{
		printExEx(WWLC_YELLOW, "Niya wwIPPool Form LUA !!!");
		data.setPoolData(ips, ports);
		m_network.setIsXML(true);
	}

	for (auto i : data.ips) printExEx(WWLC_GREEN, "Niya wwIPPool IP %s", i.c_str());
	for (auto i : data.pts) printExEx(WWLC_GREEN, "Niya wwIPPool Port %d", i);
		
	auto iter = std::find(data.pts.begin(), data.pts.end(), 80);
	if (iter != data.pts.end()) data.pts.erase(iter);

	m_network.setIPPool(data);
	//auto checkFun = [&]()
	//{
		m_network.disconnect(WWSS_IO_CLOSE);
		_hasConnected = true;
		m_network.toConnect();
	//};
	//std::thread ts(checkFun);
	//ts.detach();
}

void WWMsgManager::checkToConnect()
{
	if (!enterbackground || !_hasConnected) return;
	enterbackground = false;
	m_network.clearSendBufferBak();
	if (!m_network.isConnected()) 
	{
		this->reConnect();
		m_network.connect();
		if (getSecNow() - backTime > reConnectedTime) 
		{
			//relogin
			this->_hasConnected = false;
			cocos2d::LuaValue lv;
			MsgLuaFilter::getInstance()->onNetEvent(NetEvent::Event_reLogin, lv);
		}
	}
}

void WWMsgManager::enterBackGround()
{
	this->enterbackground = true;
	this->backTime = getSecNow();
	if (reConnectedTime==0) 
	{
		auto module = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_EVENTSYSTEM);
		for (auto &item : module.items) 
		{
			if (strcmp(item->name, "reLoginTime") == 0 && item->values.size()>0 && isnum(item->values[0]))
			{
				reConnectedTime = atoi(item->values[0].c_str());
				break;
			}
		}
	}
}
