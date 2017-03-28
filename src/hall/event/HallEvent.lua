local prefixFlag = "HALL_SCENE_EVENT_"

cc.exports.HALL_SCENE_EVENTS = {
	MAIN_ENTRY 			= prefixFlag .. "mainEntry";

}

cc.exports.HALL_ENTERINTENT = {
	ENTER_NETWORK_ERROR = 1, --登录的时候没有网络
	ENTER_LOGINING = 2, --登录的时候正在获取数据
}