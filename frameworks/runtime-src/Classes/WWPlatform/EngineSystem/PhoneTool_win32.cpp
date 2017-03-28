#include "PhoneTool_win32.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32


#include <Sensapi.h>
#pragma comment(lib, "Sensapi.lib")
#include "../DBSystem/WWGameData.h"
#include "../VariateSystem/WWConfigManager.h"

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

//将TCHAR转为char   
//*tchar是TCHAR类型指针，*_char是char类型指针   
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

WWSystemConfig enginConfig;

PhoneTool_win32::PhoneTool_win32()
{
	enginConfig = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_ENGINE);
}


PhoneTool_win32::~PhoneTool_win32()
{
}

IPhoneTool* IPhoneTool::getInstance()
{
	static PhoneTool_win32 instance;

	return &instance;
}


bool PhoneTool_win32::isMobileConnected()
{
	return false;
}


bool PhoneTool_win32::isLTOperator()
{
	return false;
}

bool PhoneTool_win32::isDXOperator()
{
	return false;
}


bool PhoneTool_win32::isYDOperator()
{
	return false;
}


std::string PhoneTool_win32::checkNetState()
{
	auto netState = "wifi";
	for (auto& item:enginConfig.items) 
	{
		if (strcmp(item->name, "connectType") == 0 && item->values.size()>0)
		{
			netState = item->values[0].c_str(); 
			break;
		}
	}
	return netState;
}

/**
* 获取运营商代码，
*
* @return
*/
int PhoneTool_win32::getNetworkOperatorCode()
{
	return 0;
}

/**
* 获取网络接入方式
*
* @return
*/
std::string PhoneTool_win32::getApnType()
{
	return "";
}

/**
* 获取用户识别码，前5位是运营商id
*/
std::string PhoneTool_win32::getIdCode()
{
	return "10";
}

/**
* 获取手机android版本号
*/
std::string PhoneTool_win32::getSDkVersion()
{
	return "";
}

/**
* 获取手机厂商
*/
std::string PhoneTool_win32::getPhoneModel()
{
	return "";
}

/**
* 获取手机Host
* @return
*/
std::string PhoneTool_win32::getPhoneHost()
{
	return "";
}
/**
* 手机型号
*/
std::string PhoneTool_win32::getPhoneMANUFACTURER()
{
	return "";
}
/**
* 获取设备唯一标示
* @return
*/
std::string PhoneTool_win32::getPhoneDeviceId()
{
	return "";
}

/**
* 获取手机上sdcard的状态
* @return true-sdcard存在  false-sdcard不存在
*/
bool PhoneTool_win32::isSdcardExist()
{
	return true;
}
/**
* 获取sd卡路径
*/
std::string PhoneTool_win32::getSdcardPath()
{
	return FileUtils::getInstance()->getWritablePath();
}

/**
* 获取mac地址
*
* @return
*/
std::string PhoneTool_win32::getMacAddress()
{
	return "";
}

/**
* 检查SIM卡是否可用
*
* @return true 可用
*/
bool PhoneTool_win32::getSimCardState()
{
	return true;
}
/**
* 获取手机IMEI
* @return
*/
std::string PhoneTool_win32::getIMEI()
{
	return "";
}

/**
* 获取手机ICCID
* @return
*/
std::string PhoneTool_win32::getICCID()
{
	return "";
}


bool PhoneTool_win32::isNetworkConnected()
{
	DWORD dw;	
	return  IsNetworkAlive(&dw);

}

//版本号
std::string PhoneTool_win32::getVersionName()
{
    return "";
}

//获取ip地址
std::string PhoneTool_win32::getIpAddress()
{
    return "";
}

void PhoneTool_win32::openLive800(const std::string &url)
{
    
}

void PhoneTool_win32::makePhoneCall(const std::string &phoneNum)
{

}

void PhoneTool_win32::openPhotoAndSavePic(int userid)
{
	TCHAR szFileName[MAX_PATH] = { 0 };
	OPENFILENAME openFileName = { 0 };
	openFileName.lStructSize = sizeof(OPENFILENAME);
	openFileName.nMaxFile = MAX_PATH;  //这个必须设置，不设置的话不会出现打开文件对话框  
	openFileName.lpstrFilter = L"PNG file(*.png)\0*.png\0JPG file(*.jpg)\0*.jpg";
	
	openFileName.lpstrFile = szFileName;
	openFileName.nFilterIndex = 1;
	openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (::GetOpenFileName(&openFileName))
	{
		//::MessageBoxA(hwndDlg, szFileName, "", MB_OK);
		
		//this->showMessage(szFileName, "111");
		int iLen = 2 * wcslen(szFileName);//CString,TCHAR汉字算一个字符，因此不用普通计算长度   
		char* chooseFile = new char[iLen + 1];
		TcharToChar(szFileName, chooseFile);
		CCLOG("%s", chooseFile);
		auto data = FileUtils::getInstance()->getDataFromFile(chooseFile);
		if (!data.isNull()&& data.getSize()<100*1024) 
		{
			if (!FileUtils::getInstance()->isDirectoryExist(FileUtils::getInstance()->getWritablePath()+"headFiles"))
			{
				FileUtils::getInstance()->createDirectory(FileUtils::getInstance()->getWritablePath()+"headFiles");
			}
			std::string headFilePath = FileUtils::getInstance()->getWritablePath() + StringUtils::format("headFiles/%d_upload_head.%s", userid, openFileName.nFilterIndex==1?"png":"jpg");

			//WriteIo::getInstance()->saveFile((const char*)data.getBytes(), headFilePath.c_str());
			FileUtils::getInstance()->writeDataToFile(data, headFilePath);

			WWGameData::getInstance()->setStringForKey(StringUtils::format("UploadHeadPath_%d",userid).c_str(), headFilePath);
			//ToolCom : uploadHead(saveNativePath)
			//刷新头像
			Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("onAvatarCrop");
			//this->uploadHead("", headFilePath);
		}
		else if (!data.isNull())
		{
			CCLOG("head file is too big!must be limited to less than 100k");
		}
	}
    
}

void PhoneTool_win32::openCameraAndSavePic(int userid)
{
    
    
}

void PhoneTool_win32::setScreenBrightness(float brightness)
{
}

int PhoneTool_win32::getWifiState()
{
    return 0;
}

int PhoneTool_win32::getPhoneNetState()
{
    return 0;
}

//震动
void PhoneTool_win32::phoneVibrate(int time)
{
    //震动是否为关闭状态

    
}
//取消震动
void PhoneTool_win32::cancelVibrate()
{
    
}

void PhoneTool_win32::appUpdate(const std::string &contentText)
{
    
}

void PhoneTool_win32::exitGame()
{
	
}

void PhoneTool_win32::updateLatestApkPackage(std::string& apkPath)
{
    
}

#endif