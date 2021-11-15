#include "HSV.hpp"
#include "HEX.hpp"
#include <algorithm>
#pragma once

namespace converterRGB {
	HSV convertToHSV(RGB code);
	float calculateCMax(RGB code);
	float calculateCMin(RGB code);
	float calculateH(RGB code, HSV codeTwo);
	float calculateS(HSV code);
	float calculateRPrim(RGB code);
	float calculateBPrim(RGB code);
	float calculateGPrim(RGB code);
	/*float calculateRange(); */

	HEX convertToHEX(RGB code);
	std::string calculateCodePart(int codePart);
	
}