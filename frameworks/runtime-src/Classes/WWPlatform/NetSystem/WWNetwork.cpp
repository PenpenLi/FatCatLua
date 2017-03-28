#include "WWNetwork.h"
#include "SocketParallelCheck.h"
#include "WWNetworkStateHandler.h"
#include "../Tools/WWUtil.h"
#include "../DBSystem/WWGameData.h"
#include "../LogSystem/WWLogMaros.h"
#include "../EngineSystem/IPhoneTool.h"
#include "../VariateSystem/WWConfigManager.h"

#pragma execution_character_set("utf-8")

static const int CONNECT_FAIL_CHANGE = 8;
static bool debug_print;
#define CCLOG_IF(debugprint,format, ...) if(debugprint)cocos2d::log(format, ##__VA_ARGS__)

WWNetwork::WWNetwork() :
m_selfRun(false),
m_isSucces(false),
isReconnect(false),
isXML(false),
m_isHeartMsgSend(false),
reconnectFlag(false),
m_bRunSchedule(false),
m_connectFailFlag(false),
m_isBankSocketStart(false),
m_eStatus(WWSS_IO_CLOSE),
channelID(-1),
m_recvMsg_Id(0),
m_sendMsg_Id(0),
m_recvIDFromServer(0),
m_nSocketConnectFailCount(0),
m_nHttpGetSocketFailCount(0),
m_connectFailedCount(CONNECT_FAIL_CHANGE),
m_nSocketConnectFailLimit(SOCKET_CONNECT_FAIL_COUNT),
m_nHttpGetSocketFailLimit(HTTP_GETSOCKET_FAIL_COUNT),
m_fSoTimeout(SOCKET_SOTIMEOUT),
m_heartBeatDelay(HEART_BEAT_DELAY_TIME),
m_fConnectingDuration(0.0f),
m_heartBeatMsgDuration(0.0f),
m_fDataReciveDelayDuration(0.0f),
m_fDataReciveDelayTime(RECIVE_DATA_DELAY_TIME),
m_strHttpUrlForNewSocketAddr("http://gs.wawagame.cn:5320/handler/requestAddress"),
m_netEventDelegate(nullptr),
m_pComeToBackgroundListener(nullptr),
m_pComeToForegroundListener(nullptr),
m_socketParallelCheck(nullptr)
{
	m_socketParallelCheck = new SocketParallelCheck();
	m_socketParallelCheck->setCheckCallback([this](SocketParallelCheck::Statue statue, const WWInetAddress &inetAddr)
	{
		switch (statue)
		{
			case SocketParallelCheck::Statue::SUCCESS:
			{
				printExEx(WWLC_GREEN, "Niya WWNetwork Callback Success %s:%d\n", inetAddr.getIp(), inetAddr.getPort());
				this->setInetAddress(inetAddr);
				this->connect();
				break;
			}
			case SocketParallelCheck::Statue::FAILURE:
			{
				printExEx(WWLC_RED, "Niya WWNetwork Callback Failure %s:%d\n", inetAddr.getIp(), inetAddr.getPort());
				auto addr = inetAddr;
				addr.setPort(80);
				this->setInetAddress(addr);
				this->connect();
				break;
			}
			case SocketParallelCheck::Statue::TIMEOUT:
			{
				printExEx(WWLC_RED, "Niya WWNetwork Callback Timeout %s:%d\n", inetAddr.getIp(), inetAddr.getPort());
				auto addr = inetAddr;
				addr.setPort(80);
				this->setInetAddress(addr);
				this->connect();
				break;
			}
		default:
			break;
		}
	});

	auto evtDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	m_pComeToBackgroundListener = evtDispatcher->addCustomEventListener(EVENT_COME_TO_BACKGROUND, 
		CC_CALLBACK_1(WWNetwork::onComeToBackgroundEvent, this));
	m_pComeToForegroundListener = evtDispatcher->addCustomEventListener(EVENT_COME_TO_FOREGROUND,
		CC_CALLBACK_1(WWNetwork::onComeToForegroundEvent, this));

	stateHandlers.push_back(new WWNetWorkStateReadHandler());
	stateHandlers.push_back(new WWNetWorkStateWriteHandler());

	this->init();
}

WWNetwork:: ~WWNetwork()
{
	m_oSocket.ccClose();
	while (!m_lSendBuffers.empty())
	{
		CC_SAFE_DELETE_ARRAY(m_lSendBuffers.front().pBuffer);
		m_lSendBuffers.pop_front();
	}

	while (!m_lSendBuffers_bak.empty())
	{
		CC_SAFE_DELETE_ARRAY(m_lSendBuffers_bak.front().pBuffer);
		m_lSendBuffers_bak.pop_front();
	}

	auto evtDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	evtDispatcher->removeEventListener(m_pComeToForegroundListener);
	evtDispatcher->removeEventListener(m_pComeToBackgroundListener);

	CC_SAFE_DELETE(m_socketParallelCheck);
}

