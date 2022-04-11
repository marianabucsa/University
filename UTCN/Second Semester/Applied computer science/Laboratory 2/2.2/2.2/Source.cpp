#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Complex
{
private:
	double Re;
	double Im;

public:
	inline Complex(double re, double im) { Re = re; Im = im; };
	friend bool operator > (Complex&, Complex&);
	friend bool operator >= (Complex&, Complex&);
	friend bool operator == (Complex&, Complex&);
	friend bool operator != (Complex&, Complex&);
	friend bool operator <= (Complex&, Complex&);
	friend bool operator < (Complex&, Complex&);
	void ToString();
};
 bool operator > (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re + po.Im*po.Im) > sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
 bool operator >= (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re +po.Im *po.Im) >= sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
bool operator == (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re + po.Im * po.Im) == sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
bool operator != (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re + po.Im * po.Im) != sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
bool operator <= (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re + po.Im * po.Im) <= sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
bool operator < (Complex& po, Complex& op)
{
	if (sqrt(po.Re*po.Re + po.Im * po.Im) < sqrt(op.Re*op.Re + op.Im*op.Im))
		return true;
	else
		return false;
}
void Complex::ToString()
{
	if (Im > 0) cout << Re << "+" << Im << "j";
	else cout << Re << Im << "j";
	cout << endl;
}
void main()
{
	Complex c1(2, 3), c2(3, -4);
	if (c1 > c2)
		cout << "c1 > c2" << endl;
	else
		cout << "c1 <= c2" << endl;
	_getch();
}