#pragma once

/*! @file
********************************************************************************
<PRE>
模块名       :  声音模块管理器
文件名       :  WWSoundManager.h
文件实现功能 :
作者         :  cruelogre  546761316@qq.com
版本         :  1.0
Copyright (c)  WaWaGame Technologies
--------------------------------------------------------------------------------
1、WWSoundManager 管理所有音乐和音效播放
2、WWSoundManager有预加载音乐和音效，都是多线程加载
3、播放音效是是通过队列来实现，游戏主循环需要调用WWSoundManager的循环API
--------------------------------------------------------------------------------
备注         : <其它说明>
现在为春节前临时版本
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2016/7/11   1.0     cruelogre		      新建
</PRE>
*******************************************************************************/

#include "../WWMacros.h"
#include <map>
#include <vector>
#include <ctype.h>
#include "../VariateSystem/WWConfigData.h"

using namespace std;



struct MusicEffectInfo
{
	float delay;
	float currentTime;
	string filepath;
	int externNativeId;
	bool hasPlayed;
	bool isLoop;
	MusicEffectInfo()
	{
		delay = 0;
		currentTime = 0;
		hasPlayed = false;
		isLoop = false;
		externNativeId = 0;
	}
};

class WWSoundManager
{
public:

	SINGLE_INSTANCE_FUNC(WWSoundManager);
	/**
	* 计时器调用 音效和音乐的循环计时器
	*/
	void SoundEffectControl(float delayTime);
	/**
	*	初始化
	*
	*/
	void init();
	/**
	* 释放  shared Engine object
	*/
	static void end();


	/**
	* 停止背景音乐
	*/
	void stopBackgroundMusic(bool bReleaseData = false);

	/**
	* 暂停背景音乐
	*/
	void pauseBackgroundMusic();
	/**
	* 重新开始背景音乐
	*/
	void resumeBackgroundMusic();
	/**
	* 回放背景音乐
	*/
	void rewindBackgroundMusic();
	/**
	* 是否会播放背景音乐
	*/
	bool willPlayBackgroundMusic();
	/**
	* 是否整播放背景音乐
	*/
	bool isBackgroundMusicPlaying();

	/**
	* 获得背景音乐音量
	*/
	float getBackgroundMusicVolume();
	/**
	* 设置背景音乐音量
	*/
	void setBackgroundMusicVolume(float volume);
	/**
	* 获得音效音量
	*/
	float getEffectsVolume();
	/**
	* 设置音效音量
	*/
	void setEffectsVolume(float volume);


	/**
	* 暂停音效
	* nSoundId 播放时获得的id号
	*/
	void pauseEffect(unsigned int nSoundId);
	/**
	* 暂停所有音效
	*/
	void pauseAllEffects();
	/**
	* 开始所有音效
	* nSoundId 播放时获得的id号
	*/
	void resumeEffect(unsigned int nSoundId);
	/**
	* 开始所有音效
	*/
	void resumeAllEffects();
	/**
	* 停止音效
	* nSoundId 播放时获得的id号
	*/
	void stopEffect(unsigned int nSoundId);
	/**
	* 停止音效（循环播放的）
	* pszFilePath 音效的路径
	*/
	void stopEffect(const char* pszFilePath);
	/**
	* 停止所有音效
	*/
	void stopAllEffects();



	/**
	* 播放背景音乐
	* @param pszFilePath 文件路径  
	* @param  isLoop  是否循环
	*/
	void playBackgroundMusic(const char* pszFilePath,bool isLoop = false);
	/**
	* 播放音效
	* @param pszFilePath 文件路径
	* @param  isLoop  是否循环
	* @param delayTime 播放延时
	*/
	void playSoundEffect(const char* pszFilePath, bool isloop = false, float delayTime = 0.0f);
	/**
	* 预加载所有资源
	*/
	void preloadResource();
	/**
	* 释放预加载的资源
	*/
	void unloadResource();
	/**
	* 添加预加载的音效文件
	* @param filepath 文件路径
	*/
	void addPreloadEffResource(const char* filepath);
	/**
	* 添加预加载的音乐文件
	* @param filepath 文件路径
	*/
	void addPreloadMusicResource(const char* filepath);
private:
	/**
	* 播放音乐
	* @param musicpath 音乐文件路径
	* @param isloop 是否重复播放
	*/
	void doPlayMusic(const char* musicpath, bool isloop = false);
	/**
	* 播放特效
	* @param effectpath 音效文件路径
	* @param nativeId 唯一标识符
	* @param isloop 是否重复播放
	*/
	void doPlayEffect(const char* effectpath, int nativeId = 0, bool isloop = false);

	std::string doPlatformSuffix(const std::string& inFile);
protected:
	map<unsigned int, MusicEffectInfo> soundCt_map;
	std::vector<unsigned int> deleteCts;

	std::map<int, int> constantEffectIDs; //循环播放的特效ID



	unsigned int _HashStr(const char *key)
	{
		unsigned int len = strlen(key);
		const char *end = key + len;
		unsigned int hash;

		for (hash = 0; key < end; key++)
		{
			hash *= 16777619;
			hash ^= (unsigned int)(unsigned char)toupper(*key);
		}
		return (hash);
	}

	private:
		std::vector<std::string> preloadEffFiles; //预加载的音效资源
		std::vector<std::string> preloadBgFiles; //预加载的背景资源

		std::map<int, WWSystemItem> wwSoundItems;
};

