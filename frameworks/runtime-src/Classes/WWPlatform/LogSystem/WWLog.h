#pragma once

//*******************************
//Name:WWLog.h
//Desc:Log
//Auth:Wawa
//Date:?
//Last:20161222
//*******************************

enum WWLogColor
{
	WWLC_BLACK		= 0,
	WWLC_BLUE		= 1,
	WWLC_GREEN		= 2,
	WWLC_CYAN		= 3,
	WWLC_RED		= 4,
	WWLC_MAGENTA	= 5,
	WWLC_YELLOW		= 6,
	WWLC_WHITE		= 7,
};

void printEx(int lc, const char* str);
void printExEx(int lc, const char* format, ...);

struct lua_State;
int luafunc_printEx(lua_State* L);