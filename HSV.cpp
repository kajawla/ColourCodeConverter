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

bool HSV::operator== (const HSV& code)
{
    return (code.h*100 == h*100
        && code.s == s
        && code.v == v ? true : false);
}
