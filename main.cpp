#include "testClass.hpp"
#include"converternamespace.hpp"


int main()
{
    Test* tests=Test::getInstance();
    tests->runTests();
    

}