#pragma once

//*******************************
//Name:WWMsgManager.h
//Desc:ToLua
//Auth:Wawa
//Date:?
//Last:20161122
//*******************************

#include "../NetSystem/WWNetwork.h"
#include "../WWMacros.h"
#include "../UpdateSystem/UpGradeDelegate.h"

class WWMsgManager : public NetEventDelegate, public UpgradeEventDelegate
{
public:
	WWMsgManager();
	~WWMsgManager();
	SINGLE_INSTANCE_FUNC(WWMsgManager);

public:
	//�̳нӿ�
	void onExceptionCaught(WWNetStatus eStatus) override;
	void onConnected() override;
	WWBuffer* onRequestLogonInfo() override;
	void reConnect(float delayTime = 2.f ) override;
	void onReceivedData(WWBuffer * data) override;
	void onUpgradeEvent(UpgradeEvent eState, EventData* eData) override;
	
	void setNewSocketUrl(const std::string& newsocketurl){ m_network.setNewSocketUrl(newsocketurl);}
	void parallelConnect(const std::vector<std::string> &ips, const std::vector<int> &ports);
	void connect(){ m_network.connect(); }
	void logout(){ m_network.setReconnect(false); m_network.disconnect(WWSS_DIS_CONNECT); }
	bool isConnect(){ return m_network.isConnected(); }
	bool hasConnected(){ return _hasConnected; };
	void sendBuffer(WWBuffer* buffer){ m_network.send(buffer); }
	void sendBufferNow(WWBuffer* buffer){ m_network.sendMessageNow(buffer);; }
	
	void checkToConnect();
	void enterBackGround();

private:
	//�������
	WWNetwork m_network;
	//�Ƿ�����̨
	bool enterbackground;
	//�����̨��ʱ��
	long backTime; 
	//���½�����Ϸ�����µ�¼��ʱ����
	int reConnectedTime; 
	//�Ƿ�ȥ������IP
	CC_SYNTHESIZE_READONLY(bool, _hasConnected, HasConnected); 
};