void WWNetwork::init()
{
	std::vector<WWSystemItem*> items = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_NET).items;

	auto func = [&](std::string str){
		auto item = findSystemItemByName(items, str.c_str());
		return (item&&item->values.size() > 0 && isnum(item->values[0])) ? item->values[0] : "";
	};

	debug_print = atoi(func("DEBUG_PRINT").c_str());
	m_fSoTimeout = atof(func("SOCKET_SOTIMEOUT").c_str());
	m_heartBeatDelay = atof(func("HEART_BEAT_DELAY_TIME").c_str());
	m_fDataReciveDelayTime = atof(func("RECIVE_DATA_DELAY_TIME").c_str());
	m_nHttpGetSocketFailLimit = atof(func("HTTP_GETSOCKET_FAIL_COUNT").c_str());
	m_nSocketConnectFailLimit = atof(func("SOCKET_CONNECT_FAIL_COUNT").c_str());
	m_socketParallelCheck->setTimeout(atof(func("SOCKET_CHECK_SOTIMEOUT").c_str()));
}

bool WWNetwork::removeIP(string ip)
{
	if (m_poolData.ips.empty()) return false;
	if (!getIsXML()) return false;
	auto iter = std::find(m_poolData.ips.begin(), m_poolData.ips.end(), ip);
	if (iter != m_poolData.ips.end()) m_poolData.ips.erase(iter);
	WWIPPool::savePool(m_poolData);
	return true;
}

bool WWNetwork::toConnect()
{
	if (m_poolData.ips.empty())
	{
		printExEx(WWLC_YELLOW, "Niya WWNetwork wwIPPool Empty !!!\n");
		return false;
	}

	vector<std::string> ips;
	srand((int)time(0));
	int index = rand() % m_poolData.ips.size();
	auto str = m_poolData.ips[index];
	ips.push_back(str);
	printExEx(WWLC_YELLOW, "Niya WWNetwork wwIPPool Random IP %s", str.c_str());
	auto v = WWInetAddress::genInetAddrs(ips, m_poolData.pts);
	parallelConnect(v);
	return true;
}

bool WWNetwork::connect()
{
	printExEx(WWLC_YELLOW, "Niya WWNetwork Connect Status %d", m_eStatus);
	if (m_eStatus != WWSS_CONNECTED && m_eStatus != WWSS_CONNECTING)
	{
		if (!m_selfRun)
		{
			m_selfRun = true;
			std::thread t(&WWNetwork::threadSchedule, this);
			t.detach();
		}

		m_oSocket.setInetAddress(m_oInetAddress);
		m_oSocket.ccConnect();

		startScheduler();
		m_eStatus = WWSS_CONNECTING;
	}
	return false;
}

void WWNetwork::parallelConnect(const std::vector< WWInetAddress > &inetAddrs)
{
	m_nSocketConnectFailCount = 0;
	m_nHttpGetSocketFailCount = 0;
	if (m_netEventDelegate)
	{
		m_netEventDelegate->setSocketConectStep(0);
	}

	if (m_socketParallelCheck->isParalleling())
	{
		m_socketParallelCheck->end();
	}

	m_socketParallelCheck->setSocketInetAddrs(inetAddrs);
	m_socketParallelCheck->start();
}

void WWNetwork::disconnect(WWSocketStatus status)
{
	if (status == WWSS_SHAKEHAND_FAIL)
	{
		m_eStatus = status;
		onDisconnected();
	}
	 
	if(m_eStatus == WWSS_CONNECTED)
	{
		m_eStatus = status;
		stopScheduler();
		m_oSocket.ccDisconnect();
		m_fDataReciveDelayDuration = 0.0f;
		m_fConnectingDuration = 0.0f;

		if (m_eStatus == WWSS_DIS_CONNECT)
		{
			while (!m_lSendBuffers_bak.empty())
			{
				_SENDBUFFER& tBuffer = m_lSendBuffers_bak.back();
				CC_SAFE_DELETE_ARRAY(tBuffer.pBuffer);
				m_lSendBuffers_bak.pop_back();
			}
		}
		onDisconnected();
	}
}

void WWNetwork::send(WWBuffer* pBuffer)
{
	if (pBuffer->empty()) return;
	m_sendMsg_Id++;

#if USING_PACKAGE_HEAD_LENGTH
	int u_len = pBuffer->length();
	pBuffer->moveRight(2 * sizeof(char));
	pBuffer->moveWriterIndexToFront();
	pBuffer->writeChar((char)m_recvMsg_Id);
	pBuffer->writeChar((char)m_sendMsg_Id);
	int u_move_len = sizeof(short);
	if (u_len >= 0xFFFF)
	{
		u_move_len += sizeof(int);
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)0xFFFF);
		pBuffer->writeInt(u_len);
	}
	else
	{
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)u_len);
	}
