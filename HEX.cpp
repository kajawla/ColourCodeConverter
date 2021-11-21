#include "HEX.hpp"

std::string HEX::getCode() const
{
	return code;
}

bool HEX::operator== (const HEX& code_)
{
	if (code==code_.getCode())
	{
		return true;
	}
	return false;
}