#include "testClass.hpp"
#include "colorConverter.hpp"
#include "HEX.hpp"
#include "HSV.hpp"
#include "RGB.hpp"

Test* Test::pointerToObject=nullptr;

void Test::runTests()
{
    if (checkIfGivenHSVThatIsZeroReturnsRGBZero())
    {
        std::cout << "checkIfGivenHSVThatIsZeroReturnsRGBZero is PASSING\n";
    }
    else
    {
        std::cout << "checkIfGivenHSVThatIsZeroReturnsRGBZero is FAILING \n";
    }

    if (checkIfGivenRGBNotZeroReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenRGBNotZeroReturnsCorrectHSV is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenRGBNotZeroReturnsCorrectHSV is FALINING \n";
    }

    if (checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero())
    {
        std::cout << "checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero is FAILING \n";
    }

    if (checkIfGivenHSVMaxReturnsCorretsRGB())
    {
        std::cout << "checkIfGivenHSVMaxReturnsCorretsRGB is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenMaxHSVReturnsCorretsRGB is FAILING \n";
    }

    if (checkIfGivenRGBZeroReturnsHSVZero())
    {
        std::cout << "checkIfGivenRGBZeroReturnsHSVZero is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenRGBZeroReturnsHSVZero is FALING \n";
    }

    if (checkIfGivenRGBMaxReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenRGBMaxReturnsCorrectHSV is PASING \n";
    }
    else
    {
        std::cout << "checkIfGivenRGBMaxReturnsCorrectHSV is FAILING \n";
    }

    if (checkIfGivenRGBZeroReturnZeroHex())
    {
        std::cout << "checkIfGivenRGBZeroReturnZeroHex is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenRGBZeroReturnZeroHex is FAILING \n";
    }

    if (checkIfGivenMaxRGBReturnsMaxHEX())
    {
        std::cout << "checkIfGivenMaxRGBReturnsMaxHEX is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenMaxRGBReturnsMaxHEX is FAILING \n";
    }

    if (checkifGivenRGBReturnsCorrectHEX())
    {
        std::cout << "checkifGivenRGBReturnsCorrectHex is PASSING \n";
    }
    else
    {
        std::cout << "checkifGivenRGBReturnsCorrectHex is FALINING \n";
    }

    if (checkIfGivenHSVZeroReturnsZeroHEX())
    {
        std::cout << "checkIfGivenHSVZeroReturnsZeroHEX is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenHSVZeroReturnsZeroHEX is FAILING \n";
    }

    if (checkIfGivenHSVMaxReturnCorrectHEX())
    {
        std::cout << "checkIfGivenHSVMaxReturnCorrectHEX is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenHSVMaxReturnCorrectHEX is FAILING \n";
    }

    if (checkIfGivenHSVReturnsCorrectHEX())
    {
        std::cout << "checkIfGivenHSVReturnsCorrectHEX is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenHSVReturnsCorrectHEX is FAILING \n";
    }

    if (checkIfGivenHEXZeroReturnCorrectRGB())
    {
        std::cout << "checkIfGivenHEXZeroReturnCorrectRGB is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenHEXZeroReturnCorrectRGB is FAILING \n";
    }

    if (checkIfGivenMaxHEXReturnsCorrectRGB())
    {
        std::cout << "checkIfGivenMaxHEXReturnsCorrectRGB is PASSING \n";
    }
    else
    {
        std::cout << "checkIfGivenMaxHEXReturnsCorrectRGB is FAILING \n";
    }

    if (checkIfGivenHEXReturnsCorrectRGB())
    {
        std::cout << "checkIfGivenHEXReturnsCorrectRGB is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHEXReturnsCorrectRGB is FAILING \n";

    if (checkIfGivenZeroHEXReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenZeroHEXReturnsCorrectHSV is PASSING \n";
    }
    else
        std::cout << "checkIfGivenZeroHEXReturnsCorrectHSV is FAILING \n";

    if (checkIfGivenHexReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenHexReturnsCorrectHSV is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHexReturnsCorrectHSV is FAILING \n";

    if (checkIfGivenMaxHEXReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenMaxHEXReturnsCorrectHSV is PASSING \n";
    }
    else
        std::cout << "checkIfGivenMaxHEXReturnsCorrectHSV is FAILING \n";
}

bool Test::checkIfGivenMaxHEXReturnsCorrectHSV()
{
    HSV expected(0, 0, 100);
    HEX codeGiven("FFFFFF");
    HSV result = colorConverter::convertToHSV(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHexReturnsCorrectHSV()
{
    HSV expected(96, 70, 45);
    HEX codeGiven("437322");
    HSV result = colorConverter::convertToHSV(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenZeroHEXReturnsCorrectHSV()
{
    HSV expected(0, 0, 0);
    HEX codeGiven("000000");
    HSV result = colorConverter::convertToHSV(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHEXReturnsCorrectRGB()
{
    RGB expected(174, 23, 65);
    HEX codeGiven("AE1741");
    RGB result = colorConverter::convertToRGB(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenMaxHEXReturnsCorrectRGB()
{
    RGB expected(255, 255, 255);
    HEX codeGiven("FFFFFF");
    RGB result = colorConverter::convertToRGB(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHEXZeroReturnCorrectRGB() 
{
    RGB expected(0, 0, 0);
    HEX codeGiven("000000");
    RGB result = colorConverter::convertToRGB(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;

}

bool Test::checkIfGivenHSVReturnsCorrectHEX()
{
    HEX expeced("293652");
    HSV codeGiven(220, 50, 32);
    HEX result = colorConverter::convertToHEX(codeGiven);
    if (expeced == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHSVMaxReturnCorrectHEX()
{
    HEX expeced("FF0000");
    HSV codeGiven(360, 100, 100);
    HEX result = colorConverter::convertToHEX(codeGiven);
    if (expeced == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHSVZeroReturnsZeroHEX()
{
    HEX expeced("000000");
    HSV codeGiven(0, 0, 0);
    HEX result = colorConverter::convertToHEX(codeGiven);
    if (expeced == result)
    {
        return true;
    }
    return false;
}

bool Test::checkifGivenRGBReturnsCorrectHEX()
{
    HEX expected("861741");
    RGB codeGiven(134, 23, 65);
    HEX result = colorConverter::convertToHEX(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenMaxRGBReturnsMaxHEX()
{
    HEX expected("FFFFFF");
    RGB codeGiven(255, 255, 255);
    HEX result = colorConverter::convertToHEX(codeGiven);
    if (expected == result)
    {
        return true;
    }
    return false;

}

bool Test::checkIfGivenRGBZeroReturnZeroHex()
{
    HEX expectedZeroHex("000000");
    RGB codeGiven(0, 0, 0);
    HEX result = colorConverter::convertToHEX(codeGiven);

    if (result == expectedZeroHex)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenRGBNotZeroReturnsCorrectHSV()
{

    RGB code(120, 30, 40);
    HSV expected(353, 75, 47);
    
    HSV result = colorConverter::convertToHSV(code);
    if (result == expected)
    {
        return true;
    }
    else
        return false;
}  

bool Test::checkIfGivenHSVMaxReturnsCorretsRGB()
{
  
    HSV code(360, 100, 100);
    RGB expected(255, 0, 0);
    RGB result = colorConverter::convertToRGB(code);
    if (result == expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenRGBMaxReturnsCorrectHSV()
{

    RGB code(255, 255, 255);
    HSV expected(0, 0, 100);
    HSV result = colorConverter::convertToHSV(code);
    if (result==expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenRGBZeroReturnsHSVZero()
{

    RGB code(0, 0, 0);
    HSV expected(0, 0, 0);
    HSV result = colorConverter::convertToHSV(code);
    if (result==expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHSVThatIsZeroReturnsRGBZero()
{

    HSV code(0, 0, 0);
    RGB expected(0, 0, 0);
    RGB result = colorConverter::convertToRGB(code);
    if (result == expected)
    {
        return true;
    }
    else
        return false;
}

bool Test::checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero()
{
 
    HSV code(130, 20, 20);
    RGB expected(41, 51, 43);
    RGB result = colorConverter::convertToRGB(code);
    if (result == expected)
    {
        return true;
    }
    else
        return false;
}

Test* Test::getInstance()
{
    if(pointerToObject == nullptr)
    {
        pointerToObject = new Test();
    }
    
    return pointerToObject;
}
