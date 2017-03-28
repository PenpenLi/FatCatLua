#pragma once
#include "IPhoneTool.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
class PhoneTool_android :
	public IPhoneTool
{
public:
	PhoneTool_android();
	~PhoneTool_android();

	/**
	* 是否是连接的移动网络
	* @return
	*/
	bool isMobileConnected() override;

	/**
	* 判断是不是联通运营商
	* @return
	*/
	bool isLTOperator() override;

	/**
	* 判断是不是电信运营商
	* @return
	*/
	bool isDXOperator() override;

	/**
	* 判断是不是移动运营商
	* @return
	*/
	bool isYDOperator() override;

	/**
	* 检查网络状态
	* @return
	*/
	std::string checkNetState() override;

	/**
	* 获取运营商代码，
	*
	* @return
	*/
	int getNetworkOperatorCode() override;

	/**
	* 获取网络接入方式
	*
	* @return
	*/
	std::string getApnType() override;

	/**
	* 获取用户识别码，前5位是运营商id
	*/
	std::string getIdCode() override;

	/**
	* 获取手机android版本号
	*/
	std::string getSDkVersion() override;


	/**
	* 获取手机厂商
	*/
	std::string getPhoneModel() override;

	/**
	* 获取手机Host
	* @return
	*/
	std::string getPhoneHost() override;
	/**
	* 手机型号
	*/
	std::string getPhoneMANUFACTURER() override;
	/**
	* 获取设备唯一标示
	* @return
	*/
	std::string getPhoneDeviceId() override;

	/**
	* 获取手机上sdcard的状态
	* @return true-sdcard存在  false-sdcard不存在
	*/
	bool isSdcardExist() override;
	/**
	* 获取sd卡路径
	*/
	std::string getSdcardPath() override;

	/**
	* 获取mac地址
	*
	* @return
	*/
	std::string getMacAddress() override;

	/**
	* 检查SIM卡是否可用
	*
	* @return true 可用
	*/
	bool getSimCardState() override;
	/**
	* 获取手机IMEI
	* @return
	*/
	std::string getIMEI() override;
	/**
	* 获取手机ICCID
	* @return
	*/
	std::string getICCID() override;

	bool isNetworkConnected() override;
    
    /**
     * 获取版本名称
     */
    std::string getVersionName() override;
    
    /**
     * 获取ip地址
     *
     */
    std::string getIpAddress() override;
    
    void openLive800(const std::string &url) override;
    
    void makePhoneCall(const std::string &phoneNum) override;
    
    //设置屏幕亮度
    void setScreenBrightness(float brightness) override;
    
    //震动
    void phoneVibrate(int time) override;
    
    //取消震动
    void cancelVibrate() override;
    
    //获取wifi信号强度
    int getWifiState() override;
    
    //获取移动网络信号强度
    int getPhoneNetState() override;
    
    
    //版本更新
    void appUpdate(const std::string &contentText) override;
    
    void updateLatestApkPackage(std::string& apkPath) override;
    
    void exitGame() override;
    
    //从相册获取图片
    void openPhotoAndSavePic(int userid) override;
    
    //拍照
    void openCameraAndSavePic(int userid) override;

	std::string getExternalFilesDir() override;

};
#endif
