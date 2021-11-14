#include <cmath>
#include "HSV.hpp"
class Converter
{
private:

public:
RGB convertToRGB(HSV code);
float calculateC(HSV code);
float calculateX(HSV code, float c);
int calculateR();
int calculateG();
int calculateB();
int calculateM();

HSV convertToHSV(RGB code);
float calculateCMax(RGB code);
float calculateCMin(RGB code);
float calculateRPrim(RGB code);
float calculateBPrim(RGB code);
float calculateGPrim(RGB code);
float calculateV(RGB code);
float calculateS(HSV code);
float calculateH(RGB code, HSV codeTwo);

};