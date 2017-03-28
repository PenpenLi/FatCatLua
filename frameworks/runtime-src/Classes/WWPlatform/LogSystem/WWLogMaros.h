#pragma once
/*
* WWLog.h
*
*  Created on: 2014年5月14日
*      Author: D.K.
*/


#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "jni.h"
//#include "WWLocalLogger.h"
#endif

/**
* 各个级别的日志输出，部分有平台相关的属性
*/

#define __WW_LOGWITHFUNCTION(level,format, ...) \
//	WawaLog::log(level, __FILE__, __LINE__, __FUNCTION__, cocos2d::__String::createWithFormat(format, ##__VA_ARGS__))
//	__android_log_print(level,__FILE__,"(%d)[%s]%s",__LINE__,__FUNCTION__, CCString::createWithFormat(format, ##__VA_ARGS__)->getCString());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)&&COCOS2D_DEBUG == 1

#define WW_LOG_VERBOSE(format,...)  __WW_LOGWITHFUNCTION(ANDROID_LOG_VERBOSE ,format, ##__VA_ARGS__)
#define WW_LOG_DEBUG(format,...)    __WW_LOGWITHFUNCTION(ANDROID_LOG_DEBUG   ,format, ##__VA_ARGS__)
#define WW_LOG_INFO(format,...)     __WW_LOGWITHFUNCTION(ANDROID_LOG_INFO    ,format, ##__VA_ARGS__)
#define WW_LOG_WARN(format,...)     __WW_LOGWITHFUNCTION(ANDROID_LOG_WARN    ,format, ##__VA_ARGS__)
// #define WW_LOG_ERROR(format,...)    __WW_LOGWITHFUNCTION(ANDROID_LOG_ERROR   ,format, ##__VA_ARGS__)
#define WW_LOG_ERROR(format, ...)	__WW_LOGWITHFUNCTION(ANDROID_LOG_WARN    ,format, ##__VA_ARGS__)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)&&COCOS2D_DEBUG == 1

//#define WW_LOG_INFO(format,...) printf("%s,%d:"format,__FILE__,__LINE__, ##__VA_ARGS__)
#define WW_LOG_INFO(format,...) cocos2d::log(format, ##__VA_ARGS__)
#define WW_LOG_ERROR(format,...) printf("%s,%d:[error]" format,__FILE__,__LINE__, ##__VA_ARGS__)
#define WW_LOG_VERBOSE(format,...) printf("%s,%d:[verbose]" format,__FILE__,__LINE__, ##__VA_ARGS__)
#define WW_LOG_WARN(format,...) printf("%s,%d:[warn]" format,__FILE__,__LINE__, ##__VA_ARGS__)
#define WW_LOG_DEBUG(format,...) printf("%s,%d:[debug]" format,__FILE__,__LINE__, ##__VA_ARGS__)

#else

#define WW_LOG_VERBOSE(...)  CCLOG(__VA_ARGS__)
#define WW_LOG_DEBUG(...)  CCLOG(__VA_ARGS__)
#define WW_LOG_INFO(...)  CCLOG(__VA_ARGS__)
#define WW_LOG_WARN(...)  CCLOG(__VA_ARGS__)
#define WW_LOG_ERROR(...)  CCLOG(__VA_ARGS__)
#endif

#if COCOS2D_DEBUG > 0
#define WW_ASSERT CCASSERT
#else
#define WW_ASSERT(con, format, ...) {if(!(con)) {cocos2d::log(format, ##__VA_ARGS__);}}
#endif




