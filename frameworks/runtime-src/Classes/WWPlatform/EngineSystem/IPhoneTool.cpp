#include "IPhoneTool.h"
#include "../../WWPlatform/Tools/MD5.h"
#include "../../WWPlatform/Tools/WWTools.h"

std::string IPhoneTool::randomAsciiString(int len)
{
	
	std::string str;
	struct timeval psv;
	gettimeofday(&psv, NULL); // 计算时间种子
	unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000; // 初始化随机数
	srand(tsrans);
	for (int i = 0; i < len; ++i)
	{
		str.push_back(getRandomChar());
	}
	return str;

}

std::string IPhoneTool::getFormatDayTime()
{
	struct timeval now;
	gettimeofday(&now, NULL);
	struct tm *tm;
	time_t timep = now.tv_sec;
	tm = localtime(&timep);
	int year = tm->tm_year + 1900;
	int month = tm->tm_mon + 1;
	int day = tm->tm_mday;

	std::string time = StringUtils::format("%d", year);
	if (month < 10)
	{
		time += StringUtils::format("-0%d", month);
	} else
	{
		time += StringUtils::format("-%d", month);
	}

	if (day < 10)
	{
		time += StringUtils::format("-0%d", day);
	} else
	{
		time += StringUtils::format("-%d", day);
	}
	return time;
}

std::string IPhoneTool::decodeChar(char *src)
{
	//char* dest = (char *)malloc(strlen(src) * sizeof(char)+1);
	std::string dest;
	int code;
	
	for (; *src != '\0'; src++)
	{
		if (*src == '%')
		{
			if (sscanf(src + 1, "%2x", &code) != 1)
				code = '?';
			//*dest = code;
			dest += code;
			src += 2;
		} else if (*src == '+')
			//*dest = ' ';
			dest += ' ';
		else
		//*dest = *src;
		dest += *src;
	}
	//*dest = '\0';
	
	return dest;
}

float IPhoneTool::getScreenWidth()
{
	return Director::getInstance()->getOpenGLView()->getFrameSize().width;
}

float IPhoneTool::getScreenHeight()
{
	return Director::getInstance()->getOpenGLView()->getFrameSize().height;
}

std::string IPhoneTool::getMobileModel()
{
	return StringUtils::format("%dX%d", (int)getScreenWidth(), (int)getScreenHeight());

}

int IPhoneTool::getVersionCode()
{
    return 0;
}

void IPhoneTool::showMessage(const char* content, const char* title)
{
	MessageBox(content, title);
}
//默认返回可读写的路径
std::string IPhoneTool::getExternalFilesDir()
{
	return FileUtils::getInstance()->getWritablePath();
}

/*
 * 上传头像
 *
 */
void IPhoneTool::uploadHead(std::string url, std::string filePath)
{
    //HTTP请求
    HttpRequest* request = new HttpRequest();
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(IPhoneTool::onHttpRequestCompleted, this));
    
    
    Image * img = new Image();
    bool bInit =  img->initWithImageFile(filePath);
    CCLOG("UserInfoManager::uploadHead:headPath=%s", filePath.c_str());
    
    if (bInit)
    {
        CCLOG("UserInfoManager::uploadHead:saveToFile");
        bool bSave = img->saveToFile(filePath);
        
        if (bSave)
        {
            CCLOG("UserInfoManager::uploadHead:saveToFile:success");
        }
    }
    
    Data headData = FileUtils::getInstance()->getDataFromFile(filePath);
    
    const char *bytes = (const char *)headData.getBytes();
    request->setRequestData(bytes, headData.getSize());
    HttpClient::getInstance()->sendImmediate(request);
    
    request->release();
}

void IPhoneTool::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    if (!response->isSucceed()) {
        CCLOG("upload failure : %ld", response->getResponseCode());
        //发送通知事件
        // 上传头像，直接调用，发送事件
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([]() {
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("onUploadFailure");
        });
        return;
    }

    if (true)
    {
        std::vector<char> *buffer = response->getResponseData();
        Image *img = new Image();
        img->autorelease();
        
        char *tmp = new char[buffer->size()];
        for (int i = 0;  i < buffer->size(); ++ i)
        {
            tmp[i] = buffer->at(i);
        }
        log("upload ret %s", tmp);
        
        std::string result = tmp;
        delete tmp;
        
        size_t find_str_postion;
        find_str_postion = result.find("result=1");
        if (find_str_postion != std::string::npos)
        {
            //提交成功
            cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([]() {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("onUploadSuccess");
            });
        }
        else
        {
            //失败
            cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([]() {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("onUploadFailure");
            });
        }
        
    }
    
}