#endif
	pBuffer->moveReaderIndexToFront();
	char* pData = pBuffer->readWholeData();
	int nLength = (int)pBuffer->length();
	pBuffer->moveReaderIndexToFront();
	pBuffer->toRelease();
	_SENDBUFFER tBuf;
	tBuf.pBuffer = pData;
	tBuf.nLength = nLength;
	tBuf.nOffset = 0;
	tBuf.nSendId = m_sendMsg_Id;

	m_lSendBuffers.push_back(tBuf);
}

void WWNetwork::sendMessageNow(WWBuffer* pBuffer)
{
	if (pBuffer->empty())return;

#if USING_PACKAGE_HEAD_LENGTH
	int u_len = pBuffer->length();
	pBuffer->moveRight(2 * sizeof(char));
	pBuffer->moveWriterIndexToFront();
	pBuffer->writeChar((char)(m_recvMsg_Id + 1));
	pBuffer->writeChar((char)(m_sendMsg_Id + 1));
	int u_move_len = sizeof(short);
	if (u_len >= 0xFFFF)
	{
		u_move_len += sizeof(int);
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)0xFFFF);
		pBuffer->writeInt(u_len);
	}
	else
	{
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)u_len);
	}
#endif
	pBuffer->moveReaderIndexToFront();
	char* pData = pBuffer->readWholeData();
	int nLength = (int)pBuffer->length();
	pBuffer->moveReaderIndexToFront();
	pBuffer->toRelease();
	_SENDBUFFER tBuffer;
	tBuffer.pBuffer = pData;
	tBuffer.nLength = nLength;
	tBuffer.nOffset = 0;
	tBuffer.nSendId = m_sendMsg_Id + 1;

	m_oSocket.ccWrite(tBuffer.pBuffer + tBuffer.nOffset, tBuffer.nLength - tBuffer.nOffset);
}

void WWNetwork::pushMsgFront(WWBuffer *pBuffer)
{
	if (!pBuffer || pBuffer->empty()) return;

	m_sendMsg_Id++;
#if USING_PACKAGE_HEAD_LENGTH
	int u_len = pBuffer->length();
	CCLOG_IF(debug_print, "send length=%d", u_len);
	//u_len-=2*sizeof(char);

	pBuffer->moveRight(2 * sizeof(char));
	pBuffer->moveWriterIndexToFront();
	pBuffer->writeChar((char)m_recvMsg_Id);
	pBuffer->writeChar((char)m_sendMsg_Id);
	int u_move_len = sizeof(short);
	if (u_len >= 0xFFFF)
	{
		u_move_len += sizeof(int);
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)0xFFFF);
		pBuffer->writeInt(u_len);
	}
	else
	{
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)u_len);
	}
#endif
	pBuffer->moveReaderIndexToFront();
	char* pData = pBuffer->readWholeData();
	int nLength = (int)pBuffer->length();
	pBuffer->moveReaderIndexToFront();
	pBuffer->toRelease();
	_SENDBUFFER tBuf;
	tBuf.pBuffer = pData;
	tBuf.nLength = nLength;
	tBuf.nOffset = 0;
	tBuf.nSendId = m_sendMsg_Id;
	m_lSendBuffers.push_front(tBuf);
}

bool WWNetwork::pushMsg()
{
	WWBuffer *pBuffer = WWBuffer::create();
	onConnected(pBuffer);
	if (pBuffer->empty() || !isConnected())
	{
		pBuffer->toRelease();
		return true;
	}

#if USING_PACKAGE_HEAD_LENGTH
	int u_len = pBuffer->length();
	int u_move_len = sizeof(short);
	if (u_len >= 0xFFFF)
	{
		u_move_len += sizeof(int);
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)0xFFFF);
		pBuffer->writeInt(u_len);
	}
	else
	{
		pBuffer->moveRight(u_move_len);
		pBuffer->moveWriterIndexToFront();
		pBuffer->writeShort((short)u_len);
	}
#endif

	pBuffer->moveReaderIndexToFront();
	char* pData = pBuffer->readWholeData();
	int nLength = (int)pBuffer->length();
	pBuffer->moveReaderIndexToFront();
	pBuffer->toRelease();
	WWNetwork::_SENDBUFFER tBuf;
	tBuf.pBuffer = pData;
	tBuf.nLength = nLength;
	tBuf.nOffset = 0;
	tBuf.nSendId = -2;

	m_lSendBuffers.push_front(tBuf);
	return false;
}

void WWNetwork::clearSendBufferBak()
{
	CCLOG_IF(debug_print,"clear send buffer bak");
	while (!m_lSendBuffers_bak.empty())
	{
		CC_SAFE_DELETE_ARRAY(m_lSendBuffers_bak.front().pBuffer);
		m_lSendBuffers_bak.pop_front();
	}
}

