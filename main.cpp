#include "testClass.hpp"

int main()
{
    Test* tests=Test::getInstance();
    tests->runTests();
    
    return 0;
}