#include "converterRGB.hpp"

namespace converterRGB {

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

    float calculateRPrim(RGB code)
    {
        return code.getR() / 255.0 * 100.0;
    }

    float calculateGPrim(RGB code)
    {
        return code.getG() / 255.0 * 100.0;
    }

    float calculateBPrim(RGB code)
    {
        return code.getB() / 255.0 * 100.0;
    }

    /* float converterRGB::calculateRange()
     {
         return cMax - cMin;
     }
     */

    HEX convertToHEX(RGB code)
    {
        std::string hexCode = "";
        hexCode+=calculateCodePart(code.getR());
        hexCode += calculateCodePart(code.getG());
        hexCode += calculateCodePart(code.getB());
        HEX result(hexCode);
        return result;
    }
    
    std::string calculateCodePart(int codePart)
    {
        int code = codePart;
        std::string result = "";
        if (code != 0)
        {
            while (code != 0)
            {
                switch (code % 16)
                {
                case 15:
                    result += "F";
                    code -= code % 16;
                    code = code / 16;
                    break;
                case 14:
                    result += "E";
                    code -= code % 16;
                    code = code / 16;
                    break;
                case 13:
                    result += "D";
                    code -= code % 16;
                    code = code / 16;
                    break;
                case 12:
                    result += "C";
                    code -= code % 16;
                    code = code / 16;
                    break;
                case 11:
                    result += "B";
                    code -= code % 16;
                    code = code / 16;
                    break;
                case 10:
                    result += "A";
                    code -= code % 16;
                    code = code / 16;
                    break;
                default:
                    result = result + std::to_string(code % 16);
                    code -= code % 16;
                    code = code / 16;
                }

            }
            std::reverse(result.begin(), result.end());
            return result;
        }
           
        return "00";
    }
}