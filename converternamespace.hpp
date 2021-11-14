#include "HSV.hpp"
#pragma once

 namespace converterRGB {
	HSV convertToHSV(RGB code);
	float calculateCMax(RGB code);
	float calculateCMin(RGB code);
	float calculateH(RGB code, HSV codeTwo);
	float calculateS(HSV code);
	/*float calculateRange(); */
}