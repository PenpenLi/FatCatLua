#include "lua_wwnetsystem_auto.hpp"
#include "../../NetSystem/WWBuffer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwnetsystem_WWBuffer_readUChar(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readUChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readUChar'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->readUChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readUChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readUChar'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_setWriterIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_setWriterIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:setWriterIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_setWriterIndex'", nullptr);
            return 0;
        }
        cobj->setWriterIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:setWriterIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_setWriterIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readBoolean(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readBoolean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readBoolean'", nullptr);
            return 0;
        }
        bool ret = cobj->readBoolean();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readBoolean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readBoolean'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:writeData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWBuffer:writeData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeData'", nullptr);
            return 0;
        }
        cobj->writeData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeString(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:writeString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeString'", nullptr);
            return 0;
        }
        cobj->writeString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeString'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeShort(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "WWBuffer:writeShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeShort'", nullptr);
            return 0;
        }
        cobj->writeShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeShort'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readWholeData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readWholeData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readWholeData'", nullptr);
            return 0;
        }
        char* ret = cobj->readWholeData();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readWholeData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readWholeData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:readData"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWBuffer:readData");

            if (!ok) { break; }

			char* c;
			const int len = strlen(arg0);
			c = new char[len + 1];
			strcpy(c, arg0);

            cobj->readData(c, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:readData");

            if (!ok) { break; }
            WWBuffer* ret = cobj->readData(arg0);
            object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWBuffer:readData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeDouble(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "WWBuffer:writeDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeDouble'", nullptr);
            return 0;
        }
        cobj->writeDouble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_getBufferSize(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_getBufferSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_getBufferSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getBufferSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:getBufferSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_getBufferSize'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readChar(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readChar'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readChar'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readShort(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_markReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_markReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_markReaderIndex'", nullptr);
            return 0;
        }
        cobj->markReaderIndex();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:markReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_markReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveRight(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:moveRight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveRight'", nullptr);
            return 0;
        }
        cobj->moveRight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveRight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveRight'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readLongLong(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readLongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readLongLong'", nullptr);
            return 0;
        }
        long long ret = cobj->readLongLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readLongLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readLongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readUShort(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readUShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readUShort'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->readUShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readUShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_getReadableSize(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_getReadableSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_getReadableSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getReadableSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:getReadableSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_getReadableSize'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readChar3ToInt(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readChar3ToInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readChar3ToInt'", nullptr);
            return 0;
        }
        int ret = cobj->readChar3ToInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readChar3ToInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readChar3ToInt'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_getReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_getReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_getReaderIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getReaderIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:getReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_getReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_capacity(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_capacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_capacity'", nullptr);
            return 0;
        }
        int ret = cobj->capacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:capacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_capacity'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_getWriterIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_getWriterIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_getWriterIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getWriterIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:getWriterIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_getWriterIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readUInt(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readUInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readUInt'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->readUInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readUInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readUInt'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_discardReadContent(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_discardReadContent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_discardReadContent'", nullptr);
            return 0;
        }
        cobj->discardReadContent();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:discardReadContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_discardReadContent'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeUChar(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeUChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "WWBuffer:writeUChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeUChar'", nullptr);
            return 0;
        }
        cobj->writeUChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeUChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeUChar'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_setReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_setReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:setReaderIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_setReaderIndex'", nullptr);
            return 0;
        }
        cobj->setReaderIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:setReaderIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_setReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readString(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:readString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeLengthAndData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeLengthAndData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:writeLengthAndData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWBuffer:writeLengthAndData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeLengthAndData'", nullptr);
            return 0;
        }
        cobj->writeLengthAndData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeLengthAndData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeLengthAndData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeFloat(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "WWBuffer:writeFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeFloat'", nullptr);
            return 0;
        }
        cobj->writeFloat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readULongLong(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readULongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readULongLong'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->readULongLong();
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned long long;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readULongLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readULongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_getContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_getContentSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getContentSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:getContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_getContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readLengthAndString(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readLengthAndString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readLengthAndString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readLengthAndString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readLengthAndString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readLengthAndString'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveWriterIndexToBack(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToBack'", nullptr);
            return 0;
        }
        cobj->moveWriterIndexToBack();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveWriterIndexToBack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToBack'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_toRealse(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_toRealse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_toRealse'", nullptr);
            return 0;
        }
        cobj->toRelease();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:toRealse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_toRealse'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeUInt(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeUInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "WWBuffer:writeUInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeUInt'", nullptr);
            return 0;
        }
        cobj->writeUInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeUInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeUInt'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_empty(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_empty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_empty'", nullptr);
            return 0;
        }
        bool ret = cobj->empty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:empty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_empty'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeLengthAndString(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeLengthAndString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:writeLengthAndString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeLengthAndString'", nullptr);
            return 0;
        }
        cobj->writeLengthAndString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeLengthAndString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeLengthAndString'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveLeft(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:moveLeft");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveLeft'", nullptr);
            return 0;
        }
        cobj->moveLeft(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveLeft",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeBoolean(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeBoolean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "WWBuffer:writeBoolean");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeBoolean'", nullptr);
            return 0;
        }
        cobj->writeBoolean(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeBoolean",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeBoolean'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeChar(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "WWBuffer:writeChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeChar'", nullptr);
            return 0;
        }
        cobj->writeChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeChar'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readInt(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readInt'", nullptr);
            return 0;
        }
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveReaderIndexToFront(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToFront'", nullptr);
            return 0;
        }
        cobj->moveReaderIndexToFront();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveReaderIndexToFront",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveWriterIndexToFront(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToFront'", nullptr);
            return 0;
        }
        cobj->moveWriterIndexToFront();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveWriterIndexToFront",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveWriterIndexToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readDouble(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readDouble'", nullptr);
            return 0;
        }
        double ret = cobj->readDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readLengthAndData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readLengthAndData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readLengthAndData'", nullptr);
            return 0;
        }
        WWBuffer* ret = cobj->readLengthAndData();
        object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readLengthAndData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readLengthAndData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_copy(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_copy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_copy'", nullptr);
            return 0;
        }
        WWBuffer* ret = cobj->copy();
        object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:copy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_copy'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_data(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_data'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_data'", nullptr);
            return 0;
        }
        char* ret = cobj->data();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:data",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_data'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_readFloat(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_readFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_readFloat'", nullptr);
            return 0;
        }
        double ret = cobj->readFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:readFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_readFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_reset(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeUShort(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeUShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "WWBuffer:writeUShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeUShort'", nullptr);
            return 0;
        }
        cobj->writeUShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeUShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_moveReaderIndexToBack(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToBack'", nullptr);
            return 0;
        }
        cobj->moveReaderIndexToBack();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:moveReaderIndexToBack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_moveReaderIndexToBack'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_clear(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeULongLong(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeULongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned long long arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned long long
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeULongLong'", nullptr);
            return 0;
        }
        cobj->writeULongLong(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeULongLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeULongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_skipData(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_skipData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:skipData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_skipData'", nullptr);
            return 0;
        }
        cobj->skipData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:skipData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_skipData'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_length(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_length'", nullptr);
            return 0;
        }
        int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_length'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_resetReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_resetReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_resetReaderIndex'", nullptr);
            return 0;
        }
        cobj->resetReaderIndex();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:resetReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_resetReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_isReadable(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_isReadable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:isReadable");

            if (!ok) { break; }
            bool ret = cobj->isReadable(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->isReadable();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWBuffer:isReadable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_isReadable'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeInt(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:writeInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeInt'", nullptr);
            return 0;
        }
        cobj->writeInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeInt'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_writeLongLong(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwnetsystem_WWBuffer_writeLongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "WWBuffer:writeLongLong");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwnetsystem_WWBuffer_writeLongLong'", nullptr);
            return 0;
        }
        cobj->writeLongLong(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWBuffer:writeLongLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_writeLongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_wwnetsystem_WWBuffer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:create");
            if (!ok) { break; }
            WWBuffer* ret = WWBuffer::create(arg0);
            object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            WWBuffer* ret = WWBuffer::create();
            object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:create"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWBuffer:create");
            if (!ok) { break; }
            WWBuffer* ret = WWBuffer::create(arg0, arg1);
            object_to_luaval<WWBuffer>(tolua_S, "WWBuffer",(WWBuffer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "WWBuffer:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_wwnetsystem_WWBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    WWBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "WWBuffer:WWBuffer");

            if (!ok) { break; }
            cobj = new WWBuffer(arg0);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"WWBuffer");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new WWBuffer();
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"WWBuffer");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWBuffer:WWBuffer"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "WWBuffer:WWBuffer");

            if (!ok) { break; }
            cobj = new WWBuffer(arg0, arg1);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"WWBuffer");
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWBuffer:WWBuffer",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_wwnetsystem_WWBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_wwnetsystem_WWBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWBuffer)");
    return 0;
}

