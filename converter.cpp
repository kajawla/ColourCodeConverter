#include "converter.hpp"

/*HSV Converter::convertToHSV(RGB code)
{
    
    result.setCMin(result.calculateCMin(code));
    result.setCMax(result.calculateCMax(code));
    result.setRange(result.calculateRange());
    RGB result(result.calculateH(code),result.calculateS(),result.calculateV());
    return result;
}
*/
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