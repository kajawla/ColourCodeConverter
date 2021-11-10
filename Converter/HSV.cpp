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

int HSV::calculateRange()
{
    return cMax-cMin;
}

void HSV::setCMax(const float& x)
{
    cMax=x;
}

void HSV::setCMin(int x)
{ 
    cMin=x;
}

void HSV::setRange(int x)
{
    range=x;
}

int HSV::getRange()
{
    return range;
}

float HSV::getCMax()
{
    return cMax;
}

const int HSV::getCMin()
{
    return cMin;
}

bool HSV::operator== (const HSV& code)
{
    return (code.h*100 == h*100
        && code.s == s
        && code.v == v ? true : false);
}
