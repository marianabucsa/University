#pragma once
#include "Lista.h"
#include <vector>

using namespace std;


class IteratorMD;

class MD
{
	friend class IteratorMD;

private:

	PNodListaChei prim;
	PNodListaChei ultim;

public:
	// constructorul implicit al MultiDictionarului
	MD();

	PNodListaChei cautaCheie(TCheie c) const;
	PNodListaValori cautaValoare(PNodListaValori ,TValoare v) const;

	vector<TValoare> stergeValoriPentruCheie(TCheie cheie);

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();



};

