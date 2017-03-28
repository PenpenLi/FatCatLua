#include "lua_wweventsystem_auto.hpp"
#include "../../EventSystem/WWMsgManager.h"
#include "../../EventSystem/MsgLuaFilter.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wweventsystem_WWMsgManager_sendBuffer(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_sendBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        WWBuffer* arg0;

        ok &= luaval_to_object<WWBuffer>(tolua_S, 2, "WWBuffer",&arg0, "WWMsgManager:sendBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_sendBuffer'", nullptr);
            return 0;
        }
        cobj->sendBuffer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:sendBuffer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_sendBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_checkToConnect(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_checkToConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_checkToConnect'", nullptr);
            return 0;
        }
        cobj->checkToConnect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:checkToConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_checkToConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_getHasConnected(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_getHasConnected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_getHasConnected'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:getHasConnected",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_getHasConnected'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_isConnect(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_isConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_isConnect'", nullptr);
            return 0;
        }
        bool ret = cobj->isConnect();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:isConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_isConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_logout(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_logout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_logout'", nullptr);
            return 0;
        }
        cobj->logout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:logout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_logout'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_connect(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_connect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_connect'", nullptr);
            return 0;
        }
        cobj->connect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:connect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_connect'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_setNewSocketUrl(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_setNewSocketUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "WWMsgManager:setNewSocketUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_setNewSocketUrl'", nullptr);
            return 0;
        }
        cobj->setNewSocketUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:setNewSocketUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_setNewSocketUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_hasConnected(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_hasConnected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_hasConnected'", nullptr);
            return 0;
        }
        bool ret = cobj->hasConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:hasConnected",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_hasConnected'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_sendBufferNow(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_sendBufferNow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        WWBuffer* arg0;

        ok &= luaval_to_object<WWBuffer>(tolua_S, 2, "WWBuffer",&arg0, "WWMsgManager:sendBufferNow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_sendBufferNow'", nullptr);
            return 0;
        }
        cobj->sendBufferNow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:sendBufferNow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_sendBufferNow'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_parallelConnect(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_parallelConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::vector<std::string> arg0;
        std::vector<int> arg1;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "WWMsgManager:parallelConnect");

        ok &= luaval_to_std_vector_int(tolua_S, 3, &arg1, "WWMsgManager:parallelConnect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_parallelConnect'", nullptr);
            return 0;
        }
        cobj->parallelConnect(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:parallelConnect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_parallelConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_enterBackGround(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_WWMsgManager_enterBackGround'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_enterBackGround'", nullptr);
            return 0;
        }
        cobj->enterBackGround();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:enterBackGround",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_enterBackGround'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_WWMsgManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_getInstance'", nullptr);
            return 0;
        }
        WWMsgManager* ret = WWMsgManager::getInstance();
        object_to_luaval<WWMsgManager>(tolua_S, "WWMsgManager",(WWMsgManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWMsgManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_wweventsystem_WWMsgManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    WWMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_WWMsgManager_constructor'", nullptr);
            return 0;
        }
        cobj = new WWMsgManager();
        tolua_pushusertype(tolua_S,(void*)cobj,"WWMsgManager");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWMsgManager:WWMsgManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_WWMsgManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_wweventsystem_WWMsgManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWMsgManager)");
    return 0;
}

int lua_register_wweventsystem_WWMsgManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWMsgManager");
    tolua_cclass(tolua_S,"WWMsgManager","WWMsgManager","NetEventDelegate",nullptr);

    tolua_beginmodule(tolua_S,"WWMsgManager");
        tolua_function(tolua_S,"new",lua_wweventsystem_WWMsgManager_constructor);
        tolua_function(tolua_S,"sendBuffer",lua_wweventsystem_WWMsgManager_sendBuffer);
        tolua_function(tolua_S,"checkToConnect",lua_wweventsystem_WWMsgManager_checkToConnect);
        tolua_function(tolua_S,"getHasConnected",lua_wweventsystem_WWMsgManager_getHasConnected);
        tolua_function(tolua_S,"isConnect",lua_wweventsystem_WWMsgManager_isConnect);
        tolua_function(tolua_S,"logout",lua_wweventsystem_WWMsgManager_logout);
        tolua_function(tolua_S,"connect",lua_wweventsystem_WWMsgManager_connect);
        tolua_function(tolua_S,"setNewSocketUrl",lua_wweventsystem_WWMsgManager_setNewSocketUrl);
        tolua_function(tolua_S,"hasConnected",lua_wweventsystem_WWMsgManager_hasConnected);
        tolua_function(tolua_S,"sendBufferNow",lua_wweventsystem_WWMsgManager_sendBufferNow);
        tolua_function(tolua_S,"parallelConnect",lua_wweventsystem_WWMsgManager_parallelConnect);
        tolua_function(tolua_S,"enterBackGround",lua_wweventsystem_WWMsgManager_enterBackGround);
        tolua_function(tolua_S,"getInstance", lua_wweventsystem_WWMsgManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWMsgManager).name();
    g_luaType[typeName] = "WWMsgManager";
    g_typeCast["WWMsgManager"] = "WWMsgManager";
    return 1;
}

