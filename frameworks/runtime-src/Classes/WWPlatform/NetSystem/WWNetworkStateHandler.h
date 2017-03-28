#pragma once
//*******************************
//Name:WWNetworkStateHandler.h
//Desc:Network State
//Auth:Wawa
//Date:20161117
//Last:20170104
//*******************************

#include "WWSocket.h"
#include "platform/CCPlatformMacros.h"

class WWNetwork;
class WWNetworkStateHandler
{
public:
	WWNetworkStateHandler(){};
	virtual ~WWNetworkStateHandler(){};
public:
	virtual bool performState(WWNetwork* sock,WWSocketStatus inputState,float dt);
protected:
	std::list<WWSocketStatus> m_avaliableStates;
};

class WWNetWorkStateReadHandler :public WWNetworkStateHandler
{
public:
	WWNetWorkStateReadHandler();
	virtual ~WWNetWorkStateReadHandler(){};
	virtual bool performState(WWNetwork* sock, WWSocketStatus inputState, float dt) override;
private:
	bool pushMsgSH(WWNetwork* sock);
};

class WWNetWorkStateWriteHandler :public WWNetworkStateHandler
{
public:
	WWNetWorkStateWriteHandler();
	virtual ~WWNetWorkStateWriteHandler(){};
	virtual bool performState(WWNetwork* sock, WWSocketStatus inputState, float dt) override;
private:
	bool pushMsg(WWNetwork* sock);
	bool onWrite(WWNetwork* sock);
	void onRecv(WWNetwork* sock, float dt);
	bool onRead(WWNetwork* sock);
};