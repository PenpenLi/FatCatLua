#include "WWSoundParser.h"


WWSoundParser::WWSoundParser()
{
}


WWSoundParser::~WWSoundParser()
{


}
void WWSoundParser::parse(WWSystemConfig & wwsConfig, tinyxml2::XMLElement* element)
{
	if (!element)return;
	wwsConfig.sid = SystemID(element->IntAttribute("id"));
	wwsConfig.name = element->Attribute("name");
	wwsConfig.desc = element->Attribute("desc");

	auto itemElement = element->FirstChildElement("item");

	for (; itemElement; itemElement = itemElement->NextSiblingElement())
	{
		WWSoundItem* witem = new WWSoundItem;
		witem->name = itemElement->Attribute("name");
		witem->platformid = itemElement->IntAttribute("id");
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