void WWNetwork::resetIPPort(string ip, int port)
{
	auto serveripkey = "server_ip";
	auto serverportkey = "server_port";
	std::vector<WWSystemItem*> items = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_NET).items;

	auto item = findSystemItemByName(items, "SAVEDATA_SERVERIP");
	if (item&&item->values.size() > 0 && item->values[0].length() > 0)
	{

		serveripkey = item->values.at(0).c_str();

	}
	item = findSystemItemByName(items, "SAVEDATA_SERVERPORT");
	if (item&&item->values.size() > 0 && item->values[0].length() > 0)
	{
		serverportkey = item->values.at(0).c_str();

	}
	items.clear();

	WWGameData::getInstance()->setStringForKey("server_ip", ip);
	WWGameData::getInstance()->setIntegerForKey("server_port", port);
}

void WWNetwork::onDisconnected()
{
	CCLOG_IF(debug_print, "WWNetManager  onDisconnected error %d", this->m_eStatus);
	m_isSucces = false;
	if (WWSS_SHAKEHAND_FAIL == m_eStatus)
	{
		if (m_netEventDelegate)
		{
			m_netEventDelegate->onExceptionCaught(NetStatueHandSharingFialed);
		}
	}
	else if (WWSS_DIS_CONNECT != m_eStatus && WWSS_DIS_CONNECT_FORBG != m_eStatus)
	{
		if (m_nSocketConnectFailCount < m_nSocketConnectFailLimit)
		{
			reconnectFlag = true;
			reSocketConnect(0);
		}
		else
		{
			if (m_netEventDelegate->getSocketConectStep() == 0)
			{
				WW_LOG_INFO("WWNetwork::onDisconnected() the step 1");
				if (m_netEventDelegate)
				{
					m_netEventDelegate->setSocketConectStep(1);
				}
				requestNewSocketAddress();
				m_isBankSocketStart = true;
			}
			else if (m_netEventDelegate->getSocketConectStep() == 1)
			{
				WW_LOG_INFO("WWNetwork::onDisconnected() the step 2");
				if (m_netEventDelegate)
				{
					m_netEventDelegate->setSocketConectStep(2);
				}
				m_nSocketConnectFailCount = 0;
				if (m_netEventDelegate)
				{
					m_netEventDelegate->onExceptionCaught(NetStatueHandSharingFialed);
				}
			}
		}
	}
	else
	{
		isReconnect = false;
		m_nSocketConnectFailCount = 0;
		m_nHttpGetSocketFailCount = 0;
	}
}

void WWNetwork::onConnectTimeout()
{
	CCLOG_IF(debug_print, "WWNetManager  onConnectTimeout");
	onDisconnected();
	if (WWSS_CONNECT_TIMEOUT == m_eStatus)
	{
		if (!m_isBankSocketStart)
		{
			reconnectFlag = true;
			reSocketConnect(0);
		}
		m_isBankSocketStart = false;
	}
}

void WWNetwork::onConnected(WWBuffer *sBuffer)
{
	m_nSocketConnectFailCount = 0;
	m_connectFailedCount = CONNECT_FAIL_CHANGE;

	if (m_netEventDelegate)
	{
		m_netEventDelegate->onConnected();
	}

	CCLOG_IF(debug_print, "connectFailCount:%d", m_connectFailedCount);

	CCLOG_IF(debug_print, "NetManager  onConnected ???? isReconnect=%d", isReconnect);

	sBuffer->writeChar(18);
	sBuffer->writeChar(0);
	sBuffer->writeChar(0);
	sBuffer->writeChar(0);
	sBuffer->writeChar(0);
	sBuffer->writeChar(0);
	sBuffer->writeChar(3);
	if (isReconnect)
	{
		auto funcReLogin = [=]() {
			sBuffer->writeBoolean(false);
			if (m_netEventDelegate)
			{
				WWBuffer* loginInfo = m_netEventDelegate->onRequestLogonInfo();
				CCLOG_IF(debug_print, "<WWNetManager | reconnect with user and password.");
				pushMsgFront(loginInfo);
			}
		};

		auto funcReConnect = [=]() {
			sBuffer->writeBoolean(isReconnect);
			int userid = UserDefault::getInstance()->getIntegerForKey("0x000001", 0);
			std::string userpwd = UserDefault::getInstance()->getStringForKey("b", "");
			CCLOG_IF(debug_print, "<WWNetManager | reconnect with isReconnect userid=%d,userpwd=%s,m_recvIDFromServer=%d,m_recvMsg_Id = %d,channelID=%d", userid, userpwd.c_str(), m_recvIDFromServer, m_recvMsg_Id, channelID);
			if (userid != 0 && userpwd != "")
			{
				sBuffer->writeInt(userid);
				sBuffer->writeLengthAndString(userpwd.c_str());
				sBuffer->writeChar((char)m_recvIDFromServer);
				sBuffer->writeInt(channelID);
			}
		};

		if (m_connectFailFlag)
		{	
			if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - m_reconnectTimePoint).count() > 150)
			{
				funcReLogin();
			}
			else
			{
				funcReConnect();
			}
		}
		else
		{
			funcReConnect();
		}
	}
	else
	{
		sBuffer->writeBoolean(isReconnect);
	}
}

