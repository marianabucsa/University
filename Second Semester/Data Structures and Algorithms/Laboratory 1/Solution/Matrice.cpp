#include "Matrice.h"

#include <exception>

using namespace std;

// complexitate theta(1)
Matrice::Matrice(int m, int n) {
	if (m <= 0 || n <= 0)
		throw exception();
	else {
		this->nrL = m;
		this->nrC = n;
	}
}


//complexitate theta(1)
int Matrice::nrLinii() const {
	return this->nrL;
}

//complexitate theta(1)
int Matrice::nrColoane() const {
	return this->nrC;
}

// complexitate theta(n)
TElem Matrice::element(int i, int j)const{
	if (i >= this->nrL || j >= this->nrC)
		throw exception();
	else {
		VElem el;
		el.linie = i;
		el.coloana = j;
		el.valoare = 0;
		TElem nr = this->v.find(el);
	    return nr;
	}
	return -1;
}


// complexitate theta(n)  n- nr de elemente
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i >= this->nrL || j >= this->nrC)
		throw exception();
	else {
		int nr;
		VElem el;
		el.linie = i;
		el.coloana = j;
		el.valoare = e;
		if (this->v.find(el) == 0 && el.valoare!=0) {
			nr = this->v.adauga_ordonat(el);
			return nr;
		}
		if (this->v.find(el) != 0 && el.valoare != 0) {
			nr = this->v.modifica(el);
			return nr;
		}
		else {
			if (this->v.find(el) != 0 && el.valoare == 0) {
				nr = this->v.sterge(el);
				return nr;
			}
		}
	}
}

