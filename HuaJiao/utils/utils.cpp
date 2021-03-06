//
//  utils.cpp
//  HuaJiao
//
//  Created by LowBoy on 2017/8/12.
//  Copyright © 2017年 @LowBoyTeam. All rights reserved.
//

#include "utils.hpp"

#include <random>
#include <sstream>

#ifdef _WIN32

std::string crc_utf8_to_ansi(const std::string& str)
{
	BSTR    bstrWide;
	char*   pszAnsi;
	int     nLength;
	const char *pszCode = str.c_str();

	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	std::string r(pszAnsi);
	delete[] pszAnsi;
	return r;
}

std::string crc_unicode_to_ansi(const std::wstring &str)
{
	std::string ret;

	int in_len = (int)str.length();
	int count = WideCharToMultiByte(CP_ACP, 0, str.c_str(), in_len, NULL, 0, NULL, NULL);

	if (count > 0)
	{
		char *buffer = (char *)malloc(count * sizeof(char));
		if (buffer != 0)
		{
			WideCharToMultiByte(CP_ACP, 0, str.c_str(), in_len, buffer, count, NULL, NULL);
			ret = std::string(buffer, count);
			free((void *)buffer);
		}
	}
	return ret;
}

#endif // _WIN32

void print_hex(unsigned char *str, int len)
{
    int i;
    for (i = 0; i < len; ++i)
        printf("%02X", str[i]);
    printf("\n\n");
}

std::string randomString(const size_t length) {
    const std::string chars("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, static_cast<int>(chars.size()) - 1);
    std::string result(length, '0');
    for (auto& chr : result)
        chr = chars[dist(rng)];
    return result;
}

int randomNumber(const size_t length) {
    int min = (int)pow(10, length - 1);
    int max = (((unsigned int)(-1)) >> 1);
    if (length < 10)
        max = (int)pow(10, length) - 1;
    std::default_random_engine rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist;
    return dist(rng, decltype(dist)::param_type(min, max));
}

std::string getstring(const int n)
{
    std::stringstream newstr;
    newstr << n;
    return newstr.str();
}

int32_t swapInt32(int32_t value)
{
    return ((value & 0x000000FF) << 24) |
    ((value & 0x0000FF00) << 8) |
    ((value & 0x00FF0000) >> 8) |
    ((value & 0xFF000000) >> 24);
}

void rc4_xx(const std::string& src, const std::string& strkey, std::string *output)
{
    output->resize(src.length());
    RC4_KEY key;
    RC4_set_key(&key, (uint32_t)strkey.length(), (unsigned char *)strkey.c_str());
    RC4(&key, (uint32_t)src.length(), (unsigned char *)src.c_str(), (unsigned char *)output->c_str());
}