void WWNetwork::reSocketConnect(float dt)
{
	if (!reconnectFlag) return;

	CCLOG_IF(debug_print, "WWNetManager::reSocketConnect %d ", m_nSocketConnectFailCount);
	if (m_isSucces) return;

	if (isConnected()) close(WWSS_DIS_CONNECT);

	connect();
	m_nSocketConnectFailCount++;
	CCLOG_IF(debug_print, "WWNetManager::reSocketConnect count(%d)", m_nSocketConnectFailCount);
}

void WWNetwork::reConnectFail()
{
	CCLOG_IF(debug_print, "reconnect fail.");
	m_nSocketConnectFailCount = 0;

	if (WWSS_RECV_TIMEOUT == m_eStatus)
	{
		if (m_netEventDelegate)
		{
			m_netEventDelegate->onExceptionCaught(NetStatueNoRsp);
			return;
		}
	}

	if (WWSS_DIS_CONNECT != m_eStatus || WWSS_DIS_CONNECT_FORBG != m_eStatus)
	{
		m_eStatus = WWSS_CONNECT_FAIL;
		onDisconnected();
	}
}

void WWNetwork::requestNewSocketAddress()
{
	if (m_nHttpGetSocketFailCount <= m_nHttpGetSocketFailLimit && !m_strHttpUrlForNewSocketAddr.empty())
	{
		printExEx(WWLC_GREEN, "Niya WWNetwork requestNewSocketAddress %s", m_strHttpUrlForNewSocketAddr.c_str());
		HttpRequest* request = new HttpRequest();
		request->setUrl(m_strHttpUrlForNewSocketAddr.c_str());
		request->setRequestType(HttpRequest::Type::POST);

		std::vector<std::string> headers;
		headers.push_back("Content-Type: application/octet-stream");
		request->setHeaders(headers);
		request->setResponseCallback(CC_CALLBACK_2(WWNetwork::onHttpRequestCompleted, this));
		WWBuffer buffer;
		buffer.writeChar(18);
		buffer.writeChar(1);
		buffer.writeChar(3);
		buffer.writeInt(7102);
		buffer.writeShort(11);
		int size = buffer.getContentSize();
		char * nRet = buffer.readWholeData();

		CCLOG_IF(debug_print, "WWSOCKET HTTP LEN %d", size);
		std::string str;

		for (int i = 0; i < size; ++i)
		{
			str += StringUtils::format(":%x", nRet[i]);
		}
		CCLOG_IF(debug_print, "WWSOCKET HTTP SEND %s", str.c_str());

		request->setRequestData(nRet, buffer.getContentSize());

		CC_SAFE_DELETE_ARRAY(nRet);

		request->setTag("WWNetManager:get new socket address");
		HttpClient::getInstance()->send(request);
		request->release();

		m_nHttpGetSocketFailCount++;
		CCLOG_IF(debug_print, "WWNetManager::requestNewSocketAddress count(%d)", m_nHttpGetSocketFailCount);
	}
	else
	{
		m_nHttpGetSocketFailCount = 0;
		reConnectFail();
	}
}

void WWNetwork::onHttpRequestCompleted(network::HttpClient *sender, network::HttpResponse *response)
{
	if (!response) return;

	int statusCode = response->getResponseCode();
	CCLOG_IF(debug_print, "response code: %d", statusCode);
	if (!response->isSucceed())
	{
		CCLOG_IF(debug_print, "response failed");
		CCLOG_IF(debug_print, "error buffer: %s", response->getErrorBuffer());
		requestNewSocketAddress();
		return;
	}

	std::vector<char> *buffer = response->getResponseData();
	std::string strData = "";
	std::copy(buffer->begin(), buffer->end(), std::insert_iterator<std::string>(strData, strData.begin()));
	if (strData.empty()) 
	{
		requestNewSocketAddress();
		return;
	}

	char ip[64] = { 0 };
	int port = 0;
	if (!handleNewSocketAddr(strData.c_str(), strData.length(), ip, port))
	{
		reConnectFail();
		return;
	}

	if (strlen(ip) <= 0 || port <= 0) 
	{
		requestNewSocketAddress();
		return;
	}

	m_nHttpGetSocketFailCount = 0;
	CCLOG_IF(debug_print, "ip(%s), port(%d)", ip, port);
	WWInetAddress socket_addr;
	auto hostInfo = gethostbyname(ip);
	if (hostInfo) 
	{
		socket_addr.setIp(inet_ntoa(*((struct in_addr *)hostInfo->h_addr)));
	}
	else 
	{
		socket_addr.setIp(ip);
	}

	socket_addr.setPort(port);
	if (isConnected())
	{
		WW_LOG_INFO("WWNetwork::connect had already connected! don't need do it again!!");
	}
	else
	{
		setInetAddress(socket_addr);
		m_eStatus = WWSS_CONNECT_TIMEOUT;
		m_oSocket.ccDisconnect();
		connect();
	}
}

