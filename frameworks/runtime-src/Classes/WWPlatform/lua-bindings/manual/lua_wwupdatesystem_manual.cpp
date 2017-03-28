#include "lua_wwupdatesystem_manual.hpp"
#include "../../UpdateSystem/WWUpgradeAssetsMgr.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "../WWLuaConversions.h"
#include "../../EventSystem/WWMsgManager.h"
int lua_wwupdatesystem_WWUpgradeAssetsMgr_constructor(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif



	argc = lua_gettop(tolua_S)-1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_constructor'", nullptr);
			return 0;
		}
		cobj = new WWUpgradeAssetsMgr();
		//cobj->retain();
		tolua_pushusertype(tolua_S, (void*)cobj, "WWUpgradeAssetsMgr");
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:WWUpgradeAssetsMgr", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_constructor'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitUserData(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setGameVersion'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:setGameversion");

		std::string arg1;

		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:setGameversion");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setGameVersion'", nullptr);
			return 0;
		}
		cobj->onInitUserData(arg0, arg1);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:onSetUpAssetMgr", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setGameVersion'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_isLuaRelateModule(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_isLuaRelateModule'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:isLuaRelateModule");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_isLuaRelateModule'", nullptr);
			return 0;
		}
		bool ret = cobj->isLuaRelateModule(arg0);
		tolua_pushboolean(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:isLuaRelateModule", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_isLuaRelateModule'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetModuleName(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetModuleName'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetModuleName");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetModuleName'", nullptr);
			return 0;
		}
		std::string ret = cobj->onGetModuleName(arg0);
		tolua_pushstring(tolua_S, ret.c_str());

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:isLuaRelateModule", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetModuleName'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadCfgInfo(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadCfgInfo'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::vector<int> arg0;

		ok &= luaval_to_std_vector_int(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetDownloadCfgInfo");
		
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadCfgInfo'", nullptr);
			return 0;
		}
		auto ret = cobj->onGetDownloadCfgInfo(arg0);

		
		resInfo_vec_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetDownloadCfgInfo", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadCfgInfo'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetJointDownloadAddress(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetJointDownloadAddress'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetJointDownloadAddress");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetJointDownloadAddress'", nullptr);
			return 0;
		}
		std::string ret = cobj->onGetJointDownloadAddress(arg0);
		tolua_pushstring(tolua_S, ret.c_str());

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetJointDownloadAddress", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetJointDownloadAddress'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnitInfo(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnitInfo'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::ValueVector arg0;

		ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetDownloadUnitInfo");

		auto resvec = WWUpgrade_ValueVector_to_resInfo_vec(arg0);
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnitInfo'", nullptr);
			return 0;
		}
		auto ret = cobj->onGetDownloadUnitInfo(resvec);

		DownloadUnits_to_luaval(tolua_S, ret);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetDownloadUnitInfo", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnitInfo'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		cocos2d::ValueVector arg0;

		ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onStartSilenceDownloading");
		
		std::vector<WWDownloader::resInfo> vecRes = WWUpgrade_ValueVector_to_resInfo_vec(arg0);
		int arg1;
		ok &= luaval_to_int32(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onStartSilenceDownloading");

		int arg2;
		ok &= luaval_to_int32(tolua_S, 4, &arg2, "WWUpgradeAssetsMgr:onStartSilenceDownloading");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading'", nullptr);
			return 0;
		}
		cobj->onStartSilenceDownloading(vecRes, WWUpgradeAssetsMgr::DownloadType(arg1), arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}else if (argc==2) 
	{
		cocos2d::ValueVector arg0;

		ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onStartSilenceDownloading");

		std::vector<WWDownloader::resInfo> vecRes = WWUpgrade_ValueVector_to_resInfo_vec(arg0);

		int arg1;
		ok &= luaval_to_int32(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onStartSilenceDownloading");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading'", nullptr);
			return 0;
		}
		cobj->onStartSilenceDownloading(vecRes, WWUpgradeAssetsMgr::DownloadType(arg1));
		lua_settop(tolua_S, 1);
		return 1;

	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onStartSilenceDownloading", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onCheckDownloadResExist(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onCheckDownloadResExist'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onCheckDownloadResExist");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onCheckDownloadResExist'", nullptr);
			return 0;
		}
		bool ret = cobj->onCheckDownloadResExist(arg0);
		tolua_pushboolean(tolua_S, ret);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onCheckDownloadResExist", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onCheckDownloadResExist'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetLocalDownloadFileSize(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetLocalDownloadFileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::ValueMap arg0;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetLocalDownloadFileSize");
		WWDownloader::DownloadUnits units = WWUpgrade_ValueMap_to_DownloadUnits(arg0);
		
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetLocalDownloadFileSize'", nullptr);
			return 0;
		}
		long ret = cobj->onGetLocalDownloadFileSize(units);
		tolua_pushnumber(tolua_S, ret);
		DownloadUnits_to_luaval(tolua_S, units);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetLocalDownloadFileSize", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetLocalDownloadFileSize'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetRemoteDownloadFileSize(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetRemoteDownloadFileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		cocos2d::ValueMap arg0;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetLocalDownloadFileSize");
		WWDownloader::DownloadUnits units = WWUpgrade_ValueMap_to_DownloadUnits(arg0);

		int arg1;

		ok &= luaval_to_int32(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onGetRemoteDownloadFileSize");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetRemoteDownloadFileSize'", nullptr);
			return 0;
		}
		long ret = cobj->onGetRemoteDownloadFileSize(units,arg1);
		tolua_pushnumber(tolua_S, ret);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetRemoteDownloadFileSize", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetRemoteDownloadFileSize'.", &tolua_err);
