local UISettingState = class("UISettingState",require("packages.statebase.UIState"))



function UISettingState:onLoad(lastStateName,param)
	UISettingState.super.onLoad(self,lastStateName,param)
	wwlog(self.logTag,"设置状态机 onLoad")
	
end


function UISettingState:onStateEnter()
	cclog("UISettingState onStateEnter")
	--print(cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
	
end
function UISettingState:onStateExit()
	cclog("UISettingState onStateExit")
	
	--print(cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
end

return UISettingState