void WWNetwork::onHeartBeatMsg(WWBuffer * buffer)
{
	CCLOG_IF(debug_print, "NetManager  onHeartBeatMsg ");
	buffer->writeChar(18);
	buffer->writeChar(2);
	buffer->writeChar(1);
}

void WWNetwork::onMessageReceived(WWBuffer& oBuffer)
{
	CCLOG_IF(debug_print, " WWNetManager onMessageReceived");
	m_recvMsg_Id = (int)oBuffer.readChar();
	m_recvIDFromServer = m_recvMsg_Id;
	CCLOG_IF(debug_print, "???????????m_recvMsg_Id=%d", m_recvMsg_Id);
	int send_id = (int)oBuffer.readChar();
	CCLOG_IF(debug_print, "???????????send_id=%d", send_id);
	removeBakBySendId(send_id);
	oBuffer.markReaderIndex();
	int msgType = oBuffer.readChar3ToInt();
	CCLOG_IF(debug_print, "msgType=%x", msgType);
	switch (msgType)
	{
	case 0x7f7f7f:
	{
		m_isHeartMsgSend = false;
		CCLOG_IF(debug_print, "");
		break;
	}
	case 0x120000: 
	{
		printExEx(WWLC_GREEN, "Niya WWNetwork ShakeHand %s:%d", m_oInetAddress.getIp(), m_oInetAddress.getPort());
		CCLOG_IF(debug_print, "");
		int tmpChannelID = oBuffer.readInt();
		CCLOG_IF(debug_print, "channelID=%d", channelID);
		m_isSucces = oBuffer.readBoolean();
		CCLOG_IF(debug_print, "isSucess=%d", m_isSucces);
		CCLOG_IF(debug_print, "isReconnect=%d", isReconnect);
		if (!m_isSucces)
		{
		   bool tmpIsReconnect = isReconnect;
		   isReconnect = false;
		   close(WWSS_SHAKEHAND_FAIL);
		   if (tmpIsReconnect)
		   {
			   if (m_oSocket.ccIsConnected())
			   {
				   m_eStatus = WWSS_CONNECTING;
			   }
		   }
		}
		else
		{
		   channelID = tmpChannelID;
		   // setReconnect(true);
		   m_connectFailFlag = false;
		}
		reconnectFlag = false;
		m_sendMsg_Id = send_id;
		break;
	}
	case 0x12010A:
	{
		printExEx(WWLC_GREEN, "Niya WWNetwork PushIP %s:%d", m_oInetAddress.getIp(), m_oInetAddress.getPort());
		CCLOG_IF(debug_print, "push ips and ports");
		IPPoolData data;
		int ipNum = oBuffer.readShort();
		for (int i = 0; i < ipNum; i++)
		{
			std::string str = oBuffer.readLengthAndString();
			printExEx(WWLC_GREEN, "Niya wwIPPool Save IP %s", str.c_str());
			data.ips.push_back(str);
		}
		int portNum = oBuffer.readShort();
		for (int i = 0; i < portNum; i++)
		{
			 int n = oBuffer.readInt();
			 printExEx(WWLC_GREEN, "Niya WWNetwork Push Port %d", n);
			 data.pts.push_back(n);
		}
		WWIPPool::savePool(data);
		break;
	}
	default:
		oBuffer.resetReaderIndex();
		CCLOG_IF(debug_print, "", msgType);
		printExEx(WWLC_GREEN, "Niya WWNetwork MSG TYPE %d", msgType);
		if (m_netEventDelegate)m_netEventDelegate->onReceivedData(&oBuffer);
		break;
	}
}

