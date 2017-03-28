#pragma once
#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/CCDownloader.h"
USING_NS_CC;
using namespace network;

/*! @file
********************************************************************************
<PRE>
ģ����       :  ͼƬ������
�ļ���       :  ImageDownLoader.h
�ļ�ʵ�ֹ��� :  ͨ��http��ʽ����ͼƬ�����ҿ��Խ�ͼƬ��texturecachekey����ʽ�����ڴ���
����         :  cruelogre  546761316@qq.com
�汾         :  1.1
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
�޸ļ�¼ :
�� ��        �汾     �޸���              �޸�����
2016/8/5   1.0     cruelogre		      �½�
2016/8/8   1.1     cruelogre		      ����ͷ�handler�ӿ�
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

