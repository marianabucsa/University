#include <iostream>
#include <conio.h>

using namespace std;
 
struct snod {
	int data;
	snod* next;
};

void InsertUltim(int);
void InsertPrim(int);
void afisareRec(snod*);
void stergereRec(snod*);
snod* cap;

int main()
{ 
	InsertPrim(1);
	InsertUltim(2);
	InsertUltim(3);
	InsertPrim(4);
	InsertPrim(5);
	InsertUltim(6);
	afisareRec(cap);
	stergereRec(cap);
	return 0;
}
void InsertPrim(int val)
{
	snod *nod = new snod;
	nod->data = val;
	nod->next = cap;
	cap = nod;
}

void InsertUltim(int val)
{
	snod *nod, *ultim;
	ultim = new snod;
	ultim->next = NULL;
	ultim->data = val;
	if (cap == NULL) cap = ultim;
	else {
		nod = cap;
		while (nod->next != NULL) nod = nod->next;
		nod->next = ultim;
	}
}
void afisareRec(snod* pn)
{
	cout << pn->data << " ";
	if (pn->next != NULL)
		afisareRec(pn->next);
}
void stergereRec(snod* pn) 
{
	if (pn->next != NULL)
		stergereRec(pn->next);
	delete pn;
}