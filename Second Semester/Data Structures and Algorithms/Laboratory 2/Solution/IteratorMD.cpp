#include "IteratorMD.h"
#include "MD.h"

using namespace std;

// complexitate theta(1)
IteratorMD::IteratorMD(const MD& _md) : md(_md) {

	this->curent = _md.prim;
}

// complexitate theta(1)
TElem IteratorMD::element() const {

	if (!this->valid())
		throw exception();
	PNodListaChei c = this->curent;
	TListaChei tlc = c->elementC();
	PNodListaValori v = tlc.second;
	TValoare tv = v->elementV();
	return pair <TCheie, TValoare>(tlc.first, tv);
}

// complexitate theta(1)
bool IteratorMD::valid() const {

	return this->curent != nullptr;
}

// complexitate theta(1)
void IteratorMD::urmator() {

	if (!this->valid())
		throw exception();
	TCheie curent_cheie = std::get<0>(this->curent->elementC());
	PNodListaValori curent_valoare = std::get<1>(this->curent->elementC());
	if (curent_valoare->urmatorV() != nullptr) {
		TListaChei u(curent_cheie, curent_valoare->urmatorV());
		curent = new NodListaChei(u, curent->urmatorC(), curent->precedentC());
	}
	else {
		this->curent = this->curent->urmatorC();
	}
}

// complexitate theta(1)
void IteratorMD::prim() {

	this->curent = md.prim;
}
