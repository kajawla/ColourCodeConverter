#include "converter.hpp"


HSV Converter::convertToHSV(RGB code)
{
    HSV resultR(0, 0, 0);
    resultR.setCMin(calculateCMin(code));
    resultR.setCMax(calculateCMax(code));
    resultR.setRange(resultR.calculateRange());
    float h=calculateH(code,resultR);
    float s=calculateS(resultR);
    int vInt = resultR.getCMax()*100;
    double v = round(vInt / 100.0);
    HSV result(h, s, v);
    return result;
}

float Converter::calculateCMax(RGB code)
{
    if (code.getB() > code.getG())
    {
        if (code.getB() > code.getR())
        {
            return calculateBPrim(code);
        }
    }
    if (code.getG() > code.getR())
    {

        return calculateGPrim(code);
    }
    else
    {
        return calculateRPrim(code);
    }
}

float Converter::calculateCMin(RGB code)
{
    if (code.getB() < code.getG())
    {
        if (code.getB() < code.getR() && code.getB() < code.getG())
        {

            return calculateBPrim(code);
        }
    }
    else if (code.getG() < code.getR() && code.getG() < code.getB())
    {
        return calculateGPrim(code);
    }
    else
        return calculateRPrim(code);
}

float Converter::calculateRPrim(RGB code)
{
    return code.getR() / 255.0 * 100.0;
}

float Converter::calculateGPrim(RGB code)
{
    return code.getG() / 255.0 * 100.0;
}

float Converter::calculateBPrim(RGB code)
{
    return code.getB() / 255.0 * 100.0;
}

float Converter::calculateS(HSV code)
{
    if (code.getCMax() == 0)
    {
        return 0;
    }
    else
        return (code.getRange() / code.getCMax()) * 100.0;
}

float Converter::calculateH(RGB code, HSV codeTwo)
{
    float gPrim = calculateGPrim(code);
    float bPrim = calculateBPrim(code);
    float rPrim = calculateRPrim(code);
    float range = codeTwo.getRange();
    float cMax = codeTwo.getCMax();
    float smallres = (gPrim - bPrim) / range;
    float sixty = fmod((gPrim - bPrim / cMax), 6.0);
    int resultMultiplied;
    if (range == 0)
    {
        return 0;
    }
    if (abs(cMax - bPrim) < 1)
    {
        resultMultiplied = 60.0 * (((rPrim - gPrim) / range) + 4)*100.0;
        return resultMultiplied/100.0;
    }
    if (abs(cMax - gPrim) < 1)
    {
        resultMultiplied= 60.0 * (((bPrim - rPrim) / range) + 2.0)*100.0;
        return resultMultiplied / 100.0;
    }
    if (abs(cMax - rPrim) < 1)
    {
        float result = 60.0 * fmod(((gPrim - bPrim) / range), 6.0);
        if (result < 0)
        {
            resultMultiplied = (360.0 + result)*100.0;
            return resultMultiplied / 100;
        }
        else
            
            resultMultiplied = 60 * fmod(((gPrim - bPrim) / range), 6)*100;
            return resultMultiplied / 100;
    }
}
RGB Converter::convertToRGB( code)
{
    RGB result(0, 0, 0);
    float c;
    float x;
    float m;
    float h = code.getH();
    c = calculateC(code);
    x = calculateX(code, c);
    m = (code.getV() / 100) - c;
    if (h >= 0 && h < 60)
    {
        RGB result(round((c + m) * 255), round((x + m) * 255), round(m * 255));
        return result;
    }
    if (h >= 60 && h < 120)
    {
        RGB result(round((x + m) * 255), round((c + m) * 255), round(m * 255));
        return result;
    }
    if (h >= 120 && h < 180)
    {
        RGB result(round(m * 255), round((c + m) * 255), ceil((x + m) * 255));
        return result;
    }
    if (h >= 180 && h < 240)
    {
        RGB result(round(m * 255), round((x + m) * 255), round((c + m) * 255));
        return result;
    }
    if (h >= 240 && h < 300)
    {
        RGB result(round((x + m) * 255), round(m * 255), round((c + m) * 255));
        return result;
    }
    if (h >= 300 && h <= 360)
    {
        RGB result(round((c + m) * 255), round(m * 255), round((x + m) * 255));
        return result;
    }
    return result;
}

float Converter::calculateC(HSV code)
{
    return (code.getS() / 100.0) * (code.getV() / 100.0);
}

float Converter::calculateX(HSV code, float c)
{
    return c * (1.0 - fabs(fmod((code.getH() / 60.0), 2.0) - 1.0));
}



