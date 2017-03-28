#pragma once

/*! @file
********************************************************************************
<PRE>
模块名       :  帧动画管理器
文件名       :  WWAnimatePacker.h
文件实现功能 :  使用animatepacker工具制作帧动画文件，游戏中直接使用该生成文件
作者         :  cruelogre  546761316@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/7/18   1.0     cruelogre		      新建
</PRE>
*******************************************************************************/

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
#include "../WWMacros.h"

using namespace cocos2d;
using namespace std;

struct WWLTAnimate {
	std::string name;
	float delay;
	bool flipX;
	bool flipY;
	std::vector<std::string> spriteFrames;
};
class WWAnimatePacker
{
public:
	
	SINGLE_INSTANCE_FUNC(WWAnimatePacker);

public:
	WWAnimatePacker();

	/************************************************************************/
	/*
	name 文件名字
	animname 动作名字，如果动作名字为空，那么表示这个文件只有一个动作，在name中表示
	*/
	/************************************************************************/
	cocos2d::Animate* getAnimate(const char *name, const char* animname = NULL);
protected:

	void loadAnimations(const char *path);

private:
	//解析xml
	vector<string> m_pPlists;
	vector<WWLTAnimate>m_pAnimates;

};

