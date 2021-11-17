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
void setR(int r_);
void setG(int g_);
void setB(int B_);
bool operator== (const RGB &code);

};