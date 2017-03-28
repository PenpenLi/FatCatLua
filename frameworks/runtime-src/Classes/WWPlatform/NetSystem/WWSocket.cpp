#include "WWSocket.h"

WWSocket::WWSocket()
: m_uSocket(INVALID_SOCKET)
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	static bool bStartup = false;
	if (!bStartup)
	{
		bStartup = true;
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);
	}
#endif
}

void WWSocket::ccClose()
{
	if (m_uSocket != INVALID_SOCKET)
	{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
		closesocket(m_uSocket);
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		close(m_uSocket);
#endif
		m_uSocket = INVALID_SOCKET;
	}
}

bool WWSocket::ccInit()
{
	ccClose();

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	m_uSocket = socket((isIPV6Net() ? AF_INET6 : AF_INET), SOCK_STREAM, IPPROTO_TCP);
#else
	m_uSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
#endif
	//end diyal.yin 2016-06-07
	if (m_uSocket == INVALID_SOCKET)
	{
		CCLOGERROR("create socket failed");
		return false;
	}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	unsigned long ul = 1;
	int nRet = ioctlsocket(m_uSocket, FIONBIO, (unsigned long*)&ul);
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	int nFlags = fcntl(m_uSocket, F_GETFL, 0);
	int nRet = fcntl(m_uSocket, F_SETFL, nFlags | O_NONBLOCK);
#endif
	if (nRet == SOCKET_ERROR)
	{
		CCLOGERROR("set unblocking failed");
		ccClose();
		return false;
	}

	int nNoDelay = 1;
	if (setsockopt(m_uSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&nNoDelay, sizeof(nNoDelay)) == SOCKET_ERROR)
	{
		CCLOGERROR("set nodelay failed");
		ccClose();
		return false;
	}

	//int bDontLinger = 0;
	//if (setsockopt(m_uSocket, SOL_SOCKET, SO_DONTLINGER, (char*)&bDontLinger, sizeof(int)) == SOCKET_ERROR)
	//if (setsockopt(m_uSocket, SOL_SOCKET, int(~(0x0080)), (char*)&bDontLinger, sizeof(int)) == SOCKET_ERROR)
	//{
	//	CCLOGERROR("set dontlinger failed");
	//	ccClose();
	//	return false;
	//}

	return true;
}

bool WWSocket::ccConnect()
{
	if (strlen(m_oInetAddress.getIp()) == 0 || m_oInetAddress.getPort() == 0) return false;

	if (m_uSocket == INVALID_SOCKET)
	{
		if (!ccInit()) return false;
	}

	int nRet = ::connect(m_uSocket, m_oInetAddress.getSockaddr(), m_oInetAddress.getLength());
	if (nRet == 0)
	{
		printExEx(WWLC_GREEN, "Niya WWSocket ccConnect Return = 0 %s:%d\n", m_oInetAddress.getIp(), m_oInetAddress.getPort());
		return true;
	}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	int nError = WSAGetLastError();
	printExEx(WWLC_RED, "Niya WWSocket ccConnect Watting %s:%d, %d\n", m_oInetAddress.getIp(), m_oInetAddress.getPort(), nError);
	return nError == WSAEWOULDBLOCK;
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	printExEx(WWLC_RED, "Niya WWSocket ccConnect Watting %s:%d, %d\n", m_oInetAddress.getIp(), m_oInetAddress.getPort(), errno);
	return (m_uSocket == SOCKET_ERROR && errno == EINPROGRESS);
#endif
}

int WWSocket::ccIsConnected()
{
	if (m_uSocket == INVALID_SOCKET) return WWSS_CONNECT_FAIL;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	fd_set	fd;
	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if (select((int)(m_uSocket + 1), NULL, &fd, NULL, &tv) > 0)
	{
		if (FD_ISSET(m_uSocket, &fd))
		{
			return WWSS_CONNECTED;
		}
	}
	return WWSS_CONNECTING;

#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	fd_set	fd;
	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);
	fd_set	rd;
	FD_ZERO(&rd);
	FD_SET(m_uSocket, &rd);
	struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	int ret = select((int)(m_uSocket + 1), &rd, &fd, NULL, &tv);
	printExEx(WWLC_YELLOW, "Niya WWSocket ccIsConnected Ret = %d", ret);
	if (ret < 0 )
	{
		return WWSS_CONNECTING;
	}
	if (ret == 0)
	{
		return WWSS_CONNECT_FAIL;
	}
	if (!FD_ISSET(m_uSocket, &fd))
	{
		return WWSS_CONNECTING;
	}
	if (FD_ISSET(m_uSocket, &rd))
	{
		//return WWSS_CONNECT_FAIL;
	}
	sockaddr sa;
	//int len = sizeof(sa);
	//int pr = getpeername(m_uSocket, &sa, &len);
	int nError;
	socklen_t l = sizeof(nError);
	int r = getsockopt(m_uSocket, SOL_SOCKET, SO_ERROR, &nError, &l);
	printExEx(WWLC_YELLOW, "Niya WWSocket ccIsConnected W R = %d Error = %d errno = %d", r, nError, errno);
	bool f = ( nError == EINVAL || nError == ECONNREFUSED || nError == ETIMEDOUT || nError == EHOSTUNREACH || nError == ENETUNREACH ||
		 /*errno == ECONNREFUSED || errno == ETIMEDOUT || errno == EHOSTUNREACH || errno == ENETUNREACH ||*/ r < 0 );
	return f ? WWSS_CONNECT_FAIL : WWSS_CONNECTED;
#endif
}

bool WWSocket::ccIsReadable()
{
	if (m_uSocket == INVALID_SOCKET) return false;
	fd_set	fd;
	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if (select((int)(m_uSocket + 1), &fd, NULL, NULL, &tv) > 0)
	{
		if (FD_ISSET(m_uSocket, &fd))
		{
			return true;
		}
	}
	return false;
}

bool WWSocket::ccIsWritable()
{
	if (m_uSocket == INVALID_SOCKET) return false;
	fd_set	fd;
	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if (select((int)(m_uSocket + 1), NULL, &fd, NULL, &tv) > 0)
	{
		if (FD_ISSET(m_uSocket, &fd))
		{
			return true;
		}
	}
	return false;
}

int WWSocket::ccRead(char* _buff, int _len)
{
	if (m_uSocket == INVALID_SOCKET) return WWSS_IO_ERROR;
	return ::recv(m_uSocket, _buff, _len, 0);
}

int WWSocket::ccWrite(char* _buff, int _len)
{
	if (m_uSocket == INVALID_SOCKET) return WWSS_IO_ERROR;
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return ::send(m_uSocket, _buff, _len, 0);
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	return ::send(m_uSocket, _buff, _len, SO_NOSIGPIPE);
#endif
}

void WWSocket::ccShutdown()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	shutdown((int)m_uSocket, SHUT_RDWR);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	ccClose();
#endif
}

