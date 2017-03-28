
/*
* WWSoundManager.cpp
*声音管理
*  Created on: 2014年5月16日
*      Author: YYH
*/
#include "WWSoundManager.h"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "../Tools/WWMapForValueFinder.h"
#include "../VariateSystem/WWConfigManager.h"
#include "../VariateSystem/parser/WWSoundParser.h"

USING_NS_CC;

void WWSoundManager::SoundEffectControl(float delayTime)
{
	float delay = 0.0;
	map<unsigned int, MusicEffectInfo>::iterator iter;
	for (iter = soundCt_map.begin(); iter != soundCt_map.end(); iter++)
	{
		iter->second.currentTime += delayTime;
		if (iter->second.currentTime>=iter->second.delay&&!iter->second.hasPlayed) 
		{
			iter->second.hasPlayed = true;
			deleteCts.push_back(iter->first);
			doPlayEffect(iter->second.filepath.c_str(), iter->first, iter->second.isLoop);
		}

	}
	for(auto deleteCt : deleteCts)
	{
		soundCt_map.erase(deleteCt);
	}
	
	deleteCts.clear();
	
}
void WWSoundManager::init()
{
   auto moduleConfig = WWConfigManager::getInstance()->getModuleConfig(SYSTEM_SOUND);
   wwSoundItems.clear();
   for (auto item : moduleConfig.items) 
   {
	   
	   WWSoundItem* ws = (struct WWSoundItem*)item;
	   if (ws)
	   {
		   
		   wwSoundItems.emplace(make_pair(ws->platformid, *item));
	   }
   }

}
void WWSoundManager::end() 
{
	CocosDenshion::SimpleAudioEngine::getInstance()->end();
}



void WWSoundManager::playBackgroundMusic(const char* pszFilePath, bool bLoop) {
	std::string musicPath = doPlatformSuffix(pszFilePath);
	
	std::string res = FileUtils::getInstance()->fullPathForFilename(musicPath);
	if (res.length() < 0)return;
	doPlayMusic(musicPath.c_str(), bLoop);

}

void WWSoundManager::playSoundEffect(const char* pszFilePath, bool isloop, float delayTime)
{
	
	std::string musicPath = doPlatformSuffix(pszFilePath);
	std::string res = FileUtils::getInstance()->fullPathForFilename(musicPath);
	
	if (res.length() < 0)return;

	

	
	unsigned int nativeId = _HashStr(musicPath.c_str());

	map<unsigned int, MusicEffectInfo>::iterator p = soundCt_map.find(nativeId);
	if (p != soundCt_map.end()) //已经有相同的音效
	{
		 //这个音效的延迟和当前时间的比较 循环的时间间隔比播放延迟大则播放，则否视为时间太短
		
		if (p->second.delay >= p->second.currentTime) 
		{
			//doPlayEffect(p->second.filepath.c_str(), nativeId, isloop);
			
			if (p->second.isLoop!=isloop) 
			{
				
				p->second.externNativeId += 1;

				MusicEffectInfo newInfo(p->second);
				newInfo.externNativeId = 0;
				newInfo.delay = delayTime;
				newInfo.currentTime = 0;

				newInfo.isLoop = isloop;
				soundCt_map.insert(pair<unsigned int, MusicEffectInfo>(nativeId+p->second.externNativeId, newInfo));

			} 
			else
			{
				p->second.currentTime = 0;
				p->second.delay = delayTime;
				p->second.hasPlayed = false;
				p->second.isLoop = isloop;
			}
		}
	} 
	else
	{
		MusicEffectInfo info;
		info.delay = delayTime;
		info.filepath = musicPath;
		info.currentTime = 0;
		info.isLoop = isloop;
		soundCt_map.insert(pair<unsigned int, MusicEffectInfo>(nativeId, info));
		//doPlayEffect(musicPath.c_str(), nativeId, isloop);
	}
	
}

void WWSoundManager::doPlayMusic(const char* musicpath, bool isloop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(musicpath, isloop);

}

void WWSoundManager::doPlayEffect(const char* effectpath, int nativeId, bool isloop)
{

	int soundID = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(effectpath, isloop);
	if (isloop)
	{
		constantEffectIDs.insert(make_pair(_HashStr(effectpath), soundID));
	}
	
}

