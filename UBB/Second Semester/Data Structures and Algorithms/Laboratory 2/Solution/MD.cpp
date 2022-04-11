#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>
#include <climits>

using namespace std;

// complexitate theta(1)
MD::MD() {
	this->prim = nullptr;
	this->ultim = nullptr;
}

// complexitate theta(n)   n -nr cheilor
PNodListaChei MD::cautaCheie(TCheie c) const{
	PNodListaChei curent = this->prim;
	while (curent != nullptr) {
		TCheie cheie = std::get<0>(curent->e);
		if (cheie == c) {
			return curent;
		}
		curent = curent->urm;
	}
	return nullptr;
}

// complexitate theta(m)  m- nr maxim de valori de la o cheie
PNodListaValori MD::cautaValoare(PNodListaValori curent, TValoare v) const {
	PNodListaValori valoare = curent;
	while (valoare != nullptr) {
		if (valoare->e == v)
			return valoare;
		valoare = valoare->urm;
	}
	return nullptr;
}

// complexitate theta(n) n- nr cheilor
void MD::adauga(TCheie c, TValoare v) {
	if (this->prim == nullptr) {
		//  adauga prima cheie
		PNodListaValori valoare = new NodListaValori(v, nullptr, nullptr);
		TListaChei nod_cheie = make_pair(c, valoare);
		PNodListaChei new_cheie = new NodListaChei(nod_cheie, nullptr, nullptr);
		this->prim = new_cheie;
		this->ultim = new_cheie;
	}
	else {
		PNodListaChei nodC = cautaCheie(c);
		if (nodC == nullptr) {
			// adauga cheie noua
			PNodListaValori valoare = new NodListaValori(v, nullptr, nullptr);
			TListaChei nod_cheie = make_pair(c, valoare);
			PNodListaChei new_cheie = new NodListaChei(nod_cheie, nullptr, nullptr);
			ultim->urm = new_cheie;
			new_cheie->prec = this->ultim;
			ultim = new_cheie;
		}
		else {
			// adauga valoare noua
			PNodListaValori nod_valoare = new NodListaValori(v, nullptr, nullptr);
			PNodListaValori prima_valoare = std::get<1>(nodC->e);
			nod_valoare->urm=prima_valoare;
			prima_valoare->prec = nod_valoare;
			nodC->e.second = nod_valoare;
		}
	}
}

// complexitate O(m)
bool MD::sterge(TCheie c, TValoare v) {
	
	if (prim != nullptr){
		PNodListaChei curent = cautaCheie(c);
		if (curent != nullptr) {
			PNodListaValori prim_valoare = get<1>(curent->e);
			if (prim_valoare->prec == nullptr && prim_valoare->urm == nullptr) {
				// cazul cu o singura valoare pentru cheie
				if (prim_valoare->e == v)
				{
					if (curent->prec == nullptr)
					{
						// cazul cu prima cheie
						delete prim_valoare;
						prim = prim->urm;
						if (prim != nullptr) {
							prim->prec = nullptr;
						}
						delete curent;
					}
					else if (curent->urm == nullptr) {
						// cazul cu ultima cheie
						delete prim_valoare;
						ultim = curent->prec;
						if (ultim != nullptr) {
							ultim->urm = nullptr;
						}
						delete curent;
					}
					else {
						// cazul in care cheia nu este nici prima nici ultima
						delete prim_valoare;
						curent->prec->urm = curent->urm;
						curent->urm->prec = curent->prec;
						delete curent;
					}
					return true;
				}
				return false;
			}
			else {
				// sunt mai multe valori
				PNodListaValori valoare = cautaValoare(prim_valoare, v);
				{
					if (valoare != nullptr) {
						if (valoare->prec == nullptr) {
							//valoare este prima 
							valoare->urm->prec = nullptr;
							get<1>(curent->e) = valoare->urm;
							delete valoare;
						}
						else if (valoare->urm == nullptr) {
							//valoarea este ultima
							valoare->prec->urm = nullptr;
							delete valoare;
						}
						else {
							PNodListaValori aux = valoare;
							valoare->urm->prec = aux->prec;
							valoare->prec->urm = aux->urm;
							delete valoare;
						}
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}

// complexitate theta(n*m) n -nr cheilor , m- nr maxim de valori de la o cheie
vector<TValoare> MD::cauta(TCheie c) const {

	vector <TValoare> valori;
	PNodListaChei nodC = cautaCheie(c);
	if (this->prim != nullptr && nodC != nullptr) {
		PNodListaValori val = std::get<1>(nodC->e);
		while (val != nullptr) {
			valori.push_back(val->e);
			val = val->urm;
		}
	}
	return valori;
}

// complexitate theta(n*m) n -nr cheilor , m- nr maxim de valori de la o cheie
int MD::dim() const {
	PNodListaChei p = this->prim;
	int d = 0;
	while (p != nullptr) {
		PNodListaValori v = get<1>(p->e);
		while (v != nullptr) {
			d++;
			v = v->urm;
		}
		p = p->urm;
	}
	return d;
}

//complexitate theta(1)
bool MD::vid() const {
	return this->prim == nullptr;
	return true;
}

//complexitate theta(1)
IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}
/*
complexitate best case: theta(1), cheia pe prima pozitie
complexitate worst case: theta(m)
complexitate average case: theta(m)  m- nr ma
Functionalitate stergeValoriPentruCheie(cheie)
	cheie -Tcheie
	md.prim - pointer la prima cheie
	daca md.prim != nil atunci
		cautaCheie(cheie,c)
		daca c !=nil atunci
			cauta(cheie,valori)
		sf daca
		cat timp cautaCheie(cheie,c) != executa
			sterge(cheie, val.e)
			val<- val->urm;
		sf cat timp
	sf daca
sf functionalitate
*/

vector<TValoare> MD::stergeValoriPentruCheie(TCheie cheie){
	vector <TValoare> valori;
	if (prim != nullptr) {
		PNodListaChei c = cautaCheie(cheie);
		if(c!=nullptr)
			valori = cauta(cheie);
		while (cautaCheie(cheie) != nullptr) {
				PNodListaValori val = get<1>(c->e);
				sterge(cheie, val->e);
		}
	}
	return valori;
}

// complexitate theta(n*m) n -nr cheilor , m- nr maxim de valori de la o cheie
MD::~MD() {
	PNodListaChei curent = this->prim;
	while (curent != nullptr) {
		PNodListaValori val_del = get<1>(curent->e);
		while (val_del != nullptr) {
			PNodListaValori val = val_del;
			val_del = val_del->urm;
			delete val;
		}
		PNodListaChei ch_del = curent;
		curent = curent->urm;
		delete ch_del;
	}
}


