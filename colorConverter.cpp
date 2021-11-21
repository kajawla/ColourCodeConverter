#include "colorConverter.hpp"

namespace colorConverter
{
	 HSV convertToHSV(const RGB &code)
    {
        HSV result;
        result.setCMin(calculateCMin(code));
        result.setCMax(calculateCMax(code));
        result.setRange(result.calculateRange());
        result.setH(calculateH(code, result));
        result.setS(round(calculateS(result)));
        int vInt = result.getCMax() * 100;
        result.setV(round(vInt / 100.0));
        return result;
    }

    float calculateCMax(const RGB& code)
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

    float calculateCMin(const RGB& code)
    {
        if (code.getB() < code.getR() && code.getB() < code.getG())
        {

            return calculateBPrim(code);
        
        }
        else if (code.getG() < code.getR() && code.getG() < code.getB())
        {
            return calculateGPrim(code);
        }
        else
            return calculateRPrim(code);
    }

    float calculateH(const RGB &code, const HSV &codeTwo)
    {
        if (codeTwo.getRange() == 0)
        {
            return 0;
        }
        const float gPrim = calculateGPrim(code);
        const float bPrim = calculateBPrim(code);
        const float rPrim = calculateRPrim(code);
        const float range = codeTwo.getRange();
        const float cMax = codeTwo.getCMax();
        int resultMultiplied = 0;
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
            resultMultiplied = 60 * fmod(((gPrim - bPrim) / range), 6) * 100;
            if (resultMultiplied < 0)
            {
                resultMultiplied = 36000.0 + resultMultiplied;
                return ceil(resultMultiplied / 100);
            }
            else
            {
                return ceil(resultMultiplied / 100);
            }
        }
    }

    inline float calculateS(const HSV &code)
    {
        return code.getCMax()==0? 0: (code.getRange() / code.getCMax()) * 100.0;
    }

    inline float calculateRPrim(const RGB &code)
    {
        return code.getR() / 255.0 * 100.0;
    }

    inline float calculateGPrim(const RGB &code)
    {
        return code.getG() / 255.0 * 100.0;
    }

    inline float calculateBPrim(const RGB& code)
    {
        return code.getB() / 255.0 * 100.0;
    }

    RGB convertToRGB(const HSV& code)
    {
        RGB result;
        const float c = calculateC(code);
        const float x = calculateX(code, c);
        const float m = (code.getV() / 100) - c;
        const float h = code.getH();
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

    inline float calculateC(const HSV& code)
    {
        return (code.getS() / 100.0) * (code.getV() / 100.0);
    }

    inline float calculateX(const HSV& code, float c)
    {
        return c * (1.0 - fabs(fmod((code.getH() / 60.0), 2.0) - 1.0));
    }

    RGB convertToRGB(const HEX& code)
    {
        std::string popingCode = code.getCode();
        RGB result(calculateRGBPart(popingCode), calculateRGBPart(popingCode), calculateRGBPart(popingCode));   
        return result;
    }

    int calculateRGBPart(std::string& code)
    {
        int result = 0;
        for (int i = 0; i < 2; i++)
        {
            if (std::isdigit(code.back()))
            {
                result += (code.back() - '0') * pow(16,i);
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
    HEX convertToHEX(const HSV &code)
    {
        std::string hexCode = "";
        RGB converterIntoRGB = convertToRGB(code);
        hexCode += calculateCodePart(converterIntoRGB.getR());
        hexCode += calculateCodePart(converterIntoRGB.getG());
        hexCode += calculateCodePart(converterIntoRGB.getB());
        HEX result(hexCode);
        return result;
    }

    

    HEX convertToHEX(const RGB &code)
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
    HSV convertToHSV(const HEX& code)
    {
       RGB converted = convertToRGB(code);
       HSV result = convertToHSV(converted);
       return result;
    }
}