bool WWNetwork::runRead()
{
	int nRet = m_oSocket.ccRead(m_pReadBuffer, SOCKET_READ_BUFFER_SIZE);

	if (nRet == WWSS_IO_ERROR || nRet == WWSS_IO_CLOSE)
	{
		stopScheduler();
		m_oSocket.ccClose();
		m_eStatus = WWSS_IO_CLOSE;
		onDisconnected();
		return true;
	}
	else
	{
#if DEBUG_LOG_READ > 1
		CCLOG_IF(debug_print, "WWSOCKET READ LEN %d", nRet);
		std::string recvType = " ";
		std::string str = "";
		for (int i = 0; i < nRet; ++i)
		{
			if (i > 3 && i < 7)
			{
				recvType += StringUtils::format(":%x", m_pReadBuffer[i]);
			}
			str += StringUtils::format(":%x", m_pReadBuffer[i]);
		}
		CCLOG_IF(debug_print, "WWSOCKET READ RecvType= %s", recvType.c_str());
		CCLOG_IF(debug_print, "WWSOCKET READ %s", str.c_str());
#elif  DEBUG_LOG_READ > 0
		CCLOG_IF(debug_print, "WWSOCKET READ LEN %d", nRet);
#endif
		m_oReadBuffer.writeData(m_pReadBuffer, nRet);
#if USING_PACKAGE_HEAD_LENGTH
		while (m_oReadBuffer.isReadable(sizeof(unsigned short)))
		{
			m_oReadBuffer.moveReaderIndexToFront();
			int n_msg_len = m_oReadBuffer.readUShort();
			int n_head_len = (int)(sizeof(unsigned short));
			if (n_msg_len <= 0)
			{
				CCLOGERROR("invalidate msg length");
				m_oReadBuffer.moveLeft(n_head_len);
			}

			if (n_msg_len >= 0xFFFF)
			{
				if (!m_oReadBuffer.isReadable(sizeof(int)))
				{
					break;
				}
				n_head_len += (int)(sizeof(int));
				n_msg_len = m_oReadBuffer.readInt();

				if (n_msg_len <= 0)
				{
					CCLOGERROR("invalidate msg length");
					m_oReadBuffer.moveLeft(n_head_len);
				}
			}
			if (!m_oReadBuffer.isReadable(2 * sizeof(char)))
			{
				break;
			}
			n_msg_len += (int)(2 * sizeof(char));

			CCLOG_IF(debug_print, "n_head_len = %d", n_head_len);
			CCLOG_IF(debug_print, "n_msg_len = %d", n_msg_len);

			int n_content_len = (int)m_oReadBuffer.length();
	
			if (n_content_len - n_head_len >= n_msg_len)
			{
				m_oReadBuffer.moveLeft(n_head_len);
				WWBuffer* pData = m_oReadBuffer.readData(n_msg_len);			
				m_oReadBuffer.moveLeft(n_msg_len);
				m_oReadBuffer.moveReaderIndexToFront();
				m_oReadBuffer.moveWriterIndexToBack();
				//onMessageReceived(*pData);
				m_vecCacheBuffer.push(pData);
			}
			else
			{
				break;
			}
		}
#else
		WWBuffer* pData = (WWBuffer*)m_oReadBuffer.copy();
		pData->autorelease();
		m_oReadBuffer.clear();

		onMessageReceived(*pData);
#endif
	}
	return false;
}

bool WWNetwork::runWrite()
{
	_SENDBUFFER& tBuffer = m_lSendBuffers.front();
	if (!m_isSucces && tBuffer.nSendId != -2)
	{
		CCLOG_IF(debug_print, " return true m_isSucces=%d tBuffer.nSendId=%d", m_isSucces, tBuffer.nSendId);
		return false;
	}
	int nRet = m_oSocket.ccWrite(tBuffer.pBuffer + tBuffer.nOffset, tBuffer.nLength - tBuffer.nOffset);
#if DEBUG_LOG_WRITE>1
	CCLOG_IF(debug_print, "WWSOCKET WRITE __String LEN= %d", nRet);
	std::string str = "";
	std::string sendType = "";
	for (int i = 0; i < tBuffer.nLength; ++i)
	{
		if (i > 3 && i < 7)
		{
			sendType += StringUtils::format(":%x", tBuffer.pBuffer[i]);
		}
		str += StringUtils::format(":%x", tBuffer.pBuffer[i]);
	}
	CCLOG_IF(debug_print, "WWSOCKET WRITE SendType= %s", sendType.c_str());
	CCLOG_IF(debug_print, "WWSOCKET WRITE %s", str.c_str());
#elif DEBUG_LOG_WRITE>0
	CCLOG_IF(debug_print, "WWSOCKET WRITE LEN= %d", nRet);
#endif
	if (nRet == WWSS_IO_ERROR)
	{
		stopScheduler();
		m_oSocket.ccClose();
		m_eStatus = WWSS_IO_CLOSE;
		onDisconnected();
		return true;
	}
	else if (nRet == tBuffer.nLength - tBuffer.nOffset)
	{
		tBuffer.nOffset = 0;
		if (tBuffer.nSendId != -1 && tBuffer.nSendId != -2)
		{
			m_lSendBuffers_bak.push_back(tBuffer);
		}
		else
		{
			CC_SAFE_DELETE_ARRAY(tBuffer.pBuffer);
			tBuffer.pBuffer = nullptr;
		}
		m_lSendBuffers.pop_front();
	}
	else
	{
		tBuffer.nOffset += nRet;
	}
	return false;
}

void WWNetwork::threadSchedule()
{
	while (m_selfRun)
	{
		auto deltaTime = Director::getInstance()->getAnimationInterval();
		if (m_bRunSchedule)
		{
			for_each(stateHandlers.begin(), stateHandlers.end(), [this, deltaTime](WWNetworkStateHandler* handler)
			{
				m_mutex.try_lock();
				handler->performState(this, m_eStatus, deltaTime);
				m_mutex.unlock();
			});
		}
		std::this_thread::sleep_for(std::chrono::milliseconds((int)(deltaTime * 1000)));
	}
}

