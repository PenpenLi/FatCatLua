#include "SuperRichText.h"
//#include "WWPlatform/tools/StringTool.h"
//#include "../tools/StringTool.h"
//#include "WWMacros.h"

USING_NS_CC;

SuperRichText::SuperRichText()
{
	this->m_DefaultFont.color = Color3B(255, 255, 255);
	this->m_DefaultFont.fontSize = 24.0f;
	this->m_DefaultFont.opacity = 255;
	this->m_DefaultFont.fontName = "Arial";
	this->m_DefaultFont.align = "left";
}

SuperRichText::~SuperRichText()
{
	this->removeAllChildren();
}

SuperRichText* SuperRichText::create()
{
	SuperRichText *pRet = new SuperRichText();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

SuperRichText* SuperRichText::create(Size size)
{
	SuperRichText *pRet = new SuperRichText();
	if (pRet && pRet->init(size))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool SuperRichText::init()
{
	if (!LayerColor::initWithColor(ccColor4B(0, 0, 0, 0)))
	{
		return false;
	}

	this->ResetFont();

	this->m_SavePositionY = 0;

	this->ChangeLine();

	return true;
}

bool SuperRichText::init(Size size)
{
	if (!LayerColor::initWithColor(ccColor4B(0, 0, 0, 0), size.width, size.height))
	{
		return false;
	}

	this->ResetFont();

	this->m_SavePositionY = 0;

	this->ChangeLine();

	return true;
}

std::vector<std::string> SuperRichText::split(std::string src, std::string separate_character)
{
	std::vector<std::string> strs;
	int separate_characterLen = separate_character.size();//分割字符串长度，这样就可以支持多字 符串的分隔符
	int last_position = 0, index = -1;
	while (-1 != (index = src.find(separate_character, last_position)))
	{
		//		WW_LOG_INFO("Charge::======================:%s", src.substr(last_position, index - last_position).c_str());
		strs.push_back(src.substr(last_position, index - last_position));
		last_position = index + separate_characterLen;
	}
	std::string lastString = src.substr(last_position);
	if (!lastString.empty())
	{
		//		WW_LOG_INFO("Charge::======================:%s", lastString.c_str());
		strs.push_back(lastString);
	}
	return strs;
}

std::string SuperRichText::replaceAll(std::string src, std::string org_str, std::string rep_str)
{
	std::vector<std::string> delimVec = split(src, org_str);
	if (delimVec.size() <= 0)
	{
		return src;
	}
	std::string target("");
	for (int i = 0; i < delimVec.size(); i++)
	{
		if (i == delimVec.size() - 1)
		{
			target = target + delimVec[i];
		}
		else
		{
			target = target + delimVec[i] + rep_str;
		}
		//       WW_LOG_INFO("Charge::======================:%s", target.c_str());
	}
	return target;
}

void SuperRichText::renderHtml(const char *html)
{
	this->removeAllChildren();

	this->m_SavePositionY = 0;

	this->ChangeLine();

	tinyxml2::XMLDocument xml;

	std::string endStr(html);

	CCLOG("txt endStr:%s", endStr.c_str());

	endStr = replaceAll(endStr, "[", "<");
	endStr = replaceAll(endStr, "]", ">");

	//endStr = replaceAll(endStr, "'", "\"");

	CCLOG("txt endStr:%s", endStr.c_str());

	//CCLOG("txt endStr:%s", endStr.c_str());

	xml.Parse(endStr.c_str());

	renderNode(xml.FirstChild());
}

void SuperRichText::renderNode(tinyxml2::XMLNode *node)
{
	while (node != nullptr)
	{
		if (node->ToText())
		{
			auto n = node->ToText();
			std::u16string text;

			CCLOG("txt info:%s", text.c_str());

			StringUtils::UTF8ToUTF16(n->Value(), text);

			std::u16string::size_type pos = 0;
			pos = text.find('\n');
			while ((pos != std::u16string::npos))
			{
				text.erase(pos, 1);
				pos = text.find('\n', pos);
			}

			pos = 0;
			pos = text.find('\r');
			while ((pos != std::u16string::npos))
			{
				text.erase(pos, 1);
				pos = text.find('\r', pos);
			}

			std::string utf8Text;
			StringUtils::UTF16ToUTF8(text, utf8Text);

			Size tempContentSize = this->getContentSize();

			Node *ptempLinesNode = Node::create();
			auto tempLabelSize = CreateTextLines(utf8Text.c_str(), tempContentSize.width - this->m_LineMaxWidth, *ptempLinesNode);

			// 换行处理
			if ((this->m_LineMaxWidth + tempLabelSize.width) > tempContentSize.width)
			{
				this->ChangeLine();
			}

			ptempLinesNode->setPositionX(this->m_LineMaxWidth);
			ptempLinesNode->setPositionY(tempLabelSize.height / 2);

			this->m_pLineNode->addChild(ptempLinesNode);

			// 判断 实际 使用高度
			if (tempLabelSize.height > this->m_LineMaxHeight)
			{
				float tempAddHeight = tempLabelSize.height - this->m_LineMaxHeight;

				this->m_LineMaxHeight += tempAddHeight;

				this->m_SavePositionY += tempAddHeight;

				// 调整 Line PositionY
				this->m_pLineNode->setPositionY(this->getContentSize().height - this->m_SavePositionY + this->m_LineMaxHeight / 2);
			}

			// 记录实际使用宽度
			this->m_LineMaxWidth += tempLabelSize.width;

			// 判度高度 是否发生变化

			if (this->m_UsedFont.align == "center")
			{
				this->m_pLineNode->setPositionX((this->getContentSize().width - this->m_LineMaxWidth) * 0.5f);
			}
			else if (this->m_UsedFont.align == "right") //右对其 （针对一些署名，日期，默认居中对其）
			{
				this->m_pLineNode->setPositionX(this->getContentSize().width - this->m_LineMaxWidth);
			}
			else
			{
				this->m_pLineNode->setPositionX(0); //默认左对齐
			}
		}
		else if (node->ToElement())
		{
			auto n = node->ToElement();
			std::string name = n->Name();

			CCLOG("txt info:%s", name.c_str());

			std::transform(name.begin(), name.end(), name.begin(), ::toupper);

			if (name == "FONT")
			{
				// 恢复 初使值
				this->ResetFont();

				auto attr = n->FirstAttribute();

				while (attr != nullptr)
				{
					//遍历所有属性
					std::string attrName = attr->Name();
					std::transform(attrName.begin(), attrName.end(), attrName.begin(), ::toupper);

					if (attrName == "FACE")
					{
						//设置字体
						this->m_UsedFont.fontName = attr->Value();
					}
					else if (attrName == "COLOR")
					{
						//设置颜色
						this->m_UsedFont.color = charToColor3B(attr->Value());
					}
					else if (attrName == "SIZE")
					{
						//设置大小
						this->m_UsedFont.fontSize = attr->IntValue();
					}
					else if (attrName == "OPACITY")
					{
						//设置不透明度
						this->m_UsedFont.opacity = attr->IntValue();
					}
					else if (attrName == "ALIGN")
					{
						this->m_UsedFont.align = attr->Value();
					}

					attr = attr->Next();
				}

				//容器的第一个是默认的字体属性，后面解析之后就放到队列后面，然后创建元素，创建控件完毕，就删掉，这样可以保持有一个默认的属性结构体

				renderNode(n->FirstChild());//继续渲染子集
			}
			else if (name == "IMG")
			{
				//图片标签的属性
				auto attr = n->FirstAttribute();

				const char* src;
				Color3B col(255, 255, 255);
				GLubyte opacity = 255;
				while (attr != nullptr)
				{
					//遍历所有属性
					std::string attrName = attr->Name();
					std::transform(attrName.begin(), attrName.end(), attrName.begin(), ::toupper);

					if (attrName == "SRC")
					{
						//设置图片路径
						src = attr->Value();
					}
					else if (attrName == "COLOR")
					{
						//设置颜色
						col = charToColor3B(attr->Value());
					}
					else if (attrName == "OPACITY")
					{
						//设置不透明度
						opacity = attr->IntValue();
					}
					attr = attr->Next();
				}

				auto fileExist = FileUtils::getInstance()->isFileExist(src);
				if (fileExist)
				{
					Sprite *pImage = Sprite::create(src);
					if (pImage != NULL)
					{
						pImage->setColor(col);
						pImage->setOpacity(opacity);

						Size tempImageSize = pImage->getContentSize();

						// 换行处理
						if ((this->m_LineMaxWidth + tempImageSize.width) > this->getContentSize().width)
						{
							this->ChangeLine();
						}

						pImage->setPositionX(this->m_LineMaxWidth + tempImageSize.width / 2);
						pImage->setPositionY(0);

						this->m_pLineNode->addChild(pImage);

						// 判断 实际 使用高度
						if (tempImageSize.height > this->m_LineMaxHeight)
						{
							float tempAddHeight = tempImageSize.height - this->m_LineMaxHeight;

							this->m_LineMaxHeight += tempAddHeight;

							this->m_SavePositionY += tempAddHeight;

							// 调整 Line PositionY
							this->m_pLineNode->setPositionY(this->getContentSize().height - this->m_SavePositionY + this->m_LineMaxHeight / 2);
						}

						// 记录实际使用宽度
						this->m_LineMaxWidth += tempImageSize.width;

						// 判度高度 是否发生变化

						if (this->m_UsedFont.align == "center")
						{
							this->m_pLineNode->setPositionX(this->getContentSize().width * 0.5f - this->m_LineMaxWidth * 0.5f);
						}
						else if (this->m_UsedFont.align == "right") //右对其 （针对一些署名，日期，默认居中对其）
						{
							this->m_pLineNode->setPositionX(this->getContentSize().width - this->m_LineMaxWidth);
						}
						else
						{
							this->m_pLineNode->setPositionX(0); //默认左对齐
						}
					}
				}
				else
				{
					// 判断 材质
					SpriteFrame *ptempFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(src);

					if (ptempFrame != NULL)
					{
						Sprite *pImage = Sprite::createWithSpriteFrameName(src);
						if (pImage != NULL)
						{
							pImage->setColor(col);
							pImage->setOpacity(opacity);

							Size tempImageSize = pImage->getContentSize();

							// 换行处理
							if ((this->m_LineMaxWidth + tempImageSize.width) > this->getContentSize().width)
							{
								this->ChangeLine();
							}

							pImage->setPositionX(this->m_LineMaxWidth + tempImageSize.width / 2);
							pImage->setPositionY(0);

							this->m_pLineNode->addChild(pImage);

							// 判断 实际 使用高度
							if (tempImageSize.height > this->m_LineMaxHeight)
							{
								float tempAddHeight = tempImageSize.height - this->m_LineMaxHeight;

								this->m_LineMaxHeight += tempAddHeight;

								this->m_SavePositionY += tempAddHeight;

								// 调整 Line PositionY
								this->m_pLineNode->setPositionY(this->getContentSize().height - this->m_SavePositionY + this->m_LineMaxHeight / 2);
							}

							// 记录实际使用宽度
							this->m_LineMaxWidth += tempImageSize.width;

							// 判度高度 是否发生变化

							if (this->m_UsedFont.align == "center")
							{
								this->m_pLineNode->setPositionX(this->getContentSize().width * 0.5f - this->m_LineMaxWidth * 0.5f);
							}
							else if (this->m_UsedFont.align == "right") //右对其 （针对一些署名，日期，默认居中对其）
							{
								this->m_pLineNode->setPositionX(this->getContentSize().width - this->m_LineMaxWidth);
							}
							else
							{
								this->m_pLineNode->setPositionX(0); //默认左对齐
							}
						}
					}
				}
			}
			else if (name == "BR")
			{
				this->m_SavePositionY += this->m_UsedFont.fontSize;

				this->ChangeLine();
			}

		}

		node = node->NextSibling();
	}
}

GLubyte SuperRichText::charToNumber(char c)
{
	GLubyte n = c - '0';//将“数字字符”转换为数字

	if (n > 9) {//如果大于9则表示当前是字母 需要将字母转换为10-15的值
		n = c - (c >= 'a' ? 'a' : 'A') + 10;
	}

	return n;
}

Color3B SuperRichText::charToColor3B(const char* code)
{
	Color3B color(0, 0, 0);
	if (strlen(code) == 6)
	{
		color.r = charToNumber(code[0]) * 16 + charToNumber(code[1]);
		color.g = charToNumber(code[2]) * 16 + charToNumber(code[3]);
		color.b = charToNumber(code[4]) * 16 + charToNumber(code[5]);
	}
	return color;
}

bool IsEnglishChar(char CheckChar)
{
	if (((CheckChar >= 'a') && (CheckChar <= 'z')) || ((CheckChar >= 'A') && (CheckChar <= 'Z')))
	{
		return true;
	}

	return false;
}

bool IsNumberChar(char CheckChar)
{
	if ((CheckChar >= '0') && (CheckChar <= '9'))
	{
		return true;
	}

	return false;
}

// 产生 字串 Node
Size SuperRichText::CreateTextLines(const char* str, float UsedWidth, Node &TextLinesNode)
{
	// 最小宽度处理
	UsedWidth = MAX(UsedWidth, this->m_UsedFont.fontSize);

	std::string tempString = str;
	CCLOG("tempString = %s", tempString.c_str());
	int tempStringCount = tempString.size();
	Size tempNodeSize = Size(0, 0);

	auto tempIsFileExist = FileUtils::getInstance()->isFileExist(this->m_UsedFont.fontName);
	Label *ptempLabel = nullptr;
	if (tempIsFileExist)
	{
		ptempLabel = Label::createWithTTF("", this->m_UsedFont.fontName, this->m_UsedFont.fontSize);
	}
	else
	{
		ptempLabel = Label::createWithSystemFont("", this->m_DefaultFont.fontName, this->m_UsedFont.fontSize);
	}
	ptempLabel->setHorizontalAlignment(cocos2d::TextHAlignment::LEFT);

	// 记录开始字串位置
	int tempStartIndex = 0;
	int tempStringIndex = 0;
	int tempSaveStringIndex = tempStringIndex;
	while (tempStringIndex < tempStringCount)
	{
		std::string tempSubString = tempString.substr(tempStringIndex, 1);

		// 判断 UTF-8 字头
		// 1110 XXXX b (xE0h)
		if ((tempSubString.c_str()[0] & 0xF0) == 0xE0)
		{
			tempStringIndex += 3;
		}
		// 判断 UTF-8 字头
		// 110X XXXX b (xC0h)
		else if ((tempSubString.c_str()[0] & 0xE0) == 0xC0)
		{
			tempStringIndex += 2;
		}
		// Ansi 
		// 0XXX XXXX 127 字
		else
		{
			tempStringIndex++;
		}

		std::string tempLineString = tempString.substr(tempStartIndex, tempStringIndex - tempStartIndex);

		ptempLabel->setString(tempLineString);

		// 判断是否换行
		if (ptempLabel->getContentSize().width > UsedWidth)
		{
			// 判断换行英文字串
			if (tempSaveStringIndex > 0)
			{
				char tempCheckChar = tempString.at(tempSaveStringIndex - 1);
				if (IsEnglishChar(tempCheckChar))
				{
					char tempCheckNextChar = tempString.at(tempSaveStringIndex);
					if (IsEnglishChar(tempCheckNextChar))
					{
						// Find English String
						int tempEnglishStartIndex = tempSaveStringIndex - 1;
						int tempEnglishEndIndex = tempSaveStringIndex;

						// 向前寻找
						while (tempEnglishStartIndex > tempStartIndex)
						{
							char tempCheckPrevChar = tempString.at(tempEnglishStartIndex - 1);
							if (IsEnglishChar(tempCheckPrevChar))
							{
								tempEnglishStartIndex--;
							}
							else
							{
								break;
							}
						}

						// 向后寻找
						while (tempEnglishEndIndex < (tempStringCount - 1))
						{
							char temptempCheckNextChar = tempString.at(tempEnglishEndIndex + 1);
							if (IsEnglishChar(temptempCheckNextChar))
							{
								tempEnglishEndIndex++;
							}
							else
							{
								break;
							}
						}

						// 判断有效长度
						if (tempEnglishStartIndex > tempStartIndex)
						{
							std::string tempEnglishString = tempString.substr(tempEnglishStartIndex, tempEnglishEndIndex - tempEnglishStartIndex + 1);

							ptempLabel->setString(tempEnglishString);

							if (ptempLabel->getContentSize().width <= UsedWidth)
							{
								// 提前换行
								tempSaveStringIndex = tempEnglishStartIndex - 1;
								tempStringIndex = tempEnglishStartIndex;
							}
						}
					}
				}
				// 判断　数字
				else if (IsNumberChar(tempCheckChar))
				{
					char tempCheckNextChar = tempString.at(tempSaveStringIndex);
					if (IsNumberChar(tempCheckNextChar))
					{
						// Find English String
						int tempEnglishStartIndex = tempSaveStringIndex - 1;
						int tempEnglishEndIndex = tempSaveStringIndex;

						// 向前寻找
						while (tempEnglishStartIndex > tempStartIndex)
						{
							char tempCheckPrevChar = tempString.at(tempEnglishStartIndex - 1);
							if (IsNumberChar(tempCheckPrevChar))
							{
								tempEnglishStartIndex--;
							}
							else
							{
								break;
							}
						}

						// 向后寻找
						while (tempEnglishEndIndex < (tempStringCount - 1))
						{
							char temptempCheckNextChar = tempString.at(tempEnglishEndIndex + 1);
							if (IsNumberChar(temptempCheckNextChar))
							{
								tempEnglishEndIndex++;
							}
							else
							{
								break;
							}
						}

						// 判断有效长度
						if (tempEnglishStartIndex > tempStartIndex)
						{
							std::string tempNumberString = tempString.substr(tempEnglishStartIndex, tempEnglishEndIndex - tempEnglishStartIndex + 1);

							ptempLabel->setString(tempNumberString);

							if (ptempLabel->getContentSize().width <= UsedWidth)
							{
								// 提前换行
								tempSaveStringIndex = tempEnglishStartIndex - 1;
								tempStringIndex = tempEnglishStartIndex;
							}
						}
					}
				}
			}

			tempLineString = tempString.substr(tempStartIndex, tempSaveStringIndex - tempStartIndex);

			Label *ptempLineLabel = nullptr;
			if (tempIsFileExist)
			{
				ptempLineLabel = Label::createWithTTF(tempLineString.c_str(), this->m_UsedFont.fontName, this->m_UsedFont.fontSize);
			}
			else
			{
				ptempLineLabel = Label::createWithSystemFont(tempLineString.c_str(), this->m_DefaultFont.fontName, this->m_UsedFont.fontSize);
			}
			ptempLineLabel->setHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
			ptempLineLabel->setColor(this->m_UsedFont.color);
			ptempLineLabel->setOpacity(this->m_UsedFont.opacity);

			Size tempLineSize = ptempLineLabel->getContentSize();

			ptempLineLabel->setPositionX(tempLineSize.width / 2);
			ptempLineLabel->setPositionY(-tempNodeSize.height - tempLineSize.height / 2);
			TextLinesNode.addChild(ptempLineLabel);

			// 指向下一行头
			tempStartIndex = tempSaveStringIndex;
			tempStringIndex = tempStartIndex;

			// 换行处理
			tempNodeSize.width = MAX(tempNodeSize.width, tempLineSize.width);
			tempNodeSize.height += tempLineSize.height;
		}
		else
		{
			// 保存　可能字串　长度
			tempSaveStringIndex = tempStringIndex;
		}
	}

	// 处理　字尾
	{
		std::string tempEndLineString = tempString.substr(tempStartIndex, tempStringCount - tempStartIndex);

		Label *ptempEndLineLabel = nullptr;
		if (tempIsFileExist)
		{
			ptempEndLineLabel = Label::createWithTTF(tempEndLineString.c_str(), this->m_UsedFont.fontName, this->m_UsedFont.fontSize);
		}
		else
		{
			ptempEndLineLabel = Label::createWithSystemFont(tempEndLineString.c_str(), this->m_DefaultFont.fontName, this->m_UsedFont.fontSize);
		}
		ptempEndLineLabel->setHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		ptempEndLineLabel->setColor(this->m_UsedFont.color);
		ptempEndLineLabel->setOpacity(this->m_UsedFont.opacity);

		Size tempLineSize = ptempEndLineLabel->getContentSize();

		ptempEndLineLabel->setPositionX(tempLineSize.width / 2);
		ptempEndLineLabel->setPositionY(-tempNodeSize.height - tempLineSize.height / 2);
		TextLinesNode.addChild(ptempEndLineLabel);

		// 换行处理
		tempNodeSize.width = MAX(tempNodeSize.width, tempLineSize.width);
		tempNodeSize.height += tempLineSize.height;
	}

	return tempNodeSize;
}

// 字型 初设定
void SuperRichText::ResetFont(void)
{
	this->m_UsedFont.color = Color3B(255, 255, 255);
	this->m_UsedFont.fontSize = 24.0f;
	this->m_UsedFont.opacity = 255;
	this->m_UsedFont.fontName = "Arial";
	this->m_UsedFont.align = "left";
}

float SuperRichText::GetMaxHeight(void)
{
	return this->m_SavePositionY;
}

// 换行处理
void SuperRichText::ChangeLine(void)
{
	// 记录 元件 使用 Width
	this->m_LineMaxWidth = 0;

	// 记录 每一行 最大行距
	this->m_LineMaxHeight = 0;

	// 新行处理
	this->m_pLineNode = Node::create();
	this->m_pLineNode->setPositionX(0);
	this->m_pLineNode->setPositionY(this->getContentSize().height - this->m_SavePositionY);
	this->addChild(this->m_pLineNode);
}

