#pragma once
#pragma execution_character_set("utf-8")
#include "UpgradeEvent.h"


struct EventData
{
	enum EventType
	{
		Event_Empty = 0, //��
		Event_Error, //�����¼�
		Event_Progress, //�����¼�
		Event_Success, //�ɹ��¼�
		Event_Unzip, //��ѹ�¼�
		Event_UnzipOver, //��ѹ����¼�
		Event_GotRemoteFileInfo, //��ȡ��Զ�������ļ���Ϣ�¼�
		Event_GotRemoteAddr, //��ȡ��Զ�����ص�ַ�¼�
		Event_CheckRes, //�����Դ�Ƿ�����¼�
	};
	EventType eType;
	bool isSuccess;
	int gameId; //������id
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