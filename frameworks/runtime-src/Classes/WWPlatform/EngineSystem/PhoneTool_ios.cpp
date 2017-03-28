#include "PhoneTool_ios.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "WWIphoneTool.h"



PhoneTool_ios::PhoneTool_ios()
{
}


PhoneTool_ios::~PhoneTool_ios()
{
}

IPhoneTool* IPhoneTool::getInstance()
{
	static PhoneTool_ios instance;

	return &instance;
}


bool PhoneTool_ios::isMobileConnected()
{
	return false;
}


bool PhoneTool_ios::isLTOperator()
{
	return false;
}

bool PhoneTool_ios::isDXOperator()
{
	return false;
}


bool PhoneTool_ios::isYDOperator()
{
	return false;
}


std::string PhoneTool_ios::checkNetState()
{
    int net = WWIphoneTool::getInstance()->getNetWorkID();
    if (net == 9)
    {
        return "wifi";
    }
    return "";
}

/**
* 获取运营商代码，
*
* @return
*/
int PhoneTool_ios::getNetworkOperatorCode()
{
    return WWIphoneTool::getInstance()->getNetWorkID();
}

/**
* 获取网络接入方式
*
* @return
*/
std::string PhoneTool_ios::getApnType()
{
	return "";
}

/**
* 获取用户识别码，前5位是运营商id
*/
std::string PhoneTool_ios::getIdCode()
{
    return WWIphoneTool::getInstance()->getPhoneIMSI();
}

/**
* 获取OS版本号
*/
std::string PhoneTool_ios::getSDkVersion()
{
    return WWIphoneTool::getInstance()->getSystemNameVersion();
}

/**
* 获取手机厂商
*/
std::string PhoneTool_ios::getPhoneModel()
{
	return WWIphoneTool::getInstance()->getPhoneModel();
}

/**
* 获取手机Host
* @return
*/
std::string PhoneTool_ios::getPhoneHost()
{
	return "";
}
/**
* 手机型号
*/
std::string PhoneTool_ios::getPhoneMANUFACTURER()
{
    return WWIphoneTool::getInstance()->getPhoneFactory();
}
/**
* 获取设备唯一标示
* @return
*/
std::string PhoneTool_ios::getPhoneDeviceId()
{
	return "";
}

/**
* 获取手机上sdcard的状态
* @return true-sdcard存在  false-sdcard不存在
*/
bool PhoneTool_ios::isSdcardExist()
{
	return true;
}
/**
* 获取sd卡路径
*/
std::string PhoneTool_ios::getSdcardPath()
{
	return FileUtils::getInstance()->getWritablePath();
}

/**
* 获取mac地址
*
* @return
*/
std::string PhoneTool_ios::getMacAddress()
{
//	return "";
    
    //直接将UDID当做唯一标识
    CCLOG("getMacAddress %s", WWIphoneTool::getInstance()->getPhoneUDID());
    return WWIphoneTool::getInstance()->getPhoneUDID();
}

/**
* 检查SIM卡是否可用
*
* @return true 可用
*/
bool PhoneTool_ios::getSimCardState()
{
    return WWIphoneTool::getInstance()->getPhoneSimCardState();
}
/**
* 获取手机IMEI
* @return
*/
std::string PhoneTool_ios::getIMEI()
{
    return WWIphoneTool::getInstance()->getPhoneIMEI();
}

/**
* 获取手机ICCID
* @return
*/
std::string PhoneTool_ios::getICCID()
{
    return WWIphoneTool::getInstance()->getPhoneICCID();
}

bool PhoneTool_ios::isNetworkConnected()
{
	return true;
}

//获取ip地址
std::string PhoneTool_ios::getIpAddress()
{
    return WWIphoneTool::getInstance()->getIpAddress();
}

void PhoneTool_ios::openLive800(const std::string &url)
{
    WWIphoneTool::getInstance()->openLive800(url);
}

void PhoneTool_ios::makePhoneCall(const std::string &phoneNum)
{
    WWIphoneTool::getInstance()->makePhoneCall(phoneNum);
}

//版本号
std::string PhoneTool_ios::getVersionName()
{
    
    std::string version = WWIphoneTool::getInstance()->getAppVersion();
    if (version.c_str())
    {
        log("ios PhoneTool::getVersionName : %s", version.c_str());
        return version;
    }
    else
    {
        return "";
    }
    
}

void PhoneTool_ios::openPhotoAndSavePic(int userid)
{
    
    WWIphoneTool::getInstance()->openPhotoAndSavePic(userid);
    
}

void PhoneTool_ios::openCameraAndSavePic(int userid)
{
    
    WWIphoneTool::getInstance()->openCameraAndSavePic(userid);
    
}

void PhoneTool_ios::setScreenBrightness(float brightness)
{
    WWIphoneTool::getInstance()->setScreenBrightness(brightness);
}

int PhoneTool_ios::getWifiState()
{
    int netStatus = WWIphoneTool::getInstance()->getWifiStatus();
    return netStatus;
}

int PhoneTool_ios::getPhoneNetState()
{
    return 0;
}

//震动
void PhoneTool_ios::phoneVibrate(int time)
{
    //震动是否为关闭状态
    bool state = UserDefault::getInstance()->getBoolForKey(KEY_SETTING_WI, true);
    if (state)
    {
        WWIphoneTool::getInstance()->vibrator(time);
    }
    else
    {
        CCLOG("PhoneTool::phoneVibrate 震动关闭了");
    }
    
}
//取消震动
void PhoneTool_ios::cancelVibrate()
{
    
}

void PhoneTool_ios::appUpdate(const std::string &contentText)
{
    
}

void PhoneTool_ios::exitGame()
{
    WWIphoneTool::getInstance()->exitGame();
}

void PhoneTool_ios::updateLatestApkPackage(std::string& apkPath)
{
    
}

#endif
