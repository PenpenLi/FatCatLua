#include "WWNetMacros.h"
#include "WWIPPool.h"
#include "tinyxml2/tinyxml2.h"

#define IP_POOL_PATH "wwIPPool.xml"

bool WWIPPool::loadPool(IPPoolData& data)
{
	auto path = cocos2d::FileUtils::getInstance()->getWritablePath();
	path += std::string(IP_POOL_PATH);
	printExEx(WWLC_YELLOW, "Niya WWIPPool Load Path %s", path.c_str());
	auto s = cocos2d::FileUtils::getInstance()->getStringFromFile(path);
	tinyxml2::XMLDocument doc;
	doc.Parse(s.c_str());
	auto root = doc.RootElement();
	if (!root)return false;

	auto ip_s = root->FirstChildElement();
	if (!ip_s)return false;
	auto ip = ip_s->FirstChildElement();
	while (ip)
	{
		std::string str = ip->GetText();
		data.ips.push_back(str);
		ip = ip->NextSiblingElement();
	}

	auto port_s = ip_s->NextSiblingElement();
	if (!port_s)return false;
	auto port = port_s->FirstChildElement();
	while (port)
	{
		std::string str = port->GetText();
		std::istringstream iss(str);
		int a;
		iss >> a;
		data.pts.push_back(a);
		port = port->NextSiblingElement();
	}

	return !data.ips.empty();
}

bool WWIPPool::savePool(IPPoolData& data)
{
	tinyxml2::XMLDocument doc;
	auto desc = doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	doc.LinkEndChild(desc);
	auto root = doc.NewElement("root");
	doc.LinkEndChild(root);

	auto ip_s = doc.NewElement("ips");
	root->LinkEndChild(ip_s);
	for (auto ip : data.ips)
	{
		auto n_ip = doc.NewElement("ip");
		ip_s->LinkEndChild(n_ip);
		auto t_ip = doc.NewText(ip.c_str());
		n_ip->LinkEndChild(t_ip);
	}

	auto port_s = doc.NewElement("ports");
	root->LinkEndChild(port_s);
	for (auto port : data.pts)
	{
		auto n_port = doc.NewElement("port");
		port_s->LinkEndChild(n_port);
		std::ostringstream oss;
		oss << port;
		std::string str = oss.str();
		auto t_port = doc.NewText(str.c_str());
		n_port->LinkEndChild(t_port);
	}

	auto path = cocos2d::FileUtils::getInstance()->getWritablePath();
	path += std::string(IP_POOL_PATH);
	printExEx(WWLC_YELLOW, "Niya WWIPPool Save Path %s", path.c_str());
	doc.SaveFile(path.c_str());
	return true;
}