#endif

	return 0;
}

int lua_wwupdatesystem_WWUpgradeAssetsMgr_onClearDownloadThread(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onClearDownloadThread'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onClearDownloadThread");
		
		cocos2d::ValueMap arg1;

		ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onSetHotUpdateUnitInfo");

		auto units = WWUpgrade_ValueMap_to_DownloadUnits(arg1);

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onClearDownloadThread'", nullptr);
			return 0;
		}
		cobj->onClearDownloadThread(arg0, units);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onClearDownloadThread", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onClearDownloadThread'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onManagerASyncThreadNum(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onManagerASyncThreadNum'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onManagerASyncThreadNum");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onManagerASyncThreadNum'", nullptr);
			return 0;
		}
		cobj->onManagerASyncThreadNum(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onManagerASyncThreadNum", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onManagerASyncThreadNum'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadID(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadID'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetDownloadID");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadID'", nullptr);
			return 0;
		}
		int ret = cobj->onGetDownloadID(arg0);
		lua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetDownloadID", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadID'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onSetHotUpdateUnitInfo(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onSetHotUpdateUnitInfo'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		cocos2d::ValueMap arg0;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onSetHotUpdateUnitInfo");
		
		auto units = WWUpgrade_ValueMap_to_DownloadUnits(arg0);


		int arg1;

		ok &= luaval_to_int32(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onSetHotUpdateUnitInfo");

		int arg2;

		ok &= luaval_to_int32(tolua_S, 4, &arg2, "WWUpgradeAssetsMgr:onSetHotUpdateUnitInfo");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onSetHotUpdateUnitInfo'", nullptr);
			return 0;
		}
		cobj->onSetHotUpdateUnitInfo(units, arg1, WWUpgradeAssetsMgr::DownloadType(arg2));

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onSetHotUpdateUnitInfo", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onSetHotUpdateUnitInfo'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_WWUpgradeAssetsMgr_onFinishOtherLuaDownloadThread(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onFinishOtherLuaDownloadThread'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onFinishOtherLuaDownloadThread");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onFinishOtherLuaDownloadThread'", nullptr);
			return 0;
		}
		cobj->onFinishOtherLuaDownloadThread(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onFinishOtherLuaDownloadThread", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onFinishOtherLuaDownloadThread'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnits(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnits'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		cocos2d::ValueVector arg0;

		ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onGetDownloadUnits");

		auto resvec = WWUpgrade_ValueVector_to_resInfo_vec(arg0);
		
		int arg1;
		ok &= luaval_to_int32(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onGetDownloadUnits");
		
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnits'", nullptr);
			return 0;
		}
		auto units = cobj->onGetDownloadUnits(resvec,WWUpgradeAssetsMgr::DownloadType(arg1));
		
		DownloadUnits_to_luaval(tolua_S,units);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onGetDownloadUnits", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnits'.", &tolua_err);
