#include "WWAnimatePacker.h"

WWAnimatePacker::WWAnimatePacker()
{

}


void WWAnimatePacker::loadAnimations(const char *path)
{
	
	std::string tempStr = path;
	size_t pos = tempStr.rfind(".");
	if (pos != std::string::npos)
	{
		tempStr = tempStr.substr(0, pos);

	}

	
	//CCLog("hiddd1");

	tinyxml2::XMLDocument * pdocx = new tinyxml2::XMLDocument();

	unsigned char* mybuf = NULL;
	ssize_t bufsize = 0;
	//mybuf = FileUtils::sharedFileUtils()->getFileData(path, "r", &bufsize);
	//
	//if (!mybuf){
	//	return;
	//}
	//pdocx->Parse((const char*)mybuf, bufsize);
	
	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(path);
	//tinyxml2::XMLDocument *pdocx = new tinyxml2::XMLDocument();
	tinyxml2::XMLError error = pdocx->LoadFile(fullPath.c_str());
	if (error != tinyxml2::XMLError::XML_NO_ERROR)return;
	tinyxml2::XMLElement* pSurface;
	tinyxml2::XMLElement *rootEle = pdocx->RootElement();
	tinyxml2::XMLElement *plist = rootEle->FirstChildElement();
	plist = plist->FirstChildElement();
	
	while (plist)
	{

		m_pPlists.push_back(plist->GetText());
		plist = plist->NextSiblingElement();
	}
	
	//CCLog("hiddd3");
	tinyxml2::XMLElement* pAnimateions = rootEle->FirstChildElement("animations");
	tinyxml2::XMLElement* animate = pAnimateions->FirstChildElement("animation");
	while (animate)
	{
		WWLTAnimate pAnimate;
		tinyxml2::XMLElement * animateInfo = animate->FirstChildElement("name");
		pAnimate.name = animateInfo->GetText();
		animateInfo = animate->FirstChildElement("delay");
		pAnimate.delay = atof(animateInfo->GetText());
		tinyxml2::XMLElement *pFrame = animate->FirstChildElement("spriteFrame");
		while (pFrame)
		{
			pAnimate.spriteFrames.push_back(pFrame->GetText());
			pFrame = pFrame->NextSiblingElement();
		}
		animate = animate->NextSiblingElement();
		m_pAnimates.push_back(pAnimate);
	}
	
	//����plist�ļ���cache��
	for (int i = 0; i<m_pPlists.size(); i++){
		
		string plistPath = FileUtils::sharedFileUtils()->fullPathFromRelativeFile(m_pPlists[i].c_str(), path);
	
		
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistPath);
		
		
	}
	//���ض�����cache��
	Vector<SpriteFrame*>animFramesArray;
	
	for (int i = 0; i<m_pAnimates.size(); i++){
		WWLTAnimate tAnimate = m_pAnimates[i];
		vector<string> tspriteFrames = tAnimate.spriteFrames;
		for (int j = 0; j<tspriteFrames.size(); j++){
			SpriteFrame* frame1 = SpriteFrameCache::getInstance()->spriteFrameByName(tspriteFrames[j].c_str());
			animFramesArray.pushBack(frame1);
		}
		Animation* animation = Animation::createWithSpriteFrames(animFramesArray, tAnimate.delay);
		AnimationCache::sharedAnimationCache()->addAnimation(animation, tAnimate.name.c_str());
		animFramesArray.clear();

	}
	
	m_pAnimates.clear();
	m_pPlists.clear();

}

cocos2d::Animate* WWAnimatePacker::getAnimate(const char *name, const char* animname/* =NULL */)
{
	
	std::string animFile = StringUtils::format("%s", name);
	
	size_t pos = animFile.rfind(".xml");
	if (pos == std::string::npos)
	{
		animFile = StringUtils::format("%s.xml", name);

	}
	
	if (!FileUtils::getInstance()->isFileExist(animFile)) return NULL;
	
	loadAnimations(animFile.c_str());
	
	animFile = animFile.substr(animFile.find_last_of("/") + 1);
	if (animFile.find_last_of(".") != string::npos)
	{
		animFile = animFile.substr(0, animFile.find_last_of("."));
	}
	if (animname)animFile = animname;
	Animation* animation = AnimationCache::sharedAnimationCache()->animationByName(animFile);
	if (animation) {
		return Animate::create(animation);
	}
	return NULL;
}

