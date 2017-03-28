#include "WWConfigManager.h"
#include "parser/WWSoundParser.h"
#include "parser/WWGeneralParser.h"

#include "tinyxml2/tinyxml2.h"
#include "../SoundSystem/WWSoundManager.h"

using namespace tinyxml2;

WWConfigManager::WWConfigManager() 
{
	configParsers.clear();
	configItems.clear();
	this->init();
}


WWConfigManager::~WWConfigManager()
{
	for (auto iter = configParsers.begin(); iter != configParsers.end();) 
	{
			auto parser = iter->second;
			configParsers.erase(iter++);
			CC_SAFE_DELETE(parser);
	}
	configItems.clear();

}
void WWConfigManager::init()
{
	configParsers.emplace(make_pair(SYSTEM_SOUND, new WWSoundParser));

	configParsers.emplace(make_pair(SYSTEM_NET, new WWGeneralParser));

	configParsers.emplace(make_pair(SYSTEM_UPGRADE, new WWGeneralParser));

	configParsers.emplace(make_pair(SYSTEM_EVENTSYSTEM, new WWGeneralParser));

	configParsers.emplace(make_pair(SYSTEM_ENGINE, new WWGeneralParser));
}

void WWConfigManager::initConfig(const char* filepath)
{
	if (!filepath || !FileUtils::getInstance()->isFileExist(filepath)) return;

	configItems.clear();

	//读取的字节数，读取失败则为0  
	ssize_t len = 0;
	//读取的内容  
	unsigned char* data = FileUtils::getInstance()->getFileData(filepath, "r", &len);
	if (len == 0)
	{
		CC_SAFE_DELETE(data);
		return;
	}
	//读取动作XML文件  
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->Parse((char*)data, (int)len);
	auto root = doc->RootElement();
	XMLElement* element = doc->RootElement()->FirstChildElement("systemitem");
	for (; element; element = element->NextSiblingElement())
	{

		WWSystemConfig wwsconfig;

		SystemID sid = SystemID(element->IntAttribute("id"));
		
		if (configParsers.find(sid) != configParsers.end())
		{
			auto parser = configParsers.at(sid);
			if (parser)parser->parse(wwsconfig, element);
			configItems.insert(make_pair(wwsconfig.sid, wwsconfig));
		}
		

	}
	//释放
	CC_SAFE_DELETE(data);

	//数据初始化完成，再初始化其他模块
	this->initOtherSystem();

}
void WWConfigManager::initOtherSystem()
{
	WWSoundManager::getInstance()->init();

}

WWSystemConfig WWConfigManager::getModuleConfig(const SystemID& sid)
{
	WWSystemConfig wc;
	if (configItems.find(sid) != configItems.end())
	{
		wc = configItems.at(sid);
	}
	return wc;

}