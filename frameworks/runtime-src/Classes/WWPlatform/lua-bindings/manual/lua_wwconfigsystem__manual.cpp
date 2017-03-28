#include "lua_wwconfigsystem__manual.hpp"
#include "../../VariateSystem/WWConfigManager.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "../WWLuaConversions.h"
#include "WWPlatform/lua-bindings/WWLuaRegistery.h"
#include "scripting/lua-bindings/manual/lua_module_register.h"
#include "WWPlatform/VariateSystem/LoadCsv.h"

int lua_wwconfigsystem_WWConfigManager_getModuleConfig(lua_State* tolua_S)
{
    int argc = 0;
    WWConfigManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWConfigManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWConfigManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwconfigsystem_WWConfigManager_getModuleConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SystemID arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWConfigManager:getModuleConfig");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwconfigsystem_WWConfigManager_getModuleConfig'", nullptr);
            return 0;
        }
        WWSystemConfig ret = cobj->getModuleConfig(arg0);
		WWSystemConfig_to_luaval(tolua_S, ret);
      //  #pragma warning NO CONVERSION FROM NATIVE FOR WWSystemConfig;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWConfigManager:getModuleConfig",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwconfigsystem_WWConfigManager_getModuleConfig'.",&tolua_err);
#endif

    return 0;
}


int lua_wwconfigsystem_WWConfigManager_reStartGame(lua_State* tolua_S)
{
	int argc = 0;
	WWConfigManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "WWConfigManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (WWConfigManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_wwconfigsystem_WWConfigManager_reStartGame'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		//LuaEngine::getInstance()->getLuaStack()->clean();
		// register lua module
		
		delete LuaEngine::getInstance();
		auto engine = LuaEngine::getInstance();
		ScriptEngineManager::getInstance()->setScriptEngine(engine);
		lua_State* L = engine->getLuaStack()->getLuaState();
		lua_module_register(L);

		// 大坑：需要先获取_G，否则在register时，LuaJIT内部会崩溃。
		lua_getfield(L, LUA_GLOBALSINDEX, "_G");
		register_wwplatform_tolua(L);
		lua_pop(L, 1);

		lua_pushcfunction(L, luafunc_load_csv);
		lua_setglobal(L, "load_csv");

		LuaStack* stack = engine->getLuaStack();


		stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));
		//register custom function
		//LuaStack* stack = engine->getLuaStack();
		//register_custom_function(stack->getLuaState());

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
		// NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
		auto runtimeEngine = RuntimeEngine::getInstance();
		runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
		runtimeEngine->start();
#else
		//auto socketTest = new SocketTest;
		//socketTest->doTest();

		//auto netTest = new NetWorkTest;
		//netTest->doTest();

		engine->executeScriptFile("src/main.lua");
		
#endif

		
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWConfigManager:getModuleConfig", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_wwconfigsystem_WWConfigManager_reStartGame'.", &tolua_err);
#endif

	return 0;
}



int lua_register_wwconfigsystem_WWConfigManager_manual(lua_State* tolua_S)
{

	lua_pushstring(tolua_S, "WWConfigManager");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "getModuleConfig", lua_wwconfigsystem_WWConfigManager_getModuleConfig);
		tolua_function(tolua_S, "reStartGame", lua_wwconfigsystem_WWConfigManager_reStartGame);
	}
	lua_pop(tolua_S, 1);

    return 1;
}
TOLUA_API int register_all_wwconfigsystem_manual(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwconfigsystem_WWConfigManager_manual(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

