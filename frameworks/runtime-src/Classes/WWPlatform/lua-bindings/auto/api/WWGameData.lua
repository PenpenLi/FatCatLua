
--------------------------------
-- @module WWGameData
-- @parent_module ww

--------------------------------
-- brief Set integer value by key.<br>
-- js NA
-- @function [parent=#WWGameData] setIntegerForKey 
-- @param self
-- @param #char pKey
-- @param #int value
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- @overload self, char, float         
-- @overload self, char         
-- @function [parent=#WWGameData] getFloatForKey
-- @param self
-- @param #char pKey
-- @param #float defaultValue
-- @return float#float ret (return value: float)

--------------------------------
-- @overload self, char, bool         
-- @overload self, char         
-- @function [parent=#WWGameData] getBoolForKey
-- @param self
-- @param #char pKey
-- @param #bool defaultValue
-- @return bool#bool ret (return value: bool)

--------------------------------
-- brief Set double value by key.<br>
-- js NA
-- @function [parent=#WWGameData] setDoubleForKey 
-- @param self
-- @param #char pKey
-- @param #double value
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- brief Set float value by key.<br>
-- js NA
-- @function [parent=#WWGameData] setFloatForKey 
-- @param self
-- @param #char pKey
-- @param #float value
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- @overload self, char, string         
-- @overload self, char         
-- @function [parent=#WWGameData] getStringForKey
-- @param self
-- @param #char pKey
-- @param #string defaultValue
-- @return string#string ret (return value: string)

--------------------------------
-- brief Set string value by key.<br>
-- js NA
-- @function [parent=#WWGameData] setStringForKey 
-- @param self
-- @param #char pKey
-- @param #string value
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- brief Save content to xml file<br>
-- js NA
-- @function [parent=#WWGameData] flush 
-- @param self
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- @overload self, char, int         
-- @overload self, char         
-- @function [parent=#WWGameData] getIntegerForKey
-- @param self
-- @param #char pKey
-- @param #int defaultValue
-- @return int#int ret (return value: int)

--------------------------------
-- @overload self, char, double         
-- @overload self, char         
-- @function [parent=#WWGameData] getDoubleForKey
-- @param self
-- @param #char pKey
-- @param #double defaultValue
-- @return double#double ret (return value: double)

--------------------------------
-- brief Set bool value by key.<br>
-- js NA
-- @function [parent=#WWGameData] setBoolForKey 
-- @param self
-- @param #char pKey
-- @param #bool value
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- 
-- @function [parent=#WWGameData] destroyInstance 
-- @param self
-- @return WWGameData#WWGameData self (return value: WWGameData)
        
--------------------------------
-- js NA
-- @function [parent=#WWGameData] getXMLFilePath 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- js NA
-- @function [parent=#WWGameData] isXMLFileExist 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#WWGameData] getInstance 
-- @param self
-- @return WWGameData#WWGameData ret (return value: WWGameData)
        
return nil
