#include"converterHSV.hpp"

namespace converterHSV
{
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

    HEX convertToHEX(HSV code)
    {
        std::string hexCode = "";
        RGB converterIntoRGB=convertToRGB(code);
        hexCode += calculateCodePart(converterIntoRGB.getR());
        hexCode += calculateCodePart(converterIntoRGB.getG());
        hexCode += calculateCodePart(converterIntoRGB.getB());
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
