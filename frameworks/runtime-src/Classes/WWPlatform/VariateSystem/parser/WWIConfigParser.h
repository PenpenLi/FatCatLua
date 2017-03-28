#pragma once

/*! @file
********************************************************************************
<PRE>
模块名       :  模块配置解析基类
文件名       :  WWIConfigParser.h
文件实现功能 :
作者         :  cruelogre  546761316@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/7/13   1.0     cruelogre		      新建
</PRE>
*******************************************************************************/

#include "tinyxml2/tinyxml2.h"
#include "../WWConfigData.h"
class WWIConfigParser
{
public:
	/**
	*	解析模块配置
	*@param wwsConfig 模块配置数据
	*@param XMLElement 节点
	*/
	virtual void parse(WWSystemConfig & wwsConfig, tinyxml2::XMLElement* element) = 0;
};