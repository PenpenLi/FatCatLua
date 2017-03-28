--初始化模块PureMVC
local appRegistry = {
	"login.init", -- 登录
	"hall.init", --大厅

}

local registApp = function (apps)
	for _,app in ipairs(apps) do
		require(app)
	end
end
registApp(appRegistry)