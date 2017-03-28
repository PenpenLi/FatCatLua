local languageString = { }
-- 根据模块划分
-- 使用方式 i18n:get('str_common', 'comm_appname')
-- 根据模块Key，字符串Key获得文字
-----------------------[[ 配置区Start ]]-----------------------------
-- 通用模块
languageString['str_common'] =
{
    ['comm_sure'] = '确定',
    ['comm_cancel'] = '取消',
    ['comm_submit'] = '提交',
    ['comm_quit_text'] = '是否退出游戏？',
    ['comm_net_closed'] = '您的设备未开启网络连接。请检查网络设备后，重新连接游戏',
    ['comm_net_discontent'] = '网络连接已断开，请重新连接网络',
    ['comm_reconnect'] = '重新连接',
    ['comm_net_connectding'] = '正在为您重新连接中',
    ['comm_loading'] = '资源加载中，请稍候',
    ['comm_waiting'] = '数据加载中，请稍候',
    ['double_login_notify'] = "您的账号已在其他设备上登录",
    ['comm_telNum'] = '400-680-1212',
    ['wan'] = '万',
    ['yi'] = '亿',
    ['yuan'] = '元',
    ['diamond'] = '钻石',
    ['gold'] = '金币',
    ["male"] = "男",
    ["female"] = "女",
    ['comm_minus0'] = '分',
    ['comm_minus1'] = '分钟',
    ['comm_second'] = '秒',
    ['comm_yes'] = '是',
    ['comm_no'] = '否',
    ['comm_ShareContent'] = '独创组队竞技玩法，免费大奖拿到手软',
}

languageString['str_hall'] =
{
    ['goal'] = 'goal',
    -- ['hall_game_exit'] = '明天签到可得|255,241,10::%d金币|奖励!',
    ['ranking'] = 'ranking',
    ['freefish'] = 'freefish',
    ['share'] = 'share',
 
}

-----------------------[[ 配置区End ]]-----------------------------
return languageString