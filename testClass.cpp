#include "testClass.hpp"
#include "HSV.hpp"


Test* Test::pointerToObject=nullptr;

void Test::runTests()
{
    RGB code(0,0,0);
    HSV result = result.convertToHSV(code);
    if(result.getH()==0 
    && result.getS()==0 
    && result.getV()==0)
    {
        std::cout<<"Test przeszedł!\n";
    }
    RGB codeOne(50,50,50);
    result=result.convertToHSV(codeOne);
    if(result.getH()==0 
    && result.getS()==0 
    && result.getV()-19.6<1)
    {
        std::cout<<"Test drugi przeszedł!\n";
    }
    RGB codeTwo(225,225,225);
    result=result.convertToHSV(codeTwo);
    std::cout<<result.getCMax();
    if(result.getH()==0 
    && result.getS()==0 
    && result.getV()-100<1 
    && result.getRange()==250 
    && result.getCMin()==0 
    && result.getCMax()==250
    )
    {
        std::cout<<"Trzeci test działa!";
    }
    std::cout<<"Testy dzialaja! \n";
}

Test* Test::getInstance()
{
    if(pointerToObject == nullptr)
    {
        pointerToObject = new Test();
    }
    
    return pointerToObject;
}
