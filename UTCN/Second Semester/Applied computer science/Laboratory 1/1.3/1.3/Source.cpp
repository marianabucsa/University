#include <iostream>
#include <conio.h>

using namespace std;

struct snod {
	int data;
	snod* next;
};

void creareLista();
void InsertPrim(int);
void InsertUltim(int);
void afisareRec(snod*);

snod *cap,*ultim;
int main()
{
	creareLista();
	afisareRec(cap);
}
void creareLista()
{
	int n,val;
	cout << "dati nr de elemente al listei: ";
	cin >> n;
	cout << "dati valori(doar nr poitive): ";
	cin >> val;
	InsertPrim(val);
	for (int i = 1; i < n; i++)
	{
		cin >> val;
		InsertUltim(val);
	}
	ultim->next = cap;
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
	snod *nod;
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
	if (pn->next != cap)
		afisareRec(pn->next);
}