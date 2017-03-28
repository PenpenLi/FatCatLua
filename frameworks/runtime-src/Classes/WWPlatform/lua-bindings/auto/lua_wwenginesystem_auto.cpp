#include "lua_wwenginesystem_auto.hpp"
#include "../../EngineSystem/IPhoneTool.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwenginesystem_IPhoneTool_checkNetState(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_checkNetState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_checkNetState'", nullptr);
            return 0;
        }
        std::string ret = cobj->checkNetState();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:checkNetState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_checkNetState'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getPhoneHost(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getPhoneHost'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getPhoneHost'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPhoneHost();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getPhoneHost",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getPhoneHost'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getPhoneDeviceId(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getPhoneDeviceId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getPhoneDeviceId'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPhoneDeviceId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getPhoneDeviceId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getPhoneDeviceId'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_makePhoneCall(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_makePhoneCall'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IPhoneTool:makePhoneCall");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_makePhoneCall'", nullptr);
            return 0;
        }
        cobj->makePhoneCall(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:makePhoneCall",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_makePhoneCall'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getApnType(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getApnType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getApnType'", nullptr);
            return 0;
        }
        std::string ret = cobj->getApnType();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getApnType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getApnType'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_phoneVibrate(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_phoneVibrate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IPhoneTool:phoneVibrate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_phoneVibrate'", nullptr);
            return 0;
        }
        cobj->phoneVibrate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:phoneVibrate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_phoneVibrate'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getIpAddress(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getIpAddress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getIpAddress'", nullptr);
            return 0;
        }
        std::string ret = cobj->getIpAddress();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getIpAddress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getIpAddress'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getNetworkOperatorCode(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getNetworkOperatorCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getNetworkOperatorCode'", nullptr);
            return 0;
        }
        int ret = cobj->getNetworkOperatorCode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getNetworkOperatorCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getNetworkOperatorCode'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isLTOperator(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isLTOperator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isLTOperator'", nullptr);
            return 0;
        }
        bool ret = cobj->isLTOperator();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isLTOperator",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isLTOperator'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getFormatDayTime(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getFormatDayTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getFormatDayTime'", nullptr);
            return 0;
        }
        std::string ret = cobj->getFormatDayTime();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getFormatDayTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getFormatDayTime'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getPhoneModel(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getPhoneModel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getPhoneModel'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPhoneModel();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getPhoneModel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getPhoneModel'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_openPhotoAndSavePic(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_openPhotoAndSavePic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IPhoneTool:openPhotoAndSavePic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_openPhotoAndSavePic'", nullptr);
            return 0;
        }
        cobj->openPhotoAndSavePic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:openPhotoAndSavePic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_openPhotoAndSavePic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_randomAsciiString(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_randomAsciiString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IPhoneTool:randomAsciiString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_randomAsciiString'", nullptr);
            return 0;
        }
        std::string ret = cobj->randomAsciiString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:randomAsciiString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_randomAsciiString'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isMobileConnected(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isMobileConnected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isMobileConnected'", nullptr);
            return 0;
        }
        bool ret = cobj->isMobileConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isMobileConnected",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isMobileConnected'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getMacAddress(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getMacAddress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getMacAddress'", nullptr);
            return 0;
        }
        std::string ret = cobj->getMacAddress();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getMacAddress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getMacAddress'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getMobileModel(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getMobileModel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getMobileModel'", nullptr);
            return 0;
        }
        std::string ret = cobj->getMobileModel();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getMobileModel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getMobileModel'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isSdcardExist(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isSdcardExist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isSdcardExist'", nullptr);
            return 0;
        }
        bool ret = cobj->isSdcardExist();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isSdcardExist",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isSdcardExist'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getPhoneNetState(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getPhoneNetState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getPhoneNetState'", nullptr);
            return 0;
        }
        int ret = cobj->getPhoneNetState();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getPhoneNetState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getPhoneNetState'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isNetworkConnected(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isNetworkConnected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isNetworkConnected'", nullptr);
            return 0;
        }
        bool ret = cobj->isNetworkConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isNetworkConnected",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isNetworkConnected'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_exitGame(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_exitGame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_exitGame'", nullptr);
            return 0;
        }
        cobj->exitGame();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:exitGame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_exitGame'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_openLive800(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_openLive800'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IPhoneTool:openLive800");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_openLive800'", nullptr);
            return 0;
        }
        cobj->openLive800(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:openLive800",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_openLive800'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getVersionCode(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getVersionCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getVersionCode'", nullptr);
            return 0;
        }
        int ret = cobj->getVersionCode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getVersionCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getVersionCode'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_setScreenBrightness(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_setScreenBrightness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "IPhoneTool:setScreenBrightness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_setScreenBrightness'", nullptr);
            return 0;
        }
        cobj->setScreenBrightness(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:setScreenBrightness",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_setScreenBrightness'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_cancelVibrate(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_cancelVibrate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_cancelVibrate'", nullptr);
            return 0;
        }
        cobj->cancelVibrate();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:cancelVibrate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_cancelVibrate'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getPhoneMANUFACTURER(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getPhoneMANUFACTURER'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getPhoneMANUFACTURER'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPhoneMANUFACTURER();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getPhoneMANUFACTURER",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getPhoneMANUFACTURER'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isYDOperator(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isYDOperator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isYDOperator'", nullptr);
            return 0;
        }
        bool ret = cobj->isYDOperator();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isYDOperator",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isYDOperator'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getIMEI(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getIMEI'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getIMEI'", nullptr);
            return 0;
        }
        std::string ret = cobj->getIMEI();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getIMEI",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getIMEI'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_is2GNetWork(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_is2GNetWork'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_is2GNetWork'", nullptr);
            return 0;
        }
        bool ret = cobj->is2GNetWork();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:is2GNetWork",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_is2GNetWork'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_isDXOperator(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_isDXOperator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_isDXOperator'", nullptr);
            return 0;
        }
        bool ret = cobj->isDXOperator();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:isDXOperator",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_isDXOperator'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getICCID(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getICCID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getICCID'", nullptr);
            return 0;
        }
        std::string ret = cobj->getICCID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getICCID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getICCID'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_appUpdate(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_appUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IPhoneTool:appUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_appUpdate'", nullptr);
            return 0;
        }
        cobj->appUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:appUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_appUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getScreenHeight(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getScreenHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getScreenHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getScreenHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getScreenHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getScreenHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getVersionName(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getVersionName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getVersionName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getVersionName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getVersionName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getVersionName'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getExternalFilesDir(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getExternalFilesDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getExternalFilesDir'", nullptr);
            return 0;
        }
        std::string ret = cobj->getExternalFilesDir();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getExternalFilesDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getExternalFilesDir'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getWifiState(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getWifiState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getWifiState'", nullptr);
            return 0;
        }
        int ret = cobj->getWifiState();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getWifiState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getWifiState'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getSdcardPath(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getSdcardPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getSdcardPath'", nullptr);
            return 0;
        }
        std::string ret = cobj->getSdcardPath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getSdcardPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getSdcardPath'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getSimCardState(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getSimCardState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getSimCardState'", nullptr);
            return 0;
        }
        bool ret = cobj->getSimCardState();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getSimCardState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getSimCardState'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_openCameraAndSavePic(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_openCameraAndSavePic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IPhoneTool:openCameraAndSavePic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_openCameraAndSavePic'", nullptr);
            return 0;
        }
        cobj->openCameraAndSavePic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:openCameraAndSavePic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_openCameraAndSavePic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getIdCode(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getIdCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getIdCode'", nullptr);
            return 0;
        }
        std::string ret = cobj->getIdCode();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getIdCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getIdCode'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getScreenWidth(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getScreenWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getScreenWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getScreenWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getScreenWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getScreenWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_updateLatestApkPackage(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_updateLatestApkPackage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IPhoneTool:updateLatestApkPackage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_updateLatestApkPackage'", nullptr);
            return 0;
        }
        cobj->updateLatestApkPackage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:updateLatestApkPackage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_updateLatestApkPackage'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_decodeChar(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_decodeChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        char* arg0;
		
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "IPhoneTool:decodeChar"); 
		int len = arg0_tmp.length();
		arg0 = new char[len + 1];
		strcpy(arg0, arg0_tmp.c_str());
		//arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_decodeChar'", nullptr);
            return 0;
        }
        std::string ret = cobj->decodeChar(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:decodeChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_decodeChar'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getSDkVersion(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_getSDkVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getSDkVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->getSDkVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:getSDkVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getSDkVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_showMessage(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_showMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "IPhoneTool:showMessage"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "IPhoneTool:showMessage"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_showMessage'", nullptr);
            return 0;
        }
        cobj->showMessage(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:showMessage",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_showMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_openNetSetting(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_openNetSetting'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_openNetSetting'", nullptr);
            return 0;
        }
        cobj->openNetSetting();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:openNetSetting",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_openNetSetting'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_uploadHead(lua_State* tolua_S)
{
    int argc = 0;
    IPhoneTool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IPhoneTool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwenginesystem_IPhoneTool_uploadHead'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IPhoneTool:uploadHead");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IPhoneTool:uploadHead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_uploadHead'", nullptr);
            return 0;
        }
        cobj->uploadHead(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IPhoneTool:uploadHead",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_uploadHead'.",&tolua_err);
