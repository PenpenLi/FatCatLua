local LoginLayer = class("LoginLayer",require("app.views.uibase.PopWindowBase"))
local LoginLayer_Content = require("res.cbcsb.LoginLayer")
local curFsm = FSRegistryManager:runWithFSM(FSMConfig.FSM_LOGIN)
function LoginLayer:ctor()
	LoginLayer.super.ctor(self)
	
	self:setOpacity(0)
end
----------------------------------------------------
--´¥ÃþÊÂ¼þ
----------------------------------------------------
function LoginLayer:onTouchBegin(touch,event)
    if event:getEventCode() == cc.EventCode.BEGAN then
        return true
    elseif event:getEventCode() == cc.EventCode.ENDED then
        --self:close()
    end
end

function LoginLayer:onEnter()
	local sp = display.newSprite("gaameLog.png")
	sp:setOpacity(0)
	sp:setPosition(display.center)
	self:addChild(sp)
	
	local seqAction = transition.sequence({
	cc.FadeIn:create(0.5),
	cc.CallFunc:create(handler(self,self.splashOver)),
	cc.DelayTime:create(0.2),
	cc.FadeOut:create(0.2),
	cc.RemoveSelf:create()})
	sp:runAction(seqAction)
end
function LoginLayer:splashOver()
	local layerContent = LoginLayer_Content:create()
	
	local layerNode = layerContent.root
	self:addChild(layerNode)
	FixUIUtils.setRootNodewithFIXED(layerNode)
	local playBtn = layerNode:getChildByName("Button_play")
	playBtn:addClickEventListener(handler(self,self.buttonListener))
	
	layerNode:getChildByName("Button_set"):addClickEventListener(handler(self,self.buttonListener))
	
	local animation = layerContent.animation
	animation:play("animation0",true)
	playBtn:runAction(animation)
end

function LoginLayer:buttonListener(sender)
	if not sender then
		return
	end
	playSoundEffect("music/button_click.mp3")
	if sender:getName()=="Button_play" then
		print("start game")
		WWFacade:dispatchCustomEvent(LOGIN_SCENE_EVENTS.JUMP_TO_HALL)
	elseif sender:getName()=="Button_set" then
		print("enter setting game")
		curFsm:trigger("setting")
		
	end
end
return LoginLayer