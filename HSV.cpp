#include "HSV.hpp"


double HSV::getH() const
{
    return h;
}

double HSV::getS() const
{
    return s;
}

double HSV::getV() const
{
    return v;
}

float HSV::calculateRange()
{
    return cMax-cMin;
}

void HSV::setCMax(const float x)
{
    cMax=x;
}

void HSV::setCMin(const float x)
{ 
    cMin=x;
}

void HSV::setRange(const float x)
{
    range=x;
}

void HSV::setH(const double& x)
{
    h = x;
}

void HSV::setS(const double& x)
{
    s = x;
}

void HSV::setV(const double& x)
{
    v = x;
}

float HSV::getRange() const
{
    return range;
}

float HSV::getCMax() const
{
    return cMax;
}

float HSV::getCMin() const
{
    return cMin;
}

bool HSV::operator== (const HSV& code)
{
    return (code.h*100 == h*100
        && code.s == s
        && code.v == v ? true : false);
}
