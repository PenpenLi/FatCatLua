#include "ImageDownLoader.h"
#include "ImageDownLoaderPool.h"
#include "network/HttpClient.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

ImageDownLoader::ImageDownLoader() : downloader(nullptr)
{
	

}


ImageDownLoader::~ImageDownLoader()
{
}
ImageDownLoader* ImageDownLoader::create(const char* url/* = nullptr*/, const char*textureCacheKey/* = nullptr*/)
{
	auto img = ImageDownLoaderPool::getInstance()->acquireObject();
	img->setUrl(url);
	img->setFunHandler(-1);
	if (textureCacheKey) 
	{
		img->textureCacheKey = textureCacheKey;
	}
	return img;
}
void ImageDownLoader::dropToPool()
{
	//httprequest->setResponseCallback(nullptr);
	//httprequest->release();
	CC_SAFE_DELETE(downloader);
	downloader = nullptr;
	textureCacheKey = "";
	LuaEngine::getInstance()->getLuaStack()->removeScriptHandler(m_luaHandler);
	ImageDownLoaderPool::getInstance()->releaseObject(this);
	ImageDownLoaderPool::getInstance()->checkToRelease();
	this->setFunHandler(-1);
}

void ImageDownLoader::excute(int handler)
{

	this->setFunHandler(handler);
	
	//httprequest = new HttpRequest;
	//httprequest->retain();
	//httprequest->setResponseCallback(CC_CALLBACK_2(ImageDownLoader::httpCB, this));
	//std::string postData = parmToStr(m_param);// "visitor=cocos2d&TestSuite=Extensions Test/NetworkTest";
	//httprequest->setRequestData(postData.c_str(), postData.length());
	//if (m_param.size() > 0)
	//{
	//	httprequest->setUrl(url);
	//	httprequest->setRequestType(HttpRequest::Type::POST);
	//} else
	//{
	//	httprequest->setUrl((url + "?" + postData).c_str());
	//	httprequest->setRequestType(HttpRequest::Type::GET);
	//}

	//HttpClient::getInstance()->sendImmediate(httprequest);
	//downloader.reset(new network::Downloader());
	downloader = new network::Downloader;
	downloader->onTaskProgress = CC_CALLBACK_3(ImageDownLoader::downloadProcess, this, std::placeholders::_4);

	downloader->onDataTaskSuccess = CC_CALLBACK_2(ImageDownLoader::downloadDataSuccess, this);

	downloader->onTaskError = CC_CALLBACK_3(ImageDownLoader::downloadError, this, std::placeholders::_4);
	downloader->createDownloadDataTask(url, url);


}
//下载进行中
void ImageDownLoader::downloadProcess(const network::DownloadTask& task, int64_t bytesReceived, int64_t totalBytesReceived, int64_t totalBytesExpected)
{
	//CCLOG("bytesReceived %I64u ,totalBytesReceived %I64u, totalBytesExpected %I64u", bytesReceived,totalBytesReceived,totalBytesExpected);
}
//下载成功
void ImageDownLoader::downloadDataSuccess(const cocos2d::network::DownloadTask& task, std::vector<unsigned char>& data)
{
	auto stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
	int data_length = data.size();
	Image* image = new Image;
	image->retain();
	image->initWithImageData((unsigned char*)data.data(), data.size());
	Image::Format formattype = image->getFileType();


	if (formattype != Image::Format::UNKNOWN)
	{
		auto texture = new Texture2D();
		bool isImage = texture->initWithImage(image);
		if (isImage)
		{
			CCLOG("Texture2D init ok!");
			texture->retain();

			if (!textureCacheKey.empty())
			{
				Director::getInstance()->getTextureCache()->addImage(image, textureCacheKey);
			}

			stack->pushObject(texture, "cc.Texture2D");
		}
	}


	//通过LuaStack调用lua里的函数	最后一个参数设置参数个数
	if (m_luaHandler > 0)
	{
		stack->executeFunctionByHandler(m_luaHandler, 1);
	}


	image->release();
	this->dropToPool();
}
//下载失败
void ImageDownLoader::downloadError(const cocos2d::network::DownloadTask& task, int errorCode, int errorCodeInternal, const std::string& errorStr)
{
	cocos2d::log("errorCode %d ,errorCodeInternal %d, errorStr %s", errorCode, errorCodeInternal, errorStr.c_str());
	auto stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
	
	//通过LuaStack调用lua里的函数	最后一个参数设置参数个数
	if (m_luaHandler > 0)
	{
		stack->executeFunctionByHandler(m_luaHandler, 1);
	}
	this->dropToPool();
}

//void ImageDownLoader::httpCB(HttpClient* client, HttpResponse* response)
//{
//	auto stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
//	if (!response)
//	{
//		this->dropToPool();
//			//通过LuaStack调用lua里的函数	最后一个参数设置参数个数
//	if (m_luaHandler>0)
//	{
//		stack->executeFunctionByHandler(m_luaHandler, 1);
//	}
//		return;
//	}
//	if (!response->isSucceed())
//	{
//		CCLOG("ImageDownLoader response failed");
//		this->dropToPool();
//		if (m_luaHandler > 0)
//		{
//			stack->executeFunctionByHandler(m_luaHandler, 1);
//		}
//		return;
//	}
//
//	if (404 == response->getResponseCode()) {
//		CCLOG("ImageDownLoader response failed");
//		this->dropToPool();
//		return;
//	}
//	std::vector<char> *data = response->getResponseData();
//	int data_length = data->size();
//	Image* image = new Image;
//	image->retain();
//	image->initWithImageData((unsigned char*)data->data(), data->size());
//	Image::Format formattype = image->getFileType();
//	
//	
//	if (formattype!=Image::Format::UNKNOWN) 
//	{
//		auto texture = new Texture2D();
//		bool isImage = texture->initWithImage(image);
//		if (isImage)
//		{
//			CCLOG("Texture2D init ok!");
//			texture->retain();
//	
//			if (!textureCacheKey.empty())
//			{
//				Director::getInstance()->getTextureCache()->addImage(image, textureCacheKey);
//			}
//		
//			stack->pushObject(texture, "cc.Texture2D");
//		}
//	}
//
//	
//	//通过LuaStack调用lua里的函数	最后一个参数设置参数个数
//	if (m_luaHandler>0)
//	{
//		stack->executeFunctionByHandler(m_luaHandler, 1);
//	}
//	
//	
//	image->release();
//	this->dropToPool();
//}
void ImageDownLoader::removeHandler()
{
	LuaEngine::getInstance()->getLuaStack()->removeScriptHandler(m_luaHandler);
	m_luaHandler = -1;
	this->dropToPool();
	
}