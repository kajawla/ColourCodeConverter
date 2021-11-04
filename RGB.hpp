class RGB
{
private:
char type ='R';
int r;
int g;
int b;

public:
RGB(int _r, int _g, int _b):r{_r},g{_g},b{_b}{};
int getR();
int getG();
int getB();


};