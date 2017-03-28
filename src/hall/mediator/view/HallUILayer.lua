local HallUILayer = class("HallUILayer",require("app.views.uibase.PopWindowBase"))
local HallUILayerContent = require("cbcsb.GameMainScene")
local Giftbag = require("xml.Giftbag")
local GiftBagButton = import(".widget.GiftBagButton")
function HallUILayer:ctor(param)
	HallUILayer.super.ctor(self)
	self:setOpacity(0)
	self:init()
end

function HallUILayer:init()
	print("HallUILayer init")
	self.blackhole = ccs.Armature:create("heidong_Animation")
	self:addChild(self.blackhole)
	self.blackhole:getAnimation():play("Animation1")
	self.blackhole:setVisible(false)
	
	local d11 = cc.DelayTime:create(1.5)
	local d12 = cc.CallFunc:create(function ()
		local partical = cc.ParticleSystemQuad:create("bjxx.plist")
		self:addChild(partical)
	end)
	self:runAction(transition.sequence({d11, d12}))
	
	
end

function HallUILayer:blackHoleAnimation()
	wwlog(self.logTag,"黑洞动画")
	self.blackhole:setVisible(true)
	local randomPos = cc.p(100+520*math.random(),100+1080*math.random())
	self.blackhole:setPosition(randomPos)
	
	local randomScale = 0.5 + math.random()
	self.blackhole:setScale(randomScale)
	self.blackhole:setOpacity(0)
	local df = 1.0 + 3.0 * math.random()
	
	local fi = cc.FadeTo:create(df, 255)
	local fo = cc.FadeTo:create(df,0)
	local d = cc.DelayTime:create(30.0 * math.random())
	local c = cc.CallFunc:create(handler(self,self.blackHoleAnimation))
	local seq = transition.sequence({fi,fo,d,c})
	self.blackhole:runAction(seq)
end

function HallUILayer:meteoriteAnimation()
	wwlog(self.logTag,"流星")
	local n = math.random(100)
	local p1 = ww.p(820,0)
	local p2 = ww.p(-100,0)
	local mx = 0
	for i=0,n do
		local d1 = 2.0 * math.random()
		local d2 = 0.6
		local d3 = d1 + d2
		
		mx = (mx < d3 and d3 or mx)
		
		local y1 = 200 + math.random() * display.height;
		local y2 = y1 - 920.0;

		local lx = display.newSprite("res/GameMainScene/liuxing.png")
		lx:setPosition(cc.p(p1.x, y1))
		lx:setScale(0.5 +  math.random()*0.5)
		self:addChild(lx, 0)

		local dd = cc.DelayTime:create(d1)
		local mt = cc.MoveTo:create(d2, cc.p(p2.x, y2))
		local es = cc.EaseIn:create(mt,1.5)
		local se = transition.sequence({dd,es,cc.RemoveSelf:create(true)})
		lx:runAction(se)
	end
	local dd = cc.DelayTime:create(mx+ 15 * math.random())
	local ca = cc.CallFunc:create(handler(self,self.meteoroliteAnimation))
	
	self:runAction(transition.sequence({dd, ca}))
	
end
function HallUILayer:meteoroliteAnimation()
	local metroliteUI = {"res/GameMainScene/yushi1.png","res/GameMainScene/yushi2.png","res/GameMainScene/yushi3.png","res/GameMainScene/yushi4.png"}
	local n = 1 + math.random(100) % 3

	local mx = 0
	for i = 0, n do
		
		local d1 = 6.0 * math.random()
		local d2 = 5.0
		local d4 = 0.3
		local d3 = d1 + d2 + d4
		mx = (mx < d3 and d3 or mx)
		local x1 = math.random() * display.width + 100
		local y1 = math.random() * display.height
		
		local x2 = x1 - math.random() * 820.0
		local y2 = y1

		local dex = math.random(100) % 4
		local scale1 = math.random() * 0.4 + 0.6
		local scale2 = scale1 * 0.2
		local lx = display.newSprite(metroliteUI[dex])
		lx:setPosition(cc.p(x1, y1))
		lx:setScale(scale1)
		lx:setOpacity(0)
		self:addChild(lx,0)

		local dd = cc.DelayTime:create(d1)
		local fi = cc.FadeIn:create(d4)
		local mt = cc.MoveTo:create(d2, cc.p(x2, y2))
		local st = cc.ScaleTo:create(d2, scale2)
		local fo = cc.FadeOut:create(d2 + 1.0)
		local spa = cc.Spawn:create(mt, st, fo)
		local es = cc.EaseIn:create(spa, 3.0)
		
		local ro = cc.RotateBy:create(d2, 720)
		local spa2 = cc.Spawn:create(es, ro)
		local se = transition.sequence({dd, fi, spa2, cc.RemoveSelf:create(true)})
		lx:runAction(se)
	end

	local dd = cc.DelayTime:create(mx + 15 *  math.random())
	local ca = cc.CallFunc:create(handler(self,self.meteoriteAnimation))
	local se = transition.sequence({dd,ca})
	self:runAction(se)
	
end

function HallUILayer:onEnter()
	self:blackHoleAnimation()
	self:meteoriteAnimation()
	self:initMainNode()
	self:updateGiftBag()
	playBackGroundMusic("music/main_interface.mp3",true)
