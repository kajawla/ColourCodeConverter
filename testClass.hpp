#include "converter.hpp"

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
    void checkIfGivenRGBZeroReturnZeroHex();
    bool checkIfGivenRGBZeroReturnsHSVZero();
    bool checkIfGivenRGBMaxReturnsCorrectHSV();
    bool checkIfGivenHSVMaxReturnsCorretsRGB();
    bool checkIfGivenRGBNotZeroReturnsCorrectHSV();
};