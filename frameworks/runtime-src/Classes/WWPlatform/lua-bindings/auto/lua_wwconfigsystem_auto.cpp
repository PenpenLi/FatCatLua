#include "lua_wwconfigsystem_auto.hpp"
#include "../../VariateSystem/WWConfigManager.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwconfigsystem_WWConfigManager_initConfig(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwconfigsystem_WWConfigManager_initConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWConfigManager:initConfig"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwconfigsystem_WWConfigManager_initConfig'", nullptr);
            return 0;
        }
        cobj->initConfig(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWConfigManager:initConfig",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwconfigsystem_WWConfigManager_initConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_wwconfigsystem_WWConfigManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWConfigManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwconfigsystem_WWConfigManager_getInstance'", nullptr);
            return 0;
        }
        WWConfigManager* ret = WWConfigManager::getInstance();
        object_to_luaval<WWConfigManager>(tolua_S, "WWConfigManager",(WWConfigManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWConfigManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwconfigsystem_WWConfigManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_wwconfigsystem_WWConfigManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    WWConfigManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwconfigsystem_WWConfigManager_constructor'", nullptr);
            return 0;
        }
        cobj = new WWConfigManager();
        tolua_pushusertype(tolua_S,(void*)cobj,"WWConfigManager");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWConfigManager:WWConfigManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_wwconfigsystem_WWConfigManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_wwconfigsystem_WWConfigManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWConfigManager)");
    return 0;
}

int lua_register_wwconfigsystem_WWConfigManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWConfigManager");
    tolua_cclass(tolua_S,"WWConfigManager","WWConfigManager","",nullptr);

    tolua_beginmodule(tolua_S,"WWConfigManager");
        tolua_function(tolua_S,"new",lua_wwconfigsystem_WWConfigManager_constructor);
      
        tolua_function(tolua_S,"initConfig",lua_wwconfigsystem_WWConfigManager_initConfig);
        tolua_function(tolua_S,"getInstance", lua_wwconfigsystem_WWConfigManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWConfigManager).name();
    g_luaType[typeName] = "WWConfigManager";
    g_typeCast["WWConfigManager"] = "WWConfigManager";
    return 1;
}
TOLUA_API int register_all_wwconfigsystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwconfigsystem_WWConfigManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

