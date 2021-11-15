#pragma once
class RGB
{
private:

int r;
int g;
int b;

public:
RGB(int _r, int _g, int _b):r{_r},g{_g},b{_b}{};
int getR() const;
int getG() const;
int getB() const;
bool operator== (const RGB &code);

};