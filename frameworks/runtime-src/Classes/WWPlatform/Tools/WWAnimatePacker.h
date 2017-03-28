#pragma once

/*! @file
********************************************************************************
<PRE>
ģ����       :  ֡����������
�ļ���       :  WWAnimatePacker.h
�ļ�ʵ�ֹ��� :  ʹ��animatepacker��������֡�����ļ�����Ϸ��ֱ��ʹ�ø������ļ�
����         :  cruelogre  546761316@qq.com
�汾         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
�޸ļ�¼ :
�� ��        �汾     �޸���              �޸�����
2016/7/18   1.0     cruelogre		      �½�
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
	name �ļ�����
	animname �������֣������������Ϊ�գ���ô��ʾ����ļ�ֻ��һ����������name�б�ʾ
	*/
	/************************************************************************/
	cocos2d::Animate* getAnimate(const char *name, const char* animname = NULL);
protected:

	void loadAnimations(const char *path);

private:
	//����xml
	vector<string> m_pPlists;
	vector<WWLTAnimate>m_pAnimates;

};