void WWSoundManager::stopBackgroundMusic(bool bReleaseData /* = false */)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(bReleaseData);

}


void WWSoundManager::pauseBackgroundMusic() {
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void WWSoundManager::resumeBackgroundMusic() {
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void WWSoundManager::rewindBackgroundMusic() {
	CocosDenshion::SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
}
bool WWSoundManager::willPlayBackgroundMusic() {
	return CocosDenshion::SimpleAudioEngine::getInstance()->willPlayBackgroundMusic();
}

bool WWSoundManager::isBackgroundMusicPlaying() {
	return CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
}

float WWSoundManager::getBackgroundMusicVolume() {
	return CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
}

void WWSoundManager::setBackgroundMusicVolume(float volume) {
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
}

float WWSoundManager::getEffectsVolume() {
	return CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume();

}

void WWSoundManager::setEffectsVolume(float volume) {
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);

}


void WWSoundManager::pauseEffect(unsigned int nSoundId) {
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseEffect(nSoundId);

}

void WWSoundManager::pauseAllEffects() {
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();

}

void WWSoundManager::resumeEffect(unsigned int nSoundId) {
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeEffect(nSoundId);

}

void WWSoundManager::resumeAllEffects() {
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();

}

void WWSoundManager::stopEffect(unsigned int nSoundId) 
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(nSoundId);
	std::map<int, int>::iterator it = constantEffectIDs.end();
	it = std::find_if(constantEffectIDs.begin(), constantEffectIDs.end(), WWMapForValueFinderInt(nSoundId));

	if (it != constantEffectIDs.end())
	{
		//CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(it->second);
		constantEffectIDs.erase(it);
	}

}
void WWSoundManager::stopEffect(const char* pszFilePath)
{

	std::string musicPath = doPlatformSuffix(pszFilePath);


	std::string res = FileUtils::getInstance()->fullPathForFilename(musicPath);
		
	if (res.length() < 0)return;

	


	unsigned int sid = _HashStr(musicPath.c_str());
	if (constantEffectIDs.find(sid) != constantEffectIDs.end())
	{

		CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(constantEffectIDs.at(sid));
		constantEffectIDs.erase(sid);
	}
	
}

std::string WWSoundManager::doPlatformSuffix(const std::string& inFile)
{
	std::string musicPath = inFile;
	
	std::string tempPath;

	if (wwSoundItems.find(CC_TARGET_PLATFORM) != wwSoundItems.end())
	{
		WWSystemItem wi = wwSoundItems.at(CC_TARGET_PLATFORM);
		for (auto suffix : wi.values)
		{
			size_t pos = inFile.rfind(".");
			if (pos == std::string::npos)
			{
				pos = inFile.length() - 1;
				suffix.insert(0, ".");
			}

			tempPath = inFile.substr(0, pos + 1) + suffix;

			if (FileUtils::getInstance()->isFileExist(tempPath))
			{
				musicPath = tempPath;
				break;
			}

		}
			
	}
	
	return musicPath;
}


void WWSoundManager::stopAllEffects() 
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
	soundCt_map.clear();
	deleteCts.clear();

}

void WWSoundManager::preloadResource()
{
	std::thread effThread([&]
	{
		for (auto& loadingpath : preloadEffFiles)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(loadingpath.c_str());
		}
	});
	effThread.detach();

	std::thread bgThread([&]
	{
		for (auto& loadingpath : preloadBgFiles)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(loadingpath.c_str());
		}
	});
	bgThread.detach();

}
void WWSoundManager::unloadResource()
{
	for (auto& loadingpath : preloadEffFiles)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect(loadingpath.c_str());
	}
	preloadEffFiles.clear();
}
void WWSoundManager::addPreloadEffResource(const char* filepath)
{
	if (std::find(preloadEffFiles.begin(), preloadEffFiles.end(), filepath) != preloadEffFiles.end())
	{
		preloadEffFiles.push_back(filepath);
	}
}
void WWSoundManager::addPreloadMusicResource(const char* filepath)
{
	if (std::find(preloadBgFiles.begin(), preloadBgFiles.end(), filepath) != preloadBgFiles.end())
	{
		preloadBgFiles.push_back(filepath);
	}
	
}


