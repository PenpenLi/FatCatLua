-------------------------------------------------------------------------
-- Desc:    地方棋牌
-- Author:  cruelogre
-- Date:    2016.12.21
-- Last: 
-- Content:  活动配置管理
--			包括常量定义
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local ActivityCfg = {}
--活动界面中的跳转配置 一级界面（状态机） 二级界面（非状态机）直接打开
ActivityCfg.openType = {
	STATEUI = 1, --状态机界面
	SECONDUI = 2,--直接打开界面
	THIRDAPP = 3, --第三方app
}


return ActivityCfg