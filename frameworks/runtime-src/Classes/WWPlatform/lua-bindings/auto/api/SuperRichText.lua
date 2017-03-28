
--------------------------------
-- @module SuperRichText
-- @extend LayerColor
-- @parent_module ww

--------------------------------
-- @overload self, size_table         
-- @overload self         
-- @function [parent=#SuperRichText] init
-- @param self
-- @param #size_table size
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#SuperRichText] renderHtml 
-- @param self
-- @param #char html
-- @return SuperRichText#SuperRichText self (return value: SuperRichText)
        
--------------------------------
-- 
-- @function [parent=#SuperRichText] renderNode 
-- @param self
-- @param #txml2.XMLNode node
-- @return SuperRichText#SuperRichText self (return value: SuperRichText)
        
--------------------------------
-- @overload self, size_table         
-- @overload self         
-- @function [parent=#SuperRichText] create
-- @param self
-- @param #size_table size
-- @return SuperRichText#SuperRichText ret (return value: SuperRichText)

--------------------------------
-- 
-- @function [parent=#SuperRichText] SuperRichText 
-- @param self
-- @return SuperRichText#SuperRichText self (return value: SuperRichText)
        
return nil
