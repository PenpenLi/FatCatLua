local LoginSceneMediator = class("LoginSceneMediator",require("packages.mvc.Mediator"))

local LoginScene = import(".LoginScene")

local targetPlatform = cc.Application:getInstance():getTargetPlatform()
--require("login.fsm.LoginFSRegistry")
function LoginSceneMediator:init()
	cclog("LoginSceneMediator init...")
		--test just show button view
	
	self.loginFSM = FSRegistryManager:runWithFSM(FSMConfig.FSM_LOGIN)
end
function LoginSceneMediator:showBG()
	wwlog("显示登陆背景")
	self.scene = LoginScene:create()
	
	--playBackGroundMusic("sound/backMusic/hallBackGroundMusic",true)

	
	display.runScene(self.scene)
	
end
function LoginSceneMediator:delayGo()

	WWFacade:dispatchCustomEvent(LOGIN_SCENE_EVENTS.JUMP_TO_HALL)
end


return LoginSceneMediator