-------------------------------------------------------------------------
-- Desc:    地方棋牌
-- Author:
-- Date:    2016.08.15
-- Last:
-- Content:  大厅状态机根配置
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local registry = {
    stateName = "UIRoot";-- 状态机模块名（见名知意即可）
    resData = { };-- 状态机对象所用到的所有资源（音频、）
    controller = "hall.fsm.stateModelControl.UIHallSceneState";-- 控制器 配置UISettingState.lua
    view = "hall.mediator.view.HallUILayer";
    entry = true;
    enter = {
    };
    push = {
        -- 压栈状态
        { eventName = "setting"; stateName = "UISettingState" },
        { eventName = "sign"; stateName = "UISignState" },
        { eventName = "chooseRoom"; stateName = "UIChooseRoomState" },
        { eventName = "store"; stateName = "UIStoreState" },
        { eventName = "match"; stateName = "UIMatchState" },
        { eventName = "email"; stateName = "UIEmailState" },
        { eventName = "userinfo"; stateName = "UIUserInfoState" },
        { eventName = "exchange"; stateName = "UIExchangeState" },
        { eventName = "siren"; stateName = "UISiRenRoomState" },
        { eventName = "activity"; stateName = "UIActivityState" },
        { eventName = "task"; stateName = "UITaskState" },
        { eventName = "rank"; stateName = "UIRankState" },
        { eventName = "fcharge"; stateName = "UIFirstChargeState" },
        { eventName = "goodsBox"; stateName = "UIGoodsBoxState" },
		{ eventName = "cardPartner"; stateName = "UICardPartnerState" },
		{ eventName = "sirenInvited"; stateName = "UISiRenInvitedState" },
		
    };
    pop = { { eventName = "back" } };
    filter =-- 过滤器配置
    {

    };
    resLimit = 3;
}

registry.resData.Texture =
{
    "animation/heidong_Animation/heidong_Animation0.png",
    "animation/mmtb_Animation/mmtb_Animation0.png",
    "animation/huizhang_Animation/huizhang_Animation0.png",
    "animation/yubi_Animation/yubi_Animation0.png",
    "animation/xx_Animation/xx_Animation0.png",
    "animation/lb1_Animation/lb1_Animation0.png",
    "animation/lb2_Animation/lb2_Animation0.png",
    "animation/lb3_Animation/lb3_Animation0.png",
    "res/GameMainScene/liuxing.png",
	"res/GameMainScene/yushi1.png",
	"res/GameMainScene/yushi2.png",
	"res/GameMainScene/yushi3.png",
	"res/GameMainScene/yushi4.png"
}
registry.resData.Plist =
{
    "animation/heidong_Animation/heidong_Animation0.plist",
    "animation/mmtb_Animation/mmtb_Animation0.plist",
    "animation/huizhang_Animation/huizhang_Animation0.plist",
    "animation/yubi_Animation/yubi_Animation0.plist",
    "animation/xx_Animation/xx_Animation0.plist",
	"animation/lb1_Animation/lb1_Animation0.plist",
	"animation/lb2_Animation/lb2_Animation0.plist",
	"animation/lb3_Animation/lb3_Animation0.plist",

}
registry.resData.Armature = { 
	 "animation/heidong_Animation/heidong_Animation.ExportJson",
	 "animation/mmtb_Animation/mmtb_Animation.ExportJson",
	 "animation/huizhang_Animation/huizhang_Animation.ExportJson",
	 "animation/yubi_Animation/yubi_Animation.ExportJson",
	 "animation/xx_Animation/xx_Animation.ExportJson",
	 "animation/lb1_Animation/lb1_Animation.ExportJson",
	 "animation/lb2_Animation/lb2_Animation.ExportJson",
	 "animation/lb3_Animation/lb3_Animation.ExportJson",
}
registry.resData.Sound = { }
registry.resData.FrameAnim = { }

return registry