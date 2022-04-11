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
void creareLista();
int listLenght(snod*);
void sortList(snod* );

snod* cap;

int main()
{
	creareLista();
	afisareRec(cap);
	cout << endl;
	cout << "lungimea listei: " << listLenght(cap) << endl;
	sortList(cap);
	afisareRec(cap);
	return 0;
}

int listLenght(snod* pn)
{
	int l = 1;
	while (pn->next != NULL)
	{
		l++;
		pn = pn->next;
	}
	return l;
}
void sortList(snod* pn)
{
	bool sortat = 0;
	int a, i;
	while (!sortat)
	{
		sortat = 1;
		while(pn->next!=NULL)
		{
			if (pn->data > pn->next->data)
			{
				a = pn->data;
				pn->data = pn->next->data;
				pn->next->data = a;
				sortat = 0;
			}
			pn = pn->next;
		}
		pn = cap;
	}
}

void creareLista()
{ 
	cout << "dati numere pana la intalnirea unui nr negativ"<<endl;
	int val;
	cin >> val;
	if(val >= 0)
	InsertPrim(val);
	cin >> val;
	while (val >= 0)
	{
		InsertUltim(val);
		cin >> val;
	}
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
