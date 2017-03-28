#include "WWLog.h"
#include "cocos2d.h"
#include <iostream>
#include <string>
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

void printEx(int lc, const char* str)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	int t = (lc >= WWLC_BLACK && lc <= WWLC_WHITE) ? lc : WWLC_WHITE;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | t);
	std::cout << str << std::endl;
	SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | WWLC_WHITE);
#endif
}

void printExEx(int lc, const char* format,  ...)
{
	va_list params;
	va_start(params, format);
	char c[256];
	vsprintf(c, format, params);
	printEx(lc, c);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	CCLOG(std::string(c).c_str(), "");
#endif
	va_end(params);
}

int luafunc_printEx(lua_State* L)
{
	int lc = luaL_checkint(L, 1);
	const char* str = luaL_checkstring(L, 2);
	printEx(lc, str);
	return 0;
}