int lua_wweventsystem_MsgLuaFilter_unRegisterUpgradeEvent(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_unRegisterUpgradeEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:unRegisterUpgradeEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_unRegisterUpgradeEvent'", nullptr);
            return 0;
        }
        cobj->unRegisterUpgradeEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:unRegisterUpgradeEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_unRegisterUpgradeEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_clearNetEventId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_clearNetEventId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_clearNetEventId'", nullptr);
            return 0;
        }
        cobj->clearNetEventId();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:clearNetEventId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_clearNetEventId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_clearRootMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_clearRootMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_clearRootMsgId'", nullptr);
            return 0;
        }
        cobj->clearRootMsgId();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:clearRootMsgId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_clearRootMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_onRootMessageReceived(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_onRootMessageReceived'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        WWBuffer* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:onRootMessageReceived");

        ok &= luaval_to_object<WWBuffer>(tolua_S, 3, "WWBuffer",&arg1, "MsgLuaFilter:onRootMessageReceived");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_onRootMessageReceived'", nullptr);
            return 0;
        }
        bool ret = cobj->onRootMessageReceived(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:onRootMessageReceived",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_onRootMessageReceived'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_unRegisterMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_unRegisterMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:unRegisterMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_unRegisterMsgId'", nullptr);
            return 0;
        }
        cobj->unRegisterMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:unRegisterMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_unRegisterMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_onNetEvent(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_onNetEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        NetEvent arg0;
        cocos2d::LuaValue* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:onNetEvent");

        ok &= luaval_to_object<cocos2d::LuaValue>(tolua_S, 3, "cc.LuaValue",&arg1, "MsgLuaFilter:onNetEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_onNetEvent'", nullptr);
            return 0;
        }
        cobj->onNetEvent(arg0, *arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:onNetEvent",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_onNetEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_onMessageReceived(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_onMessageReceived'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        WWBuffer* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:onMessageReceived");

        ok &= luaval_to_object<WWBuffer>(tolua_S, 3, "WWBuffer",&arg1, "MsgLuaFilter:onMessageReceived");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_onMessageReceived'", nullptr);
            return 0;
        }
        bool ret = cobj->onMessageReceived(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:onMessageReceived",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_onMessageReceived'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_unRegisterGlobalMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_unRegisterGlobalMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:unRegisterGlobalMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_unRegisterGlobalMsgId'", nullptr);
            return 0;
        }
        cobj->unRegisterGlobalMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:unRegisterGlobalMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_unRegisterGlobalMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_registerUpgradeEventId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_registerUpgradeEventId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:registerUpgradeEventId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_registerUpgradeEventId'", nullptr);
            return 0;
        }
        cobj->registerUpgradeEventId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:registerUpgradeEventId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_registerUpgradeEventId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_unRegisterRootMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_unRegisterRootMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:unRegisterRootMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_unRegisterRootMsgId'", nullptr);
            return 0;
        }
        cobj->unRegisterRootMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:unRegisterRootMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_unRegisterRootMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_registerGlobalMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_registerGlobalMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:registerGlobalMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_registerGlobalMsgId'", nullptr);
            return 0;
        }
        cobj->registerGlobalMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:registerGlobalMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_registerGlobalMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_registerNetEventId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_registerNetEventId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:registerNetEventId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_registerNetEventId'", nullptr);
            return 0;
        }
        cobj->registerNetEventId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:registerNetEventId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_registerNetEventId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_clearUpgradeEvent(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_clearUpgradeEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_clearUpgradeEvent'", nullptr);
            return 0;
        }
        cobj->clearUpgradeEvent();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:clearUpgradeEvent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_clearUpgradeEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_bindMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_bindMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        cocos2d::ValueVector arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:bindMsgId");

        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, "MsgLuaFilter:bindMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_bindMsgId'", nullptr);
            return 0;
        }
        cobj->bindMsgId(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:bindMsgId",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_bindMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_clearMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_clearMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_clearMsgId'", nullptr);
            return 0;
        }
        cobj->clearMsgId();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:clearMsgId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_clearMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_registerRootMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_registerRootMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:registerRootMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_registerRootMsgId'", nullptr);
            return 0;
        }
        cobj->registerRootMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:registerRootMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_registerRootMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_clearGlobalMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_clearGlobalMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_clearGlobalMsgId'", nullptr);
            return 0;
        }
        cobj->clearGlobalMsgId();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:clearGlobalMsgId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_clearGlobalMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_registerMsgId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_registerMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:registerMsgId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_registerMsgId'", nullptr);
            return 0;
        }
        cobj->registerMsgId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:registerMsgId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_registerMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_onUpdateEvent(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_onUpdateEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        UpgradeEvent arg0;
        cocos2d::LuaValue* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:onUpdateEvent");

        ok &= luaval_to_object<cocos2d::LuaValue>(tolua_S, 3, "cc.LuaValue",&arg1, "MsgLuaFilter:onUpdateEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_onUpdateEvent'", nullptr);
            return 0;
        }
        cobj->onUpdateEvent(arg0, *arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:onUpdateEvent",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_onUpdateEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_unRegisterNetEventId(lua_State* tolua_S)
{
    int argc = 0;
    MsgLuaFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MsgLuaFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wweventsystem_MsgLuaFilter_unRegisterNetEventId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MsgLuaFilter:unRegisterNetEventId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_unRegisterNetEventId'", nullptr);
            return 0;
        }
        cobj->unRegisterNetEventId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MsgLuaFilter:unRegisterNetEventId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_unRegisterNetEventId'.",&tolua_err);
#endif

    return 0;
}
int lua_wweventsystem_MsgLuaFilter_deleteInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_deleteInstance'", nullptr);
            return 0;
        }
        MsgLuaFilter::deleteInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MsgLuaFilter:deleteInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_deleteInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_wweventsystem_MsgLuaFilter_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MsgLuaFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wweventsystem_MsgLuaFilter_getInstance'", nullptr);
            return 0;
        }
        MsgLuaFilter* ret = MsgLuaFilter::getInstance();
        object_to_luaval<MsgLuaFilter>(tolua_S, "MsgLuaFilter",(MsgLuaFilter*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MsgLuaFilter:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wweventsystem_MsgLuaFilter_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_wweventsystem_MsgLuaFilter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MsgLuaFilter)");
    return 0;
}

