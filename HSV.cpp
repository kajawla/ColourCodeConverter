#include "HSV.hpp"

HSV HSV::convertToHSV(RGB code)
{
    
    setCMin(calculateCMin(code));
    setCMax(calculateCMax(code));
    setRange(calculateRange());
    HSV result(code.getR(),code.getG(),calculateV(cMax));
    

    return result;
}
float HSV::getH()
{
    return 0;
}

float HSV::getS()
{
    return 0;
}

float HSV::getV()
{
    return v;
}

float HSV::calculateV(float i)
{
    return ((i/255)*100);
}
int HSV::calculateCMax(RGB code)
{
    if(code.getB()>code.getG())
    {
        if(code.getB()>code.getR())
        {
            
            return code.getB();
        }
    }
    if(code.getG()>code.getR())
    {
        return code.getG();
    }
    else 
    {

    return code.getR();
    }
}
int HSV::calculateCMin(RGB code)
{
    if(code.getB()<code.getG())
    {
        if(code.getB()<code.getR())
        {
            return code.getB();
        }
    }
    else if(code.getG()<code.getR())
    {
        return code.getB();
    }
    else 
    return code.getR();
}
int HSV::calculateRange()
{
    return cMax-cMin;
}
void HSV::setCMax(const int &x)
{
    std::cout<<"Tutaj jestem"<<x<<" ";
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
int HSV::getCMax()
{
    return cMax;
}
int HSV::getCMin()
{
    return cMin;
}

