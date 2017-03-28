
--------------------------------
-- @module IPhoneTool
-- @parent_module ww

--------------------------------
-- 检查网络状态<br>
-- return
-- @function [parent=#IPhoneTool] checkNetState 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取手机Host<br>
-- return
-- @function [parent=#IPhoneTool] getPhoneHost 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取设备唯一标示<br>
-- return
-- @function [parent=#IPhoneTool] getPhoneDeviceId 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- open makePhone
-- @function [parent=#IPhoneTool] makePhoneCall 
-- @param self
-- @param #string phoneNum
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 获取网络接入方式<br>
-- return
-- @function [parent=#IPhoneTool] getApnType 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] phoneVibrate 
-- @param self
-- @param #int time
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 获取ip地址
-- @function [parent=#IPhoneTool] getIpAddress 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取运营商代码，<br>
-- return
-- @function [parent=#IPhoneTool] getNetworkOperatorCode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 判断是不是联通运营商<br>
-- return
-- @function [parent=#IPhoneTool] isLTOperator 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getFormatDayTime 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取手机厂商
-- @function [parent=#IPhoneTool] getPhoneModel 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] openPhotoAndSavePic 
-- @param self
-- @param #int userid
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 随机生成指定长度大小写字母、数字组合字符串<br>
-- param len<br>
-- return
-- @function [parent=#IPhoneTool] randomAsciiString 
-- @param self
-- @param #int len
-- @return string#string ret (return value: string)
        
--------------------------------
-- 是否是连接的移动网络<br>
-- return
-- @function [parent=#IPhoneTool] isMobileConnected 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 获取mac地址<br>
-- return
-- @function [parent=#IPhoneTool] getMacAddress 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getMobileModel 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取手机上sdcard的状态<br>
-- return true-sdcard存在  false-sdcard不存在
-- @function [parent=#IPhoneTool] isSdcardExist 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getPhoneNetState 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 判断网络是否可用<br>
-- return
-- @function [parent=#IPhoneTool] isNetworkConnected 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] exitGame 
-- @param self
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- open live800
-- @function [parent=#IPhoneTool] openLive800 
-- @param self
-- @param #string url
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 获取版本号
-- @function [parent=#IPhoneTool] getVersionCode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] setScreenBrightness 
-- @param self
-- @param #float brightness
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] cancelVibrate 
-- @param self
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 手机型号
-- @function [parent=#IPhoneTool] getPhoneMANUFACTURER 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 判断是不是移动运营商<br>
-- return
-- @function [parent=#IPhoneTool] isYDOperator 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 获取手机IMEI<br>
-- return
-- @function [parent=#IPhoneTool] getIMEI 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] is2GNetWork 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 判断是不是电信运营商<br>
-- return
-- @function [parent=#IPhoneTool] isDXOperator 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 获取手机ICCID<br>
-- return
-- @function [parent=#IPhoneTool] getICCID 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] appUpdate 
-- @param self
-- @param #string contentText
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getScreenHeight 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 获取版本名称
-- @function [parent=#IPhoneTool] getVersionName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getExternalFilesDir 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getWifiState 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 获取sd卡路径
-- @function [parent=#IPhoneTool] getSdcardPath 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 检查SIM卡是否可用<br>
-- return true 可用
-- @function [parent=#IPhoneTool] getSimCardState 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] openCameraAndSavePic 
-- @param self
-- @param #int userid
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 获取用户识别码，前5位是运营商id
-- @function [parent=#IPhoneTool] getIdCode 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getScreenWidth 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] updateLatestApkPackage 
-- @param self
-- @param #string apkPath
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] decodeChar 
-- @param self
-- @param #char src
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取手机android版本号
-- @function [parent=#IPhoneTool] getSDkVersion 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 弹出提示框<br>
-- param len<br>
-- return
-- @function [parent=#IPhoneTool] showMessage 
-- @param self
-- @param #char content
-- @param #char title
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] openNetSetting 
-- @param self
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] uploadHead 
-- @param self
-- @param #string url
-- @param #string filePath
-- @return IPhoneTool#IPhoneTool self (return value: IPhoneTool)
        
--------------------------------
-- 
-- @function [parent=#IPhoneTool] getInstance 
-- @param self
-- @return IPhoneTool#IPhoneTool ret (return value: IPhoneTool)
        
return nil
