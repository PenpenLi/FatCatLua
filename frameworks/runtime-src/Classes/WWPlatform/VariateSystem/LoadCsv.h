#ifndef __LOAD_CSV_H__
#define __LOAD_CSV_H__

#include <string>
#include <vector>

struct lua_State;

bool CsvDataToCpp(const char* str, size_t length, std::vector<std::vector<std::string> >* outputTable, size_t* outputColumnNum);
bool CsvDataToLua(const char* str, size_t length, lua_State* L);

bool CsvFileToCpp(const char* filename, std::vector<std::vector<std::string> >* outputTable, size_t* outputColumnNum);
bool CsvFileToLua(const char* filename, lua_State* L);

int luafunc_load_csv(lua_State* L);

#endif