int lua_register_wwnetsystem_WWBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWBuffer");
    tolua_cclass(tolua_S,"WWBuffer","WWBuffer","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"WWBuffer");
        tolua_function(tolua_S,"new",lua_wwnetsystem_WWBuffer_constructor);
        tolua_function(tolua_S,"readUChar",lua_wwnetsystem_WWBuffer_readUChar);
        tolua_function(tolua_S,"setWriterIndex",lua_wwnetsystem_WWBuffer_setWriterIndex);
        tolua_function(tolua_S,"readBoolean",lua_wwnetsystem_WWBuffer_readBoolean);
        tolua_function(tolua_S,"writeData",lua_wwnetsystem_WWBuffer_writeData);
        tolua_function(tolua_S,"writeString",lua_wwnetsystem_WWBuffer_writeString);
        tolua_function(tolua_S,"writeShort",lua_wwnetsystem_WWBuffer_writeShort);
        tolua_function(tolua_S,"readWholeData",lua_wwnetsystem_WWBuffer_readWholeData);
        tolua_function(tolua_S,"readData",lua_wwnetsystem_WWBuffer_readData);
        tolua_function(tolua_S,"writeDouble",lua_wwnetsystem_WWBuffer_writeDouble);
        tolua_function(tolua_S,"getBufferSize",lua_wwnetsystem_WWBuffer_getBufferSize);
        tolua_function(tolua_S,"readChar",lua_wwnetsystem_WWBuffer_readChar);
        tolua_function(tolua_S,"readShort",lua_wwnetsystem_WWBuffer_readShort);
        tolua_function(tolua_S,"markReaderIndex",lua_wwnetsystem_WWBuffer_markReaderIndex);
        tolua_function(tolua_S,"moveRight",lua_wwnetsystem_WWBuffer_moveRight);
        tolua_function(tolua_S,"readLongLong",lua_wwnetsystem_WWBuffer_readLongLong);
        tolua_function(tolua_S,"readUShort",lua_wwnetsystem_WWBuffer_readUShort);
        tolua_function(tolua_S,"getReadableSize",lua_wwnetsystem_WWBuffer_getReadableSize);
        tolua_function(tolua_S,"readChar3ToInt",lua_wwnetsystem_WWBuffer_readChar3ToInt);
        tolua_function(tolua_S,"getReaderIndex",lua_wwnetsystem_WWBuffer_getReaderIndex);
        tolua_function(tolua_S,"capacity",lua_wwnetsystem_WWBuffer_capacity);
        tolua_function(tolua_S,"getWriterIndex",lua_wwnetsystem_WWBuffer_getWriterIndex);
        tolua_function(tolua_S,"readUInt",lua_wwnetsystem_WWBuffer_readUInt);
        tolua_function(tolua_S,"discardReadContent",lua_wwnetsystem_WWBuffer_discardReadContent);
        tolua_function(tolua_S,"writeUChar",lua_wwnetsystem_WWBuffer_writeUChar);
        tolua_function(tolua_S,"setReaderIndex",lua_wwnetsystem_WWBuffer_setReaderIndex);
        tolua_function(tolua_S,"readString",lua_wwnetsystem_WWBuffer_readString);
        tolua_function(tolua_S,"writeLengthAndData",lua_wwnetsystem_WWBuffer_writeLengthAndData);
        tolua_function(tolua_S,"writeFloat",lua_wwnetsystem_WWBuffer_writeFloat);
        tolua_function(tolua_S,"readULongLong",lua_wwnetsystem_WWBuffer_readULongLong);
        tolua_function(tolua_S,"getContentSize",lua_wwnetsystem_WWBuffer_getContentSize);
        tolua_function(tolua_S,"readLengthAndString",lua_wwnetsystem_WWBuffer_readLengthAndString);
        tolua_function(tolua_S,"moveWriterIndexToBack",lua_wwnetsystem_WWBuffer_moveWriterIndexToBack);
        tolua_function(tolua_S,"toRealse",lua_wwnetsystem_WWBuffer_toRealse);
        tolua_function(tolua_S,"writeUInt",lua_wwnetsystem_WWBuffer_writeUInt);
        tolua_function(tolua_S,"empty",lua_wwnetsystem_WWBuffer_empty);
        tolua_function(tolua_S,"writeLengthAndString",lua_wwnetsystem_WWBuffer_writeLengthAndString);
        tolua_function(tolua_S,"moveLeft",lua_wwnetsystem_WWBuffer_moveLeft);
        tolua_function(tolua_S,"writeBoolean",lua_wwnetsystem_WWBuffer_writeBoolean);
        tolua_function(tolua_S,"writeChar",lua_wwnetsystem_WWBuffer_writeChar);
        tolua_function(tolua_S,"readInt",lua_wwnetsystem_WWBuffer_readInt);
        tolua_function(tolua_S,"moveReaderIndexToFront",lua_wwnetsystem_WWBuffer_moveReaderIndexToFront);
        tolua_function(tolua_S,"moveWriterIndexToFront",lua_wwnetsystem_WWBuffer_moveWriterIndexToFront);
        tolua_function(tolua_S,"readDouble",lua_wwnetsystem_WWBuffer_readDouble);
        tolua_function(tolua_S,"readLengthAndData",lua_wwnetsystem_WWBuffer_readLengthAndData);
        tolua_function(tolua_S,"copy",lua_wwnetsystem_WWBuffer_copy);
        tolua_function(tolua_S,"data",lua_wwnetsystem_WWBuffer_data);
        tolua_function(tolua_S,"readFloat",lua_wwnetsystem_WWBuffer_readFloat);
        tolua_function(tolua_S,"reset",lua_wwnetsystem_WWBuffer_reset);
        tolua_function(tolua_S,"writeUShort",lua_wwnetsystem_WWBuffer_writeUShort);
        tolua_function(tolua_S,"moveReaderIndexToBack",lua_wwnetsystem_WWBuffer_moveReaderIndexToBack);
        tolua_function(tolua_S,"clear",lua_wwnetsystem_WWBuffer_clear);
        tolua_function(tolua_S,"writeULongLong",lua_wwnetsystem_WWBuffer_writeULongLong);
        tolua_function(tolua_S,"skipData",lua_wwnetsystem_WWBuffer_skipData);
        tolua_function(tolua_S,"length",lua_wwnetsystem_WWBuffer_length);
        tolua_function(tolua_S,"resetReaderIndex",lua_wwnetsystem_WWBuffer_resetReaderIndex);
        tolua_function(tolua_S,"isReadable",lua_wwnetsystem_WWBuffer_isReadable);
        tolua_function(tolua_S,"writeInt",lua_wwnetsystem_WWBuffer_writeInt);
        tolua_function(tolua_S,"writeLongLong",lua_wwnetsystem_WWBuffer_writeLongLong);
        tolua_function(tolua_S,"create", lua_wwnetsystem_WWBuffer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWBuffer).name();
    g_luaType[typeName] = "WWBuffer";
    g_typeCast["WWBuffer"] = "WWBuffer";
    return 1;
}
TOLUA_API int register_all_wwnetsystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwnetsystem_WWBuffer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

