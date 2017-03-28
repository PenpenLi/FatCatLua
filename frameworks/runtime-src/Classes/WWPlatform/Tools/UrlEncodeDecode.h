//
//  UrlEncodeDecode.h
//  WW_DDZ_V2
//
//  Created by Sam on 14-10-30.
//
//

#ifndef __WW_DDZ_V2__UrlEncodeDecode__
#define __WW_DDZ_V2__UrlEncodeDecode__

#include <string>

class UrlEncodeDecode
{
public:
    static std::string UrlEncode(const std::string& str);
    static std::string UrlDecode(const std::string& str);

private:
    static unsigned char ToHex(unsigned char x);
    static unsigned char FromHex(unsigned char x);
    
};


#endif /* defined(__WW_DDZ_V2__UrlEncodeDecode__) */
