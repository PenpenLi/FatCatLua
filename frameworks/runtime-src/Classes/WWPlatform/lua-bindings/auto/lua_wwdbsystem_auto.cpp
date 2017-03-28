#include "lua_wwdbsystem_auto.hpp"
#include "../../DBSystem/WWGameData.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwdbsystem_WWGameData_setIntegerForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_setIntegerForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:setIntegerForKey"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWGameData:setIntegerForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_setIntegerForKey'", nullptr);
            return 0;
        }
        cobj->setIntegerForKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:setIntegerForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_setIntegerForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_getFloatForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_getFloatForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getFloatForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "WWGameData:getFloatForKey");

            if (!ok) { break; }
            double ret = cobj->getFloatForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getFloatForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            double ret = cobj->getFloatForKey(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWGameData:getFloatForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getFloatForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_getBoolForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_getBoolForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getBoolForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "WWGameData:getBoolForKey");

            if (!ok) { break; }
            bool ret = cobj->getBoolForKey(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getBoolForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->getBoolForKey(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWGameData:getBoolForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getBoolForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_setDoubleForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_setDoubleForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:setDoubleForKey"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1, "WWGameData:setDoubleForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_setDoubleForKey'", nullptr);
            return 0;
        }
        cobj->setDoubleForKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:setDoubleForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_setDoubleForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_setFloatForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_setFloatForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:setFloatForKey"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1, "WWGameData:setFloatForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_setFloatForKey'", nullptr);
            return 0;
        }
        cobj->setFloatForKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:setFloatForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_setFloatForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_getStringForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_getStringForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getStringForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "WWGameData:getStringForKey");

            if (!ok) { break; }
            std::string ret = cobj->getStringForKey(arg0, arg1);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getStringForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            std::string ret = cobj->getStringForKey(arg0);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWGameData:getStringForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getStringForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_setStringForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_setStringForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        std::string arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:setStringForKey"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "WWGameData:setStringForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_setStringForKey'", nullptr);
            return 0;
        }
        cobj->setStringForKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:setStringForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_setStringForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_flush(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_flush'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_flush'", nullptr);
            return 0;
        }
        cobj->flush();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:flush",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_flush'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_getIntegerForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_getIntegerForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getIntegerForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWGameData:getIntegerForKey");

            if (!ok) { break; }
            int ret = cobj->getIntegerForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getIntegerForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int ret = cobj->getIntegerForKey(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWGameData:getIntegerForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getIntegerForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_getDoubleForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_getDoubleForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getDoubleForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "WWGameData:getDoubleForKey");

            if (!ok) { break; }
            double ret = cobj->getDoubleForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:getDoubleForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            double ret = cobj->getDoubleForKey(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWGameData:getDoubleForKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getDoubleForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_setBoolForKey(lua_State* tolua_S)
{
    int argc = 0;
    WWGameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWGameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwdbsystem_WWGameData_setBoolForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWGameData:setBoolForKey"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "WWGameData:setBoolForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_setBoolForKey'", nullptr);
            return 0;
        }
        cobj->setBoolForKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWGameData:setBoolForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_setBoolForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_wwdbsystem_WWGameData_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_destroyInstance'", nullptr);
            return 0;
        }
        WWGameData::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWGameData:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_wwdbsystem_WWGameData_getXMLFilePath(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_getXMLFilePath'", nullptr);
            return 0;
        }
        const std::string& ret = WWGameData::getXMLFilePath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWGameData:getXMLFilePath",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getXMLFilePath'.",&tolua_err);
#endif
    return 0;
}
int lua_wwdbsystem_WWGameData_isXMLFileExist(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_isXMLFileExist'", nullptr);
            return 0;
        }
        bool ret = WWGameData::isXMLFileExist();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWGameData:isXMLFileExist",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_isXMLFileExist'.",&tolua_err);
#endif
    return 0;
}
int lua_wwdbsystem_WWGameData_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWGameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwdbsystem_WWGameData_getInstance'", nullptr);
            return 0;
        }
        WWGameData* ret = WWGameData::getInstance();
        object_to_luaval<WWGameData>(tolua_S, "WWGameData",(WWGameData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWGameData:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwdbsystem_WWGameData_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_wwdbsystem_WWGameData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWGameData)");
    return 0;
}

int lua_register_wwdbsystem_WWGameData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWGameData");
    tolua_cclass(tolua_S,"WWGameData","WWGameData","",nullptr);

    tolua_beginmodule(tolua_S,"WWGameData");
        tolua_function(tolua_S,"setIntegerForKey",lua_wwdbsystem_WWGameData_setIntegerForKey);
        tolua_function(tolua_S,"getFloatForKey",lua_wwdbsystem_WWGameData_getFloatForKey);
        tolua_function(tolua_S,"getBoolForKey",lua_wwdbsystem_WWGameData_getBoolForKey);
        tolua_function(tolua_S,"setDoubleForKey",lua_wwdbsystem_WWGameData_setDoubleForKey);
        tolua_function(tolua_S,"setFloatForKey",lua_wwdbsystem_WWGameData_setFloatForKey);
        tolua_function(tolua_S,"getStringForKey",lua_wwdbsystem_WWGameData_getStringForKey);
        tolua_function(tolua_S,"setStringForKey",lua_wwdbsystem_WWGameData_setStringForKey);
        tolua_function(tolua_S,"flush",lua_wwdbsystem_WWGameData_flush);
        tolua_function(tolua_S,"getIntegerForKey",lua_wwdbsystem_WWGameData_getIntegerForKey);
        tolua_function(tolua_S,"getDoubleForKey",lua_wwdbsystem_WWGameData_getDoubleForKey);
        tolua_function(tolua_S,"setBoolForKey",lua_wwdbsystem_WWGameData_setBoolForKey);
        tolua_function(tolua_S,"destroyInstance", lua_wwdbsystem_WWGameData_destroyInstance);
        tolua_function(tolua_S,"getXMLFilePath", lua_wwdbsystem_WWGameData_getXMLFilePath);
        tolua_function(tolua_S,"isXMLFileExist", lua_wwdbsystem_WWGameData_isXMLFileExist);
        tolua_function(tolua_S,"getInstance", lua_wwdbsystem_WWGameData_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWGameData).name();
    g_luaType[typeName] = "WWGameData";
    g_typeCast["WWGameData"] = "WWGameData";
    return 1;
}
TOLUA_API int register_all_wwdbsystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwdbsystem_WWGameData(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

