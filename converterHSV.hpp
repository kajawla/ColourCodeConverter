#include "HSV.hpp"
#include "HEX.hpp"
#pragma once

namespace converterHSV {
	RGB convertToRGB(HSV code);
	float calculateC(HSV code);
	float calculateX(HSV code, float c);
	
	HEX convertToHEX(HSV code);
	std::string calculateCodePart(int codePart);
}