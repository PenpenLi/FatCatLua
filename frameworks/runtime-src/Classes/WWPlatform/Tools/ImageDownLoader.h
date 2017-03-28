#pragma once
#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/CCDownloader.h"
USING_NS_CC;
using namespace network;

/*! @file
********************************************************************************
<PRE>
模块名       :  图片下载器
文件名       :  ImageDownLoader.h
文件实现功能 :  通过http方式下载图片，并且可以将图片以texturecachekey的形式存入内存中
作者         :  cruelogre  546761316@qq.com
版本         :  1.1
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/8/5   1.0     cruelogre		      新建
2016/8/8   1.1     cruelogre		      添加释放handler接口
</PRE>
*******************************************************************************/
class ImageDownLoader:public Ref
{
public:
	friend class ImageDownLoaderPool;
public:
	
	~ImageDownLoader();

	static ImageDownLoader* create(const char* url = nullptr, const char*textureCacheKey = nullptr);
	void setParam(std::map<std::string, std::string>& param){ m_param = param; };
	void excute(int handler);
	
	void removeHandler();
protected:
	ImageDownLoader();
//	void httpCB(HttpClient* client, HttpResponse* response);

	void downloadProcess(const network::DownloadTask& task,
		int64_t bytesReceived,
		int64_t totalBytesReceived,
		int64_t totalBytesExpected);

	void downloadDataSuccess(const cocos2d::network::DownloadTask& task,
		std::vector<unsigned char>& data);

	void downloadError(const cocos2d::network::DownloadTask& task,
		int errorCode,
		int errorCodeInternal,
		const std::string& errorStr);

	void dropToPool();

	std::string parmToStr(const std::map<std::string, std::string>& params)
	{
		std::string paramStr;
		int len = params.size();
		int index = 0;
		for (auto& pa : params)
		{
			index++;
			paramStr.append(pa.first).append("=").append(pa.second);
			if (index < len)
			{
				paramStr.append("&");
			}

		}

		return paramStr;
	}

private:
	//HttpRequest* httprequest;
	//std::unique_ptr<network::Downloader> downloader;
	network::Downloader* downloader;
	CC_SYNTHESIZE(std::string, url,Url);
	CC_SYNTHESIZE(int, m_luaHandler, FunHandler);

	std::string textureCacheKey;

	std::map<std::string, std::string> m_param;
};

