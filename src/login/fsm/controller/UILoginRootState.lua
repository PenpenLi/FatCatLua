local UILoginRootState = class("UILoginRootState",require("packages.statebase.UIState"))

function UILoginRootState:onLoad(lastStateName,param)
	print("UILoginRootState  onLoad")
	UILoginRootState.super.onLoad(self,lastStateName,param)
	self:setVoice()
end
function UILoginRootState:setVoice()
	setSoundVolume(getSoundVolume())
	setMusicVolume(getMusicVolume())
	
end

function UILoginRootState:onStateEnter()
	wwlog("UILoginRootState onStateEnter")

end
function UILoginRootState:onStateExit()
	wwlog("UILoginRootState onStateExit")

end

return UILoginRootState