#endif

    return 0;
}
int lua_wwenginesystem_IPhoneTool_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IPhoneTool",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwenginesystem_IPhoneTool_getInstance'", nullptr);
            return 0;
        }
        IPhoneTool* ret = IPhoneTool::getInstance();
        object_to_luaval<IPhoneTool>(tolua_S, "IPhoneTool",(IPhoneTool*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IPhoneTool:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwenginesystem_IPhoneTool_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_wwenginesystem_IPhoneTool_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IPhoneTool)");
    return 0;
}

int lua_register_wwenginesystem_IPhoneTool(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IPhoneTool");
    tolua_cclass(tolua_S,"IPhoneTool","IPhoneTool","",nullptr);

    tolua_beginmodule(tolua_S,"IPhoneTool");
        tolua_function(tolua_S,"checkNetState",lua_wwenginesystem_IPhoneTool_checkNetState);
        tolua_function(tolua_S,"getPhoneHost",lua_wwenginesystem_IPhoneTool_getPhoneHost);
        tolua_function(tolua_S,"getPhoneDeviceId",lua_wwenginesystem_IPhoneTool_getPhoneDeviceId);
        tolua_function(tolua_S,"makePhoneCall",lua_wwenginesystem_IPhoneTool_makePhoneCall);
        tolua_function(tolua_S,"getApnType",lua_wwenginesystem_IPhoneTool_getApnType);
        tolua_function(tolua_S,"phoneVibrate",lua_wwenginesystem_IPhoneTool_phoneVibrate);
        tolua_function(tolua_S,"getIpAddress",lua_wwenginesystem_IPhoneTool_getIpAddress);
        tolua_function(tolua_S,"getNetworkOperatorCode",lua_wwenginesystem_IPhoneTool_getNetworkOperatorCode);
        tolua_function(tolua_S,"isLTOperator",lua_wwenginesystem_IPhoneTool_isLTOperator);
        tolua_function(tolua_S,"getFormatDayTime",lua_wwenginesystem_IPhoneTool_getFormatDayTime);
        tolua_function(tolua_S,"getPhoneModel",lua_wwenginesystem_IPhoneTool_getPhoneModel);
        tolua_function(tolua_S,"openPhotoAndSavePic",lua_wwenginesystem_IPhoneTool_openPhotoAndSavePic);
        tolua_function(tolua_S,"randomAsciiString",lua_wwenginesystem_IPhoneTool_randomAsciiString);
        tolua_function(tolua_S,"isMobileConnected",lua_wwenginesystem_IPhoneTool_isMobileConnected);
        tolua_function(tolua_S,"getMacAddress",lua_wwenginesystem_IPhoneTool_getMacAddress);
        tolua_function(tolua_S,"getMobileModel",lua_wwenginesystem_IPhoneTool_getMobileModel);
        tolua_function(tolua_S,"isSdcardExist",lua_wwenginesystem_IPhoneTool_isSdcardExist);
        tolua_function(tolua_S,"getPhoneNetState",lua_wwenginesystem_IPhoneTool_getPhoneNetState);
        tolua_function(tolua_S,"isNetworkConnected",lua_wwenginesystem_IPhoneTool_isNetworkConnected);
        tolua_function(tolua_S,"exitGame",lua_wwenginesystem_IPhoneTool_exitGame);
        tolua_function(tolua_S,"openLive800",lua_wwenginesystem_IPhoneTool_openLive800);
        tolua_function(tolua_S,"getVersionCode",lua_wwenginesystem_IPhoneTool_getVersionCode);
        tolua_function(tolua_S,"setScreenBrightness",lua_wwenginesystem_IPhoneTool_setScreenBrightness);
        tolua_function(tolua_S,"cancelVibrate",lua_wwenginesystem_IPhoneTool_cancelVibrate);
        tolua_function(tolua_S,"getPhoneMANUFACTURER",lua_wwenginesystem_IPhoneTool_getPhoneMANUFACTURER);
        tolua_function(tolua_S,"isYDOperator",lua_wwenginesystem_IPhoneTool_isYDOperator);
        tolua_function(tolua_S,"getIMEI",lua_wwenginesystem_IPhoneTool_getIMEI);
        tolua_function(tolua_S,"is2GNetWork",lua_wwenginesystem_IPhoneTool_is2GNetWork);
        tolua_function(tolua_S,"isDXOperator",lua_wwenginesystem_IPhoneTool_isDXOperator);
        tolua_function(tolua_S,"getICCID",lua_wwenginesystem_IPhoneTool_getICCID);
        tolua_function(tolua_S,"appUpdate",lua_wwenginesystem_IPhoneTool_appUpdate);
        tolua_function(tolua_S,"getScreenHeight",lua_wwenginesystem_IPhoneTool_getScreenHeight);
        tolua_function(tolua_S,"getVersionName",lua_wwenginesystem_IPhoneTool_getVersionName);
        tolua_function(tolua_S,"getExternalFilesDir",lua_wwenginesystem_IPhoneTool_getExternalFilesDir);
        tolua_function(tolua_S,"getWifiState",lua_wwenginesystem_IPhoneTool_getWifiState);
        tolua_function(tolua_S,"getSdcardPath",lua_wwenginesystem_IPhoneTool_getSdcardPath);
        tolua_function(tolua_S,"getSimCardState",lua_wwenginesystem_IPhoneTool_getSimCardState);
        tolua_function(tolua_S,"openCameraAndSavePic",lua_wwenginesystem_IPhoneTool_openCameraAndSavePic);
        tolua_function(tolua_S,"getIdCode",lua_wwenginesystem_IPhoneTool_getIdCode);
        tolua_function(tolua_S,"getScreenWidth",lua_wwenginesystem_IPhoneTool_getScreenWidth);
        tolua_function(tolua_S,"updateLatestApkPackage",lua_wwenginesystem_IPhoneTool_updateLatestApkPackage);
        tolua_function(tolua_S,"decodeChar",lua_wwenginesystem_IPhoneTool_decodeChar);
        tolua_function(tolua_S,"getSDkVersion",lua_wwenginesystem_IPhoneTool_getSDkVersion);
        tolua_function(tolua_S,"showMessage",lua_wwenginesystem_IPhoneTool_showMessage);
        tolua_function(tolua_S,"openNetSetting",lua_wwenginesystem_IPhoneTool_openNetSetting);
        tolua_function(tolua_S,"uploadHead",lua_wwenginesystem_IPhoneTool_uploadHead);
        tolua_function(tolua_S,"getInstance", lua_wwenginesystem_IPhoneTool_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IPhoneTool).name();
    g_luaType[typeName] = "IPhoneTool";
    g_typeCast["IPhoneTool"] = "IPhoneTool";
    return 1;
}
TOLUA_API int register_all_wwenginesystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwenginesystem_IPhoneTool(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

