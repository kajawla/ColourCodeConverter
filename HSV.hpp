#include "RGB.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

#pragma once
class HSV
{
private:
double h;
double s;
double v;
float cMax;
float cMin;
float range;

public:
HSV() : h(0), s(0), v(0) {};
HSV(float _h, float _s, float _v):h{_h}, s{_s}, v{_v} {};

double getH() const;
double getS() const;
double getV() const;
float getCMax() const;
float getCMin() const;
float getRange() const;

void setH(const double& x);
void setS(const double& x);
void setV(const double& x);
void setCMax (const float x);
void setCMin(const float x);
void setRange(const float x);

float calculateRange(); 

bool operator== (const HSV &code);

};