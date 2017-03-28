#include "lua_wwguisystem_auto.hpp"
#include "../../GUISystem/SuperRichText.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwguisystem_SuperRichText_init(lua_State* tolua_S)
{
    int argc = 0;
    SuperRichText* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SuperRichText",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SuperRichText*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwguisystem_SuperRichText_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0, "SuperRichText:init");

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->init();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "SuperRichText:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwguisystem_SuperRichText_init'.",&tolua_err);
#endif

    return 0;
}
int lua_wwguisystem_SuperRichText_renderHtml(lua_State* tolua_S)
{
    int argc = 0;
    SuperRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SuperRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SuperRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwguisystem_SuperRichText_renderHtml'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SuperRichText:renderHtml"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwguisystem_SuperRichText_renderHtml'", nullptr);
            return 0;
        }
        cobj->renderHtml(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SuperRichText:renderHtml",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwguisystem_SuperRichText_renderHtml'.",&tolua_err);
#endif

    return 0;
}
int lua_wwguisystem_SuperRichText_renderNode(lua_State* tolua_S)
{
    int argc = 0;
    SuperRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SuperRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SuperRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwguisystem_SuperRichText_renderNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tinyxml2::XMLNode* arg0;

        ok &= luaval_to_object<tinyxml2::XMLNode>(tolua_S, 2, "txml2.XMLNode",&arg0, "SuperRichText:renderNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwguisystem_SuperRichText_renderNode'", nullptr);
            return 0;
        }
        cobj->renderNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SuperRichText:renderNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwguisystem_SuperRichText_renderNode'.",&tolua_err);
#endif

    return 0;
}
int lua_wwguisystem_SuperRichText_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SuperRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0, "SuperRichText:create");
            if (!ok) { break; }
            SuperRichText* ret = SuperRichText::create(arg0);
            object_to_luaval<SuperRichText>(tolua_S, "SuperRichText",(SuperRichText*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            SuperRichText* ret = SuperRichText::create();
            object_to_luaval<SuperRichText>(tolua_S, "SuperRichText",(SuperRichText*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "SuperRichText:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwguisystem_SuperRichText_create'.",&tolua_err);
#endif
    return 0;
}
int lua_wwguisystem_SuperRichText_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SuperRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwguisystem_SuperRichText_constructor'", nullptr);
            return 0;
        }
        cobj = new SuperRichText();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SuperRichText");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SuperRichText:SuperRichText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_wwguisystem_SuperRichText_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_wwguisystem_SuperRichText_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SuperRichText)");
    return 0;
}

int lua_register_wwguisystem_SuperRichText(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SuperRichText");
    tolua_cclass(tolua_S,"SuperRichText","SuperRichText","cc.LayerColor",nullptr);

    tolua_beginmodule(tolua_S,"SuperRichText");
        tolua_function(tolua_S,"new",lua_wwguisystem_SuperRichText_constructor);
        tolua_function(tolua_S,"init",lua_wwguisystem_SuperRichText_init);
        tolua_function(tolua_S,"renderHtml",lua_wwguisystem_SuperRichText_renderHtml);
        tolua_function(tolua_S,"renderNode",lua_wwguisystem_SuperRichText_renderNode);
        tolua_function(tolua_S,"create", lua_wwguisystem_SuperRichText_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SuperRichText).name();
    g_luaType[typeName] = "SuperRichText";
    g_typeCast["SuperRichText"] = "SuperRichText";
    return 1;
}
TOLUA_API int register_all_wwguisystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwguisystem_SuperRichText(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

