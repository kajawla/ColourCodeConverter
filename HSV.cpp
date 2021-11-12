#include "HSV.hpp"


double HSV::getH()
{
    return h;
}

double HSV::getS()
{
    return s;
}

double HSV::getV()
{
    return v;
}

float HSV::calculateRange()
{
    return cMax-cMin;
}

void HSV::setCMax(const float& x)
{
    cMax=x;
}

void HSV::setCMin(const float& x)
{ 
    cMin=x;
}

void HSV::setRange(const float& x)
{
    range=x;
}

float HSV::getRange()
{
    return range;
}

float HSV::getCMax()
{
    return cMax;
}

const float HSV::getCMin()
{
    return cMin;
}

bool HSV::operator== (const HSV& code)
{
    return (code.h*100 == h*100
        && code.s == s
        && code.v == v ? true : false);
}
