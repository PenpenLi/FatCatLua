#pragma once

//*******************************
//Name:WWInetAddress.h
//Desc:Net Address
//Auth:Wawa
//Date:20161111
//Last:20170104
//*******************************

#include "WWNetMacros.h"

class WWInetAddress
{
public:
	WWInetAddress();
	WWInetAddress(const char* ip, unsigned short port);
	WWInetAddress(const struct sockaddr* addr);
	virtual ~WWInetAddress(){}

public:
	//多组IP和端口组成的排列组合
	static vector<WWInetAddress> genInetAddrs(const vector<std::string> &ips, const vector<int> &ports);

public:
	operator struct sockaddr*();
	operator const struct sockaddr*() const;
	const char* getHostAddress() const;
	const char* getIp() const;
	struct sockaddr* getSockaddr() const;
	unsigned short getPort() const;
	void setIp(const char* ip);
	void setIp(unsigned int ip);
	void setPort(unsigned short port);
	void setHost(const char* name);
	int getLength();

private:
	struct sockaddr_in addr_v4;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	struct sockaddr_in6 addr_v6;
	bool m_isNetWorkIpv6;
#endif
};

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
static bool isIPV6Net(const std::string domainStr = "www.baidu.com")
{
	bool isIPV6Net = false;
	struct addrinfo *result = nullptr, *curr;
	int ret = getaddrinfo(domainStr.c_str(), nullptr, nullptr, &result);
	if (ret == 0)
	{
		for (curr = result; curr != nullptr; curr = curr->ai_next)
		{
			switch (curr->ai_family)
			{
			case AF_INET6:
			{
							 isIPV6Net = true;
							 break;
			}
			default:
				break;
			}
		}
	}
	if (result)
	{
		freeaddrinfo(result);
	}
	return isIPV6Net;
}

static std::string domainToIP(const char* pDomain)
{
	if (isIPV6Net())
	{
		struct addrinfo hint;
		memset(&hint, 0x0, sizeof(hint));
		hint.ai_family = AF_INET6;
		hint.ai_flags = AI_V4MAPPED;
		addrinfo* answer = nullptr;
		getaddrinfo(pDomain, nullptr, &hint, &answer);
		if (nullptr != answer)
		{
			char hostname[1025] = "";
			getnameinfo(answer->ai_addr, answer->ai_addrlen, hostname, 1025, nullptr, 0, 0);
			char ipv6[128] = "";
			memcpy(ipv6, hostname, 128);
			CCLOG("domainToIP addrStr:%s", ipv6);
			return ipv6;
		}
		freeaddrinfo(answer);
	}
	else
	{
		struct hostent* h = gethostbyname(pDomain);
		if (!h)
		{
			unsigned char* p = (unsigned char *)(h->h_addr_list)[0];
			if (!p)
			{
				char ip[16] = { 0 };
				sprintf(ip, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
				return ip;
			}
		}
	}
	return "";
}

static std::string IP4ToIP6(string ip4)
{
	if(isIPV6Net())
	{
        std::string str = domainToIP("www.baidu.com");
		int pos = str.find("::");
		if(std::string::npos != pos)
		{
			auto sub = str.substr(0, pos + 2);
            return (sub + ip4);
		}
	}
	return "";
}

static std::string AddrToIP(std::string addr)
{
	if(isIPV6Net())
	{
		if (addr.empty()) return "";
		bool b6 = (std::string::npos != addr.find(":"));
		bool b4 = ('0' < addr[0] && addr[0] <= '9');
		if(b6)
		{
			return addr;
		}
		else if(b4)
		{
			return IP4ToIP6(addr);
		}
		else
		{
			return domainToIP(addr.c_str());
		}
	}
    return "";
}

#endif
