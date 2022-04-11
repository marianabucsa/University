#include "IteratorMD.h"
#include "MD.h"

using namespace std;

//Complexitate O(m)
void IteratorMD::deplasare() {
	while ((curent < md.m) && (md.t[curent].first == NIL || md.t[curent].first == STERS))
		curent++;
}

// Complexitate Theta(m)
IteratorMD::IteratorMD(const MD& _md): md(_md) {
	this->curent = 0;
	deplasare();
}

// Complexitate Theta(1)
TElem IteratorMD::element() const{
	if (!valid())
		throw exception();
	return md.t[curent];
}

// Complexitate Theta(1)
bool IteratorMD::valid() const {
	return (curent < md.m);
}

// Complexitate O(m)
void IteratorMD::urmator() {
	if (!valid())
		throw exception();
	curent++;
	deplasare();
}
// Complexitate O(m)
void IteratorMD::prim() {
	curent = 0;
	deplasare();
}

