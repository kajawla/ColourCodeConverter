
#pragma once
class Test
{
public:
    void runTests();
    ~Test(){};
    static Test *getInstance();

private:
    Test(){};
    static Test *pointerToObject;
    bool checkIfGivenHSVThatIsZeroReturnsRGBZero();
    bool checkIfGivenHSVThatIsNotZeroReturnsRGBNotZero();
    bool checkIfGivenRGBZeroReturnZeroHex();
    bool checkIfGivenRGBZeroReturnsHSVZero();
    bool checkIfGivenRGBMaxReturnsCorrectHSV();
    bool checkIfGivenHSVMaxReturnsCorretsRGB();
    bool checkIfGivenRGBNotZeroReturnsCorrectHSV();
    bool checkIfGivenMaxRGBReturnsMaxHEX();
    bool checkifGivenRGBReturnsCorrectHEX();
    bool checkIfGivenHSVZeroReturnsZeroHEX();
    bool checkIfGivenHSVMaxReturnCorrectHEX();
    bool checkIfGivenHSVReturnsCorrectHEX();
    bool checkIfGivenHEXZeroReturnCorrectRGB();
    bool checkIfGivenMaxHEXReturnsCorrectRGB();
    bool checkIfGivenHEXReturnsCorrectRGB();
    bool checkIfGivenZeroHEXReturnsCorrectHSV();
    bool checkIfGivenHexReturnsCorrectHSV();
    bool checkIfGivenMaxHEXReturnsCorrectHSV();
    
};