#endif

	return 0;
}

int lua_wwupdatesystem_WWUpgradeAssetsMgr_onHttpRequestDownloadAddress(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onHttpRequestDownloadAddress'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 5)
	{

		int arg00;

		ok &= luaval_to_int32(tolua_S, 2, &arg00, "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress");

		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 3, &arg0, "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress");

		std::string arg01;

		ok &= luaval_to_std_string(tolua_S, 4, &arg01, "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress");

		int arg1;

		ok &= luaval_to_int32(tolua_S, 5, &arg1, "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress");

		int arg2;

		ok &= luaval_to_int32(tolua_S, 6, &arg2, "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onHttpRequestDownloadAddress'", nullptr);
			return 0;
		}
		cobj->onHttpRequestDownloadAddress(arg00,arg0, arg01, arg1, WWUpgradeAssetsMgr::DownloadType(arg2));
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onHttpRequestDownloadAddress'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_WWUpgradeAssetsMgr_onIsModuleThreadRunning(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onIsModuleThreadRunning'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onIsModuleThreadRunning'", nullptr);
			return 0;
		}
		bool ret = cobj->onIsModuleThreadRunning();
		lua_pushboolean(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onHttpRequestDownloadAddress", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onIsModuleThreadRunning'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_setDelegate(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setDelegate'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		WWMsgManager* arg0;

		//ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:setDelegate");
		ok &= luaval_to_object<WWMsgManager>(tolua_S, 2, "WWMsgManager", &arg0, "WWUpgradeAssetsMgr:setDelegate");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setDelegate'", nullptr);
			return 0;
		}
		cobj->setDelegate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:setDelegate", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_setDelegate'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleIdCfg(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleIdCfg'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:addModuleIdCfg");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleIdCfg'", nullptr);
			return 0;
		}
		cobj->addModuleIdCfg(arg0);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:addModuleIdCfg", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleIdCfg'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleNameCfg(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleNameCfg'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		int arg0;

		ok &= luaval_to_int32(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:addModuleNameCfg");

		const char* arg1;

		std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "WWUpgradeAssetsMgr:addModuleNameCfg"); arg1 = arg1_tmp.c_str();

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleNameCfg'", nullptr);
			return 0;
		}
		cobj->addModuleNameCfg(arg0, arg1);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:addModuleNameCfg", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleNameCfg'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitDownloadJsonInfo(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitDownloadJsonInfo'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onInitDownloadJsonInfo");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitDownloadJsonInfo'", nullptr);
			return 0;
		}
		cobj->onInitDownloadJsonInfo(arg0);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:onInitDownloadJsonInfo", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitDownloadJsonInfo'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "WWUpgradeAssetsMgr:onInitModuleInfo");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo'", nullptr);
			return 0;
		}
		string arg1;

		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "WWUpgradeAssetsMgr:onInitModuleInfo");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo'", nullptr);
			return 0;
		}

		cobj->onInitModuleInfo(arg0, arg1);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:onInitModuleInfo", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartAPKDownload(lua_State* tolua_S)
{
	int argc = 0;
	WWUpgradeAssetsMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWUpgradeAssetsMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWUpgradeAssetsMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartAPKDownload'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		


		std::string arg1;

		ok &= luaval_to_std_string(tolua_S, 2, &arg1, "WWUpgradeAssetsMgr:onStartAPKDownload");

		std::string arg2;

		ok &= luaval_to_std_string(tolua_S, 3, &arg2, "WWUpgradeAssetsMgr:onStartAPKDownload");
		std::vector<std::string> arg3;

		ok &= luaval_to_std_vector_string(tolua_S, 4, &arg3, "WWUpgradeAssetsMgr:onStartAPKDownload");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartAPKDownload'", nullptr);
			return 0;
		}
		cobj->onStartAPKDownload(arg1, arg2, arg3);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWUpgradeAssetsMgr:onStartAPKDownload", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartAPKDownload'.", &tolua_err);
