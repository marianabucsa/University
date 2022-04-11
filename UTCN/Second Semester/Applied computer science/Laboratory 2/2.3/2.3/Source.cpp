#include <iostream>
#include <conio.h>

using namespace std;

class elementLista;

class Lista {
private:
	elementLista* prim;
	elementLista* ultim;
public:
	Lista() :prim{ NULL }, ultim{ NULL } {}
	void addElement(int);
	void afisare();
	~Lista();
};

class elementLista
{
private:
	int val;
	elementLista* urm;
public:
	friend class Lista;
	elementLista();// 3 constuctori
	elementLista(int);
	elementLista(int, elementLista*);
	elementLista(elementLista&);// 1 constustor de copiere
	void set_val(int);//atribuire valoare
	void set_urm(elementLista*);//atribuire pointer
	void afis();// metoda de afisare
};

elementLista::elementLista() {}; //constructor implicit
elementLista::elementLista(int x) :val{ x }, urm{ NULL }{}//constructor fara pointer
elementLista::elementLista(int x, elementLista* y) : val{ x }, urm{ y } {};// constructor cu pointer
void elementLista::set_val(int x) { val = x; }; //atribuire valoare
void elementLista::set_urm(elementLista* x) { urm = x; }; //atribuire pointer

elementLista::elementLista(elementLista& sursa) :val{ sursa.val }, urm{ sursa.urm }{}//constructor de copiere
//{
//	this->val = sursa.val;
//	this->urm = sursa.urm;
//};


void Lista::addElement(int e) {

	elementLista* elemLista = new elementLista(e, NULL);
	if (this->prim == NULL) {
		this->prim = elemLista;
		this->ultim = elemLista;
	}
	else {
		elementLista* p = this->prim;
		while (p->urm != NULL) {
			p = p->urm;
		}
		p->urm = elemLista;
	}
}

void Lista::afisare() {

	elementLista* p = prim;
	while (p != NULL) {
		std::cout << p->val << " ";
		p = p->urm;
	}
}

Lista::~Lista() {

	elementLista* p = this->prim, *del;
	while (p != NULL) {
		del = p;
		p = p->urm;
		delete del;
	}
}

void main()
{
	Lista mylist{};
	mylist.addElement(2);
	mylist.addElement(3);
	mylist.addElement(4);
	mylist.addElement(5);
	std::cout << "Elementele listei sunt: ";
	mylist.afisare();
	_getch();
}