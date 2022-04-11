#include <iostream>
#include <conio.h>
#include <math.h>

#define PI 3.14

using namespace std;
//CLASELE  

class Figura {
public:
	virtual double Aria_Vol() = 0;
	virtual double Perim_Sup() = 0;
	Figura() { cout << "\tConstuctor Figura" << endl; }
	~Figura() { cout << "Destructor Figura" << endl; }
};

class Punct {
protected:
	int x;
	int y;
public:
	Punct(int cx = 0, int cy = 0) {
		cout << "\tConstructor Punct" << endl;
		x = cx;
		y = cy;
	};
	~Punct() { cout << "Destructor Punct" << endl << endl; }
};

class Cerc : public Punct, public Figura {
protected:
	int raza;
public:
	Cerc(int cx = 0, int cy = 0, int r = 0) :Punct(cx, cy), raza{ r }
	{
		cout << "\tConstructor Cerc" << endl;
	}

	double Aria_Vol() override {

		return PI * pow(raza, 2);
	}

	double Perim_Sup() override {

		return 2 * PI*raza;
	}

	~Cerc() { cout << "Destructor Cerc" << endl; };
};

class Sfera : public Cerc {
public:
	Sfera(int cx, int cy, int r) :Cerc(cx, cy, r) {

		cout << "\tConstructor Sfera" << endl;
	}

	double Aria_Vol() override {

		return 4 * Cerc::Aria_Vol()*raza / 3;
	}

	double Perim_Sup() override {

		return 4 * PI*pow(raza, 2);
	}

	~Sfera() { cout << "Destructor Sfera " << endl; }
};

class Patrat : public Punct, public Figura {
protected:
	int lat;
public:
	Patrat(int cx, int cy, int l) :Punct(cx, cy), lat{ l }
	{
		cout << "\tConstructor Patrat" << endl;
	}

	double Aria_Vol() override {

		return pow(lat, 2);
	}

	double Perim_Sup() override {

		return 4 * lat;
	}

	~Patrat() { cout << "Destructor Patrat" << endl; };
};

class Cub :public Patrat {
public:
	Cub(int cx = 0, int cy = 0, int l = 0) :Patrat(cx, cy, l)
	{
		cout << "\tConstructor Cub" << endl;
	}

	double Aria_Vol() override {

		return pow(lat, 3);
	}

	double Perim_Sup() override {

		return 6 * pow(lat, 2);
	}

	~Cub() { cout << "Destructor Cub" << endl; }
};


//MAIN
void main()
{
	cout << "Cerc:\n";
	Cerc cerc{ 0,0,1 };
	cout << "\tAria: " << cerc.Aria_Vol() << ", Lungimea: " << cerc.Perim_Sup() << endl;

	cout << "Sfera:\n";
	Sfera sfera{ 1,1,2 };
	cout << "\tVolumul: " << sfera.Aria_Vol() << ", Suprafata: " << sfera.Perim_Sup() << endl;

	cout << "Patrat:\n";
	Patrat patrat{ 1,1,1 };
	cout << "\tAria: " << patrat.Aria_Vol() << ", Perimetrul: " << patrat.Perim_Sup() << endl;

	cout << "Cub:\n";
	Cub cub{ 0,0,1 };
	cout << "\tVolumul: " << cub.Aria_Vol() << ", Suprafata: " << cub.Perim_Sup() << endl;

	_getch();
}