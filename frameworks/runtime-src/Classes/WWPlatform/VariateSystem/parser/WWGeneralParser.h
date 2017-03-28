#pragma once
/*! @file
********************************************************************************
<PRE>
模块名       :  通用模块解析类
文件名       :  WWGeneralParser.h
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

#include "WWIConfigParser.h"
class WWGeneralParser :public WWIConfigParser
{
public:
	WWGeneralParser();
	virtual ~WWGeneralParser();

	virtual void parse(WWSystemConfig & wwsConfig, tinyxml2::XMLElement* element);

};

