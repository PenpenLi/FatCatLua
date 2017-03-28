/*! @file
 ********************************************************************************
 <PRE>
 模块名       :  系统工具类
 文件名       :  WWTools.h
 文件实现功能 :	live800  网页活动 充值接口
 作者         :  diyal.yin
 版本         :  1.0
 Copyright (c)  WaWaGame Technologies
 --------------------------------------------------------------------------------
 修改记录 :
 日 期        版本     修改人              修改内容
 2016/8/20   1.0     diyal.yin		      新建
 </PRE>
 *******************************************************************************/
#ifndef _WWTools_H_
#define _WWTools_H_

#include "cocos2d.h"

#include "network/HttpClient.h"

class WWTools : public cocos2d::Ref
{
private:
    
	WWTools(void);
	~WWTools(void);

public:
	static WWTools* getInstance()
	{
		if( !m_pInstance )
			m_pInstance = new WWTools();
		return m_pInstance;
	}

	static void release()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance=nullptr;
		}
	}
    
    std::vector<std::string> splitByArr(std::string src, std::string separate_character);

private:
    static WWTools* m_pInstance;
    
};

#endif

