#include "RGB.hpp"

int RGB::getR() const
{
    return r;
}

int RGB::getB() const
{
    return b;
}

int RGB::getG() const
{
    return g;
}

bool RGB::operator== (const RGB& code)
{
    /*return (r == code.getR()
        && g == code.getG()
        && b == code.getB()) ? true : false;
        */

    if (r == code.getR()
        && g == code.getG()
        && b == code.getB())
    {
        return true;
    }

    return false;
        

}