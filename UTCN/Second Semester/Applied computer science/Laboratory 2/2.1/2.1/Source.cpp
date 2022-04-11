#include <iostream>
#include <conio.h>

using namespace std;

class Punct
{
private:
	int x;
	int y;
public:
	Punct(int cx = 0, int cy = 0);
	Punct& operator -- (); // -- Punct;
	Punct& operator -- (int); // Punct --
	void afis();
};

Punct::Punct(int cx, int cy) { x = cx; y = cy; };
Punct& Punct::operator --() { --x; --y; return *this; };
Punct& Punct::operator -- (int a) { Punct p(x, y); --x; --y; return p; };
void Punct::afis() { cout << "[ " << x << " , " << y << " ]" << endl; };
int main()
{
	Punct p(2, -4), p1;
	p.afis();
	cout << endl;
	p1 = --p;
	p.afis();
	p1.afis();
	cout << endl;
	p1 = p--;
	p1.afis();
	p.afis();
	return 0;
}