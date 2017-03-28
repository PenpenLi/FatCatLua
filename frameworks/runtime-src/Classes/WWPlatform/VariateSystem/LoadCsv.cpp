#include "LoadCsv.h"

#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

#include <regex>


std::string doubleQuoteToSingle(const std::string& str)
{
    bool quoteMark = false;
    std::string ret;

    for (char c : str)
    {
        if (c == '\"')
        {
            if (!quoteMark)
            {
                quoteMark = true;
            }
            else
            {
                quoteMark = false;
                ret.push_back(c);
            }
        }
        else
        {
            quoteMark = false;
            ret.push_back(c);
        }
    }

    return ret;
}


bool CsvDataToCpp(const char* str, size_t length, std::vector<std::vector<std::string> >* outputTable, size_t* outputColumnNum)
{
    // skip UTF8 BOM
    if (length >= 3 && str[0] == (char)0xEF && str[1] == (char)0xBB && str[2] == (char)0xBF)
    {
        str += 3;
        length -= 3;
    }

    std::vector<std::vector<std::string> > dataTable;
    std::vector<std::string> dataLine;

    size_t p_cell_start = 0;
    while (p_cell_start < length)
    {
        bool isInQuote = false;
        bool cellOk = false;

        if (str[p_cell_start] == '"')
        {
            isInQuote = true;
            ++p_cell_start;
        }

        size_t p_cell_end = p_cell_start;
        for (; p_cell_end < length; ++p_cell_end)
        {
            char c = str[p_cell_end];

            if (!isInQuote)
            {
                if (c == ',' || c == '\r' || c == '\n')
                {
                    std::string cell(str + p_cell_start, str + p_cell_end);
                    dataLine.push_back(std::move(cell));
                    cellOk = true;
                    break;
                }
            }
            else
            {
                if (c == '"')
                {
                    if (p_cell_end + 1 >= length || str[p_cell_end + 1] == ',' || str[p_cell_end + 1] == '\r' || str[p_cell_end + 1] == '\n')
                    {
                        std::string cell(str + p_cell_start, str + p_cell_end);
                        cell = doubleQuoteToSingle(cell);
                        dataLine.push_back(std::move(cell));
                        cellOk = true;
                        ++p_cell_end;
                        break;
                    }
                }
            }
        }

        if (!cellOk)
        {
            return false;
        }

        if (str[p_cell_end] == '\r' || str[p_cell_end] == '\n')
        {
            dataTable.push_back(std::move(dataLine));
        }

        p_cell_start = p_cell_end + 1;

        if (p_cell_start < length && str[p_cell_start] == '\n')
        {
            ++p_cell_start;
        }
    }

    size_t colNum = 0;
    for (const auto& line : dataTable)
    {
        if (colNum < line.size())
        {
            colNum = line.size();
        }
    }

    for (auto& line : dataTable)
    {
        line.resize(colNum);
    }

    if (outputColumnNum)
    {
        *outputColumnNum = colNum;
    }

    if (outputTable)
    {
        outputTable->swap(dataTable);
    }

    return true;
}


bool CsvDataToLua(const char* str, size_t length, lua_State* L)
{
    std::vector<std::vector<std::string> > dataTable;
    size_t colNum;
    if (!CsvDataToCpp(str, length, &dataTable, &colNum))
    {
        return false;
    }

    int rows = (int)dataTable.size() - 1;
    if (rows < 0)
    {
        rows = 0;
    }

    lua_createtable(L, rows, 0);

    if (rows <= 0)
    {
        return true;
    }

    std::vector<int> refs;
    for (const std::string& fieldName : dataTable[0])
    {
        lua_pushlstring(L, fieldName.c_str(), fieldName.length());
        refs.push_back(lua_ref(L, 1));
    }

    for (size_t i = 1; i < dataTable.size(); ++i)
    {
        const std::vector<std::string>& dataLine = dataTable[i];

        lua_createtable(L, 0, (int)refs.size());

        for (size_t j = 0; j < dataLine.size(); ++j)
        {
            const std::string& dataCell = dataLine[j];

            assert(j < refs.size());

            lua_getref(L, refs[j]);
            lua_pushlstring(L, dataCell.c_str(), dataCell.length());
            lua_settable(L, -3);
        }

        lua_rawseti(L, -2, i);
    }

    for (int r : refs)
    {
        lua_unref(L, r);
    }

    return true;
}


bool CsvFileToCpp(const char* filename, std::vector<std::vector<std::string> >* outputTable, size_t* outputColumnNum)
{
    cocos2d::Data d = cocos2d::FileUtils::getInstance()->getDataFromFile(filename);
    if (d.isNull())
    {
        return false;
    }

    return CsvDataToCpp((const char*)d.getBytes(), d.getSize(), outputTable, outputColumnNum);
}


bool CsvFileToLua(const char* filename, lua_State* L)
{
    cocos2d::Data d = cocos2d::FileUtils::getInstance()->getDataFromFile(filename);
    if (d.isNull())
    {
        return false;
    }

    return CsvDataToLua((const char*)d.getBytes(), d.getSize(), L);
}


int luafunc_load_csv(lua_State* L)
{
    const char* filename = luaL_checkstring(L, 1);
    if (!CsvFileToLua(filename, L))
    {
        lua_pushnil(L);
    }

    return 1;
}
