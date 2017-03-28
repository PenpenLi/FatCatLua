#pragma once
#pragma execution_character_set("utf-8")
#include "UpgradeEvent.h"


struct EventData
{
	enum EventType
	{
		Event_Empty = 0, //空
		Event_Error, //错误事件
		Event_Progress, //进度事件
		Event_Success, //成功事件
		Event_Unzip, //解压事件
		Event_UnzipOver, //解压完成事件
		Event_GotRemoteFileInfo, //获取到远程下载文件信息事件
		Event_GotRemoteAddr, //获取到远程下载地址事件
		Event_CheckRes, //监测资源是否存在事件
	};
	EventType eType;
	bool isSuccess;
	int gameId; //操作的id
	EventData()
	{
		eType = Event_Empty;
		isSuccess = true;
		gameId = 0;
	}
};

class UpgradeEventDelegate
{
public:
	UpgradeEventDelegate() {}
public:
	virtual void onUpgradeEvent(UpgradeEvent eState, EventData* eData) = 0;

private:
	
};