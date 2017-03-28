#pragma once
#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

class IPhoneTool
{
public:

	static IPhoneTool* getInstance();
	const char* KEY_SETTING_SILENCE = "key_setting_silence";
	const char* KEY_SETTING_effect_VALUE = "key_setting_sound_value";
	const char* KEY_SETTING_bg_VALUE = "key_setting_music_value";
	const char* KEY_SETTING_WI = "key_setting_wi";
	const char* KEY_SETTING_ACTION = "key_setting_action";

	//静音之前两个音量的大小
	const char* KEY_SLIENCE_EFFECT_RECORD = "key_before_slience_effect";
	const char* KEY_SLIENCE_MUSIC_RECORD = "key_before_slience_music";

public:

	/**
	* 随机生成指定长度大小写字母、数字组合字符串
	*
	* @param len
	* @return
	*/
	std::string randomAsciiString(int len);
	std::string getFormatDayTime();

	//打开网络设置
	virtual void openNetSetting(){};

	virtual float getScreenWidth();

	virtual float getScreenHeight();
	virtual std::string getMobileModel();
	virtual bool is2GNetWork(){ return false; }

	std::string decodeChar(char *src);
	/**
	* 弹出提示框
	*
	* @param len
	* @return
	*/
	void showMessage(const char* content,const char* title);
    
    //上传头像
    void uploadHead(std::string url, std::string filePath);

public:
	
	/**
	* 是否是连接的移动网络
	* @return
	*/
	virtual bool isMobileConnected() =0;

	/**
	* 判断是不是联通运营商
	* @return
	*/
	virtual bool isLTOperator() = 0;

	/**
	* 判断是不是电信运营商
	* @return
	*/
	virtual bool isDXOperator() = 0;

	/**
	* 判断是不是移动运营商
	* @return
	*/
	virtual bool isYDOperator() =0;

	/**
	* 检查网络状态
	* @return
	*/
	virtual std::string checkNetState() = 0;


	

	/**
	* 获取运营商代码，
	*
	* @return
	*/
	virtual int getNetworkOperatorCode() = 0;

	/**
	* 获取网络接入方式
	*
	* @return
	*/
	virtual std::string getApnType() = 0;

	/**
	* 获取用户识别码，前5位是运营商id
	*/
	virtual std::string getIdCode() = 0;

	/**
	* 获取手机android版本号
	*/
	virtual std::string getSDkVersion() = 0;


	/**
	* 获取手机厂商
	*/
	virtual std::string getPhoneModel() = 0;

	/**
	* 获取手机Host
	* @return
	*/
	virtual std::string getPhoneHost() = 0;
	/**
	* 手机型号
	*/
	virtual std::string getPhoneMANUFACTURER() = 0;
	/**
	* 获取设备唯一标示
	* @return
	*/
	virtual std::string getPhoneDeviceId() = 0;

	/**
	* 获取手机上sdcard的状态
	* @return true-sdcard存在  false-sdcard不存在
	*/
	virtual bool isSdcardExist() = 0;
	/**
	* 获取sd卡路径
	*/
	virtual std::string getSdcardPath() = 0;

	/**
	* 获取mac地址
	*
	* @return
	*/
	virtual std::string getMacAddress() = 0;

	/**
	* 检查SIM卡是否可用
	*
	* @return true 可用
	*/
	virtual bool getSimCardState() = 0;
	/**
	* 获取手机IMEI
	* @return
	*/
	virtual std::string getIMEI() = 0;
	/**
	* 获取手机ICCID
	* @return
	*/
	virtual std::string getICCID() = 0;

	/**
	* 判断网络是否可用
	* @return
	*/
	virtual bool isNetworkConnected() = 0;
    
    /**
     * 获取版本号
     */
    virtual int getVersionCode();
    
    /**
     * 获取版本名称
     */
    virtual std::string getVersionName() = 0;
    
    /**
     * 获取ip地址
     *
     */
    virtual std::string getIpAddress() = 0;
    
    //设置屏幕亮度
    virtual void setScreenBrightness(float brightness) = 0;
    
    //震动
    virtual void phoneVibrate(int time) = 0;
    
    //取消震动
    virtual void cancelVibrate() = 0;
    
    //获取wifi信号强度
    virtual int getWifiState() = 0;
    
    //获取移动网络信号强度
    virtual int getPhoneNetState() = 0;
    
    //版本更新
    virtual void appUpdate(const std::string &contentText) = 0;
    
    virtual void updateLatestApkPackage(std::string& apkPath) = 0;
    
    virtual void exitGame() = 0;
    
    /**
     * open live800
     *
     */
    virtual void openLive800(const std::string &url) = 0;
    
    /**
     * open makePhone
     *
     */
    virtual void makePhoneCall(const std::string &phoneNum) = 0;
    
    //从相册获取图片
    virtual void openPhotoAndSavePic(int userid) = 0;
    
    //拍照
    virtual void openCameraAndSavePic(int userid) = 0;
	//获取外部的文件路径
	virtual std::string getExternalFilesDir();
protected:
	//上传头像返回
	void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);
	//随机一个字符
		char getRandomChar()
		{
			int randomInt;

			randomInt = (int)(CCRANDOM_0_1() * 62);

			//		WW_LOG_ERROR("randomInt=%d",randomInt);

			if (randomInt < 10)
			{
				randomInt += 48;
			} else if (randomInt < 36)
			{
				randomInt += 55;
			} else
			{
				randomInt += 61;
			}
			return (char)randomInt;
		}
};

