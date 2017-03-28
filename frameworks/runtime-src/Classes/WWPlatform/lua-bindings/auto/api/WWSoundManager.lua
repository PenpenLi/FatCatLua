
--------------------------------
-- @module WWSoundManager
-- @parent_module ww

--------------------------------
-- 停止所有音效
-- @function [parent=#WWSoundManager] stopAllEffects 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 预加载所有资源
-- @function [parent=#WWSoundManager] preloadResource 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 获得音效音量
-- @function [parent=#WWSoundManager] getEffectsVolume 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @overload self, char         
-- @overload self, unsigned int         
-- @function [parent=#WWSoundManager] stopEffect
-- @param self
-- @param #unsigned int nSoundId
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)

--------------------------------
-- 设置背景音乐音量
-- @function [parent=#WWSoundManager] setBackgroundMusicVolume 
-- @param self
-- @param #float volume
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 是否会播放背景音乐
-- @function [parent=#WWSoundManager] willPlayBackgroundMusic 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 暂停背景音乐
-- @function [parent=#WWSoundManager] pauseBackgroundMusic 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 停止背景音乐
-- @function [parent=#WWSoundManager] stopBackgroundMusic 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 播放音效<br>
-- param pszFilePath 文件路径<br>
-- param  isLoop  是否循环<br>
-- param delayTime 播放延时
-- @function [parent=#WWSoundManager] playSoundEffect 
-- @param self
-- @param #char pszFilePath
-- @param #bool isloop
-- @param #float delayTime
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 是否整播放背景音乐
-- @function [parent=#WWSoundManager] isBackgroundMusicPlaying 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 初始化
-- @function [parent=#WWSoundManager] init 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 计时器调用 音效和音乐的循环计时器
-- @function [parent=#WWSoundManager] SoundEffectControl 
-- @param self
-- @param #float delayTime
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 暂停所有音效
-- @function [parent=#WWSoundManager] pauseAllEffects 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 播放背景音乐<br>
-- param pszFilePath 文件路径  <br>
-- param  isLoop  是否循环
-- @function [parent=#WWSoundManager] playBackgroundMusic 
-- @param self
-- @param #char pszFilePath
-- @param #bool isLoop
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 开始所有音效
-- @function [parent=#WWSoundManager] resumeAllEffects 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 添加预加载的音效文件<br>
-- param filepath 文件路径
-- @function [parent=#WWSoundManager] addPreloadEffResource 
-- @param self
-- @param #char filepath
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 释放预加载的资源
-- @function [parent=#WWSoundManager] unloadResource 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 获得背景音乐音量
-- @function [parent=#WWSoundManager] getBackgroundMusicVolume 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 添加预加载的音乐文件<br>
-- param filepath 文件路径
-- @function [parent=#WWSoundManager] addPreloadMusicResource 
-- @param self
-- @param #char filepath
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 回放背景音乐
-- @function [parent=#WWSoundManager] rewindBackgroundMusic 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 暂停音效<br>
-- nSoundId 播放时获得的id号
-- @function [parent=#WWSoundManager] pauseEffect 
-- @param self
-- @param #unsigned int nSoundId
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 重新开始背景音乐
-- @function [parent=#WWSoundManager] resumeBackgroundMusic 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 设置音效音量
-- @function [parent=#WWSoundManager] setEffectsVolume 
-- @param self
-- @param #float volume
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 开始所有音效<br>
-- nSoundId 播放时获得的id号
-- @function [parent=#WWSoundManager] resumeEffect 
-- @param self
-- @param #unsigned int nSoundId
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 释放  shared Engine object
-- @function [parent=#WWSoundManager] end 
-- @param self
-- @return WWSoundManager#WWSoundManager self (return value: WWSoundManager)
        
--------------------------------
-- 
-- @function [parent=#WWSoundManager] getInstance 
-- @param self
-- @return WWSoundManager#WWSoundManager ret (return value: WWSoundManager)
        
return nil
