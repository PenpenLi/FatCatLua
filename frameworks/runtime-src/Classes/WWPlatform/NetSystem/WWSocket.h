#pragma once
//*******************************
//Name:WWSocket.h
//Desc:Socket Base
//Auth:Wawa
//Date:20161117
//Last:20170103
//*******************************

#include "WWInetAddress.h"

enum WWSocketStatus
{
	WWSS_CONNECTED = 1,
	WWSS_CONNECTING = 2, 
	WWSS_DIS_CONNECT = 3,	//主动关闭
	WWSS_CONNECT_FAIL = 4,	//连接失败
	WWSS_CONNECT_TIMEOUT = 5,	//连接超时
	WWSS_RECV_TIMEOUT = 6,	//接收超时
	WWSS_DIS_CONNECT_FORBG = 7,	//进入后台关闭
	WWSS_SHAKEHAND_FAIL = 8,	//握手失败
	WWSS_IO_CLOSE = 0,	//IO关闭
	WWSS_IO_ERROR = -1,		//IO错误
};

class WWSocket
{
public:
	WWSocket();
	virtual ~WWSocket(){ ccClose(); }

public:
	void ccClose();
	void ccDisconnect(){ ccClose(); }
	bool ccInit();
	bool ccConnect();
	bool ccIsReadable();
	bool ccIsWritable();
	int  ccIsConnected();
	int  ccRead(char* _buff, int _len);
	int  ccWrite(char* _buff, int _len);
	void setInetAddress(const WWInetAddress& oInetAddress){ m_oInetAddress = oInetAddress; }
	void ccShutdown();

protected:
	SOCKET m_uSocket;
	WWInetAddress m_oInetAddress;
};