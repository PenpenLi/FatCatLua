-------------------------------------------------------------------------
-- Desc:   
-- Author: cruelogre
-- Date:    2016.12.15
-- Last:
-- Content:  登陆场景
-- Copyright (c) Personal Entertainment All right reserved.
--------------------------------------------------------------------------
local LoginScene = class("LoginScene",require("app.views.uibase.WWSceneBase"))
function LoginScene:ctor(param)
	LoginScene.super.ctor(self)
	self.param = param
	self.logTag = self.__cname..".lua"
end

function LoginScene:onEnter()
	LoginScene.super.onEnter(self)
	wwlog(self.logTag,"登陆场景进入onEnter")
	--场景状态机初始化
	soundEffectControl()
	FSRegistryManager:runWithFSM(FSMConfig.FSM_LOGIN):onEntry({parentNode = self, zorder = 2,data = self.param})
	
end
return LoginScene