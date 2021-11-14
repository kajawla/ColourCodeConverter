#include "HSV.hpp"

using namespace converterRGB;

    HSV convertToHSV(RGB code)
    {
        HSV resultR(0, 0, 0);
        resultR.setCMin(calculateCMin(code));
        resultR.setCMax(calculateCMax(code));
        resultR.setRange(resultR.calculateRange());
        float h = calculateH(code, resultR);
        float s = calculateS(resultR);
        int vInt = resultR.getCMax() * 100;
        double v = round(vInt / 100.0);
        HSV result(h, s, v);
        return result;
    }

    float calculateCMax(RGB code)
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

    float calculateCMin(RGB code)
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

    float calculateH(RGB code, HSV codeTwo)
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
            resultMultiplied = 60.0 * (((rPrim - gPrim) / range) + 4) * 100.0;
            return resultMultiplied / 100.0;
        }
        if (abs(cMax - gPrim) < 1)
        {
            resultMultiplied = 60.0 * (((bPrim - rPrim) / range) + 2.0) * 100.0;
            return resultMultiplied / 100.0;
        }
        if (abs(cMax - rPrim) < 1)
        {
            float result = 60.0 * fmod(((gPrim - bPrim) / range), 6.0);
            if (result < 0)
            {
                resultMultiplied = (360.0 + result) * 100.0;
                return resultMultiplied / 100;
            }
            else

                resultMultiplied = 60 * fmod(((gPrim - bPrim) / range), 6) * 100;
            return resultMultiplied / 100;
        }
    }

    float calculateS(HSV code)
    {
        if (code.getCMax() == 0)
        {
            return 0;
        }
        else
            return (code.getRange() / code.getCMax()) * 100.0;
    }

    /* float converterRGB::calculateRange()
     {
         return cMax - cMin;
     }
     */
