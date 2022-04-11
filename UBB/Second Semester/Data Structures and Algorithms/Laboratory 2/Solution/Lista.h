#pragma once
#include<utility>

class NodListaValori;
class NodListaChei;
typedef int TValoare;
typedef NodListaValori* PNodListaValori; // adresa unui nod de tip valoare

typedef int TCheie;
typedef NodListaChei* PNodListaChei; // adresa unui nod de tip cheie
typedef std::pair<TCheie, TValoare> TElem;
typedef std::pair<TCheie, PNodListaValori> TListaChei;


class NodListaValori {
	friend class MD;

private:
	TValoare e; // informatia
	PNodListaValori urm, prec; // legaturi

public:
	//constructor
	NodListaValori(TValoare e, PNodListaValori urm, PNodListaValori prec);
	TValoare elementV();
	PNodListaValori urmatorV();
	PNodListaValori precedentV();
};

class NodListaChei {
	friend class MD;
private:
	TListaChei e; // informatia
	PNodListaChei urm, prec; // legaturi
public:

	//constructor
	NodListaChei(TListaChei e, PNodListaChei urm, PNodListaChei prec);
	TListaChei elementC();
	PNodListaChei urmatorC();
	PNodListaChei precedentC();
};



