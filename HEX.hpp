#pragma once
#include <string>

class HEX
{
private:
	std::string code;
public:
	HEX(std::string code_) : code(code_) {};
	std::string getCode();
	void setCode(std::string code_);
	bool operator== (HEX code_);
};