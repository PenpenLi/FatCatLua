#ifndef __LSQLITE3_H__
#define __LSQLITE3_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

extern "C" int luaopen_lsqlite3(lua_State* L);   //lsqlite3.c �е�C����������ע��C����
#endif