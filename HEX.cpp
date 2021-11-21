#include "HEX.hpp"

std::string HEX::getCode() const
{
	return code;
}

void HEX::setCode(std::string code_)
{
	code = code_;
}

bool HEX::operator== (const HEX& code_)
{
	if (code==code_.getCode())
	{
		return true;
	}
	return false;
}