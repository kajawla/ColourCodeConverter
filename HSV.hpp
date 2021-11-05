#include "RGB.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

class HSV
{
private:
char type;
float h;
float s;
float v;
float cMax;
float cMin;
float range;

public:
HSV(float _h, float _s, float _v):h{_h},s{_s},v{_v}{};

HSV convertToHSV(RGB code);
float getH();
float getS();
float getV();
int getCMax();
const int getCMin ();
int getRange();

void setCMax (const int &x);
void setCMin(int x);
void setRange(int x);

float calculateRPrim(RGB code);
float calculateBPrim(RGB code);
float calculateGPrim(RGB code);
float calculateV();
float calculateS();
float calculateH(RGB code);
float calculateCMax(RGB code);
float calculateCMin(RGB code);
int calculateRange();


};