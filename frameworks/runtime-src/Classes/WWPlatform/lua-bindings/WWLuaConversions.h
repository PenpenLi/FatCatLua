#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "../VariateSystem/WWConfigData.h"
#include "../UpdateSystem/WWUpgradeAssetsMgr.h"

using namespace std;

inline void WWSystemItem_to_luaval(cocos2d::ValueVector& vmap, const WWSystemItem&wwi)
{
	//const char* name;
	//std::vector<std::string> values;

	cocos2d::ValueMap wwimap;

	wwimap.insert(make_pair("name", cocos2d::Value(wwi.name)));

	cocos2d::ValueVector wwimap2;
	int index = 0;
	for (auto s : wwi.values)
	{
		index++;
		wwimap2.push_back(cocos2d::Value(s.c_str()));

	}
	
	wwimap.insert(make_pair("values", cocos2d::Value(wwimap2)));


	vmap.push_back(cocos2d::Value(wwimap));
}

inline void WWSystemConfig_to_luaval(lua_State* L, const WWSystemConfig& inValue)
{

	cocos2d::ValueMap vmap;

	vmap.insert(make_pair("sid", cocos2d::Value(inValue.sid)));
	vmap.insert(make_pair("name", cocos2d::Value(inValue.name)));
	vmap.insert(make_pair("desc", cocos2d::Value(inValue.desc)));

	cocos2d::ValueVector items;
	for (auto wws : inValue.items)
	{
		WWSystemItem_to_luaval(items, *wws);
	}
	vmap.insert(make_pair("items", cocos2d::Value(items)));

	ccvaluemap_to_luaval(L, vmap);

}



inline std::vector<WWDownloader::resInfo> WWUpgrade_ValueVector_to_resInfo_vec(cocos2d::ValueVector& value)
{
	std::vector<WWDownloader::resInfo> resinfos;
	for (auto v:value)
	{
		if (v.getType()==cocos2d::Value::Type::MAP) 
		{
			auto m =  v.asValueMap();
			WWDownloader::resInfo resinfo;
			
			if (m.find("downloadId") != m.end())
			{
				resinfo.downloadId = m.at("downloadId").asInt();
			} else
			{
				resinfo.downloadId = 0;
			}
			
			if (m.find("gameId") != m.end())
			{
				resinfo.gameId = m.at("gameId").asInt();
			} else
			{
				resinfo.gameId = 0;
			}
			
			if (m.find("priority") != m.end())
			{
				resinfo.priority = m.at("priority").asInt();
			}
			else
			{
				resinfo.priority = 0;
			}
			if (m.find("resName") != m.end())
			{
				resinfo.resName = m.at("resName").asString();
			}
			
			if (m.find("storagePath") != m.end())
			{
				resinfo.storagePath = m.at("storagePath").asString();
			}
			if (m.find("state") != m.end())
			{
				resinfo.state = WWDownloader::DownloadState(m.at("state").asInt());
			} else
			{
				resinfo.state = WWDownloader::DownloadState::UN_DOWNLOAD;
			}
			
			resinfos.push_back(resinfo);
		}

	}

	return resinfos;
}

inline WWDownloader::DownloadUnits WWUpgrade_ValueMap_to_DownloadUnits(cocos2d::ValueMap& value)
{
	WWDownloader::DownloadUnits units;

	for (auto v:value)
	{
		
	
		if (v.second.getType() == cocos2d::Value::Type::MAP)
		{
			WWDownloader::DownloadUnit unit;
			auto m = v.second.asValueMap();
			if (m.find("src") != m.end())
			{
				unit.srcUrl = m.at("src").asString();
			}
			
			if (m.find("storagePath") != m.end())
			{
				unit.storagePath = m.at("storagePath").asString();
			}
			if (m.find("customId") != m.end())
			{
				unit.customId = m.at("customId").asString();
			}
			if (m.find("resumeDownload") != m.end())
			{
				unit.resumeDownload = m.at("resumeDownload").asBool();
			}
			else
			{
				unit.resumeDownload = false;
			}

			if (m.find("priority") != m.end())
			{
				unit.priority = m.at("priority").asInt();;
			} 
			else
			{
				unit.priority = 0;
			}

			if (m.find("resName") != m.end())
			{
				unit.resName = m.at("resName").asString();;
			}

			
			
			units.emplace(make_pair(atoi(v.first.c_str()), unit));
		}
		
	}

	return units;
}


inline void resInfo_vec_to_luaval(lua_State* L, std::vector<WWDownloader::resInfo> resinfos)
{

	cocos2d::ValueVector resvec;

	for (auto resinfo:resinfos) 
	{

		cocos2d::ValueMap vmap;
		vmap.insert(make_pair("downloadId", cocos2d::Value(resinfo.downloadId)));
		vmap.insert(make_pair("gameId", cocos2d::Value(resinfo.gameId)));
		vmap.insert(make_pair("priority", cocos2d::Value(resinfo.priority)));
		vmap.insert(make_pair("resName", cocos2d::Value(resinfo.resName)));
		vmap.insert(make_pair("storagePath", cocos2d::Value(resinfo.storagePath)));

		resvec.push_back(cocos2d::Value(vmap));
	}
	ccvaluevector_to_luaval(L, resvec);
	

}

inline void DownloadUnits_to_luaval(lua_State* L, WWDownloader::DownloadUnits& units)
{
	cocos2d::ValueMap vmap;

	for (auto unit:units)
	{
		
		cocos2d::ValueMap vmap2;
		vmap2.emplace(make_pair("srcUrl", cocos2d::Value(unit.second.srcUrl)));
		vmap2.emplace(make_pair("storagePath", cocos2d::Value(unit.second.storagePath)));
		vmap2.emplace(make_pair("customId", cocos2d::Value(unit.second.customId)));
		vmap2.emplace(make_pair("resumeDownload", cocos2d::Value(unit.second.resumeDownload)));
		vmap2.emplace(make_pair("priority", cocos2d::Value(unit.second.priority)));
		vmap2.emplace(make_pair("resName", cocos2d::Value(unit.second.resName)));

		vmap.emplace(make_pair(StringUtils::format("%d", unit.first), cocos2d::Value(vmap2)));
	}

	ccvaluemap_to_luaval(L, vmap);
}