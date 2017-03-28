/*! @file
********************************************************************************
<PRE>
模块名       :  自定义富文本标签
文件名       :  SuperRichText.h
文件实现功能 :  
作者         :  Diyal  670924505@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
  一、继承LayoutColor, ignoreAnchorPointForPosition设置为false(默认)，则锚点为中心点，
  否则为原点。如果要设置背景，需要将opacity设置为255

  作为一个基本控件，大小一开始应该固定，所以我在这里设计的时候，希望宽度至少是要固定的。高度可以预设值，
  高度会跟类容向下扩展。避免一些不必要的内容自适应的处理。

  二、Html配置 API
  根据HTML标签来配置，要求不能配置错误，图片路径必须正确
  1、文字标签 <font><font/>键值对来定义，常用标签属性如下：
     <font>标签对，属性有
     FACE->字体
     COLOR->颜色
     SIZE->字体大小
     OPACITY->透明度
	 ALIGN->对其方式，（*一个<br/> 前面按照第一个元素的对齐方式处理）
  2、换行标签 <br/>
  3、图片标签 <img>标签对
    opacity->透明度设置 COLOR->设置图片颜色 src->图片路径
	  eg:
	  auto richText = SuperRichText::create();
	  richText->setPosition(Vec2(m_pHeadShopBgFrame->getContentSize().width * 0.5, m_pHeadShopBgFrame->getContentSize().height * 0.5));
	  richText->renderHtml("\
	  <font color='ff0000'>this is a superRichText</font>\
	  <img opacity='255' src='res/Images/Common/btn_bule.png' />\
	  <br/>\
	  <font color='00ff00' face='fonts/Marker Felt.ttf'>Everything is ok</font>\
	  123\
	  </font>");
	  addChild(richText, BASIC_ZORDER_FRAME);

	三、注意事项
	1、需要使用转义字符来处理特殊字符
	&(逻辑与)  &amp;        
	<(小于)    &lt;        
	>(大于)    &gt;        
	"(双引号)  &quot;      
	'(单引号)  &apos; [/size] 
	2、图文混编的时候，可以设置垂直对其方式
--------------------------------------------------------------------------------
备注         : <其它说明>
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2015/08/11   1.0     diyal.yin		      新建
2015/08/17   1.0     diyal.yin            重写底层UIRichText实现 功能优化
</PRE>
*******************************************************************************/

#ifndef __SUPERRICHTEXT__SUPERRICHTEXT__
#define __SUPERRICHTEXT__SUPERRICHTEXT__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/UIRichText.h"
#include "tinyxml2/tinyxml2.h"

//#include "cocos2d/external/tinyxml2/tinyxml2.h"



//using namespace ui;

struct FontInfo{
	std::string fontName;
	float fontSize;
	std::string align; //对齐方式
	cocos2d::Color3B color;
	GLubyte opacity;
};

class SuperRichText : public cocos2d::LayerColor
{

public:

	SuperRichText();
	virtual ~SuperRichText();

	virtual bool init();
	virtual bool init(cocos2d::Size size);

	//CREATE_FUNC(SuperRichText);
	static SuperRichText* create();
	static SuperRichText* create(cocos2d::Size size);

	virtual void renderHtml(const char* html); //根据HTML标签解析

    virtual void renderNode(tinyxml2::XMLNode* node); //根据Xml的一个节点解析

private:
	GLubyte charToNumber(char c);

	cocos2d::Color3B charToColor3B(const char* code);

	float GetMaxHeight(void);

protected:

	// 记录 正使用字型
	FontInfo m_UsedFont;
	FontInfo m_DefaultFont;

	// 记录 元件最后 Y 值
	float m_SavePositionY;

	// 记录 元件 使用 Width
	float m_LineMaxWidth;

	// 记录 每一行 最大行距
	float m_LineMaxHeight;

	// 字型 初设定
	void ResetFont(void);

	// 记录 LineNode
	Node * m_pLineNode;

	// 换行处理
	void ChangeLine(void);

	// 产生 字串 Node
	cocos2d::Size CreateTextLines(const char *str, float UsedWidth, Node &TextLinesNode);

	static std::vector<std::string> split(std::string src, std::string separate_character);
	static std::string replaceAll(std::string src, std::string org_str, std::string rep_str);
};

#endif /* defined(__SUPERRICHTEXT__SUPERRICHTEXT__) */