void WWNetwork::pushBak2SendFront()
{
	while (!m_lSendBuffers_bak.empty())
	{
		_SENDBUFFER& tBuffer = m_lSendBuffers_bak.back();
		m_sendMsg_Id = tBuffer.nSendId;
		m_lSendBuffers.push_front(tBuffer);
		m_lSendBuffers_bak.pop_back();
	}
}

void WWNetwork::removeBakBySendId(int m_sendMsg_Id)
{
	std::list<_SENDBUFFER>::iterator it;
	for (it = m_lSendBuffers_bak.begin(); it != m_lSendBuffers_bak.end();)
	{
		if (it->nSendId == m_sendMsg_Id)
		{
			CC_SAFE_DELETE_ARRAY(it->pBuffer);
			it = m_lSendBuffers_bak.erase(it);
		}
		else
		{
			++it;
		}
	}
}

bool WWNetwork::handleNewSocketAddr(const char *pData, int len, char *ip, int &port)
{
	WWBuffer *buf = WWBuffer::create(pData, len);
	int type = buf->readChar3ToInt();
	CCLOG_IF(debug_print, " handleNewSocketAddr type=%x", type);
	std::string addr_1 = buf->readLengthAndString(); 
	std::string addr_2 = buf->readLengthAndString(); 
	std::string addr_3 = buf->readLengthAndString(); 
	std::string addr_4 = buf->readLengthAndString(); 
	CCLOG_IF(debug_print, "adddr_1(%s),adddr_2(%s),adddr_3(%s),adddr_4(%s)", addr_1.c_str(), addr_2.c_str(), addr_3.c_str(), addr_4.c_str());

	std::string socket_addr;
	if (IPhoneTool::getInstance()->isMobileConnected())
	{
		if (IPhoneTool::getInstance()->isYDOperator())
		{
			socket_addr = addr_2;
		}

		if (IPhoneTool::getInstance()->isLTOperator())
		{
			socket_addr = addr_3;
		}

		if (IPhoneTool::getInstance()->isDXOperator())
		{
			socket_addr = addr_4;
		}
	}
	else
	{
		socket_addr = addr_4;
	}

	//	socket_addr = addr_1;
	if (strcmp(m_oInetAddress.getHostAddress(), socket_addr.c_str()) == 0)
	{
		return false;
	}

	int pos = socket_addr.find(":");
	std::string strIp = socket_addr.substr(0, pos);
	std::string strPort = socket_addr.substr(pos + 1, socket_addr.length() - pos - 1);

	CCLOG_IF(debug_print, "strIp(%s), strPort(%s)", strIp.c_str(), strPort.c_str());
	strcpy(ip, strIp.c_str());
	port = atoi(strPort.c_str());
	return true;
}

void WWNetwork::netException(WWSocketStatus eStatus)
{
	CCLOG_IF(debug_print, "WWNetwork::netExceptiont[eStatus %d  m_connectFailedCount %d ]", eStatus, m_connectFailedCount);
	if (WWSS_CONNECT_FAIL == eStatus)
	{
		CC_ASSERT(m_netEventDelegate);
		if (m_connectFailedCount < CONNECT_FAIL_CHANGE - 2 && IPhoneTool::getInstance()->checkNetState().empty())
		{
			m_netEventDelegate->onExceptionCaught(NetStatueClose);
			m_connectFailFlag = true;
			m_reconnectTimePoint = std::chrono::steady_clock::now();
		} 
		else
		{
			if (m_connectFailedCount > 0)
			{
				if (m_connectFailedCount == CONNECT_FAIL_CHANGE)
				{
					m_netEventDelegate->reConnect(0.f);
				} 
				else 
				{
					m_netEventDelegate->reConnect();
				}
				
				m_connectFailedCount--;
				CCLOG_IF(debug_print,"onExceptionCaught:reConnect[%d]", m_connectFailedCount);
				this->connect();
				return;
			}

			m_connectFailedCount = CONNECT_FAIL_CHANGE;
			CCLOG_IF(debug_print,"onExceptionCaught: m_connectFailedCount[%d]", m_connectFailedCount);
			m_netEventDelegate->onExceptionCaught(NetStatueClose);
			m_connectFailFlag = true;
			m_reconnectTimePoint = std::chrono::steady_clock::now();
		}
		return;
	}
	CCLOG_IF(debug_print,"WWNetManager  onExceptionCaught %d", (int)eStatus);
	onDisconnected();
}

void WWNetwork::onComeToBackgroundEvent(cocos2d::EventCustom *pEvent)
{
	if (m_connectFailFlag) return;
	m_connectFailFlag = true;
	m_reconnectTimePoint = std::chrono::steady_clock::now();
}