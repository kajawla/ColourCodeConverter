#include "converter.hpp"

HSV Converter::convertToHSV(RGB code)
{
    HSV resultR(0,0,0);
    resultR.setCMin(resultR.calculateCMin(code));
    resultR.setCMax(resultR.calculateCMax(code));
    resultR.setRange(resultR.calculateRange());
    HSV result(resultR.calculateH(code),resultR.calculateS(),resultR.calculateV());
    return result;
}

RGB Converter::convertToRGB(HSV code)
{
    RGB result(0,0,0);
    float c;
    float x;
    float m;
    float h=code.getH();
    c=calculateC(code);
    x=calculateX(code,c);
    m=(code.getV()/100)-c;
    if(h>=0 && h<60)
    {   
        RGB result(round((c+m)*255),round((x+m)*255),round(m*255));
        return result;
    }
    if(h>=60 && h<120)
    {
        RGB result(round((x+m)*255),round((c+m)*255),round(m*255));
        return result;
    }
    if(h>=120 && h<180)
    {
        RGB result(round(m*255),round((c+m)*255),round((x+m)*255));
        return result;
    }
    if(h>=180 && h<240)
    {
        RGB result(round(m*255),round((x+m)*255),round((c+m)*255));
        return result;
    }
    if(h>=240 && h<300)
    {
        RGB result(round((x+m)*255),round(m*255),round((c+m)*255));
        return result;
    }
    if(h>=300 && h<360)
    {
        RGB result(round((x+m)*255),round(m*255),round((c+m)*255));
        return result;
    }
    return result;
}

float Converter::calculateC(HSV code)
{
    return (code.getS()/100)*(code.getV()/100);
}

float Converter::calculateX(HSV code, float c)
{
    return c*(1-fabs(fmod((code.getH()/60),2)-1));
}

float Converter::calculateCMin(RGB code)
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