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


};