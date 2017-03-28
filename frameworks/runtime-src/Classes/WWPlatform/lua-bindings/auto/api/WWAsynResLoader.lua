
--------------------------------
-- @module WWAsynResLoader
-- @extend Node
-- @parent_module ww

--------------------------------
-- 
-- @function [parent=#WWAsynResLoader] unloadTexture 
-- @param self
-- @param #string uniqueTag
-- @param #array_table texturePath
-- @return WWAsynResLoader#WWAsynResLoader self (return value: WWAsynResLoader)
        
--------------------------------
-- 异步加载图集资源<br>
-- param	uniqueTag 请求加载的唯一标识符<br>
-- param	texturePath 需要加载的纹理集合<br>
-- param	handler	加载完成后的LUA回调
-- @function [parent=#WWAsynResLoader] loadPlist 
-- @param self
-- @param #string uniqueTag
-- @param #array_table texturePath
-- @param #int handler
-- @return WWAsynResLoader#WWAsynResLoader self (return value: WWAsynResLoader)
        
--------------------------------
-- 异步加载纹理资源<br>
-- param	uniqueTag 请求加载的唯一标识符<br>
-- param	texturePath 需要加载的纹理集合<br>
-- param	handler	加载完成后的LUA回调
-- @function [parent=#WWAsynResLoader] loadTexture 
-- @param self
-- @param #string uniqueTag
-- @param #array_table texturePath
-- @param #int handler
-- @return WWAsynResLoader#WWAsynResLoader self (return value: WWAsynResLoader)
        
--------------------------------
-- 
-- @function [parent=#WWAsynResLoader] getInstance 
-- @param self
-- @return WWAsynResLoader#WWAsynResLoader ret (return value: WWAsynResLoader)
        
return nil
