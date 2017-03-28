#include "WWBufferPool.h"

WWBufferPool::WWBufferPool() :WWObjPool()
{
	this->mChunkSize = 20;
	this->releaseCountLimit = 80;
}

void WWBufferPool::allocateChunk()
{
	for (int i = 0; i < mChunkSize;i++) 
	{
		auto wb = new WWBuffer;
		wb->retain();
		mFreeList->addObject(wb);
	}
}

void WWBufferPool::releaseObject(WWBuffer* obj)
{
	obj->clear();
	if (obj->fromPool)
	{
		WWObjPool::releaseObject(obj);
	} 
	else
	{
		CC_SAFE_DELETE(obj);
	}
}