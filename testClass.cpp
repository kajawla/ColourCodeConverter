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
    std::cout<<"Trzeci test \n";
    RGB codeTwo(255,255,255);
    HSV resultTwo=resultTwo.convertToHSV(codeTwo);
    
    if(resultTwo.getH()==0 
    && resultTwo.getS()==0 
    && resultTwo.getV()-100<1 
    )
    {
        std::cout<<"Trzeci test działa!";
    }
    std::cout<<"Test trzeci \n";
    RGB codeThree(0,0,255);
    HSV resultThree=resultThree.convertToHSV(codeThree);
    if(abs(resultThree.getH()-240)<1
    && abs(resultThree.getS()-100)<1 
    && abs(resultThree.getV()-100)<1
    )
    {
        std::cout<<"Czwarty test działa!\n";
    }
    std::cout<<"Test piąty \n";
    RGB codeFour(128,128,0);
    HSV resultFour=resultFour.convertToHSV(codeFour);
   if(abs(resultFour.getH()-60<1
    && abs(resultFour.getS()-100)<1 
    && abs(resultFour.getV()-50)<1
    ))
    {
        std::cout<<"Piąty test działa!\n";
    }
}

Test* Test::getInstance()
{
    if(pointerToObject == nullptr)
    {
        pointerToObject = new Test();
    }
    
    return pointerToObject;
}