#endif

	return 0;
}


int lua_register_wwupdatesystem_UpgradeAssetsMgr(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "WWUpgradeAssetsMgr");
	tolua_cclass(tolua_S, "WWUpgradeAssetsMgr", "WWUpgradeAssetsMgr", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "WWUpgradeAssetsMgr");
	tolua_function(tolua_S, "create", lua_wwupdatesystem_WWUpgradeAssetsMgr_constructor);
	tolua_function(tolua_S, "onInitUserData", lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitUserData);

	tolua_function(tolua_S, "isLuaRelateModule", lua_wwupdatesystem_WWUpgradeAssetsMgr_isLuaRelateModule);
	tolua_function(tolua_S, "onGetModuleName", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetModuleName);
	tolua_function(tolua_S, "onGetDownloadCfgInfo", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadCfgInfo);
	tolua_function(tolua_S, "onGetJointDownloadAddress", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetJointDownloadAddress);
	tolua_function(tolua_S, "onGetDownloadUnitInfo", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnitInfo);
	tolua_function(tolua_S, "onStartSilenceDownloading", lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartSilenceDownloading);

	tolua_function(tolua_S, "onCheckDownloadResExist", lua_wwupdatesystem_WWUpgradeAssetsMgr_onCheckDownloadResExist);
	tolua_function(tolua_S, "onGetLocalDownloadFileSize", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetLocalDownloadFileSize);
	tolua_function(tolua_S, "onGetRemoteDownloadFileSize", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetRemoteDownloadFileSize);
	tolua_function(tolua_S, "onClearDownloadThread", lua_wwupdatesystem_WWUpgradeAssetsMgr_onClearDownloadThread);
	tolua_function(tolua_S, "onManagerASyncThreadNum", lua_wwupdatesystem_WWUpgradeAssetsMgr_onManagerASyncThreadNum);
	tolua_function(tolua_S, "onGetDownloadID", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadID);
	tolua_function(tolua_S, "onSetHotUpdateUnitInfo", lua_wwupdatesystem_WWUpgradeAssetsMgr_onSetHotUpdateUnitInfo);
	tolua_function(tolua_S, "onFinishOtherLuaDownloadThread", lua_wwupdatesystem_WWUpgradeAssetsMgr_onFinishOtherLuaDownloadThread);
	tolua_function(tolua_S, "onGetDownloadUnits", lua_wwupdatesystem_WWUpgradeAssetsMgr_onGetDownloadUnits);
	tolua_function(tolua_S, "onHttpRequestDownloadAddress", lua_wwupdatesystem_WWUpgradeAssetsMgr_onHttpRequestDownloadAddress);
	tolua_function(tolua_S, "onIsModuleThreadRunning", lua_wwupdatesystem_WWUpgradeAssetsMgr_onIsModuleThreadRunning);
	tolua_function(tolua_S, "setDelegate", lua_wwupdatesystem_WWUpgradeAssetsMgr_setDelegate);
	
	tolua_function(tolua_S, "addModuleNameCfg", lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleNameCfg);
	tolua_function(tolua_S, "addModuleIdCfg", lua_wwupdatesystem_WWUpgradeAssetsMgr_addModuleIdCfg);


	tolua_function(tolua_S, "onInitDownloadJsonInfo", lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitDownloadJsonInfo);
	tolua_function(tolua_S, "onInitModuleInfo", lua_wwupdatesystem_WWUpgradeAssetsMgr_onInitModuleInfo);

	tolua_function(tolua_S, "onStartAPKDownload", lua_wwupdatesystem_WWUpgradeAssetsMgr_onStartAPKDownload);
	
	
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(WWUpgradeAssetsMgr).name();
	g_luaType[typeName] = "WWUpgradeAssetsMgr";
	g_typeCast["WWUpgradeAssetsMgr"] = "WWUpgradeAssetsMgr";
	return 1;
}



