#pragma once

//*******************************
//Name:WWNetwork.h
//Desc:Network Base
//Auth:Wawa
//Date:20161118
//Last:20170104
//*******************************

#include "WWSocket.h"
#include "WWBuffer.h"
#include "WWIPPool.h"
#include "network/HttpClient.h"

enum WWNetStatus
{
	NetStatueLag,				
	NetStatueClose,				
	NetStatueNoRsp,				
	NetStatueHandSharingFialed	
};

class NetEventDelegate
{
public:
	NetEventDelegate() :curStep(0){}
public:
	virtual void onExceptionCaught(WWNetStatus eStatus) = 0;
	virtual void onConnected() = 0;
	virtual void reConnect(float delayTime = 2.f) = 0;
	virtual void onReceivedData(WWBuffer * data) = 0;
	virtual WWBuffer* onRequestLogonInfo() = 0;
private:
	CC_SYNTHESIZE(int, curStep, SocketConectStep);
};

class SocketParallelCheck;
class WWNetworkStateHandler;
class WWNetwork
{
public:
	friend class WWNetWorkStateReadHandler;
	friend class WWNetWorkStateWriteHandler;

public:
	WWNetwork();
	virtual ~WWNetwork();

public:
	void setInetAddress(const WWInetAddress& oInetAddress){ m_oInetAddress = oInetAddress; }
	const WWInetAddress& getInetAddress() const{ return m_oInetAddress; }
	void setNewSocketUrl(const std::string &newSocketUrl){ m_strHttpUrlForNewSocketAddr = newSocketUrl; }
	void setDelegate(NetEventDelegate* pDelegate) { m_netEventDelegate = pDelegate; }
	bool isConnected(){ return m_eStatus == WWSS_CONNECTED; }

	CC_SYNTHESIZE(WWSocketStatus, m_eStatus, ExitStatus);
	CC_SYNTHESIZE(bool, isXML, IsXML);
	CC_SYNTHESIZE(bool, isReconnect, Reconnect);
	CC_SYNTHESIZE_READONLY(bool, reconnectFlag, ReconnectFlag);

	void setIPPool(IPPoolData& data){ m_poolData = data; }
	bool removeIP(std::string ip);
	bool toConnect();
	
	bool connect();
	void parallelConnect(const std::vector< WWInetAddress > &inetAddrs);
	void disconnect(WWSocketStatus status);
	void close(WWSocketStatus status){ disconnect(status); }
	void send(WWBuffer* pBuffer);
	void sendMessageNow(WWBuffer* pBuffer);
	void pushMsgFront(WWBuffer* pBuffer);
	bool pushMsg();
	void clearSendBufferBak();
	void resetIPPort(std::string ip, int port);

private:
	void init();
	void onDisconnected();
	void onConnectTimeout();
	void onConnected(WWBuffer* pBuffer);
	void reSocketConnect(float dt);
	void reConnectFail();
	void requestNewSocketAddress();
	void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);
	void startScheduler(){ m_bRunSchedule = true; }
	void stopScheduler(){ m_bRunSchedule = false; }

	void onHeartBeatMsg(WWBuffer* pBuffer);
	void onMessageReceived(WWBuffer& oBuffer);
	bool runRead();
	bool runWrite();
	void threadSchedule();

	void pushBak2SendFront();
	void removeBakBySendId(int m_sendMsg_Id);
	bool handleNewSocketAddr(const char* pData, int len, char* ip, int &port);

	void onComeToBackgroundEvent(cocos2d::EventCustom *pEvent);
	void onComeToForegroundEvent(cocos2d::EventCustom *pEvent){}
	void netException(WWSocketStatus eStatus);

	struct _SENDBUFFER
	{
		char* pBuffer;
		int nOffset;
		int nLength;
		int nSendId;
	};

	std::mutex m_mutex;
	bool m_selfRun;	
	bool m_isSucces;
	bool m_bRunSchedule;
	bool m_isHeartMsgSend;
	bool m_connectFailFlag;
	bool m_isBankSocketStart;  
	int channelID;
	int m_sendMsg_Id;
	int m_recvMsg_Id;
	int m_recvIDFromServer;
	int m_connectFailedCount;
	int m_nSocketConnectFailCount;
	int m_nSocketConnectFailLimit;
	int m_nHttpGetSocketFailCount;
	int m_nHttpGetSocketFailLimit;
	float m_fSoTimeout;
	float m_heartBeatDelay;
	float m_heartBeatMsgDuration;
	float m_fConnectingDuration;
	float m_fDataReciveDelayTime;
	float m_fDataReciveDelayDuration;
	std::string m_strHttpUrlForNewSocketAddr;
	char m_pReadBuffer[SOCKET_READ_BUFFER_SIZE];

	IPPoolData m_poolData;
	WWSocket m_oSocket;	
	WWBuffer m_oReadBuffer;	
	WWInetAddress m_oInetAddress;	
	SocketParallelCheck *m_socketParallelCheck;  
	NetEventDelegate* m_netEventDelegate;	
	cocos2d::EventListener *m_pComeToForegroundListener; 
	cocos2d::EventListener *m_pComeToBackgroundListener;
	std::chrono::steady_clock::time_point m_reconnectTimePoint;

	std::queue<WWBuffer*> m_vecCacheBuffer;
	std::list<_SENDBUFFER> m_lSendBuffers;
	std::list<_SENDBUFFER> m_lSendBuffers_bak;	
	std::list<WWNetworkStateHandler*> stateHandlers;	
};