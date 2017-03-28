#pragma once
#include "WWObjPool.h"
#include "ImageDownLoader.h"
class ImageDownLoaderPool :public WWObjPool<ImageDownLoaderPool,ImageDownLoader>
{
public:
	ImageDownLoaderPool();
	virtual ~ImageDownLoaderPool();

	void allocateChunk() override;


};

