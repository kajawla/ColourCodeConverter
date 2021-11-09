#include "testClass.hpp"



Test* Test::pointerToObject=nullptr;

void Test::runTests()
{
    Converter converter;
    RGB code(0,0,0);
    HSV resulT = converter.convertToHSV(code);
    if(resulT.getH()==0 
    && resulT.getS()==0 
    && resulT.getV()==0)
    {
        std::cout<<"Test przeszedł!\n";
    }
    else 
        std::cout<<"Test nie przeszedł! \n";
    RGB codeOne(50,50,50);
    resulT=converter.convertToHSV(codeOne);
    if(resulT.getH()==0 
    && resulT.getS()==0 
    && resulT.getV()-19.6<1)
    {
        std::cout<<"Test drugi przeszedł!\n";
    }
    else 
        std::cout<<"Test drugi nie przeszedł! \n";
    std::cout<<"Trzeci test \n";
    RGB codeTwo(255,255,255);
    HSV resultTwo=converter.convertToHSV(codeTwo);
    
    if(resultTwo.getH()==0 
    && resultTwo.getS()==0 
    && resultTwo.getV()-100<1 
    )
    {
        std::cout<<"Trzeci test działa!\n";
    }
    else 
        std::cout<<"Test trzeci nie przeszedł! \n";
    std::cout<<"Test trzeci \n";
    RGB codeThree(0,0,255);
    HSV resultThree=converter.convertToHSV(codeThree);
    if(abs(resultThree.getH()-240)<1
    && abs(resultThree.getS()-100)<1 
    && abs(resultThree.getV()-100)<1
    )
    {
        std::cout<<"Czwarty test działa!\n";
    }
    else 
        std::cout<<"Test czwartek nie przeszedł! \n";
    std::cout<<"Test piąty \n";
    RGB codeFour(128,128,0);
    HSV resultFour=converter.convertToHSV(codeFour);
    if(abs(resultFour.getH()-60)<1
    && abs(resultFour.getS()-100)<1 
    && abs(resultFour.getV()-50)<1
    )
    {
        std::cout<<"Piąty test działa!\n";
    }
    else 
        std::cout<<"Test piąty nie przeszedł! \n";
    
    std::cout<<"Test szósty \n";
    RGB codeFive(128,0,50);
    HSV resultFive=converter.convertToHSV(codeFive);
    if(abs(resultFive.getH()-337)<1
    && abs(resultFive.getS()-100)<1 
    && abs(resultFive.getV()-50)<1
    )
    {
        std::cout<<"Szósty test działa!\n";
    }
    else 
        std::cout<<"Test szósty nie przeszedł! \n";
    std::cout<<"Test siódmy \n";
    HSV codeSix(0,0,0);
   
    RGB resultSix=converter.convertToRGB(codeSix);
    if(resultSix.getB()==0
    && resultSix.getR()==0
    && resultSix.getG()==0)
    {
        std::cout<<"Test siódmy przeszedł!\n";
    }
    else 
        std::cout<<"Test siódmy nie przeszedł! \n";
    std::cout<<"Test ósmy \n";
    HSV codeSeven(130,20,20);
    RGB resultSeven=converter.convertToRGB(codeSeven);
    if(resultSeven.getR()==41
    && resultSeven.getG()==51
    && resultSeven.getB()==43)
    {
        std::cout<<"Test ósmy przechodzi! \n";
    }
    else 
        std::cout<<"Test ósmy nie przeszedł! \n";

    
}

Test* Test::getInstance()
{
    if(pointerToObject == nullptr)
    {
        pointerToObject = new Test();
    }
    
    return pointerToObject;
}
