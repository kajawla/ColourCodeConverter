#include "HSV.hpp"
#include <cmath>
class Converter
{
private:

public:
RGB convertToRGB(HSV code);
/*HSV convertToHSV(RGB code);*/
float calculateC(HSV code);
float calculateX(HSV code, float c);
int calculateR();
int calculateG();
int calculateB();
int calculateM();
};