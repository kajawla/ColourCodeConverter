#include "testClass.hpp"
#include "converterRGB.hpp"
#include "converterHSV.hpp"

Test* Test::pointerToObject=nullptr;

void Test::runTests()
{
    if(checkIfGivenHSVThatIsZeroReturnsRGBZero())
    {
        std::cout<<"checkIfGivenHSVThatIsZeroReturnsRGBZero is PASSING\n";
    }
    else 
        std::cout<<"checkIfGivenHSVThatIsZeroReturnsRGBZero is FAILING \n";

    if (checkIfGivenRGBNotZeroReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenRGBNotZeroReturnsCorrectHSV is PASSING \n";
    }
    else
        std::cout << "checkIfGivenRGBNotZeroReturnsCorrectHSV is FALINING \n";

    if (checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero())
    {
        std::cout << "checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero is FAILING \n";
    
    if (checkIfGivenHSVMaxReturnsCorretsRGB())
    {
        std::cout << "checkIfGivenHSVMaxReturnsCorretsRGB is PASSING \n";
    }
    else
        std::cout << "checkIfGivenMaxHSVReturnsCorretsRGB is FAILING \n";

    if (checkIfGivenRGBZeroReturnsHSVZero())
    {
        std::cout << "checkIfGivenRGBZeroReturnsHSVZero is PASSING \n";
    }
    else
        std::cout << "checkIfGivenRGBZeroReturnsHSVZero is FALING \n";

    if (checkIfGivenRGBMaxReturnsCorrectHSV())
    {
        std::cout << "checkIfGivenRGBMaxReturnsCorrectHSV is PASING \n";
    }
    else
        std::cout << "checkIfGivenRGBMaxReturnsCorrectHSV is FAILING \n";

    if (checkIfGivenRGBZeroReturnZeroHex())
    {
        std::cout << "checkIfGivenRGBZeroReturnZeroHex is PASSING \n";
    }
    else
        std::cout << "checkIfGivenRGBZeroReturnZeroHex is FAILING \n";
    
    if (checkIfGivenMaxRGBReturnsMaxHEX())
    {
        std::cout << "checkIfGivenMaxRGBReturnsMaxHEX is PASSING \n";
    }
    else
        std::cout << "checkIfGivenMaxRGBReturnsMaxHEX is FAILING \n";

    if (checkifGivenRGBReturnsCorrectHEX())
    {
        std::cout << "checkifGivenRGBReturnsCorrectHex is PASSING \n";
    }
    else
        std::cout << "checkifGivenRGBReturnsCorrectHex is FALINING \n";

    if (checkIfGivenHSVZeroReturnsZeroHEX())
    {
        std::cout << "checkIfGivenHSVZeroReturnsZeroHEX is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHSVZeroReturnsZeroHEX is FAILING \n";

    if (checkIfGivenHSVMaxReturnCorrectHEX())
    {
        std::cout << "checkIfGivenHSVMaxReturnCorrectHEX is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHSVMaxReturnCorrectHEX is FAILING \n";

    if (checkIfGivenHSVReturnsCorrectHEX())
    {
        std::cout << "checkIfGivenHSVReturnsCorrectHEX is PASSING \n";
    }
    else
        std::cout << "checkIfGivenHSVReturnsCorrectHEX is FAILING \n";
}

bool Test::checkIfGivenHSVReturnsCorrectHEX()
{
    HEX expeced("293652");
    HSV codeGiven(220, 50, 32);
    HEX result = converterHSV::convertToHEX(codeGiven);
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
    HEX result = converterHSV::convertToHEX(codeGiven);
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
    HEX result = converterHSV::convertToHEX(codeGiven);
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
    HEX result = converterRGB::convertToHEX(codeGiven);
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
    HEX result = converterRGB::convertToHEX(codeGiven);
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
    HEX result = converterRGB::convertToHEX(codeGiven);

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
    
    HSV result = converterRGB::convertToHSV(code);

    std::cout << result.getV();
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
    RGB result = converterHSV::convertToRGB(code);
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
    HSV result = converterRGB::convertToHSV(code);
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
    HSV result = converterRGB::convertToHSV(code);
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
    RGB result = converterHSV::convertToRGB(code);
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
    RGB result = converterHSV::convertToRGB(code);
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
