#pragma once
#pragma execution_character_set("utf-8")

#include "cocos2d.h"
#ifdef WIN32
#include <stdio.h>  
#include <io.h>  
#include <string.h>  
#include <direct.h>  
#else
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#endif // WIN32

using namespace std;

inline bool isnum(string s)
{
	stringstream sin(s);
	double t;
	char p;
	if (!(sin >> t))
		return false;
	if (sin >> p)
		return false;
	else
		return true;
}

inline long getSecNow()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
	//win32
	struct tm *tm;
	time_t timep;
	time(&timep);
	tm = localtime(&timep);
	return timep;
#else  
	//android,ios
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec;
#endif 
}

inline int stringToint(const std::string& string)
{
	char* end = NULL;
	int i = static_cast<int>(strtol(string.c_str(), &end, 10));
	return i;
}

inline std::vector<std::string> splitStr(std::string src, std::string separate_character)
{
	std::vector<std::string> strs;
	int separate_characterLen = separate_character.size();//分割字符串长度，这样就可以支持多字 符串的分隔符
	int last_position = 0, index = -1;
	while (-1 != (index = src.find(separate_character, last_position)))
	{
		//		WW_LOG_INFO("Charge::======================:%s", src.substr(last_position, index - last_position).c_str());
		strs.push_back(src.substr(last_position, index - last_position));
		last_position = index + separate_characterLen;
	}
	std::string lastString = src.substr(last_position);
	if (!lastString.empty())
	{
		//		WW_LOG_INFO("Charge::======================:%s", lastString.c_str());
		strs.push_back(lastString);
	}
	return strs;
}

#ifdef WIN32
/*
函数入口：文件夹的绝对路径 
const char*  dirPath 

函数功能：删除该文件夹，包括其中所有的文件和文件夹 

返回值：  0  删除  
-1  路径不对，或其它情况，没有执行删除操作 
*/  
inline int removeDir(const char*  dirPath)  
{  

	struct _finddata_t fb;   //查找相同属性文件的存储结构体  
	char  path[250];            
	long    handle;  
	int  resultone;  
	int   noFile;            //对系统隐藏文件的处理标记  

	noFile = 0;  
	handle = 0;  


	//制作路径  
	strcpy(path,dirPath);  
	strcat (path,"/*");  

	handle = _findfirst(path,&fb);  
	//找到第一个匹配的文件  
	if (handle != 0)  
	{  
		//当可以继续找到匹配的文件，继续执行  
		while (0 == _findnext(handle,&fb))  
		{  
			//windows下，常有个系统文件，名为“..”,对它不做处理  
			noFile = strcmp(fb.name,"..");  

			if (0 != noFile)  
			{  
				//制作完整路径  
				memset(path,0,sizeof(path));  
				strcpy(path,dirPath);  
				strcat(path,"/");  
				strcat(path, fb.name);
				//属性值为16，则说明是文件夹，迭代  
				if (fb.attrib == 16)
				{
					removeDir(path);
				}
				//非文件夹的文件，直接删除。对文件属性值的情况没做详细调查，可能还有其他情况。  
				else
				{
					remove(path);
				}
			}
		}
		//关闭文件夹，只有关闭了才能删除。找这个函数找了很久，标准c中用的是closedir  
		//经验介绍：一般产生Handle的函数执行后，都要进行关闭的动作。  
		_findclose(handle);
	}
	//移除文件夹  
	resultone = rmdir(dirPath);
	return  resultone;
}
#else
/**
* File_Delete_Dir--删除文件目录
*/
inline int removeDir(const char* dirName) {
	if (dirName == NULL) {
		return -1;
	}
	DIR* dp = NULL;
	DIR* dpin = NULL;
	char *pathname = (char*)malloc(256);
	memset(pathname, 0, 256);
	struct dirent* dirp;
	dp = opendir(dirName);
	if (dp == NULL) {

		return -1;
	}
	while ((dirp = readdir(dp)) != NULL) {
		if (strcmp(dirp->d_name, "..") == 0 || strcmp(dirp->d_name, ".") == 0)
			continue;
		strcpy(pathname, dirName);
		strcat(pathname, "/");
		strcat(pathname, dirp->d_name);
		dpin = opendir(pathname);
		if (dpin != NULL) {
			closedir(dpin);
			dpin = NULL;
			cocos2d::log("remove path:%s",pathname);
			removeDir(pathname);
		} else {
			cocos2d::log("remove file:%s",pathname);
			if (remove(pathname)==0) 
			{
				cocos2d::log("remove file:%s success!",pathname);
			}else
			{
				cocos2d::log("remove file:%s failed! code %d",pathname,errno);
			}
			
		}
	}
	rmdir(dirName);
	closedir(dp);
	free(pathname);
	pathname = NULL;
	dirp = NULL;

	return 1;
}
#endif // WIN32
