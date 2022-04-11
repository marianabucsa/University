
using namespace std;

#include "VectorDinamic.h"


VectorDinamic::VectorDinamic() {

	this->capacity = 1;
	this->elements = new VElem[1];
	this->nr_elem = 0;
}

VectorDinamic::~VectorDinamic() {
	delete[] this->elements;
}

int VectorDinamic::dim(){
	return this->nr_elem;
}

void VectorDinamic::resize() {

	VElem* eNou = new VElem[2 * capacity];

	for (int i = 0; i < nr_elem; i++)
		eNou[i] = this->elements[i];

	capacity = 2 * capacity;

	delete[] this->elements;

	this->elements = eNou;
}

VElem VectorDinamic::element(int i){
	return this->elements[i - 1];
}

int VectorDinamic::adauga_ordonat(VElem e) {
	//daca s-a atins capacitatea maxima, redimensionam
	if (this->nr_elem == this->capacity)
		resize();
	int i = 0;
	while ((i < this->nr_elem && this->elements[i].linie < e.linie) || (i < this->nr_elem && this->elements[i].linie == e.linie && this->elements[i].coloana < e.coloana))
		i++;
	if (i == this->nr_elem) {
		this->elements[i] = e;
		this->nr_elem++;
	}
	else {
		for (int j = nr_elem; j > i; j--)
			this->elements[j] = this->elements[j - 1];
		this->elements[i] = e;
		this->nr_elem++;
	}
	return 0;
}

int VectorDinamic::modifica(VElem e) {
	VElem* s = this->elements;
	int nr=0;
	for (int i = 0; i < this->nr_elem; i++)
		if (s[i].linie == e.linie && s[i].coloana == e.coloana) {
			nr = s[i].valoare;
			s[i].valoare = e.valoare;
		}
	return nr;
}

int VectorDinamic::sterge(VElem e) {
	VElem* s = this->elements;
	int nr=0;
	for (int i = 0; i < this->nr_elem; i++)
		if (s[i].linie == e.linie && s[i].coloana == e.coloana)
		{
			nr = s[i].valoare;
			for (int j = i; j < this->nr_elem; j++)
				s[i] = s[i + 1];
			break;
		}
	this->nr_elem--;
	return nr;
}

int VectorDinamic::find(VElem e) const{
	VElem* s = this->elements;
	for (int i = 0; i < this->nr_elem; i++)
		if (s[i].linie == e.linie && s[i].coloana == e.coloana)
			return s[i].valoare;
	return 0;
}