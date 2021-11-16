#include "converterHEX.hpp"
#include <cctype>
namespace converterHEX {

	RGB convertToRGB(HEX code)
	{
		std::string popingCode = code.getCode();
		int result = 0;
		while (!popingCode.empty())
		{
			if (popingCode.size() % 2 == 0 && popingCode.size() != 6)
			{
				if (std::isdigit(popingCode.back()))
				{
					result += popingCode.back() - '0';
					result += 16 * popingCode.size();
					popingCode.pop_back();
				}
				else
				{
					switch (popingCode.back())
					{
					case 'A':
						result += 10;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					case 'B':
						result += 11;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					case 'C':
						result += 12;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					case 'D':
						result += 13;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					case 'E':
						result += 14;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					case 'F':
						result += 15;
						result += 16 * popingCode.size();
						popingCode.pop_back();
						break;
					}
				}
			}
		}

		RGB codeee(0, 0, 0);
		return codeee;
	}
	
}