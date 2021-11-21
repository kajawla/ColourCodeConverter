#pragma once
#include "RGB.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

class HSV
{
private:
double h;
double s;
double v;

public:
HSV() : h(0), s(0), v(0) {};
HSV(float _h, float _s, float _v):h{_h}, s{_s}, v{_v} {};

double getH() const;
double getS() const;
double getV() const;

bool operator== (const HSV &code);

};