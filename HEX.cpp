#include "HEX.hpp"

std::string HEX::getCode()
{
	return code;
}

void HEX::setCode(std::string code_)
{
	code = code_;
}

bool HEX::operator== (HEX code_)
{
	if (code==code_.getCode())
	{
		return true;
	}
	return false;
}