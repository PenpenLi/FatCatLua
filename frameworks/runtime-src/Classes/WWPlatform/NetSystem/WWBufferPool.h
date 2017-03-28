#pragma once

//*******************************
//Name:WWBufferPool.h
//Desc:Buffer Pool
//Auth:Wawa
//Date:?
//Last:20161124
//*******************************

#include "../Tools/WWObjPool.h"
#include "WWBuffer.h"

class WWBufferPool :public WWObjPool<WWBufferPool, WWBuffer>
{
public:
	WWBufferPool();
	virtual ~WWBufferPool(){}

	void allocateChunk() override;
	void releaseObject(WWBuffer* obj) override;
};