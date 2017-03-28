
--------------------------------
-- @module WWBuffer
-- @extend Ref
-- @parent_module ww

--------------------------------
-- 
-- @function [parent=#WWBuffer] readUChar 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] setWriterIndex 
-- @param self
-- @param #int u_pos
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readBoolean 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeData 
-- @param self
-- @param #char p_data
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeString 
-- @param self
-- @param #char p_data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeShort 
-- @param self
-- @param #short data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readWholeData 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- @overload self, char, int         
-- @overload self, int         
-- @function [parent=#WWBuffer] readData
-- @param self
-- @param #char p_out_data
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)

--------------------------------
-- 
-- @function [parent=#WWBuffer] writeDouble 
-- @param self
-- @param #double data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] getBufferSize 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readChar 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readShort 
-- @param self
-- @return short#short ret (return value: short)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] markReaderIndex 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveRight 
-- @param self
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readLongLong 
-- @param self
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readUShort 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] getReadableSize 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readChar3ToInt 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] getReaderIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] capacity 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] getWriterIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readUInt 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] discardReadContent 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeUChar 
-- @param self
-- @param #unsigned char data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] setReaderIndex 
-- @param self
-- @param #int u_pos
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readString 
-- @param self
-- @param #int u_len
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeLengthAndData 
-- @param self
-- @param #char p_data
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeFloat 
-- @param self
-- @param #float data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readULongLong 
-- @param self
-- @return unsigned long long#unsigned long long ret (return value: unsigned long long)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] getContentSize 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readLengthAndString 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveWriterIndexToBack 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] toRealse 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeUInt 
-- @param self
-- @param #unsigned int data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] empty 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeLengthAndString 
-- @param self
-- @param #char p_data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveLeft 
-- @param self
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeBoolean 
-- @param self
-- @param #bool isbool
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeChar 
-- @param self
-- @param #char data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readInt 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveReaderIndexToFront 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveWriterIndexToFront 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readDouble 
-- @param self
-- @return double#double ret (return value: double)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readLengthAndData 
-- @param self
-- @return WWBuffer#WWBuffer ret (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] copy 
-- @param self
-- @return WWBuffer#WWBuffer ret (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] data 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] readFloat 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] reset 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeUShort 
-- @param self
-- @param #unsigned short data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] moveReaderIndexToBack 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] clear 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeULongLong 
-- @param self
-- @param #unsigned long long data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] skipData 
-- @param self
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] length 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] resetReaderIndex 
-- @param self
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#WWBuffer] isReadable
-- @param self
-- @param #int u_len
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#WWBuffer] writeInt 
-- @param self
-- @param #int data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- 
-- @function [parent=#WWBuffer] writeLongLong 
-- @param self
-- @param #long long data
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)
        
--------------------------------
-- @overload self, int         
-- @overload self         
-- @overload self, char, int         
-- @function [parent=#WWBuffer] create
-- @param self
-- @param #char p_data
-- @param #int u_len
-- @return WWBuffer#WWBuffer ret (return value: WWBuffer)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @overload self, char, int         
-- @function [parent=#WWBuffer] WWBuffer
-- @param self
-- @param #char p_data
-- @param #int u_len
-- @return WWBuffer#WWBuffer self (return value: WWBuffer)

return nil
