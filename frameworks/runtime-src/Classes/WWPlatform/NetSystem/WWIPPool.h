#pragma once
//*******************************
//Name:WWIPPool.h
//Desc:IP Pool
//Auth:Wawa
//Date:20161214
//*******************************

#include "cocos2d.h"

typedef std::vector<int>			vecInt;
typedef std::vector<std::string>	vecStr;

typedef struct IPPoolData
{
	vecStr ips;
	vecInt pts;
	IPPoolData(){};
	IPPoolData(vecStr _ips, vecInt _pts){ips = _ips; pts = _pts; }
	void setPoolData(vecStr _ips, vecInt _pts){ ips = _ips; pts = _pts; }
}IPPoolData;

class WWIPPool
{
public:
	static bool loadPool(IPPoolData& data);
	static bool savePool(IPPoolData& data);
};