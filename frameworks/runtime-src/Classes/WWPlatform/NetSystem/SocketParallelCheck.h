#pragma once
//*******************************
//Name:SocketParallelCheck.h
//Desc:Socket Parallel Check
//Auth:Wawa
//Date:20161117
//Last:20170104
//*******************************

#include "WWInetAddress.h"

class SocketParallelCheck
{
public:
	SocketParallelCheck();
	~SocketParallelCheck(){ end(); }

public:
	enum class Statue
	{
		SUCCESS,	
		FAILURE,
		TIMEOUT,			
	};

	typedef std::function<void(Statue, const WWInetAddress &)> FN_CheckCallback;

	void setCheckCallback(const FN_CheckCallback &callback){ m_callback = callback; }
	bool isParalleling() { return m_isParalleling; }
	void setTimeout(float fTimeout);
	bool setSocketInetAddrs(const std::vector<WWInetAddress> &inetAddrs);
	bool start();
	bool end();

protected:
	void threadStart();
	void update(float);

private:
	enum class CheckStatusType 
	{
		INIT,				
		FAILURE,		
		SUCCESS,			
	};

	struct SocketData : public Ref
	{
		WWInetAddress _inetAddr;			
		CheckStatusType _checkSuccessed;	
		std::mutex _mutex;					
		explicit SocketData(const WWInetAddress &inetAddr, CheckStatusType init = CheckStatusType::INIT)
			: _inetAddr(inetAddr), _checkSuccessed(init) {}
	};

	void checkThreadFunc(SocketData *pData);

	void generateSocketDatas();

	void dispatchNetEventWithInetAddr(Statue val, const WWInetAddress &inetAddr);

	CC_DISALLOW_COPY_AND_ASSIGN(SocketParallelCheck);

private:
	int m_nTimeKey;
	bool m_isParalleling;								
	bool m_threadExitTag;							
	float m_totalSchedulerTime;						
	float m_timeout;								
	FN_CheckCallback m_callback;						
	vector<WWInetAddress> m_inetAddrs;					
	vector<SocketData*> m_socketDatas;					
	vector<std::thread> m_parallels;					
};