#include "WWGeneralParser.h"
#include "../WWConfigManager.h"

WWGeneralParser::WWGeneralParser()
{
}


WWGeneralParser::~WWGeneralParser()
{
}

void WWGeneralParser::parse(WWSystemConfig & wwsConfig, tinyxml2::XMLElement* element)
{

		if (!element)return;
		wwsConfig.sid = SystemID(element->IntAttribute("id"));
		wwsConfig.name = element->Attribute("name");
		wwsConfig.desc = element->Attribute("desc");

		auto itemElement = element->FirstChildElement("item");

		for (; itemElement; itemElement = itemElement->NextSiblingElement())
		{
			WWSystemItem *witem = new WWSystemItem;
			witem->name = itemElement->Attribute("name");

			auto valueElement = itemElement->FirstChildElement("value");

			for (; valueElement; valueElement = valueElement->NextSiblingElement())
			{
				auto text = valueElement->GetText();
				if (text)
				{
					witem->values.push_back(text);
				}
			}

			wwsConfig.items.push_back(witem);
		}
}
