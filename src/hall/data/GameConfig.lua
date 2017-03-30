-------------------------------------------------------------------------
-- Desc: 游戏数据封装
-- Author: cruelogre
-- Date:    2017.03.30
-- Last:
-- Content:  封装所有游戏的数据，内存和本地
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local GameConfig = class("GameConfig")
local GameData = ww.WWGameData:getInstance()
function GameConfig:ctor()
	self.logTag = self.__cname..".lua"
	self:init()
end

function GameConfig:init()
	ToolCom.addSynthesize(self,"goldNum",0) --金币数量
	ToolCom.addSynthesize(self,"dryFilshNum",0) --鱼干数
	ToolCom.addSynthesize(self,"mintNum",0) --体力值
	ToolCom.addSynthesize(self,"maxStageStar",1) -- 最大关卡数对应的星球sid
	ToolCom.addSynthesize(self,"maxStage",1) --最大关卡数量
	ToolCom.addSynthesize(self,"maxStageAtk",0) --保存最大关卡数是否打过
	ToolCom.addSynthesize(self,"lastLoginDay",0) --最后一天首登时间
	ToolCom.addSynthesize(self,"loginCount",0) --登录天数
	ToolCom.addSynthesize(self,"signNum",0) --签到天数
	ToolCom.addSynthesize(self,"lastSignTime",0) --上次签到时间
	ToolCom.addSynthesize(self,"soundOn",true) --声音开关
	ToolCom.addSynthesize(self,"musicOn",true) --音乐开关
	ToolCom.addSynthesize(self,"curStarSid",1) --当前星球sid
	ToolCom.addSynthesize(self,"curCatSkinSid",1) --当前喵喵皮肤sid
	ToolCom.addSynthesize(self,"reGinerBeginTime",0) --恢复体力的开始时间
	ToolCom.addSynthesize(self,"reGinerEndTime",0) --恢复体力的结束时间
	ToolCom.addSynthesize(self,"guideIndex",0) --
	ToolCom.addSynthesize(self,"exp",0) --经验
	ToolCom.addSynthesize(self,"roleLevel",0) --等级
	self:loadAllData()
end
--初始化所有游戏数据
function GameConfig:loadAllData()

	self:addAllCatSkin()  --添加原始猫皮肤数据
	self:addAllWeapon()
	local first = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_ISFIRST)
	if first and string.len(first) > 3 then --已经初始化就大于3
		self:initNotFirstData()
	else
		self:initFirstData()
	end

--[[
	//save_maxStageStar = GETNUMTOSAVE(6);
	//GameConfig::setIntegerForKey(user, SAVEDATA_MAX_STAGE_STAR, save_maxStageStar);
	//save_maxStage = GETNUMTOSAVE(8);// GameConfig::numChangeTrueToSaveData(1);//点亮的关卡
	//GameConfig::setIntegerForKey(user, SAVEDATA_MAXSTATE, save_maxStage);
//	save_MintNum = GETNUMTOSAVE(GAME_MAX_MINTNUM);
//	GameConfig::setIntegerForKey(user, SAVEDATA_MINTNUM, save_MintNum);--]]
	self:loadFileData()
end
--初始化游戏第一次的数据
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
		GameData:setStringForKey( HALL_GAME_CONST.SAVEDATA_LAST_LOGIN_DAY,self.lastLoginDay) --最后一天首登时间
		GameData:setIntegerForKey( HALL_GAME_CONST.SAVEDATA_SIGN_NUM, self.signNum) --签到天数

		GameData:setStringForKey(HALL_GAME_CONST.SAVEDATA_SIGN_TIME, self.lastSignTime)--上次签到时间

		GameData:setIntegerForKey(HALL_GAME_CONST.SAVEDATA_REMOVE_AD,0)

		GameData:setStringForKey(HALL_GAME_CONST.SAVEDATA_ISFIRST, "first")

		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_GAME_ONLINE,false)
		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_MUSIC_ON, true)
		GameData:setBoolForKey(HALL_GAME_CONST.SAVEDATA_SOUND_ON,true)
		--测试 默认解锁前三把武器
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
		--读取最后一次首登时间
		self.lastLoginDay = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_LAST_LOGIN_DAY)
		--读取已签到天数
		self.signNum = GameData:getIntegerForKey(HALL_GAME_CONST.SAVEDATA_SIGN_NUM)
		--读取上次签到时间
		self.lastSignTime = GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_SIGN_TIME)

		self.soundOn = GameData:getBoolForKey(HALL_GAME_CONST.SAVEDATA_SOUND_ON, true)
		self.musicOn = GameData:getBoolForKey(HALL_GAME_CONST.SAVEDATA_MUSIC_ON, true)
		--读取已拥有的所有武器的sid和lv
		self:loadWeaponMap(GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_WEAPON_SID_LV))
		--读取穿戴中的所有武器的sid
		self:loadWearWeaponVec(GameData:getStringForKey(HALL_GAME_CONST.SAVEDATA_WEAR_WEAPON_SID))
		--读取已拥有的喵喵皮肤数据
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