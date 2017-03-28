#pragma once
//*******************************
//Name:WWNetMacros.h
//Desc:Header Including and Macros
//Auth:Wawa
//Date:20161124
//Last:20170103
//*******************************

#include "cocos2d.h"
#include "../LogSystem/WWLog.h"

using namespace std;
using namespace cocos2d;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <windows.h>
#include <stdlib.h>
#pragma comment(lib, "Ws2_32.lib")
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
typedef unsigned int          SOCKET;
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#endif

//Socket超时时间
#define SOCKET_SOTIMEOUT			30.0f

//心跳间隔时间
#define HEART_BEAT_DELAY_TIME		30.0f

//接收数据间隔时间
#define RECIVE_DATA_DELAY_TIME		70.0f

//读取缓冲区大小
#define SOCKET_READ_BUFFER_SIZE		8192

//WWBuffer默认构造大小
#define WWBUFFER_ORGINAL_SIZE		512

//内存字节序是否反序
#define MEMORYTYPE_REVERSE			1

//是否使用数据包头长度
#define USING_PACKAGE_HEAD_LENGTH	1

//socket连接失败重试次数
#define SOCKET_CONNECT_FAIL_COUNT	1

//http获取socket地址连接失败重试次数
#define HTTP_GETSOCKET_FAIL_COUNT	1

//是否一帧内收发所有数据（0 则一帧收发一次数据，1则读完）
#define HANDLE_ON_SINGLE_FRAME		0

//读写网络数据：0 无日志  ；1 打印接收长度 ；2 打印长度加信息
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define DEBUG_LOG_WRITE				1
#define DEBUG_LOG_READ				1
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define DEBUG_LOG_WRITE				2
#define DEBUG_LOG_READ				2
#endif