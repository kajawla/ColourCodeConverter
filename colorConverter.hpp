#pragma once
#include "RGB.hpp"
#include "HSV.hpp"
#include "HEX.hpp"

namespace colorConverter
{
	HSV convertToHSV(RGB code);
	float calculateCMax(RGB code);
	float calculateCMin(RGB code);
	float calculateH(RGB code, HSV codeTwo);
	float calculateS(HSV code);
	float calculateRPrim(RGB code);
	float calculateGPrim(RGB code);
	float calculateBPrim(RGB code);
	HSV convertToHSV(HEX code);
	RGB convertToRGB(HEX code);
	RGB convertToRGB(HSV code);
	float calculateC(HSV code);
	float calculateX(HSV code, float c);
	HEX convertToHEX(HSV code);
	std::string calculateCodePart(int codePart);
	HEX convertToHEX(RGB code);
	int calculateRGBPart(std::string& code);
	
	



}



