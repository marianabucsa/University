#include <iostream>
#include <conio.h>

using namespace std;

class complex
{
private:
	struct c
	{
		double re;
		double im;
	};
public:
	complex(double x, double y) { c.re = x; c.im = y; };

};