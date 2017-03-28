#pragma once
#include "WWGeneralParser.h"

typedef struct WWSoundItem : WWSystemItem
{
	int platformid;
	WWSoundItem()
	{
		platformid = 0;
	}
};

class WWSoundParser:public WWGeneralParser
{
public:
	WWSoundParser();
	~WWSoundParser();
	void parse(WWSystemConfig & wwsConfig, tinyxml2::XMLElement* element) override;
};

