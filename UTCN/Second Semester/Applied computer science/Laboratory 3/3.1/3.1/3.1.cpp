#include <iostream>
#include <conio.h>

using namespace std;

class Mamifer {
public:
	Mamifer() { cout << "Constructor Mamifer" << endl; }
	~Mamifer() { cout << "Destructor Mamifer" << endl << endl; }

};
class Felina : public Mamifer {
public:
	Felina() { cout << "Constructor Felina" << endl; }
	~Felina() { cout << "Destructor Felina" << endl; }
};
class Canida : public Mamifer {
public:
	Canida() { cout << "Constructor Canida" << endl; }
	~Canida() { cout << "Destructor Canida" << endl; }
};

class Pisica : public Felina {
public:
	Pisica() { cout << "Constructor Pisica" << endl; }
	~Pisica() { cout << "Destructor Pisica" << endl; }
};
class Leu : public Felina {
public:
	Leu() { cout << "Constructor  Leu" << endl; }
	~Leu() { cout << "Destructor  Leu" << endl; }
};
class Caine : public Canida {
public:
	Caine() { cout << "Constructor  Caine" << endl; }
	~Caine() { cout << "Destructor  Caine" << endl; }
};

void main()
{
	Pisica x;
	cout << endl;
	Leu y;
	cout << endl;
	Caine z;
	cout << endl;
	_getch();
}