int lua_wwupdatesystem_DownloadThreadState_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "DownloadThreadState", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_DownloadThreadState_getInstance'", nullptr);
			return 0;
		}
		DownloadThreadState* ret = DownloadThreadState::getInstance();
		object_to_luaval<DownloadThreadState>(tolua_S, "DownloadThreadState", (DownloadThreadState*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UpgradeAssetsMgrContainer:getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_DownloadThreadState_getInstance'.", &tolua_err);
#endif
	return 0;
}


int lua_wwupdatesystem_DownloadThreadState_onGetDownloadThreadState(lua_State* tolua_S)
{
	int argc = 0;
	DownloadThreadState* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "DownloadThreadState", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (DownloadThreadState*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_DownloadThreadState_onGetDownloadThreadState'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, "DownloadThreadState::onGetDownloadThreadState");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_DownloadThreadState_onGetDownloadThreadState'", nullptr);
			return 0;
		}
		auto state = cobj->onGetDownloadThreadState(arg0);
		
		lua_pushnumber(tolua_S, static_cast<int>(state));
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DownloadThreadState::onGetDownloadThreadState", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_DownloadThreadState_onGetDownloadThreadState'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_DownloadThreadState_onGetModuleHttpAddr(lua_State* tolua_S)
{
	int argc = 0;
	DownloadThreadState* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "DownloadThreadState", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (DownloadThreadState*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_DownloadThreadState_onGetModuleHttpAddr'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "DownloadThreadState::onGetModuleHttpAddr");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_DownloadThreadState_onGetModuleHttpAddr'", nullptr);
			return 0;
		}
		auto url = cobj->onGetModuleHttpAddr(arg0);

		lua_pushstring(tolua_S, url.c_str());
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DownloadThreadState::onGetModuleHttpAddr", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_DownloadThreadState_onGetModuleHttpAddr'.", &tolua_err);
#endif

	return 0;
}

int lua_wwupdatesystem_DownloadThreadState_onSetLocalFileSize(lua_State* tolua_S)
{
	int argc = 0;
	DownloadThreadState* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "DownloadThreadState", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (DownloadThreadState*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_DownloadThreadState_onSetLocalFileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, "DownloadThreadState::onSetLocalFileSize");

		long arg1;
		ok &= luaval_to_long(tolua_S, 2, &arg1, "DownloadThreadState::onSetLocalFileSize");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_DownloadThreadState_onSetLocalFileSize'", nullptr);
			return 0;
		}
		cobj->onSetLocalFileSize(arg0,arg1);

		lua_settop(tolua_S, 1);

		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DownloadThreadState::onSetLocalFileSize", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_DownloadThreadState_onSetLocalFileSize'.", &tolua_err);
#endif

	return 0;
}

int lua_wwupdatesystem_DownloadThreadState_onGetLocalFileSize(lua_State* tolua_S)
{
	int argc = 0;
	DownloadThreadState* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "DownloadThreadState", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (DownloadThreadState*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_DownloadThreadState_onGetLocalFileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, "DownloadThreadState::onGetLocalFileSize");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_DownloadThreadState_onGetLocalFileSize'", nullptr);
			return 0;
		}
		auto fileSize = cobj->onGetLocalFileSize(arg0);

		lua_pushnumber(tolua_S, fileSize);

		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DownloadThreadState::onGetLocalFileSize", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_DownloadThreadState_onGetLocalFileSize'.", &tolua_err);
