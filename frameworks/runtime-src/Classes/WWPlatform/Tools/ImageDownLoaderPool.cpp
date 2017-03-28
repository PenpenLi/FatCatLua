#include "ImageDownLoaderPool.h"


ImageDownLoaderPool::ImageDownLoaderPool()
{
}


ImageDownLoaderPool::~ImageDownLoaderPool()
{
}


void ImageDownLoaderPool::allocateChunk()
{
	for (int i = 0; i < mChunkSize; i++)
	{
		auto wb = new ImageDownLoader;
		wb->retain();
		mFreeList->addObject(wb);
	}
}
