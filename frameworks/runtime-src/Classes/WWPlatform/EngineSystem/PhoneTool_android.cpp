#include "PhoneTool_android.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#define PhoneToolPath "com/ww/platform/utils/PhoneTool"
PhoneTool_android::PhoneTool_android()
{
}


PhoneTool_android::~PhoneTool_android()
{
}

IPhoneTool* IPhoneTool::getInstance()
{
	static PhoneTool_android instance;

	return &instance;
}


bool PhoneTool_android::isMobileConnected()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "isMobileConnected",
                                       "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 判断是不是联通运营商
 * @return
 */
bool PhoneTool_android::isLTOperator()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "isLTOperator", "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 判断是不是电信运营商
 * @return
 */
bool PhoneTool_android::isDXOperator()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "isDXOperator", "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 判断是不是移动运营商
 * @return
 */
bool PhoneTool_android::isYDOperator()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "isYDOperator", "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 检查网络状态
 * @return
 */
std::string PhoneTool_android::checkNetState()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "checkNetState",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取运营商代码，
 *
 * @return
 */
int PhoneTool_android::getNetworkOperatorCode()
{
    int ret = -1;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "getNetworkOperatorCode", "()I"))
    {
        ret = t.env->CallStaticIntMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    
    return ret;
}



/**
 * 获取网络接入方式
 *
 * @return
 */
std::string PhoneTool_android::getApnType()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getApnType",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取用户识别码，前5位是运营商id
 */
std::string PhoneTool_android::getIdCode()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getIdCode",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取手机android版本号
 */
std::string PhoneTool_android::getSDkVersion()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getSDkVersion",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取手机厂商
 */
std::string PhoneTool_android::getPhoneModel()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getPhoneModel",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = std::string(str);
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

std::string PhoneTool_android::getPhoneHost()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getPhoneHost",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 手机型号
 */
std::string PhoneTool_android::getPhoneMANUFACTURER()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getPhoneMANUFACTURER",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取设备唯一标示
 * @return
 */
std::string PhoneTool_android::getPhoneDeviceId()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getPhoneDeviceId",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取手机上sdcard的状态
 * @return true-sdcard存在  false-sdcard不存在
 */
bool PhoneTool_android::isSdcardExist()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "isSdcardExist",
                                       "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}
/**
* 获得SD卡路径
*/
std::string PhoneTool_android::getSdcardPath()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getSdcardPath",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取mac地址
 *
 * @return
 */
std::string PhoneTool_android::getMacAddress()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getMacAddress",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 检查SIM卡是否可用
 *
 * @return true 可用
 */
bool PhoneTool_android::getSimCardState()
{
    bool ret = false;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getSimCardState",
                                       "()Z"))
    {
        
        jboolean retFromJava = t.env->CallStaticBooleanMethod(t.classID,
                                                              t.methodID);
        ret = retFromJava;
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取手机IMEI
 * @return
 */
std::string PhoneTool_android::getIMEI()
{
    
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getIMEI",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

/**
 * 获取手机ICCID
 * @return
 */
std::string PhoneTool_android::getICCID()
{
    std::string ret;
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getICCID",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret = str;
        
        t.env->ReleaseStringUTFChars(retFromJava, str);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

bool PhoneTool_android::isNetworkConnected()
{
	bool ret = false;
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
		"isNetworkConnected", "()Z"))
	{
		ret = t.env->CallStaticBooleanMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
	return ret;
	
}

std::string PhoneTool_android::getVersionName()
{
    return "";
}

//获取ip地址
std::string PhoneTool_android::getIpAddress()
{
    std::string ret;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "getIpAddress",
                                       "()Ljava/lang/String;"))
    {
        
        jstring retFromJava = (jstring) t.env->CallStaticObjectMethod(t.classID,
                                                                      t.methodID);
        const char* str = t.env->GetStringUTFChars(retFromJava, 0);
        ret=str;
        t.env->ReleaseStringUTFChars(retFromJava, str);
        
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

void PhoneTool_android::openLive800(const std::string &url)
{
    int ret = 0;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "loadWapActivity", "(Ljava/lang/String;)V"))
    {
        jstring jurl = t.env->NewStringUTF(url.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID,jurl);
        t.env->DeleteLocalRef(t.classID);
    }
}

void PhoneTool_android::makePhoneCall(const std::string &phoneNum)
{
    int ret = 0;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "makePhoneCall", "(Ljava/lang/String;)V"))
    {
        CCLOG("PhoneCall----number=%s",phoneNum.c_str());
        jstring jurl = t.env->NewStringUTF(phoneNum.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID,jurl);
        t.env->DeleteLocalRef(t.classID);
    }
}

void PhoneTool_android::openPhotoAndSavePic(int userid)
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "pickHeadFromAlbum", "(I)V"))
    {
        jint juserid=userid;
        t.env->CallStaticVoidMethod(t.classID, t.methodID,userid);
        t.env->DeleteLocalRef(t.classID);
    }
}

void PhoneTool_android::openCameraAndSavePic(int userid)
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "pickHeadFromCamera", "(I)V"))
    {
        jint juserid=userid;
        t.env->CallStaticVoidMethod(t.classID, t.methodID,juserid);
        t.env->DeleteLocalRef(t.classID);
    }
}

void PhoneTool_android::setScreenBrightness(float brightness)
{

}

//震动
void PhoneTool_android::phoneVibrate(int time)
{
    //震动是否为关闭状态
    bool state = UserDefault::getInstance()->getBoolForKey(KEY_SETTING_WI, true);
    if (state)
    {
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "phoneVibrate", "(I)V"))
        {
            t.env->CallStaticVoidMethod(t.classID, t.methodID, time);
            t.env->DeleteLocalRef(t.classID);
        }
    }
    else
    {
        CCLOG("PhoneTool::phoneVibrate 震动关闭了");
    }
    
}
//取消震动
void PhoneTool_android::cancelVibrate()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "cancelVibrate", "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

/**
 * 获取wifi信号强度
 */
int PhoneTool_android::getWifiState()
{
    int ret = -1;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "getWifistatus", "()I"))
    {
        ret = t.env->CallStaticIntMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

int PhoneTool_android::getPhoneNetState()
{
    int ret = -1;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath,
                                       "getPhoneNetState", "()I"))
    {
        ret = t.env->CallStaticIntMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

void PhoneTool_android::updateLatestApkPackage(std::string& apkPath)
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, PhoneToolPath, "updateVersion", "(Ljava/lang/String;)V"))
    {
        jstring jkey = t.env->NewStringUTF(apkPath.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jkey);
        t.env->DeleteLocalRef(t.classID);
    }
}

std::string PhoneTool_android::getExternalFilesDir()
{

	std::string ret= JniHelper::callStaticStringMethod(PhoneToolPath, "getExternalFilesDir");
	if (ret.empty())
	{
		ret = IPhoneTool::getExternalFilesDir();
	}

	return ret;
}


void PhoneTool_android::exitGame()
{

}

void PhoneTool_android::appUpdate(const std::string &contentText)
{

}

#endif
