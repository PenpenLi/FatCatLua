#include "SocketParallelCheck.h"
#include "WWSocket.h"

#define DEFAULT_TIME_OUT 10.0f

#define CHANGE_CHECK_STATE(pData, stateType) \
{ \
	std::lock_guard<std::mutex> lck(pData->_mutex); \
	pData->_checkSuccessed = stateType; \
	pData->release(); \
}

SocketParallelCheck::SocketParallelCheck()
: m_isParalleling(false)
, m_threadExitTag(false)
, m_totalSchedulerTime(DEFAULT_TIME_OUT)
, m_timeout(0.0f)
, m_nTimeKey(0)
{
}

void SocketParallelCheck::setTimeout(float fTimeout)
{
	m_totalSchedulerTime = fTimeout > 0.0f ? fTimeout : DEFAULT_TIME_OUT;
}

bool SocketParallelCheck::setSocketInetAddrs(const std::vector< WWInetAddress>& inetAddrs)
{
	if (isParalleling()) return false;
	m_inetAddrs = inetAddrs;
	return true;
}

bool SocketParallelCheck::start()
{
	if (isParalleling()) return false;
	if (m_inetAddrs.empty()) return false;
	m_isParalleling = true;
	m_threadExitTag = false;
	generateSocketDatas();
	m_timeout = 0.0f;
	m_nTimeKey = 0;
	std::thread t(&SocketParallelCheck::threadStart, this);
	t.detach();
	for (auto &item : m_socketDatas) 
	{
		m_parallels.push_back(std::thread(&SocketParallelCheck::checkThreadFunc, this, item));
		m_parallels.back().detach();
	}
	return true;
}

bool SocketParallelCheck::end()
{
	if (!isParalleling()) return false;
	//Director::getInstance()->getScheduler()->unscheduleUpdate(this);
	m_isParalleling = false;
	m_threadExitTag = true;
	m_inetAddrs.clear();
	m_parallels.clear();
	m_socketDatas.clear();
	return true;
}

void SocketParallelCheck::threadStart()
{
	auto interval = Director::getInstance()->getAnimationInterval();
	int slp = 1000 * interval;
	while (!m_threadExitTag)
	{
		update(interval);
		std::this_thread::sleep_for(std::chrono::milliseconds(slp));
	}
}

void SocketParallelCheck::update(float deltaTime)
{
	m_timeout += deltaTime;
	if ((int)m_timeout > m_nTimeKey)
	{
		m_nTimeKey += 1;
		printExEx(WWLC_YELLOW, "Niya SocketParallelCheck Update Time %f", m_timeout);
	}
	
	bool checkSuccessMark = false;
	int checkFailCount = 0;
	WWInetAddress inetAddr = (*m_socketDatas.begin())->_inetAddr;
	for (auto &item : m_socketDatas) 
	{
		std::lock_guard<std::mutex> lck(item->_mutex);
		if (CheckStatusType::FAILURE == item->_checkSuccessed) 
		{
			checkFailCount++;
		}
		else if (CheckStatusType::SUCCESS == item->_checkSuccessed) 
		{
			checkSuccessMark = true;
			inetAddr = item->_inetAddr;
			break;
		}
	}

	bool isEnded = false;
	Statue resultStatue = Statue::TIMEOUT;
	if (checkSuccessMark)
	{
		printExEx(WWLC_GREEN, "Niya SocketParallelCheck Success %s:%d", inetAddr.getIp(), inetAddr.getPort());
		resultStatue = Statue::SUCCESS;
		isEnded = true;
	}
	if (checkFailCount == m_socketDatas.size())
	{
		printExEx(WWLC_RED, "Niya SocketParallelCheck Failure %s:%d", inetAddr.getIp(), inetAddr.getPort());
		resultStatue = Statue::FAILURE;
		isEnded = true;
	}
	if (m_timeout >= m_totalSchedulerTime)
	{
		printExEx(WWLC_RED, "Niya SocketParallelCheck Timeout %s:%d", inetAddr.getIp(), inetAddr.getPort());
		resultStatue = Statue::TIMEOUT;
		isEnded = true;
	}

	if (isEnded)
	{
		end();
		m_callback ? m_callback(resultStatue, inetAddr) : dispatchNetEventWithInetAddr(resultStatue, inetAddr);
	}
}

void SocketParallelCheck::checkThreadFunc(SocketData *pData)
{
	if (m_threadExitTag) 
	{
		printExEx(WWLC_RED, "Niya SocketParallelCheck Thread Exit %s:%d\n", pData->_inetAddr.getIp(), pData->_inetAddr.getPort());
		CHANGE_CHECK_STATE(pData, CheckStatusType::FAILURE);
		return;
	}

	WWSocket _socket;
	_socket.setInetAddress(pData->_inetAddr);
	_socket.ccConnect();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	while (true) 
	{
		if (m_threadExitTag) 
		{
			printExEx(WWLC_RED, "Niya SocketParallelCheck Thread Exit1 %s:%d\n", pData->_inetAddr.getIp(), pData->_inetAddr.getPort());
			CHANGE_CHECK_STATE(pData, CheckStatusType::FAILURE);
			_socket.ccShutdown();
			break;
		}
		auto connectStatus = _socket.ccIsConnected();
		if (WWSS_CONNECTED == connectStatus) 
		{
			printExEx(WWLC_GREEN, "Niya SocketParallelCheck Thread Success %s:%d", pData->_inetAddr.getIp(), pData->_inetAddr.getPort());
			CHANGE_CHECK_STATE(pData, CheckStatusType::SUCCESS);
			_socket.ccShutdown();
			break;
		}
		else if (WWSS_CONNECT_FAIL == connectStatus) 
		{
			printExEx(WWLC_RED, "Niya SocketParallelCheck Thread Failure %s:%d", pData->_inetAddr.getIp(), pData->_inetAddr.getPort());
			CHANGE_CHECK_STATE(pData, CheckStatusType::FAILURE);
			_socket.ccShutdown();
			break;
		}
		// sleep for 1 millisecond to let other thread to execute
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void SocketParallelCheck::generateSocketDatas()
{
	m_socketDatas.clear();
	for (auto &item : m_inetAddrs) 
	{
		SocketData *pData = new SocketData(item);
		pData->retain();
		m_socketDatas.push_back(pData);
	}
}

void SocketParallelCheck::dispatchNetEventWithInetAddr(Statue val, const WWInetAddress &inetAddr)
{
	Director::getInstance()->getScheduler()->performFunctionInCocosThread([this, val, &inetAddr]() 
	{
		std::tuple<Statue, const WWInetAddress*> data = std::make_tuple(val, &inetAddr);
		cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("Event_ParallelLordNetResult", &data);
	});
}
