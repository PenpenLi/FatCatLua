

#pragma once
#include <stdlib.h>
#include "../NetSystem/WWBuffer.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "../UpdateSystem/UpgradeEvent.h"
using namespace std;


//network event
enum NetEvent
{
	//exception cught
	Event_onExceptionCaught,	
	//connected to server
	Event_onConnected,	
	//request login infomation
	Event_onRequestLogonInfo,	
	//reconnect
	Event_reConnect,
	//connect not used
	Event_connect,
	//client need relogin
	Event_reLogin,
};
//消息类型
enum MsgType
{
	TYPE_NORMAL, //键值对
	TYPE_LOOP, //循环
};
struct MsgInfo
{
	MsgType mType;
	string kType; //消息的类型  如果是循环则是循环类型
	string kName; //消息名字 如果是循环则是循环的名字
	string kCountName; //循环的时候 循环count的名字
	vector<MsgInfo> msgInfo;// 循环的消息内容

	MsgInfo()
	{
		mType = TYPE_NORMAL;
		kType = "";
		kName = "";
		kCountName = "";
		msgInfo.clear();
	}
	MsgInfo(MsgType mType0, string kType0, string kName0, vector<MsgInfo> msgInfo0)
	{
		mType = mType0;
		kType = kType0;
		kName = kName0;
		msgInfo = msgInfo0;
	}
};
//message filter
class MsgLuaFilter
{
public:
	static MsgLuaFilter* getInstance();
	static void deleteInstance();

public:
	//send message to lua
	bool onMessageReceived(int msgType, WWBuffer* oBuffer);

	bool onRootMessageReceived(int msgType, WWBuffer* oBuffer);
	void onNetEvent(const NetEvent& netEvent,const cocos2d::LuaValue& value);
	void onUpdateEvent(UpgradeEvent upevent,cocos2d::LuaValue& value);
	//register message receiver
	void registerMsgId(int msg);
	void bindMsgId(int msg, cocos2d::ValueVector& vec);
	void unRegisterMsgId(int msg);
	void clearMsgId();

	//register root message
	void registerRootMsgId(int msg);
	void unRegisterRootMsgId(int msg);
	void clearRootMsgId();

	//register global message 
	void registerGlobalMsgId(int msg);
	void unRegisterGlobalMsgId(int msg);
	void clearGlobalMsgId();

	//register network event message
	void registerNetEventId(int msg);
	void unRegisterNetEventId(int msgId);
	void clearNetEventId();

	void registerUpgradeEventId(int msg);
	void unRegisterUpgradeEvent(int msg);
	void clearUpgradeEvent();
private:
	MsgLuaFilter(){}
	~MsgLuaFilter(){}
	bool onMessageReceived0(int msgType, WWBuffer* oBuffer);
	bool onMessageReceived1(int msgType, WWBuffer* oBuffer);
private:
	//normal message
	std::vector<int> m_arrMsgId;
	std::map<int, std::vector<MsgInfo>> m_arrMsgInfo;
	//root message
	std::vector<int> m_arrRootMsgId;
	//global message
	std::vector<int> m_arrGlobalMsgId;
	//network message
	std::vector<int> m_arrEventId;
	//
	std::vector<int> m_arrUpgradeId;
};

