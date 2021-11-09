#include "HSV.hpp"

float HSV::getH()
{
    return h;
}

float HSV::getS()
{
    return s;
}

float HSV::getV()
{
    return v;
}

float HSV::calculateRPrim(RGB code)
{
    return code.getR()/255.0*100;
}

float HSV::calculateGPrim(RGB code)
{
    return code.getG()/255.0*100;
}

float HSV::calculateBPrim(RGB code)
{
    return code.getB()/255.0*100;
}

float HSV::calculateV()
{   
    return cMax;
}

float HSV::calculateS()
{
    if(cMax==0)
    {
        return 0;
    }
    else 
        return (range/cMax)*100;
}

float HSV::calculateH(RGB code)
{
    float gPrim=calculateGPrim(code);
    float bPrim=calculateBPrim(code);
    float rPrim=calculateRPrim(code);
    if(range==0)
    {
        return 0;
    }
    if(abs(cMax-bPrim)<1)
    {
       return 60*(((rPrim-gPrim)/range)+4);
    }
    if(abs(cMax-gPrim)<1)
    {   
        return 60*(((bPrim-rPrim)/range)+2);
    }
    if(abs(cMax-rPrim)<1)
    {
        float result=60*fmod(((gPrim-bPrim)/range),6);
        if(result<0)
        {
            return 360+result;
        }
        else
        return 60*fmod(((gPrim-bPrim)/range),6);
    }
    
}

float HSV::calculateCMax(RGB code)
{
    if(code.getB()>code.getG())
    {
        if(code.getB()>code.getR())
        { 
            return calculateBPrim(code);
        }
    }
    if(code.getG()>code.getR())
    {
        
        return calculateGPrim(code);
    }
    else 
    {
        return calculateRPrim(code);
    }
}

float HSV::calculateCMin(RGB code)
{
    if(code.getB()<code.getG())
    {
        if(code.getB()<code.getR() && code.getB()<code.getG())
        {
            
            return calculateBPrim(code);
        }
    }
    else if(code.getG()<code.getR() && code.getG()<code.getB())
    {
        return calculateGPrim(code);
    }
    else 
    return calculateRPrim(code);
}

int HSV::calculateRange()
{
    return cMax-cMin;
}

void HSV::setCMax(const int& x)
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

int HSV::getCMax()
{
    return cMax;
}

const int HSV::getCMin()
{
    return cMin;
}

