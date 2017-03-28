local SettingLayer = class("SettingLayer",require("app.views.uibase.PopWindowBase"))
local SettingCfg = import("..cfg.SettingCfg")
local settingLayerNode = require("cbcsb.setingLayer")
local WWGameData = ww.WWGameData:getInstance()
function SettingLayer:ctor(param)
	SettingLayer.super.ctor(self)
	self:init()
end
function SettingLayer:init()
	local settingNode = settingLayerNode:create()
	local node = settingNode.root
	FixUIUtils.setRootNodewithFIXED(node)
	--FixUIUtils.stretchUI(layerNode)
	self:addChild(node)
	self.setnode = node
	self:initUIListener()
	self:setDisCallback(function ( ... )
		-- body
		FSRegistryManager:currentFSM():trigger("back")
	end)
	
end
function SettingLayer:initUIListener()
	self.setnode:getChildByName("b_rate"):addClickEventListener(handler(self,self.btnListener))
	self.setnode:getChildByName("sound_bt"):addClickEventListener(handler(self,self.btnListener))
	self.setnode:getChildByName("music_bt"):addClickEventListener(handler(self,self.btnListener))
	self.setnode:getChildByName("Button_3"):addClickEventListener(handler(self,self.btnListener))
	
	self.setnode:getChildByName("sound_bt"):loadTextureNormal(getSoundVolume()>0 and "res/setingLayer/soundo.png" or "res/setingLayer/soundoff.png")
	self.setnode:getChildByName("music_bt"):loadTextureNormal(getMusicVolume()>0 and "res/setingLayer/music.png" or "res/setingLayer/musicoff.png")
end
function SettingLayer:onEnter()
	
end
function SettingLayer:btnListener(sender)
	if not sender then
		return
	end
	playSoundEffect("music/button_click.mp3")
	if sender:getName()=="b_rate" then
		print("to be continue...")
	elseif sender:getName()=="sound_bt" then
		setSoundVolume(getSoundVolume()>0 and 0 or 100)
		sender:loadTextureNormal(getSoundVolume()>0 and "res/setingLayer/sound.png" or "res/setingLayer/soundoff.png")
	elseif sender:getName()=="music_bt" then	
		setMusicVolume(getMusicVolume()>0 and 0 or 100)
		sender:loadTextureNormal(getMusicVolume()>0 and "res/setingLayer/music.png" or "res/setingLayer/musicoff.png")
	elseif sender:getName()=="Button_3" then	
		self:close()
	end
	
	
end

return SettingLayer