#include "testClass.hpp"



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


}
/*
void Test::checkIfGivenRGBZeroReturnZeroHex()
{
    Converter converter;
    HEX expectedZeroHex(0,0,0);
    RGB codeGiven(0, 0, 0);
    HEX result = converter.convertToRGB(codeGiven);

    if (result == expectedZeroHex)
    {
        std::cout << "checkIfGivenRGBZeroReturnZeroHex is PASSING! \n";
    }
    else
        std::cout<< "checkIfGivenRGBZeroReturnZeroHex FAILING! \n";
}*/
bool Test::checkIfGivenRGBNotZeroReturnsCorrectHSV()
{
    Converter converter;
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
    Converter converter;
    HSV code(360, 100, 100);
    RGB expected(255, 0, 0);
    RGB result = converter.convertToRGB(code);
    if (result == expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenRGBMaxReturnsCorrectHSV()
{
    Converter converter;
    RGB code(255, 255, 255);
    HSV expected(0, 0, 100);
    HSV result = converter.convertToHSV(code);
    if (result==expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenRGBZeroReturnsHSVZero()
{
    Converter converter;
    RGB code(0, 0, 0);
    HSV expected(0, 0, 0);
    HSV result = converter.convertToHSV(code);
    if (result==expected)
    {
        return true;
    }
    return false;
}

bool Test::checkIfGivenHSVThatIsZeroReturnsRGBZero()
{
    Converter converter;
    HSV code(0, 0, 0);
    RGB expected(0, 0, 0);
    RGB result = converter.convertToRGB(code);
    if (result == expected)
    {
        return true;
    }
    else
        return false;
}

bool Test::checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero()
{
    Converter converter;
    HSV code(130, 20, 20);
    RGB expected(41, 51, 43);
    RGB result = converter.convertToRGB(code);
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
