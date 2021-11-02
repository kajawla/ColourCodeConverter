#include "RGB.hpp"
#include <iomanip>
#include <iostream>
class HSV
{
private:
char type;
float h;
float s;
float v;
int cMax;
int cMin;
int range;

public:
HSV(float _h, float _s, float _v):h{_h},s{_s},v{_v}{};

HSV convertToHSV(RGB code);
float getH();
float getS();
float getV();
int getCMax();
int getCMin();
int getRange();
void setCMax (const int & x);
void setCMin(int x);
void setRange(int x);
float calculateV(float i);
int calculateCMax(RGB code);
int calculateCMin(RGB code);
int calculateRange();
};