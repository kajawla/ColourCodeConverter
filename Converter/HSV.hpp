#include "RGB.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

class HSV
{
private:
char type;
double h;
double s;
double v;
float cMax;
float cMin;
float range;

public:
HSV(float _h, float _s, float _v):h{_h},s{_s},v{_v}{};

double getH();
double getS();
double getV();
float getCMax();
const int getCMin ();
int getRange();

void setCMax (const float &x);
void setCMin(int x); 
void setRange(int x);

int calculateRange();

bool operator== (const HSV &code);

};