int lua_register_wweventsystem_MsgLuaFilter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MsgLuaFilter");
    tolua_cclass(tolua_S,"MsgLuaFilter","MsgLuaFilter","",nullptr);

    tolua_beginmodule(tolua_S,"MsgLuaFilter");
        tolua_function(tolua_S,"unRegisterUpgradeEvent",lua_wweventsystem_MsgLuaFilter_unRegisterUpgradeEvent);
        tolua_function(tolua_S,"clearNetEventId",lua_wweventsystem_MsgLuaFilter_clearNetEventId);
        tolua_function(tolua_S,"clearRootMsgId",lua_wweventsystem_MsgLuaFilter_clearRootMsgId);
        tolua_function(tolua_S,"onRootMessageReceived",lua_wweventsystem_MsgLuaFilter_onRootMessageReceived);
        tolua_function(tolua_S,"unRegisterMsgId",lua_wweventsystem_MsgLuaFilter_unRegisterMsgId);
        tolua_function(tolua_S,"onNetEvent",lua_wweventsystem_MsgLuaFilter_onNetEvent);
        tolua_function(tolua_S,"onMessageReceived",lua_wweventsystem_MsgLuaFilter_onMessageReceived);
        tolua_function(tolua_S,"unRegisterGlobalMsgId",lua_wweventsystem_MsgLuaFilter_unRegisterGlobalMsgId);
        tolua_function(tolua_S,"registerUpgradeEventId",lua_wweventsystem_MsgLuaFilter_registerUpgradeEventId);
        tolua_function(tolua_S,"unRegisterRootMsgId",lua_wweventsystem_MsgLuaFilter_unRegisterRootMsgId);
        tolua_function(tolua_S,"registerGlobalMsgId",lua_wweventsystem_MsgLuaFilter_registerGlobalMsgId);
        tolua_function(tolua_S,"registerNetEventId",lua_wweventsystem_MsgLuaFilter_registerNetEventId);
        tolua_function(tolua_S,"clearUpgradeEvent",lua_wweventsystem_MsgLuaFilter_clearUpgradeEvent);
        tolua_function(tolua_S,"bindMsgId",lua_wweventsystem_MsgLuaFilter_bindMsgId);
        tolua_function(tolua_S,"clearMsgId",lua_wweventsystem_MsgLuaFilter_clearMsgId);
        tolua_function(tolua_S,"registerRootMsgId",lua_wweventsystem_MsgLuaFilter_registerRootMsgId);
        tolua_function(tolua_S,"clearGlobalMsgId",lua_wweventsystem_MsgLuaFilter_clearGlobalMsgId);
        tolua_function(tolua_S,"registerMsgId",lua_wweventsystem_MsgLuaFilter_registerMsgId);
        tolua_function(tolua_S,"onUpdateEvent",lua_wweventsystem_MsgLuaFilter_onUpdateEvent);
        tolua_function(tolua_S,"unRegisterNetEventId",lua_wweventsystem_MsgLuaFilter_unRegisterNetEventId);
        tolua_function(tolua_S,"deleteInstance", lua_wweventsystem_MsgLuaFilter_deleteInstance);
        tolua_function(tolua_S,"getInstance", lua_wweventsystem_MsgLuaFilter_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MsgLuaFilter).name();
    g_luaType[typeName] = "MsgLuaFilter";
    g_typeCast["MsgLuaFilter"] = "MsgLuaFilter";
    return 1;
}
TOLUA_API int register_all_wweventsystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wweventsystem_MsgLuaFilter(tolua_S);
	lua_register_wweventsystem_WWMsgManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

