#include "Lista.h"
#include <climits>

// complexitate theta(1)
NodListaValori::NodListaValori(TValoare e, PNodListaValori urm, PNodListaValori prec) {
	this->e = e;
	this->urm = urm;
	this->prec = prec;
}

// complexitate theta(1)
TValoare NodListaValori::elementV() {
	return this->e;
}

// complexitate theta(1)
PNodListaValori NodListaValori::urmatorV() {
	return this->urm;
}

// complexitate theta(1)
PNodListaValori NodListaValori::precedentV() {
	return this->prec;
}

// complexitate theta(1)
NodListaChei::NodListaChei(TListaChei e, PNodListaChei urm, PNodListaChei prec) {
	this->e = e;
	this->urm = urm;
	this->prec = prec;
}

// complexitate theta(1)
TListaChei NodListaChei::elementC() {
	return this->e;
}

// complexitate theta(1)
PNodListaChei NodListaChei::urmatorC() {
	return this->urm;
}

// complexitate theta(1)
PNodListaChei NodListaChei::precedentC() {
	return this->prec;
}

