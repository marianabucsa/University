
#include "CP.h"
#include <exception>
#include <stdio.h>
#include <iostream>

using namespace std;

//complexitate theta(1)
Element Nod::element() {
	return this->e;
}

//complexitate theta(1)
PNod Nod::urmator() {
	return this->urm;
}

// complexitate theta(1)
CP::CP(Relatie r) {
	this->rel = r;
	this->prim = nullptr;
	this->ultim = nullptr;
}

//complexitate O(n) n - nr de elemente din coada
void CP::adauga(TElem e, TPrioritate p) {
	Element elem = make_pair(e, p);
	PNod n = new Nod(elem, nullptr);
	// adaugare primul element
	if (this->prim == nullptr && this->ultim == nullptr) {
		this->prim = n;
		this->ultim = n;
	}
	else {
		PNod curent = this->prim;
		PNod anterior = this->prim;
		while (curent != nullptr && !this->rel(p, curent->element().second)) {
			anterior = curent;
			curent = curent->urm;
		}
		if (curent == this->prim) {
			n->urm = this->prim;
			this->prim = n;
		}
		else
			if (curent == nullptr) {
				this->ultim->urm = n;
				this->ultim = n;
			}
			else {
				anterior->urm = n;
				n->urm = curent;
			}
	}
}

// complexitate theta(1)
Element CP::element() const {
	if (this->prim == nullptr && this->ultim == nullptr)
		throw exception();
	return this->prim->element();
	//return pair <TElem, TPrioritate>  (-1, -1);       // copy constructor
	;
}

//complexitate theta(1)
Element CP::sterge() {
	if (this->prim == nullptr && this->ultim == nullptr)
		throw exception();
	Element r = this->prim->element();
	PNod v = this->prim;
	if (this->prim == this->ultim) {
		this->prim = nullptr;
		this->ultim = nullptr;
	}
	else {
		this->prim = this->prim->urmator();
	}
	delete v;
	return r;
	//return pair <TElem, TPrioritate>  (-1, -1);
}

//complexitate theta(1)
bool CP::vida() const {
	if (this->prim == nullptr && this->ultim == nullptr)
		return true;
	return false;
}

//complexitate 
//caz favorabil theta(1) - elementul cautat este primul in coada 
//caz defavorabil theta(n) -elementul cautat nu se afla in coada, n- nr de elemente din coada 
//caz mediu O(n)
/*
	subalgoritm cautare(elem)
		curent<-prim
		cat timp curent != nil executa
			daca [curent].element().first == elem
				cautare <- true
			sf daca
			curent <- [curent].urm
		sf cat timp
		cautare <- false
	sf subalgoritm
*/
bool CP::cautare(TElem elem)const {
	PNod curent = this->prim;
	while (curent != nullptr) {
		if (curent->element().first == elem)
			return true;
		curent = curent->urm;
	}
	return false;
}

// complexitate theta(n) n- nr de elemente din coada
CP::~CP() {
	while (this->prim != nullptr) {
		PNod n = this->prim;
		this->prim = this->prim->urmator();
		delete n;
	}
};

