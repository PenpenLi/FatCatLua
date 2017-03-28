#include "lua_wwsoundsystem_auto.hpp"
#include "../../SoundSystem/WWSoundManager.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_wwsoundsystem_WWSoundManager_stopAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_stopAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_stopAllEffects'", nullptr);
            return 0;
        }
        cobj->stopAllEffects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:stopAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_stopAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_preloadResource(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_preloadResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_preloadResource'", nullptr);
            return 0;
        }
        cobj->preloadResource();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:preloadResource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_preloadResource'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_getEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_getEffectsVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_getEffectsVolume'", nullptr);
            return 0;
        }
        double ret = cobj->getEffectsVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:getEffectsVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_getEffectsVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_stopEffect(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_stopEffect'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:stopEffect"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->stopEffect(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "WWSoundManager:stopEffect");

            if (!ok) { break; }
            cobj->stopEffect(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "WWSoundManager:stopEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_stopEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_setBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_setBackgroundMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "WWSoundManager:setBackgroundMusicVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_setBackgroundMusicVolume'", nullptr);
            return 0;
        }
        cobj->setBackgroundMusicVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:setBackgroundMusicVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_setBackgroundMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_willPlayBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_willPlayBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_willPlayBackgroundMusic'", nullptr);
            return 0;
        }
        bool ret = cobj->willPlayBackgroundMusic();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:willPlayBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_willPlayBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_pauseBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_pauseBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_pauseBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->pauseBackgroundMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:pauseBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_pauseBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->stopBackgroundMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "WWSoundManager:stopBackgroundMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->stopBackgroundMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:stopBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_playSoundEffect(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_playSoundEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:playSoundEffect"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_playSoundEffect'", nullptr);
            return 0;
        }
        cobj->playSoundEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:playSoundEffect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "WWSoundManager:playSoundEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_playSoundEffect'", nullptr);
            return 0;
        }
        cobj->playSoundEffect(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        bool arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:playSoundEffect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "WWSoundManager:playSoundEffect");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "WWSoundManager:playSoundEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_playSoundEffect'", nullptr);
            return 0;
        }
        cobj->playSoundEffect(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:playSoundEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_playSoundEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_isBackgroundMusicPlaying(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_isBackgroundMusicPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_isBackgroundMusicPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isBackgroundMusicPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:isBackgroundMusicPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_isBackgroundMusicPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_init(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_init'", nullptr);
            return 0;
        }
        cobj->init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_init'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_SoundEffectControl(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_SoundEffectControl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "WWSoundManager:SoundEffectControl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_SoundEffectControl'", nullptr);
            return 0;
        }
        cobj->SoundEffectControl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:SoundEffectControl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_SoundEffectControl'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_pauseAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_pauseAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_pauseAllEffects'", nullptr);
            return 0;
        }
        cobj->pauseAllEffects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:pauseAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_pauseAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_playBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_playBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:playBackgroundMusic"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_playBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->playBackgroundMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:playBackgroundMusic"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "WWSoundManager:playBackgroundMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_playBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->playBackgroundMusic(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:playBackgroundMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_playBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_resumeAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_resumeAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_resumeAllEffects'", nullptr);
            return 0;
        }
        cobj->resumeAllEffects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:resumeAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_resumeAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_addPreloadEffResource(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_addPreloadEffResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:addPreloadEffResource"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_addPreloadEffResource'", nullptr);
            return 0;
        }
        cobj->addPreloadEffResource(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:addPreloadEffResource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_addPreloadEffResource'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_unloadResource(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_unloadResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_unloadResource'", nullptr);
            return 0;
        }
        cobj->unloadResource();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:unloadResource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_unloadResource'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_getBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_getBackgroundMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_getBackgroundMusicVolume'", nullptr);
            return 0;
        }
        double ret = cobj->getBackgroundMusicVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:getBackgroundMusicVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_getBackgroundMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_addPreloadMusicResource(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_addPreloadMusicResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "WWSoundManager:addPreloadMusicResource"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_addPreloadMusicResource'", nullptr);
            return 0;
        }
        cobj->addPreloadMusicResource(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:addPreloadMusicResource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_addPreloadMusicResource'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_rewindBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_rewindBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_rewindBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->rewindBackgroundMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:rewindBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_rewindBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_pauseEffect(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_pauseEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "WWSoundManager:pauseEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_pauseEffect'", nullptr);
            return 0;
        }
        cobj->pauseEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:pauseEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_pauseEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_resumeBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_resumeBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_resumeBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->resumeBackgroundMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:resumeBackgroundMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_resumeBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_setEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_setEffectsVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "WWSoundManager:setEffectsVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_setEffectsVolume'", nullptr);
            return 0;
        }
        cobj->setEffectsVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:setEffectsVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_setEffectsVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_resumeEffect(lua_State* tolua_S)
{
    int argc = 0;
    WWSoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (WWSoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wwsoundsystem_WWSoundManager_resumeEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "WWSoundManager:resumeEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_resumeEffect'", nullptr);
            return 0;
        }
        cobj->resumeEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WWSoundManager:resumeEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_resumeEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_wwsoundsystem_WWSoundManager_end(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_end'", nullptr);
            return 0;
        }
        WWSoundManager::end();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWSoundManager:end",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_end'.",&tolua_err);
