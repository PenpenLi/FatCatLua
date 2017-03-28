-------------------------------------------------------------------------
-- Desc:    地方棋牌
-- Author:  cruelogre
-- Date:    2016.09.25
-- Last:
-- Content:  场景管理器(大厅)
-- Copyright (c) wawagame Entertainment All right reserved.
--------------------------------------------------------------------------
local WWSceneBase = class("WWSceneBase", cc.Scene)
local ExitGameLayer = require("app.views.customwidget.ExitGameLayer")
local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
local LuaLoginNativeBridge = require("app.utilities.LuaLoginNativeBridge"):create()
import(".KeyBoardEvent", "app.event.")
local IPhoneTool = ww.IPhoneTool:getInstance()


function WWSceneBase:ctor(callback)
    self.callback = callback
    self.logTag = "WWSceneBase.lua"
    self.listener2 = nil
    self.systemInfoNode = nil
    self.handles = { }
    self:initListener()
    self:registerScriptHandler( function(event)
        if event == "enter" then
            self:onEnter()
        elseif event == "exit" then
            self:onExit()
        end
    end )

end

function WWSceneBase:createExitGameDialog()
    LuaLoginNativeBridge:callNativeLogout(
    handler(self, self._logoutSuccThridParty),
    handler(self, self._logoutFailThridParty),
    function()
        -- 非第三方登录情况
        local function exitCallback(...)
            -- body
            if self.ExitGameLayer then
                self.ExitGameLayer:close()
                self.ExitGameLayer = nil
            end
        end
        self.ExitGameLayer = ExitGameLayer:create(exitCallback)
        self.ExitGameLayer:show()
    end )
end

-- sdk退出成功
function WWSceneBase:_logoutSuccThridParty(result)
    wwlog(self.logTag, "_logoutSuccThridParty result=%s:", result or "")
    cc.Director:getInstance():endToLua()
end

-- sdk退出失败
function WWSceneBase:_logoutFailThridParty(result)
    wwlog(self.logTag, "_logoutFailThridParty result=%s:", result or "")
end

function WWSceneBase:onEnter()
    local function keyboardPressed(keyCode, event)
        if keyCode == cc.KeyCode.KEY_BACK then
            if MediatorMgr:getPopupNodeCount() == 0 then
                playSoundEffect("sound/effect/anniu")
                if self.callback then
                    -- 有回调优先回调
                    self.callback()
                else
                    -- 弹出退出提示界面
                    if self.ExitGameLayer then
                        self.ExitGameLayer:close()
                        self.ExitGameLayer = nil
                    else
                        self:createExitGameDialog()
                    end
                end
            end
        end
    end

    self.listener2 = cc.EventListenerKeyboard:create()
    self.listener2:registerScriptHandler(keyboardPressed, cc.Handler.EVENT_KEYBOARD_PRESSED)
    eventDispatcher:addEventListenerWithFixedPriority(self.listener2, KEYBOARD_EVENTS.KETBOARD_SCENE)
end

function WWSceneBase:initListener()
   
end

function WWSceneBase:onExit()

    if self.listener2 and eventDispatcher then
        eventDispatcher:removeEventListener(self.listener2)
    end
    self.listener2 = nil

end

return WWSceneBase