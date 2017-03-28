#pragma once

/*! @file
********************************************************************************
<PRE>
模块名       :  模块配置管理器
文件名       :  WWConfigManager.h
文件实现功能 :	框架中所有关于模块配置的管理器，游戏中业务逻辑的配置放在lua层实现
作者         :  cruelogre  546761316@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/7/13   1.0     cruelogre		      新建
</PRE>
*******************************************************************************/

#include "cocos2d.h"
#include "../WWMacros.h"
#include "WWConfigData.h"
#include "parser/WWIConfigParser.h"

USING_NS_CC;
using namespace std;

class WWConfigManager
{
public:
	WWConfigManager();
	~WWConfigManager();
	SINGLE_INSTANCE_FUNC(WWConfigManager);

	void initConfig(const char* filepath);

	/**
	* 通过模块获取配置                                             
	*@param sid 模块编号
	*@return 模块配置
	**/
	WWSystemConfig getModuleConfig(const SystemID& sid);
private:
	//初始化所有的模块解析工具
	void init();
	/**
	*  初始化其他模块
	*
	**/
	void initOtherSystem();
private:
	std::map<SystemID, WWSystemConfig> configItems;
	//
	std::map<SystemID, WWIConfigParser*>configParsers;
};

