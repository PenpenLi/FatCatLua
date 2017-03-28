#include "lua_wwtools_auto.hpp"
#include "../../Tools/WWAnimatePacker.h"
#include "../../Tools/ImageDownLoader.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwtools_WWAnimatePacker_getAnimate(lua_State* tolua_S)
{
    int argc = 0;
    WWAnimatePacker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWAnimatePacker",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWAnimatePacker*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_WWAnimatePacker_getAnimate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWAnimatePacker:getAnimate"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_WWAnimatePacker_getAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = cobj->getAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWAnimatePacker:getAnimate"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "WWAnimatePacker:getAnimate"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_WWAnimatePacker_getAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = cobj->getAnimate(arg0, arg1);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWAnimatePacker:getAnimate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_WWAnimatePacker_getAnimate'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_WWAnimatePacker_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWAnimatePacker",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_WWAnimatePacker_getInstance'", nullptr);
            return 0;
        }
        WWAnimatePacker* ret = WWAnimatePacker::getInstance();
        object_to_luaval<WWAnimatePacker>(tolua_S, "WWAnimatePacker",(WWAnimatePacker*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWAnimatePacker:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_WWAnimatePacker_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_wwtools_WWAnimatePacker_constructor(lua_State* tolua_S)
{
    int argc = 0;
    WWAnimatePacker* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_WWAnimatePacker_constructor'", nullptr);
            return 0;
        }
        cobj = new WWAnimatePacker();
        tolua_pushusertype(tolua_S,(void*)cobj,"WWAnimatePacker");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWAnimatePacker:WWAnimatePacker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_WWAnimatePacker_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_wwtools_WWAnimatePacker_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWAnimatePacker)");
    return 0;
}

int lua_register_wwtools_WWAnimatePacker(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWAnimatePacker");
    tolua_cclass(tolua_S,"WWAnimatePacker","WWAnimatePacker","",nullptr);

    tolua_beginmodule(tolua_S,"WWAnimatePacker");
        tolua_function(tolua_S,"new",lua_wwtools_WWAnimatePacker_constructor);
        tolua_function(tolua_S,"getAnimate",lua_wwtools_WWAnimatePacker_getAnimate);
        tolua_function(tolua_S,"getInstance", lua_wwtools_WWAnimatePacker_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWAnimatePacker).name();
    g_luaType[typeName] = "WWAnimatePacker";
    g_typeCast["WWAnimatePacker"] = "WWAnimatePacker";
    return 1;
}

int lua_wwtools_ImageDownLoader_excute(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_excute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

       // ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImageDownLoader:excute");
		arg0 = (toluafix_ref_function(tolua_S, 2, 0));
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_excute'", nullptr);
            return 0;
        }
        cobj->excute(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:excute",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_excute'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_getUrl(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_getUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_getUrl'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUrl();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:getUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_getUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_setParam(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_setParam'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::map<std::string, std::string> arg0;

        ok &= luaval_to_std_map_string_string(tolua_S, 2, &arg0, "ImageDownLoader:setParam");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_setParam'", nullptr);
            return 0;
        }
        cobj->setParam(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:setParam",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_setParam'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_setFunHandler(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_setFunHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

     //   ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImageDownLoader:setFunHandler");
		arg0 =  (toluafix_ref_function(tolua_S, 2, 0));
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_setFunHandler'", nullptr);
            return 0;
        }
        cobj->setFunHandler(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:setFunHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_setFunHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_setUrl(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_setUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ImageDownLoader:setUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_setUrl'", nullptr);
            return 0;
        }
        cobj->setUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:setUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_setUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_removeHandler(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_removeHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_removeHandler'", nullptr);
            return 0;
        }
        cobj->removeHandler();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:removeHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_removeHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_getFunHandler(lua_State* tolua_S)
{
    int argc = 0;
    ImageDownLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImageDownLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwtools_ImageDownLoader_getFunHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_getFunHandler'", nullptr);
            return 0;
        }
        int ret = cobj->getFunHandler();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImageDownLoader:getFunHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_getFunHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_wwtools_ImageDownLoader_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ImageDownLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_create'", nullptr);
            return 0;
        }
        ImageDownLoader* ret = ImageDownLoader::create();
        object_to_luaval<ImageDownLoader>(tolua_S, "ImageDownLoader",(ImageDownLoader*)ret);
        return 1;
    }
    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ImageDownLoader:create"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_create'", nullptr);
            return 0;
        }
        ImageDownLoader* ret = ImageDownLoader::create(arg0);
        object_to_luaval<ImageDownLoader>(tolua_S, "ImageDownLoader",(ImageDownLoader*)ret);
        return 1;
    }
    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ImageDownLoader:create"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "ImageDownLoader:create"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwtools_ImageDownLoader_create'", nullptr);
            return 0;
        }
        ImageDownLoader* ret = ImageDownLoader::create(arg0, arg1);
        object_to_luaval<ImageDownLoader>(tolua_S, "ImageDownLoader",(ImageDownLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ImageDownLoader:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwtools_ImageDownLoader_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_wwtools_ImageDownLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ImageDownLoader)");
    return 0;
}

int lua_register_wwtools_ImageDownLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ImageDownLoader");
    tolua_cclass(tolua_S,"ImageDownLoader","ImageDownLoader","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ImageDownLoader");
        tolua_function(tolua_S,"excute",lua_wwtools_ImageDownLoader_excute);
        tolua_function(tolua_S,"getUrl",lua_wwtools_ImageDownLoader_getUrl);
        tolua_function(tolua_S,"setParam",lua_wwtools_ImageDownLoader_setParam);
        tolua_function(tolua_S,"setFunHandler",lua_wwtools_ImageDownLoader_setFunHandler);
        tolua_function(tolua_S,"setUrl",lua_wwtools_ImageDownLoader_setUrl);
        tolua_function(tolua_S,"removeHandler",lua_wwtools_ImageDownLoader_removeHandler);
        tolua_function(tolua_S,"getFunHandler",lua_wwtools_ImageDownLoader_getFunHandler);
        tolua_function(tolua_S,"create", lua_wwtools_ImageDownLoader_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ImageDownLoader).name();
    g_luaType[typeName] = "ImageDownLoader";
    g_typeCast["ImageDownLoader"] = "ImageDownLoader";
    return 1;
}
TOLUA_API int register_all_wwtools(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwtools_ImageDownLoader(tolua_S);
	lua_register_wwtools_WWAnimatePacker(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

