#include "colorConverter.hpp"

namespace colorConverter
{
	 HSV convertToHSV(RGB code)
    {
        HSV resultR(0, 0, 0);
        resultR.setCMin(calculateCMin(code));
        resultR.setCMax(calculateCMax(code));
        resultR.setRange(resultR.calculateRange());
        float h = calculateH(code, resultR);
        float s = round(calculateS(resultR));
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
            return ceil(resultMultiplied / 100.0);
        }
        if (abs(cMax - gPrim) < 1)
        {
            resultMultiplied = 60.0 * (((bPrim - rPrim) / range) + 2.0) * 100.0;
            return ceil(resultMultiplied / 100.0);
        }
        if (abs(cMax - rPrim) < 1)
        {
            float result = 60.0 * fmod(((gPrim - bPrim) / range), 6.0);
            if (result < 0)
            {
                resultMultiplied = (360.0 + result) * 100.0;
                return ceil(resultMultiplied / 100);
            }
            else

                resultMultiplied = 60 * fmod(((gPrim - bPrim) / range), 6) * 100;
            return ceil(resultMultiplied / 100);
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

    RGB convertToRGB(HSV code)
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

    float calculateC(HSV code)
    {
        return (code.getS() / 100.0) * (code.getV() / 100.0);
    }

    float calculateX(HSV code, float c)
    {
        return c * (1.0 - fabs(fmod((code.getH() / 60.0), 2.0) - 1.0));
    }

    RGB convertToRGB(HEX code)
    {
        std::string popingCode = code.getCode();
        RGB result(calculateRGBPart(popingCode), calculateRGBPart(popingCode), calculateRGBPart(popingCode));

        /*
        while (!popingCode.empty())
        {
            if (popingCode.size() % 2 == 0 && popingCode.size() != 6)
            {
                if (std::isdigit(popingCode.back()))
                {
                    result += popingCode.back() - '0';
                    result += 16 * popingCode.size();
                    popingCode.pop_back();
                }
                else
                {
                    switch (popingCode.back())
                    {
                    case 'A':
                        result += 10;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    case 'B':
                        result += 11;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    case 'C':
                        result += 12;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    case 'D':
                        result += 13;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    case 'E':
                        result += 14;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    case 'F':
                        result += 15;
                        result += 16 * popingCode.size();
                        popingCode.pop_back();
                        break;
                    }
                }
            }
        }
        */
        
        return result;
    }
    int calculateRGBPart(std::string& code)
    {
        int result = 0;
        for (int i = 0; i < 2; i++)
        {
                if (std::isdigit(code.back()))
                {
                    result += (code.back() - '0')*pow(16,i);
                    code.pop_back();
                }
                else
                {
                    switch (code.back())
                    {
                    case 'A':
                        result += 10 * pow(16,i);
                        code.pop_back();
                        break;
                    case 'B':
                        result += 11 * pow(16, i);
                        code.pop_back();
                        break;
                    case 'C':
                        result += 12 * pow(16, i);
                        code.pop_back();
                        break;
                    case 'D':
                        result += 13 * pow(16, i);
                        code.pop_back();
                        break;
                    case 'E':
                        result += 14 * pow(16, i);
                        code.pop_back();
                        break;
                    case 'F':
                        result += 15 * pow(16, i);
                        code.pop_back();
                        break;
                    }
                }
            
        }
        return result;
    }
    HEX convertToHEX(HSV code)
    {
        std::string hexCode = "";
        RGB converterIntoRGB = convertToRGB(code);
        hexCode += calculateCodePart(converterIntoRGB.getR());
        hexCode += calculateCodePart(converterIntoRGB.getG());
        hexCode += calculateCodePart(converterIntoRGB.getB());
        HEX result(hexCode);
        return result;
    }

    

    HEX convertToHEX(RGB code)
    {
        std::string hexCode = "";
        hexCode += calculateCodePart(code.getR());
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
    HSV convertToHSV(HEX code)
    {
       RGB converted = convertToRGB(code);
       HSV result = convertToHSV(converted);
       return result;
    }
}