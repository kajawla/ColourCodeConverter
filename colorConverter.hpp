#pragma once
#include "RGB.hpp"
#include "HSV.hpp"
#include "HEX.hpp"

namespace colorConverter
{
	//Conversion from RGB to other types
	HSV convertToHSV(const RGB &code);
	float calculateCMax(const RGB &code);
	float calculateCMin(const RGB &code);
	float calculateH(const RGB &code, const HSV &codeTwo);
	float calculateS(const HSV &code);
	float calculateRPrim(const RGB &code);
	float calculateGPrim(const RGB &code);
	float calculateBPrim(const RGB& code);

	HEX convertToHEX(const RGB& code);
	int calculateRGBPart(std::string& code);

	//Conversion from HEX to other types
	HSV convertToHSV(const HEX& code);

	RGB convertToRGB(const HEX &code);

	//Conversion from HSV to other types
	RGB convertToRGB(const HSV& code);
	float calculateC(const HSV& code);
	float calculateX(const HSV &code, float c);

	HEX convertToHEX(const HSV& code);
	std::string calculateCodePart(int codePart);

	
	
	



}