#endif
    return 0;
}
int lua_wwsoundsystem_WWSoundManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"WWSoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_wwsoundsystem_WWSoundManager_getInstance'", nullptr);
            return 0;
        }
        WWSoundManager* ret = WWSoundManager::getInstance();
        object_to_luaval<WWSoundManager>(tolua_S, "WWSoundManager",(WWSoundManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "WWSoundManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wwsoundsystem_WWSoundManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_wwsoundsystem_WWSoundManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WWSoundManager)");
    return 0;
}

int lua_register_wwsoundsystem_WWSoundManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WWSoundManager");
    tolua_cclass(tolua_S,"WWSoundManager","WWSoundManager","",nullptr);

    tolua_beginmodule(tolua_S,"WWSoundManager");
        tolua_function(tolua_S,"stopAllEffects",lua_wwsoundsystem_WWSoundManager_stopAllEffects);
        tolua_function(tolua_S,"preloadResource",lua_wwsoundsystem_WWSoundManager_preloadResource);
        tolua_function(tolua_S,"getEffectsVolume",lua_wwsoundsystem_WWSoundManager_getEffectsVolume);
        tolua_function(tolua_S,"stopEffect",lua_wwsoundsystem_WWSoundManager_stopEffect);
        tolua_function(tolua_S,"setBackgroundMusicVolume",lua_wwsoundsystem_WWSoundManager_setBackgroundMusicVolume);
        tolua_function(tolua_S,"willPlayBackgroundMusic",lua_wwsoundsystem_WWSoundManager_willPlayBackgroundMusic);
        tolua_function(tolua_S,"pauseBackgroundMusic",lua_wwsoundsystem_WWSoundManager_pauseBackgroundMusic);
        tolua_function(tolua_S,"stopBackgroundMusic",lua_wwsoundsystem_WWSoundManager_stopBackgroundMusic);
        tolua_function(tolua_S,"playSoundEffect",lua_wwsoundsystem_WWSoundManager_playSoundEffect);
        tolua_function(tolua_S,"isBackgroundMusicPlaying",lua_wwsoundsystem_WWSoundManager_isBackgroundMusicPlaying);
        tolua_function(tolua_S,"init",lua_wwsoundsystem_WWSoundManager_init);
        tolua_function(tolua_S,"SoundEffectControl",lua_wwsoundsystem_WWSoundManager_SoundEffectControl);
        tolua_function(tolua_S,"pauseAllEffects",lua_wwsoundsystem_WWSoundManager_pauseAllEffects);
        tolua_function(tolua_S,"playBackgroundMusic",lua_wwsoundsystem_WWSoundManager_playBackgroundMusic);
        tolua_function(tolua_S,"resumeAllEffects",lua_wwsoundsystem_WWSoundManager_resumeAllEffects);
        tolua_function(tolua_S,"addPreloadEffResource",lua_wwsoundsystem_WWSoundManager_addPreloadEffResource);
        tolua_function(tolua_S,"unloadResource",lua_wwsoundsystem_WWSoundManager_unloadResource);
        tolua_function(tolua_S,"getBackgroundMusicVolume",lua_wwsoundsystem_WWSoundManager_getBackgroundMusicVolume);
        tolua_function(tolua_S,"addPreloadMusicResource",lua_wwsoundsystem_WWSoundManager_addPreloadMusicResource);
        tolua_function(tolua_S,"rewindBackgroundMusic",lua_wwsoundsystem_WWSoundManager_rewindBackgroundMusic);
        tolua_function(tolua_S,"pauseEffect",lua_wwsoundsystem_WWSoundManager_pauseEffect);
        tolua_function(tolua_S,"resumeBackgroundMusic",lua_wwsoundsystem_WWSoundManager_resumeBackgroundMusic);
        tolua_function(tolua_S,"setEffectsVolume",lua_wwsoundsystem_WWSoundManager_setEffectsVolume);
        tolua_function(tolua_S,"resumeEffect",lua_wwsoundsystem_WWSoundManager_resumeEffect);
        tolua_function(tolua_S,"end", lua_wwsoundsystem_WWSoundManager_end);
        tolua_function(tolua_S,"getInstance", lua_wwsoundsystem_WWSoundManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(WWSoundManager).name();
    g_luaType[typeName] = "WWSoundManager";
    g_typeCast["WWSoundManager"] = "WWSoundManager";
    return 1;
}
TOLUA_API int register_all_wwsoundsystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ww",0);
	tolua_beginmodule(tolua_S,"ww");

	lua_register_wwsoundsystem_WWSoundManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

