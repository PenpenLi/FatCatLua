-------------------------------------------------------------------------
-- Desc:    地方棋牌
-- Author:
-- Date:    2016.08.15
-- Last:    
-- Content:  大厅状态机对应周期函数实现
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local UIHallSceneState = class("UIHallSceneState",
	require("packages.statebase.UIState"),
	require("packages.mvc.Controller"))


local gamedata = ww.WWGameData:getInstance()

function UIHallSceneState:ctor()
	
	self.super.ctor(self)
	
	wwlog(self.logTag,"UIHallSceneState ctor")
	
	
end



function UIHallSceneState:onLoad(lastStateName,param)
		--显示大厅内容
--[[	local reslist = {
		"hall/plist/halltop.plist",
		"hall/plist/hallbottom.plist",
		"hall/plist/hallcontent.plist",
		"hall/animation/hall_plist1.plist",
	}
	for _,v in pairs(reslist) do
		cc.SpriteFrameCache:getInstance():addSpriteFrames(v)
	end--]]
	--cc.SpriteFrameCache:getInstance():addSpriteFrames("hall/plist/halltop.plist")
	--cc.SpriteFrameCache:getInstance():addSpriteFrames("hall/plist/hallbottom.plist")
	--cc.SpriteFrameCache:getInstance():addSpriteFrames("hall/plist/hallcontent.plist")
	
	UIHallSceneState.super.onLoad(self,lastStateName,param)
	self.param = param

	
	
end
function UIHallSceneState:onStateEnter()
	UIHallSceneState.super.onStateEnter(self)
	--self:getMainSceneMediator():showView()

	
	wwlog(self.logTag,cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
end


function UIHallSceneState:onStateExit()
	UIHallSceneState.super.onStateExit(self)
	


	-- print(cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
end
function UIHallSceneState:onStateResume()

	UIHallSceneState.super.onStateResume(self)

end

function UIHallSceneState:onStatePause()
	UIHallSceneState.super.onStatePause(self)
	
end


return UIHallSceneState