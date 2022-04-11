#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>
#include <map>
using namespace std;

// Complexitate Theta(1)
int hashCode(TElem e) {
	return abs(e.first);
}

// Complexitate Theta(1)
int MD::d(TElem e, int i) const {
	int c=0.5;
	return(hashCode(e) % m + c * i + c *( i * i)) % m;
}


// Complexitate Theta(m)
MD::MD() {
	this->m = MAX;
	TCheie c = NIL;
	TValoare v = NIL;
	t =(TElem*)malloc(sizeof(TElem) * MAX);
	for (int i = 0; i < m; i++)
		t[i] = make_pair(c,v);
}

// Complexitate O(m)
int MD::prim_liber(int k) {
	for (int i = k; i < m; i++)
		if (t[i].first == NIL || t[i].first == STERS)
			return i;
	for (int i = 0; i < k; i++)
		if (t[i].first == NIL || t[i].first == STERS)
			return i;
	return -1;
}

//Complexitate O(m)
void MD::adauga(TCheie c, TValoare v) {
	int i = 0; 
	bool gasit = false;
	TElem elem = make_pair(c, v);
	int j = d(elem, i);
	if (t[j].first == NIL || t[j].first ==STERS) {
		t[j] = elem;
		gasit = true;
	}
	else {
		if (prim_liber(j) != -1) {
			t[prim_liber(j)] = elem;
			gasit = true;
		}
	}
	if (gasit==false) {
		cout << "Depasire Tabela!!!";
		//redimensionare();
	}
}

// Complexitate O(m)
bool MD::sterge(TCheie c, TValoare v) {
	TElem elem = make_pair(c, v);
	TElem elem_sters = make_pair(STERS, STERS);
	int i = 0;
	int j = d(elem, i);
	bool gasit = false;
	if (t[j].first != NIL) {
		if (t[j].first == c && t[j].second==v) {
			t[j] = elem_sters;
			gasit = true;
		}
		else {
			int k = j+1;
			while (t[k].first != NIL && k < m) {
				if (t[k].first == c && t[k].second == v) {
					t[k] = elem_sters;
					gasit = true;
				}
				if (gasit)
					break;
				k++;
			}
			if (!gasit && t[k].first!=NIL) {
				k = 0;
				while (t[k].first != NIL && k < j) {
					if (t[k].first == c && t[k].second == v) {
						t[k] = elem_sters;
						gasit = true;
					}
					if (gasit)
						break;
					k++;
				}
			}
		}

	}
	return gasit;
}

// Complexitate O(m)
vector<TValoare> MD::cauta(TCheie c) const {
	vector<TValoare> v;
	TValoare val = 0;
	TElem elem = make_pair(c,val);
	int i = 0;
	int j = d(elem, i);
	if (t[j].first != NIL){
		if(t[j].first == c)
			v.push_back(t[j].second);
		int k = j + 1;
		while (t[k].first != NIL && k < m) {
			if (t[k].first == c)
				v.push_back(t[k].second);
			k++;
		}
		if (k == m - 1) {
			k = 0;
			while (t[k].first != NIL && k < j) {
				if (t[k].first == c)
					v.push_back(t[k].second);
				k++;
			}
		}

	}
	return v;
}

// Complexitate caz favorabil -Theta(m)
//				caz defavorabil -Theta(m)
//				caz mediu  -  Theta(m)
//
// subalgoritm ceaMaiFrecventaValoare(D)
//	daca D.dim() = 0 atunci
//		ceaMaiFrecventaValoare<-NIL
//	sf daca
//  pentru i<-0,m,1 executa
//		daca D.t[i].c != NIL && D.t[i].c != STERS
//			v.adauga(D.t[i].v);
//		sf daca
// sf pentru
// pentru valoare in v executa
//		g[valoare]<-0
// sf pentru
// pentru valoare in v executa
//		g[valoare]<-g[valoare]+1;
// sf pentru
// k<-0
//	pentru element in g executa
//		daca element.nr_aparitii > k atunci
//			val<-element.valoare
//			k<-element.nr_aparitii 
//		sf daca
// sf pentru
// ceaMaiFrecventaValoare<-val
// sf subalgoritm

TValoare MD::ceaMaiFrecventaValoare() const {
	vector<TValoare> v;
	map<TValoare,int> g;
	if (dim() == 0)
		return NIL;
	for (int i = 0; i < m; i++)
		if (t[i].first != NIL && t[i].first != STERS)
			v.push_back(t[i].second);
	for (auto valoare : v) {
		g[valoare] = 0;
	}
	for (auto valoare : v) {
		g[valoare]++;
	}
	int k = 0;
	TValoare val = NIL;
	for (auto elem : g) {
		if (elem.second > k) {
			val = elem.first;
			k = elem.second;
		}
	}
	return val;
}

// Complexitate Theta(m)
int MD::dim() const {
	int dimensiune = 0;
	for (int i = 0; i < m; i++)
		if (t[i].first != NIL && t[i].first != STERS)
			dimensiune++;
	return dimensiune;
}

// Complexitate Theta(1)
bool MD::vid() const {
	if(dim()==0)
		return true;
	return false;
}

// Complexitate Theta(m)
IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}

// Complexitate Theta(1);
MD::~MD() {
	free(t);
}

