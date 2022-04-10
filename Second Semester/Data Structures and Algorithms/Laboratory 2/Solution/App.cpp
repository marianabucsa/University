#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
#include "MD.h"
#include <assert.h>

using namespace std;

int main() {
	MD m;
	m.adauga(1, 100);
	m.adauga(1, 200);
	m.adauga(1, 300);
	m.adauga(1, 500);
	m.adauga(2, 600);
	m.adauga(4, 800);
	assert(m.dim() == 6);
	TCheie cheie = 1;
	vector<TValoare> val = m.stergeValoriPentruCheie(cheie);

	assert(m.dim() == 2);
	assert(val[0] == 500);
	assert(val[1] == 300);
	assert(val[2] == 200);
	assert(val[3] == 100);
	testAll();
	testAllExtins();
	cout<<"End";
}
