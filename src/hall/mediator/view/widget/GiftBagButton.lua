local GiftBagButton = class("GiftBagButton",ccui.Button)
local Giftbag = require("xml.Giftbag")
local HallUICfg = require("hall.mediator.cfg.HallUICfg")
function GiftBagButton:ctor(gid)
	self:initGid(gid)
end
function GiftBagButton:initGid(gid)
	self:init("res/btn_tm_hd.png","res/btn_tm_hd.png","res/btn_tm_hd.png")
	self.gid = gid
	local data = Giftbag[gid]
	if not data then
		return false
	end
	if HallUICfg.getGiftBagData(5000+gid) then
		ToolCom.ButtonArmature(self, HallUICfg.getGiftBagData(5000+gid).zh, data.icon,false)
		self:addClickEventListener(handler(self,self.buttonListener))
	end
	
end
function GiftBagButton:buttonListener(sender)
	if not sender then
		return
	end
	playSoundEffect("music/button_click.mp3")
	print("进入背包界面"..self.gid)
	--GiftBagLayer
end
function GiftBagButton:getId()
	return self.gid
end
return GiftBagButton