#include "base64_converter.h"
#include <iostream>

namespace websocket
{
	const std::string Base64::base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";
	std::string Base64::to_base64(std::vector <unsigned char> data)
	{
		std::string result;
		result.reserve(data.size());
		size_t pushCount = 0;
		while (data.size() % 3 != 0)
		{
			data.push_back('\0');
			pushCount++;
		}
		for (int i = 0; i < data.size(); i++)
		{
			if ((i + 1) % 3 == 0)
			{
				result.push_back(base64Chars.at(((data.at(i - 2)) & 0xFC) >> 2));
				result.push_back(base64Chars.at(((data.at(i - 2) & 0x03) << 4) | ((data.at(i - 1) & 0xF0) >> 4)));
				result.push_back(base64Chars.at(((data.at(i - 1) & 0x0F) << 2) | ((data.at(i) & 0xC0) >> 6)));
				result.push_back(base64Chars.at(data.at(i) & 0x3F));
			}
		}

		bool first = true;
		while (pushCount > 0)
		{
			result[result.size() - pushCount] = '=';
			data.pop_back();
			pushCount--;
			first = false;
		}
		return result;
	}
}
