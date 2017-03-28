#include "WWNetworkStateHandler.h"
#include "WWNetwork.h"
#include "WWBuffer.h"

bool WWNetworkStateHandler::performState(WWNetwork* sock, WWSocketStatus inputState, float dt)
{
	if (m_avaliableStates.empty()) return false;
	return std::find(m_avaliableStates.begin(), m_avaliableStates.end(), inputState) != m_avaliableStates.end();
}

WWNetWorkStateReadHandler::WWNetWorkStateReadHandler()
{
	m_avaliableStates.push_back(WWSocketStatus::WWSS_CONNECTING);
}

bool WWNetWorkStateReadHandler::pushMsgSH(WWNetwork* network)
{
	WWBuffer *pBuffer = WWBuffer::create();
	network->onConnected(pBuffer);
	if (pBuffer->empty() || !network->isConnected())
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
	network->m_lSendBuffers.push_front(tBuf);
	return false;
}

bool WWNetWorkStateReadHandler::performState(WWNetwork* network, WWSocketStatus inputState, float dt)
{
	if (!WWNetworkStateHandler::performState(network, inputState, dt)) return false;

	auto ret = network->m_oSocket.ccIsConnected();
	switch (ret)
	{
		case WWSS_CONNECTED:
		{
			printExEx(WWLC_GREEN, "Niya WWNetWorkStateReadHandler Success %s:%d", network->getInetAddress().getIp(), network->getInetAddress().getPort());
			network->m_eStatus = WWSS_CONNECTED;
			network->pushBak2SendFront();
			pushMsgSH(network);
			break;
		}
		case WWSS_CONNECT_FAIL:
		{
			printExEx(WWLC_RED, "Niya WWNetWorkStateReadHandler Failure %s:%d", network->getInetAddress().getIp(), network->getInetAddress().getPort());
			network->stopScheduler();
			network->m_oSocket.ccClose();
			network->m_eStatus = WWSS_CONNECT_FAIL;
			network->removeIP(string(network->getInetAddress().getIp()));
			if (!network->toConnect())
			{
				network->requestNewSocketAddress();
			}
			break;
		}
		case WWSS_CONNECTING:
		{
			if (network->m_fConnectingDuration < network->m_fSoTimeout)
			{
				network->m_fConnectingDuration += dt;
			} 
			else
			{
				printExEx(WWLC_RED, "Niya WWNetWorkStateReadHandler Timeout %s:%d", network->getInetAddress().getIp(), network->getInetAddress().getPort());
				network->stopScheduler();
				network->m_oSocket.ccClose();
				network->m_eStatus = WWSS_CONNECT_TIMEOUT;
				network->m_fConnectingDuration = 0.0f;
				network->removeIP(string(network->getInetAddress().getIp()));
				if (!network->toConnect())
				{
					network->requestNewSocketAddress();
				}
			}
			break;
		}
	default:
		break;
	}
	return true;
}

WWNetWorkStateWriteHandler::WWNetWorkStateWriteHandler()
{
	m_avaliableStates.push_back(WWSocketStatus::WWSS_CONNECTED);
}

bool WWNetWorkStateWriteHandler::pushMsg(WWNetwork* sock)
{
	WWBuffer* pBuffer = WWBuffer::create();
	sock->onHeartBeatMsg(pBuffer);
	if (pBuffer->empty() || !sock->isConnected())
	{
		pBuffer->toRelease();
		return true;
	}
	int u_len = pBuffer->length();
	pBuffer->moveRight((int)(2 * sizeof(char)));
	pBuffer->moveWriterIndexToFront();
	pBuffer->writeChar((char)sock->m_recvMsg_Id);
	pBuffer->writeChar((char)sock->m_sendMsg_Id);
#if USING_PACKAGE_HEAD_LENGTH
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
	tBuf.nSendId = -1;
	sock->m_lSendBuffers.push_back(tBuf);
	sock->m_heartBeatMsgDuration = 0.0f;
	sock->m_isHeartMsgSend = true;
	return false;
}

bool WWNetWorkStateWriteHandler::performState(WWNetwork* network, WWSocketStatus inputState, float dt)
{
	if (!WWNetworkStateHandler::performState(network, inputState, dt)) return false;

	if (network->m_fDataReciveDelayDuration > network->m_fDataReciveDelayTime)
	{
		CCLOG("m_fDataReciveDelayDuration > RECIVE_DATA_DELAY_TIME");
		network->stopScheduler();
		network->m_oSocket.ccDisconnect();
		network->m_eStatus = WWSS_RECV_TIMEOUT;
		network->onDisconnected();
		network->m_fDataReciveDelayDuration = 0.0f;
		return true;
	}

	onRecv(network, dt);
	if (onRead(network))return true;

	if (network->m_lSendBuffers.empty() && network->m_heartBeatMsgDuration >= network->m_heartBeatDelay)
	{
		if (network->m_isHeartMsgSend)
		{
			if (network->m_netEventDelegate)
			{
				network->m_netEventDelegate->onExceptionCaught(NetStatueNoRsp);
			}
		}
		if (pushMsg(network))return true;
	} 
	else
	{
		network->m_heartBeatMsgDuration += dt;
	}

	onWrite(network);

	return true;
}

void WWNetWorkStateWriteHandler::onRecv(WWNetwork* sock, float dt)
{
	if (sock->m_oSocket.ccIsReadable())
	{
		sock->m_fDataReciveDelayDuration = 0.0f;
	}
	else
	{
		sock->m_fDataReciveDelayDuration += dt;
	}

	if (sock->m_vecCacheBuffer.size() > 0)
	{
		auto pData = sock->m_vecCacheBuffer.front();
		sock->onMessageReceived(*pData);
		sock->m_vecCacheBuffer.pop();
	}
}

bool WWNetWorkStateWriteHandler::onRead(WWNetwork* sock)
{
#if HANDLE_ON_SINGLE_FRAME
	while (m_oSocket.ccIsReadable())
#else
	if (sock->m_oSocket.ccIsReadable())
#endif
	{
		if (sock->runRead()) return true;
	}

	return false;
}

bool WWNetWorkStateWriteHandler::onWrite(WWNetwork* sock)
{
#if HANDLE_ON_SINGLE_FRAME
	while (sock->m_oSocket.ccIsWritable() && !sock->m_lSendBuffers.empty())
#else
	if (sock->m_oSocket.ccIsWritable() && !sock->m_lSendBuffers.empty())
#endif
	{
		if (sock->runWrite()) return true;

		sock->m_heartBeatMsgDuration = 0.0f;
	}
	return false;
}