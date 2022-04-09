#include "Sort.h"


void sort_array(Array* v, cmp_f cmp, int dim) {
	for (int i = 0; i < dim - 1; i++) {
		for (int j = i + 1; j < dim; j++) {
			Product* p1 = v->elements[i];
			Product* p2 = v->elements[j];
			if (cmp(p1, p2) > 0) {
				v->elements[i] = p2;
				v->elements[j] = p1;
			}
		}
	}
}