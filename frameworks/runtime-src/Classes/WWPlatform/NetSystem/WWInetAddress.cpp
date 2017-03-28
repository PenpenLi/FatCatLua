#include "WWInetAddress.h"

WWInetAddress::WWInetAddress()
{
	addr_v4.sin_family = AF_INET;
	addr_v4.sin_addr.s_addr = INADDR_ANY;
	addr_v4.sin_port = 0;
	memset(addr_v4.sin_zero, 0, 8);

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	m_isNetWorkIpv6 = isIPV6Net();
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	bzero(&addr_v6, sizeof(addr_v6));
	addr_v6.sin6_len = sizeof(struct sockaddr_in6);
	addr_v6.sin6_family = AF_INET6;
	addr_v6.sin6_port = 0;
	addr_v6.sin6_flowinfo = 0;
	addr_v6.sin6_addr = in6addr_any;
	addr_v6.sin6_scope_id = 0;
#endif
}

WWInetAddress::WWInetAddress(const char* ip, unsigned short port)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	m_isNetWorkIpv6 = isIPV6Net();
	if (m_isNetWorkIpv6)
	{
		bzero(&addr_v6, sizeof(addr_v6));
		addr_v6.sin6_family = AF_INET6;
		addr_v6.sin6_port = htons(port);
		inet_pton(AF_INET6, ip, &addr_v6.sin6_addr);
	} 
	else
	{
#endif
		addr_v4.sin_family = AF_INET;
		addr_v4.sin_addr.s_addr = inet_addr(ip);
		addr_v4.sin_port = htons(port);
		memset(addr_v4.sin_zero, 0, 8);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	}
#endif
}

WWInetAddress::WWInetAddress(const struct sockaddr * addr)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	m_isNetWorkIpv6 = isIPV6Net();
#endif
	memcpy(&addr_v4.sin_family, addr, sizeof(struct sockaddr));
}

WWInetAddress::operator struct sockaddr*()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return (struct sockaddr *)(&addr_v4.sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	return m_isNetWorkIpv6 ? (struct sockaddr*)&addr_v6.sin6_len : (struct sockaddr *)(&addr_v4.sin_len);
#endif
}

WWInetAddress::operator const struct sockaddr*() const
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return (const struct sockaddr *)(&addr_v4.sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	return m_isNetWorkIpv6 ? (const struct sockaddr*)&addr_v6.sin6_len : (const struct sockaddr *)(&addr_v4.sin_len);
#endif
}

const char* WWInetAddress::getHostAddress() const
{
	static char addr[64];
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	sprintf_s(addr, 64, "%s:%u", inet_ntoa(addr_v4.sin_addr), getPort());
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	snprintf(addr, 64, "%s:%u", inet_ntoa(addr_v4.sin_addr), getPort());
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	if (m_isNetWorkIpv6)
	{
		char addrStr[INET6_ADDRSTRLEN];
		inet_ntop(AF_INET6, (void *)&addr_v6.sin6_addr, addrStr, INET6_ADDRSTRLEN);
		snprintf(addr, 64, "%s:%u", addrStr, getPort());
	} 
	else
	{
		snprintf(addr, 64, "%s:%u", inet_ntoa(addr_v4.sin_addr), getPort());
	}

#endif
	return addr;
}

const char* WWInetAddress::getIp() const
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	if (m_isNetWorkIpv6)
	{
		static char addrStr[INET6_ADDRSTRLEN];
		inet_ntop(AF_INET6, (void *)&addr_v6.sin6_addr.s6_addr, addrStr, INET6_ADDRSTRLEN);
		return addrStr;
	}
#endif

	return inet_ntoa(addr_v4.sin_addr);
}

struct sockaddr* WWInetAddress::getSockaddr() const
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	return m_isNetWorkIpv6 ? (struct sockaddr*)&addr_v6 : (struct sockaddr*)&addr_v4;
#else
	return (struct sockaddr*)&addr_v4;
#endif
}

unsigned short WWInetAddress::getPort() const
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	return m_isNetWorkIpv6 ? ntohs(addr_v6.sin6_port) : ntohs(addr_v4.sin_port);
#else
	return ntohs(addr_v4.sin_port);
#endif
}

void WWInetAddress::setIp(const char* ip)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	if (m_isNetWorkIpv6)
	{
		inet_pton(AF_INET6, ip, &addr_v6.sin6_addr);
	} 
	else
	{
#endif
		addr_v4.sin_addr.s_addr = inet_addr(ip);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	}
#endif
}

void WWInetAddress::setIp(unsigned int ip)
{
	addr_v4.sin_addr.s_addr = ip;
}

void WWInetAddress::setPort(unsigned short port)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	if (m_isNetWorkIpv6)
	{
		addr_v6.sin6_port = htons(port);
	} 
	else
	{
#endif
		addr_v4.sin_port = htons(port);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	}
#endif
}

void WWInetAddress::setHost(const char* name)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	if (m_isNetWorkIpv6)
	{
		struct addrinfo hint;
		memset(&hint, 0x0, sizeof(hint));
		hint.ai_family = AF_INET6;
		hint.ai_flags = AI_V4MAPPED;

		addrinfo* answer = nullptr;
		getaddrinfo(name, nullptr, &hint, &answer);

		if (answer != nullptr)
		{
			char hostname[1025] = "";

			getnameinfo(answer->ai_addr, answer->ai_addrlen, hostname, 1025, nullptr, 0, 0);

			char ipv6[128] = "";
			memcpy(ipv6, hostname, 128);

			inet_pton(AF_INET6, ipv6, &addr_v6.sin6_addr);
		}

		freeaddrinfo(answer);
	} else
	{
#endif
		hostent* h = gethostbyname(name);
		if (h != NULL)
		{
			addr_v4.sin_addr.s_addr = *((u_long *)h->h_addr_list[0]);
		}
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	}
#endif
}

int WWInetAddress::getLength()
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	return m_isNetWorkIpv6 ? sizeof(sockaddr_in6) : sizeof(sockaddr_in);
#else
	return sizeof(sockaddr_in);
#endif
}

std::vector< WWInetAddress> WWInetAddress::genInetAddrs(const std::vector<std::string> &ips, const std::vector<int> &ports)
{
	std::vector<WWInetAddress> ret;
	for (auto &ip : ips)
	{
		WWInetAddress inetAddr;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		if (isIPV6Net())
		{
			inetAddr.setIp(AddrToIP(ip.c_str()).c_str());
		}
		else
		{
#endif
			auto hostInfo = gethostbyname(ip.c_str());
			if (hostInfo)
			{
				inetAddr.setIp(inet_ntoa(*((struct in_addr *)hostInfo->h_addr)));
			}
			else
			{
				inetAddr.setIp(ip.c_str());
			}
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		}
#endif
		for (auto &port : ports)
		{
			WWInetAddress inetItem;
			inetItem.setIp(inetAddr.getIp());
			inetItem.setPort(port);
			ret.push_back(inetItem);
		}
	}
	return ret;
}