end
function HallUILayer:updateGiftBag()
	local listview = ToolCom.seekNodeByName(self.uinode,"l_0")
	if not listview then
		return
	end
	local items = listview:getItems()
	for _,data in ipairs(Giftbag) do
		
		local btn = nil
		for _,wid in ipairs(items) do
			local temBtn = wid
			if temBtn.getId and data.sid == temBtn:getId() then			
				btn = temBtn
				break
			end
		end

		if data then
			if not btn then
				local tem = GiftBagButton:create(data.sid)
				listview:pushBackCustomItem(tem)
			end
		else		
			if btn then
				listview:removeItem(listview:getIndex(btn))
			end
		end
	end

end

function HallUILayer:initMainNode()
	local nodeBundle = HallUILayerContent:create()
	local node = nodeBundle.root
	self:addChild(node,1)
	self.uinode = node
	local btnAchivement = ToolCom.seekNodeByName(node,"btn_cj")
	ToolCom.ButtonArmature(btnAchivement,i18n:get('str_hall','goal'),"mmtb_Animation")
	btnAchivement:addClickEventListener(handler(self,self.buttonListener))


	--排行按钮
	local btnPhb = ToolCom.seekNodeByName(node,"btn_phb")
	ToolCom.ButtonArmature(btnPhb,i18n:get('str_hall','ranking'),"huizhang_Animation")
	btnPhb:addClickEventListener(handler(self,self.buttonListener))

	--视频按钮
	local btnSp = ToolCom.seekNodeByName(node,"btn_sp")
	ToolCom.ButtonArmature(btnSp, i18n:get('str_hall','freefish'), "yubi_Animation")
	btnSp:addClickEventListener(handler(self,self.buttonListener))

	local videoSp = ToolCom.seekNodeByName(i18n:get('str_hall','freefish'))
	if videoSp and not self.m_videoInfo then
		
		self.m_videoInfo = cc.TextBMFont:create("", "fnts/fnt.fnt")
		--0xD8, 0x6D, 0x3C
		self.m_videoInfo:setColor(cc.YELLOW)
		self.m_videoInfo:setScale(0.8)
		self.m_videoInfo:setVisible(false)
		self.m_videoInfo:setPosition(cc.p(videoSp:getPositionX(),videoSp:getPositionY())+cc.p(0,15))
		btnSp:addChild(self.m_videoInfo, 1)
	end
	local btnFx = ToolCom.seekNodeByName(node,"b_fx")
	ToolCom.ButtonArmature(btnFx,i18n:get('str_hall','share'), "xx_Animation")
	--fxBar->setPosition(btnFx->getPosition());
	btnFx:addClickEventListener(handler(self,self.buttonListener))



	local lv_bg = ToolCom.seekNodeByName(node,"lv_bg")
	self.m_LvText = ToolCom.seekNodeByName(node,"lv_text")
	self.m_ExpText = ToolCom.seekNodeByName(node,"exp_text")
	self.m_ExpBar = ToolCom.seekNodeByName(node,"expBar")

	self.m_SetingBt = ToolCom.seekNodeByName(node,"shezi_bt")
	self.m_SetingBt:addClickEventListener(handler(self,self.buttonListener))


	self.m_ShopBt = ToolCom.seekNodeByName(node,"shangdian_bt")
	self.m_ShopBt:addClickEventListener(handler(self,self.buttonListener))


	self.m_WeaponBt = ToolCom.seekNodeByName(node,"wuqi_bt")
	self.m_WeaponBt:addClickEventListener(handler(self,self.buttonListener))


	self.m_CatHomeBt = ToolCom.seekNodeByName(node,"miaowu_bt")
	self.m_CatHomeBt:addClickEventListener(handler(self,self.buttonListener))


	local btnPet = ToolCom.seekNodeByName(node,"btn_cw")
	btnPet:addClickEventListener(handler(self,self.buttonListener))


	local m_SignBtn = ToolCom.seekNodeByName(node,"qiandao_bt")
	m_SignBtn:addClickEventListener(handler(self,self.buttonListener))
end

function HallUILayer:buttonListener(sender)
	if not sender then
		return
	end
	playSoundEffect("music/button_click.mp3")
	if sender:getName()=="btn_cj" then
		print("进入成就状态")
		--AchievementLayer
	elseif sender:getName()=="btn_phb" then
		print("进入排行榜状态")
		--RankLayer
	elseif sender:getName()=="btn_sp" then
--[[		if (!FishFromVideo::getInstance()->beginPlayVideo()
			&& FishFromVideo::getInstance()->getRemainCount() > 0)
		{
			addChild(WaitDialog::create(), 10);
		}--]]
		print("进入视频分享状态")
		--WaitDialog
	elseif sender:getName()=="b_fx" then
		print("进入分享状态")
		--ShareLayer
	elseif sender:getName()=="shezi_bt" then
		print("进入设置状态")
		--SettingLayer
	elseif sender:getName()=="shangdian_bt" then
		print("进入商店状态")
		--ShopLayer
	elseif sender:getName()=="wuqi_bt" then
		print("进入武器状态")
		--IronWeaponLayer
	elseif sender:getName()=="miaowu_bt" then
		print("进入喵屋状态")
		--CatHomeLayer
	elseif sender:getName()=="btn_cw" then
		print("进入宠物状态")
		--PetLayer
	elseif sender:getName()=="qiandao_bt" then
		print("进入签到状态")
		--SignLayer
	end
	
end
----------------------------------------------------
--触摸事件
----------------------------------------------------
function HallUILayer:onTouchBegin(touch,event)
    if event:getEventCode() == cc.EventCode.BEGAN then
        return true
    elseif event:getEventCode() == cc.EventCode.ENDED then
        --self:close()
    end
end
return HallUILayer