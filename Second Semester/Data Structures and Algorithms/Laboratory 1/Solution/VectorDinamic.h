#pragma once
typedef int TElem;


typedef struct {
	int linie;
	int coloana;
	TElem valoare;
}VElem;

class VectorDinamic {

private:

	int capacity; // capacitatea		
	int nr_elem; // dimensiunea
	VElem* elements;  // elementul
	void resize();  // pentru redimensionare

public:

	//constructor
	VectorDinamic();

	//destructor
	~VectorDinamic();

	//dimensiunea vectorului (numar de elemente)
	int dim();

	//elementul al i-lea (1 <= i <= numar de elemente)
	VElem element(int);

	//adaugare ordonata a elementelor 
	int adauga_ordonat(VElem);

	//modificare element
	int modifica(VElem);
	
	//stergere element 
	int sterge(VElem);

	// cauta un element
	// returneaza 1 daca elementul este gasit, 0 in rest
	int find(VElem)const;

};





