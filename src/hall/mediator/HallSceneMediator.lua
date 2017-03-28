-------------------------------------------------------------------------
-- Desc:    地方棋牌
-- Author:  diyal.yin
-- Date:    2016.08.15
-- Last:
-- Content:  大厅Mediator（View）组件
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local HallSceneMediator = class("HallSceneMediator",require("packages.mvc.Mediator"))

local HallScene = import(".HallScene")


local Toast = require("app.views.common.Toast")

local JumpFilter = require("packages.statebase.filter.JumpFilter")

--在大厅进入后引用
require("hall.data.UIStateJumper")

function HallSceneMediator:init()
	self.logTag = "HallSceneMediator.lua"
end
--进入的额外数据
function HallSceneMediator:onCreate(userdata)
	
	cclog("显示大厅背景")
	self.scene = HallScene:create(userdata)
	
	--播放背景音乐

	
	--playBackGroundMusic("sound/backMusic/hallBackGroundMusic",true)
	
	display.runScene(self.scene)
	
	self:installInnerEventListeners()
end

--装载组建消息事件
function HallSceneMediator:installInnerEventListeners()

	
end

return HallSceneMediator