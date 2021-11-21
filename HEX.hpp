#pragma once
#include <string>

class HEX
{
private:
	std::string code;
public:
	HEX() : code("000000") {};
	HEX(std::string code_) : code(code_) {};

	std::string getCode() const;

	bool operator== (const HEX &code_);
};