#endif

	return 0;
}

int lua_register_wwupdatesystem_DownloadThreadState(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "DownloadThreadState");
	tolua_cclass(tolua_S, "DownloadThreadState", "DownloadThreadState", "", nullptr);

	tolua_beginmodule(tolua_S, "DownloadThreadState");
	tolua_function(tolua_S, "getInstance", lua_wwupdatesystem_DownloadThreadState_getInstance);
	tolua_function(tolua_S, "onGetDownloadThreadState", lua_wwupdatesystem_DownloadThreadState_onGetDownloadThreadState);
	tolua_function(tolua_S, "onGetModuleHttpAddr", lua_wwupdatesystem_DownloadThreadState_onGetModuleHttpAddr);
	tolua_function(tolua_S, "onSetLocalFileSize", lua_wwupdatesystem_DownloadThreadState_onSetLocalFileSize);
	tolua_function(tolua_S, "onGetLocalFileSize", lua_wwupdatesystem_DownloadThreadState_onGetLocalFileSize);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(DownloadThreadState).name();
	g_luaType[typeName] = "DownloadThreadState";
	g_typeCast["DownloadThreadState"] = "DownloadThreadState";
	return 1;
}




int lua_wwupdatesystem_UpgradeAssetsMgrContainer_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_getInstance'", nullptr);
			return 0;
		}
		UpgradeAssetsMgrContainer* ret = UpgradeAssetsMgrContainer::getInstance();
		object_to_luaval<UpgradeAssetsMgrContainer>(tolua_S, "WWAnimatePacker", (UpgradeAssetsMgrContainer*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UpgradeAssetsMgrContainer:getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_getInstance'.", &tolua_err);
#endif
	return 0;
}

int lua_wwupdatesystem_UpgradeAssetsMgrContainer_onGetUpAssetMgr(lua_State* tolua_S)
{
	int argc = 0;
	UpgradeAssetsMgrContainer* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (UpgradeAssetsMgrContainer*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onGetUpAssetMgr'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, "UpgradeAssetsMgrContainer::onGetUpAssetMgr");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onGetUpAssetMgr'", nullptr);
			return 0;
		}
		WWUpgradeAssetsMgr* ret = cobj->onGetUpAssetMgr(arg0);
		object_to_luaval<WWUpgradeAssetsMgr>(tolua_S, "WWUpgradeAssetsMgr", (WWUpgradeAssetsMgr*)ret);
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:onGetUpAssetMgr", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onGetUpAssetMgr'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_UpgradeAssetsMgrContainer_onSetUpAssetMgr(lua_State* tolua_S)
{
	int argc = 0;
	UpgradeAssetsMgrContainer* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (UpgradeAssetsMgrContainer*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onSetUpAssetMgr'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		int arg0;
		WWUpgradeAssetsMgr *arg1;

		ok &= luaval_to_int32(tolua_S, 2, (int *)&arg0, "UpgradeAssetsMgrContainer:onSetUpAssetMgr");

		ok &= luaval_to_object<WWUpgradeAssetsMgr>(tolua_S, 3, "WWUpgradeAssetsMgr", &arg1, "onSetUpAssetMgr:onSetUpAssetMgr");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onSetUpAssetMgr'", nullptr);
			return 0;
		}
		cobj->onSetUpAssetMgr(arg0, arg1);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:onSetUpAssetMgr", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_onSetUpAssetMgr'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_UpgradeAssetsMgrContainer_setUpdateUrl(lua_State* tolua_S)
{
	int argc = 0;
	UpgradeAssetsMgrContainer* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (UpgradeAssetsMgrContainer*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setUpdateUrl'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;


		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "UpgradeAssetsMgrContainer:setUpdateUrl");


		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setUpdateUrl'", nullptr);
			return 0;
		}
		cobj->setUpdateUrl(arg0);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:setUpdateUrl", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setUpdateUrl'.", &tolua_err);
#endif

	return 0;
}



int lua_wwupdatesystem_UpgradeAssetsMgrContainer_setDownloadURL(lua_State* tolua_S)
{
	int argc = 0;
	UpgradeAssetsMgrContainer* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (UpgradeAssetsMgrContainer*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setDownloadURL'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "UpgradeAssetsMgrContainer:setDownloadURL");

		std::string arg1;

		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "UpgradeAssetsMgrContainer:setDownloadURL");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setDownloadURL'", nullptr);
			return 0;
		}
		cobj->setDownloadURL(arg0, arg1);

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:setDownloadURL", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_setDownloadURL'.", &tolua_err);
#endif

	return 0;
}


