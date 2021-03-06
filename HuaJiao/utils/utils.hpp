//
//  utils.hpp
//  HuaJiao
//
//  Created by LowBoy on 2017/8/12.
//  Copyright © 2017年 @LowBoyTeam. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>

#include "../crypto/rc4/rc4.hpp"

#ifdef _WIN32

#include <windows.h>

std::string crc_utf8_to_ansi(const std::string& str);

std::string crc_unicode_to_ansi(const std::wstring &str);

#endif // _WIN32


inline bool IsNum(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        int tmp = (int)str[i];
        if (tmp >= 48 && tmp <= 57)
            continue;
        else
            return false;
    }
    return true;
}

void print_hex(unsigned char *str, int len);

std::string randomString(const size_t length);

int randomNumber(const size_t length);

std::string getstring(const int n);

int32_t swapInt32(int32_t value);

void rc4_xx(const std::string& src, const std::string& strkey, std::string *output);

#endif /* utils_hpp */
