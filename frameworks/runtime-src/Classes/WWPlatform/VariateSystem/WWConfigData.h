#pragma once
#include "cocos2d.h"
#include <vector>

typedef enum SystemID
{
	SYSTEM_NULL, 
	SYSTEM_SOUND, //声音系统
	SYSTEM_NET,//网络系统
	SYSTEM_UPGRADE,//更新系统
	SYSTEM_EVENTSYSTEM,//事件系统
	SYSTEM_ENGINE//平台系统
};

struct WWSystemItem;
//蛙蛙系统配置
typedef struct WWSystemConfig
{
	SystemID sid;
	const char* name;
	const char* desc;
	std::vector<WWSystemItem*> items;
	WWSystemConfig()
	{
		sid = SYSTEM_NULL;
		name = nullptr;
		desc = nullptr;

	}

};
//
typedef struct WWSystemItem
{
	const char* name;
	std::vector<std::string> values;
	WWSystemItem()
	{
		name = nullptr;
	}
};



inline WWSystemItem* findSystemItemByName(std::vector<WWSystemItem*>& items, const char* fieldName)
{
	std::vector<WWSystemItem*>::iterator it = std::find_if(items.begin(), items.end(), [fieldName](WWSystemItem* i)
	{
		if (strcmp(i->name, fieldName) == 0)
		{
			return true;
		}
		return false;

	});
	if (it != items.end())
	{
		return *it;
	}
	return nullptr;
}