int lua_wwupdatesystem_UpgradeAssetsMgrContainer_release(lua_State* tolua_S)
{
	int argc = 0;
	UpgradeAssetsMgrContainer* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "UpgradeAssetsMgrContainer", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (UpgradeAssetsMgrContainer*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_release'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		cobj->release();

		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpgradeAssetsMgrContainer:release", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwupdatesystem_UpgradeAssetsMgrContainer_release'.", &tolua_err);
#endif

	return 0;
}

int lua_register_wwupdatesystem_UpgradeAssetsMgrContainer(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "UpgradeAssetsMgrContainer");
	tolua_cclass(tolua_S, "UpgradeAssetsMgrContainer", "UpgradeAssetsMgrContainer", "", nullptr);

	tolua_beginmodule(tolua_S, "UpgradeAssetsMgrContainer");
	tolua_function(tolua_S, "getInstance", lua_wwupdatesystem_UpgradeAssetsMgrContainer_getInstance);
	tolua_function(tolua_S, "onSetUpAssetMgr", lua_wwupdatesystem_UpgradeAssetsMgrContainer_onSetUpAssetMgr);
	tolua_function(tolua_S, "onGetUpAssetMgr", lua_wwupdatesystem_UpgradeAssetsMgrContainer_onGetUpAssetMgr);
	tolua_function(tolua_S, "setUpdateUrl", lua_wwupdatesystem_UpgradeAssetsMgrContainer_setUpdateUrl);
	tolua_function(tolua_S, "setDownloadURL", lua_wwupdatesystem_UpgradeAssetsMgrContainer_setDownloadURL);
	tolua_function(tolua_S, "release", lua_wwupdatesystem_UpgradeAssetsMgrContainer_release);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(UpgradeAssetsMgrContainer).name();
	g_luaType[typeName] = "UpgradeAssetsMgrContainer";
	g_typeCast["UpgradeAssetsMgrContainer"] = "UpgradeAssetsMgrContainer";
	return 1;
}


int lua_register_wwupdatesystem_UpgradeEventDelegate(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "UpgradeEventDelegate");
	tolua_cclass(tolua_S, "UpgradeEventDelegate", "UpgradeEventDelegate", "", nullptr);

	tolua_beginmodule(tolua_S, "UpgradeEventDelegate");
	
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(UpgradeEventDelegate).name();
	g_luaType[typeName] = "UpgradeEventDelegate";
	g_typeCast["UpgradeEventDelegate"] = "UpgradeEventDelegate";
	return 1;
}


TOLUA_API int register_all_wwupdatesystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "ww", 0);
	tolua_beginmodule(tolua_S, "ww");

	lua_register_wwupdatesystem_UpgradeEventDelegate(tolua_S);

	lua_register_wwupdatesystem_UpgradeAssetsMgrContainer(tolua_S);
	lua_register_wwupdatesystem_UpgradeAssetsMgr(tolua_S);
	lua_register_wwupdatesystem_DownloadThreadState(tolua_S);
	tolua_endmodule(tolua_S);
	return 1;
}
