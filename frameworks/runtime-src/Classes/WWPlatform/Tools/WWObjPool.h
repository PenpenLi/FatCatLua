#pragma once
#pragma execution_character_set("utf-8")

#include "cocos2d.h"
#include <thread>
#include <mutex>

USING_NS_CC;


template <typename T1, typename T2>
class WWObjPool
{
public:
	static T1* getInstance();
	static void releaseInstance();
	//
	//acquire object from pool or generate object and add to object pool if necessary
	//
	virtual T2* acquireObject();
	//  
	// Return the object to the pool. Clients must not use the object after  
	// it has been returned to the pool.  
	//we do not remove the object from it own parent for we remove at the end of main loop
	//  
	virtual void releaseObject(T2* obj);
	//
	//every end of main loop check to release object from pool
	//
	inline void checkToRelease();
	virtual void removeAllObjects();
protected:
	WWObjPool();
	~WWObjPool();
	__Array *mFreeList;

	CC_SYNTHESIZE(int, releaseCountLimit, ReleaseCountLimit);//realease count warnning limit
	CC_SYNTHESIZE(int, mChunkSize, ChunkSize);
	//static int mChunkSize = 20;
	int objectCount;
	int releaseCount;
	static T1* t;
	//int kDefaultChunkSize;  

	//  
	// Allocates mChunkSize new objects and adds them  
	// to the mFreeList.  
	//  
	virtual void allocateChunk(){};
	std::mutex gobj_lock;
};

template <typename T1, typename T2>
inline T1* WWObjPool<T1, T2>::getInstance()
{
	if (!t)
	{
		t = new T1;
	}
	return t;
}

template<typename T1, typename T2>
void WWObjPool<T1, T2>::releaseInstance()
{
	if (t)
	{
		delete t;
		t = 0;
	}
}



template<typename T1, typename T2>
WWObjPool<T1, T2>::WWObjPool() :objectCount(0), releaseCount(0)
{
	mChunkSize = 10;
	releaseCountLimit = 20;
	if (mChunkSize <= 1) {
		CCAssert(mChunkSize >= 1, "mChunkSize should >= 1");
	}
	// Create mChunkSize objects to start  
	mFreeList = __Array::createWithCapacity(mChunkSize);
	mFreeList->retain();
	//allocateChunk();  

}
template<typename T1, typename T2>
WWObjPool<T1, T2>::~WWObjPool()
{
	Ref * obj;
	CCARRAY_FOREACH(mFreeList, obj)
	{
		delete[] obj;
	}
}
template<typename T1, typename T2>
T2* WWObjPool<T1, T2>::acquireObject()
{
	gobj_lock.lock();
	if (mFreeList->count() <= 0) {
		allocateChunk();
	}
	objectCount = mFreeList->count();
	//CCAssert(mFreeList->count() >= 1, "mFreeList must be initialized,override allocateChunk");  

	T2 *obj = dynamic_cast<T2*>(mFreeList->getObjectAtIndex(0));
	mFreeList->removeObjectAtIndex(0, false);
	
	gobj_lock.unlock();
	return obj;
}
//  
// Return the object to the pool. Clients must not use the object after  
// it has been returned to the pool.  
//we do not remove the object from it own parent for we remove at the end of main loop
//  
template<typename T1, typename T2>
void WWObjPool<T1, T2>::releaseObject(T2* obj)
{
	//here we add some mechanism to auto release the holding objects
	if (obj&&!mFreeList->containsObject(obj)) 
	{
		releaseCount++;
		mFreeList->addObject(obj);
	}
	
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
template<typename T1, typename T2>
inline void WWObjPool<T1, T2>::checkToRelease()
{
	if (releaseCount >= releaseCountLimit) //every 10 times we check the object pool,and release object if the count of object in pool is bigger than 5*mChunkSize
	{
		releaseCount = 0;
		if (mFreeList->count() >= 5 * mChunkSize)
		{
			mFreeList->removeAllObjects();
		}
	}
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
template<typename T1, typename T2>
void WWObjPool<T1, T2>::removeAllObjects()
{

	mFreeList->removeAllObjects();
}
//template<typename T1,typename T2>
//void GameObjPool<T1,T2>::allocateChunk()
//{
// for (int i = 0; i < mChunkSize; i++) {  
//	 T2* newObjects = T2::create();  
//	 //	mFreeList.push(newObjects);
//	 mFreeList->addObject(newObjects);
// }  
//}

template<typename T1, typename T2>
T1* WWObjPool<T1, T2>::t = 0;