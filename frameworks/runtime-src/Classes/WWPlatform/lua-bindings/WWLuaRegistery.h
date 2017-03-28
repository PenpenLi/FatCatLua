#pragma once
#pragma execution_character_set("utf-8")


#include "auto/lua_wwdbsystem_auto.hpp"
#include "auto/lua_wwconfigsystem_auto.hpp"
#include "auto/lua_wweventsystem_auto.hpp"
#include "auto/lua_wwtools_auto.hpp"
#include "auto/lua_wwnetsystem_auto.hpp"
#include "auto/lua_wwenginesystem_auto.hpp"
#include "auto/lua_wwsoundsystem_auto.hpp"
#include "auto/lua_wwguisystem_auto.hpp"
#include "manual/lua_wwupdatesystem_manual.hpp"
#include "manual/lua_wwconfigsystem__manual.hpp"
#include "WWPlatform/Tools/WWUtil.h"
#include "WWPlatform/DBSystem/Sqlite3/lsqlite3.h"

inline int luafunc_removeDir(lua_State* L)
{
	const char* filename = luaL_checkstring(L, 1);
	if (filename)
	{
		lua_pushnumber(L, removeDir(filename));
	} else
	{
		lua_pushnil(L);
	}
	return 1;
}


inline int register_wwplatform_tolua(lua_State* L)
{
	
	register_all_wwdbsystem(L);
	register_all_wwconfigsystem(L);
	register_all_wwtools(L);
	register_all_wweventsystem(L);
	register_all_wwnetsystem(L);
	register_all_wwenginesystem(L);
	register_all_wwguisystem(L);

	register_all_wwsoundsystem(L);
	register_all_wwupdatesystem(L);
	
	register_all_wwconfigsystem_manual(L);

	luaopen_lsqlite3(L);

	lua_pushcfunction(L, luafunc_removeDir);
	lua_setglobal(L, "removeDir");
	return 0;
}