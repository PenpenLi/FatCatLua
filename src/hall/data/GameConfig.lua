-------------------------------------------------------------------------
-- Desc: ��Ϸ���ݷ�װ
-- Author: cruelogre
-- Date:    2017.03.30
-- Last:
-- Content:  ��װ������Ϸ�����ݣ��ڴ�ͱ���
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local GameConfig = class("GameConfig")
local GameData = ww.WWGameData:getInstance()
function GameConfig:ctor()
	self.logTag = self.__cname..".lua"
	self:init()
end

function GameConfig:init()
	ToolCom.addSynthesize(self,"goldNum",0) --�������
	ToolCom.addSynthesize(self,"dryFilshNum",0) --�����
	ToolCom.addSynthesize(self,"mintNum",0) --����ֵ
	ToolCom.addSynthesize(self,"maxStageStar",1) -- ���ؿ�����Ӧ������sid
	ToolCom.addSynthesize(self,"maxStage",1) --���ؿ�����
	ToolCom.addSynthesize(self,"maxStageAtk",0) --�������ؿ����Ƿ���
	ToolCom.addSynthesize(self,"lastLoginDay",0) --���һ���׵�ʱ��
	ToolCom.addSynthesize(self,"loginCount",0) --��¼����
	ToolCom.addSynthesize(self,"signNum",0) --ǩ������
	ToolCom.addSynthesize(self,"lastSignTime",0) --�ϴ�ǩ��ʱ��
	ToolCom.addSynthesize(self,"soundOn",true) --��������
	ToolCom.addSynthesize(self,"musicOn",true) --���ֿ���
	ToolCom.addSynthesize(self,"curStarSid",1) --��ǰ����sid
	ToolCom.addSynthesize(self,"curCatSkinSid",1) --��ǰ����Ƥ��sid
	ToolCom.addSynthesize(self,"reGinerBeginTime",0) --�ָ������Ŀ�ʼʱ��
	ToolCom.addSynthesize(self,"reGinerEndTime",0) --�ָ������Ľ���ʱ��
	ToolCom.addSynthesize(self,"guideIndex",0) --
	ToolCom.addSynthesize(self,"exp",0) --����
	ToolCom.addSynthesize(self,"roleLevel",0) --�ȼ�
	self:loadAllData()
end
--��ʼ��������Ϸ����
function GameConfig:loadAllData()

	self:addAllCatSkin()  --���ԭʼèƤ������
	self:addAllWeapon()
	local first = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_ISFIRST)
	if first and string.len(first) > 3 then --�Ѿ���ʼ���ʹ���3
		self:initNotFirstData()
	else
		self:initFirstData()
	end

--[[
	//save_maxStageStar = GETNUMTOSAVE(6);
	//GameConfig::setIntegerForKey(user, SAVEDATA_MAX_STAGE_STAR, save_maxStageStar);
	//save_maxStage = GETNUMTOSAVE(8);// GameConfig::numChangeTrueToSaveData(1);//�����Ĺؿ�
	//GameConfig::setIntegerForKey(user, SAVEDATA_MAXSTATE, save_maxStage);
//	save_MintNum = GETNUMTOSAVE(GAME_MAX_MINTNUM);
//	GameConfig::setIntegerForKey(user, SAVEDATA_MINTNUM, save_MintNum);--]]
	self:loadFileData()
end
--��ʼ����Ϸ��һ�ε�����
function GameConfig:initFirstData()
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_GOLDNUM, self.goldNum)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_MINTNUM, self.mintNum)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_GEMNUM, self.dryFilshNum)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_CURRENTLEVEL_EXP, self.exp)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_CURRENTLEVEL, roleLevel)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAX_STAGE_STAR, self.maxStageStar)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAXSTATE, self.maxStage)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAXSTATE_ATK, self.maxStageAtk)
		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_GAMEGUIDEINDEX, self.guideIndex)
		GameData:setStringForKey( HALL_GAME_CONST.SAVEDATA_LAST_LOGIN_DAY,self.lastLoginDay) --���һ���׵�ʱ��
		GameData:setIntegerForKey( HALL_GAME_CONST.SAVEDATA_SIGN_NUM, self.signNum) --ǩ������

		GameData:setStringForKey(HALL_GAME_CONST.SAVEDATA_SIGN_TIME, self.lastSignTime)--�ϴ�ǩ��ʱ��

		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_REMOVE_AD,0)

		GameData:setStringForKey(HALL_GAME_CONST.SAVEDATA_ISFIRST, "first")

		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_GAME_ONLINE,false)
		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_MUSIC_ON, true)
		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_SOUND_ON,true)
		--���� Ĭ�Ͻ���ǰ��������
		self:addWeaponBySid(1)
		--self:addWeaponBySid(2)
		--self:addWeaponBySid(3)
		self:saveWeaponData()
		self:saveReGinerTime(0, 0)
end
function GameConfig:initNotFirstData()
	--save_highscore = GameData::getIntegerForKey(user,SAVEDATA_HIGHSCORE)

	--	save_scoreMapInfo = GameData::getStringForKey(user, SAVEDATA_HIGHSCORE)
		local save_leveStarInfo = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_HIGHLEVEL)

		self.goldNum = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_GOLDNUM)
		self.mintNum = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_MINTNUM)
		self.dryFilshNum = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_GEMNUM)
		self.exp = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_CURRENTLEVEL_EXP)
		self.roleLevel = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_CURRENTLEVEL)	
		self.levelStars = self:getLevelStarMap()
		self.maxStage = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAXSTATE)
		self.maxStageStar = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAX_STAGE_STAR)
		self.maxStageAtk = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_MAXSTATE_ATK)
		self.guideIndex = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_GAMEGUIDEINDEX)
		--��ȡ���һ���׵�ʱ��
		self.lastLoginDay = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_LAST_LOGIN_DAY)
		--��ȡ��ǩ������
		self.signNum = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_SIGN_NUM)
		--��ȡ�ϴ�ǩ��ʱ��
		self.lastSignTime = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_SIGN_TIME)

		self.soundOn = GameData:getBoolForKey(HALL_GAME_CONST.SAVEDATA_SOUND_ON, true)
		self.musicOn = GameData:getBoolForKey(HALL_GAME_CONST.SAVEDATA_MUSIC_ON, true)
		--��ȡ��ӵ�е�����������sid��lv
		self:loadWeaponMap(GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_WEAPON_SID_LV))
		--��ȡ�����е�����������sid
		self:loadWearWeaponVec(GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_WEAR_WEAPON_SID))
		--��ȡ��ӵ�е�����Ƥ������
		self:loadCatSkinMap(GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_CAT_SKIN))
		self:loadReGinerTime()
end
function GameConfig:loadFileData()

end
function GameConfig:addAllCatSkin()

end
function GameConfig:addAllWeapon()

end
function GameConfig:addWeaponBySid(sid)

end
function GameConfig:loadWearWeaponVec(weaponStr)

end
function GameConfig:saveWeaponData()

end
function GameConfig:saveReGinerTime(beginTime,endTime)

end
function GameConfig:loadReGinerTime()

end
function GameConfig:getLevelStarMap()

end
function GameConfig:loadCatSkinMap(skinStr)

end
cc.exports.GameConfig = cc.exports.GameConfig or GameConfig:create()
return cc.exports.GameConfig