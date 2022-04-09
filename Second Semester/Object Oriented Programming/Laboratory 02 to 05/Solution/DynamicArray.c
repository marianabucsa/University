#include "DynamicArray.h"
#include <stdlib.h>
#include "Domain.h"

Array* init_array(int capacity) {
	Array* v = (Array*)malloc(sizeof(Array));
	v->dim = 0;
	v->capacity = capacity;
	v->elements = (TElem*)malloc(sizeof(TElem) * capacity);
	return v;
}

TElem get_elem(Array* v, int i) {
	return v->elements[i];
}

void add_elem(Array* v, TElem e) {
	if (v->dim == v->capacity)
		resize(v);
	v->elements[v->dim] = e;
	v->dim++;
}

void modify_elem(Array* v, TElem e) {
	int i = find_elem(v, e);
	TElem el = v->elements[i];
	v->elements[i] = e;
	destroy_product(el);
}

void delete_elem(Array* v, TElem e) {
	int poz = find_elem(v, e);
	TElem el = v->elements[poz];
	for (int i = poz; i < v->dim - 1; i++)
		v->elements[i] = v->elements[i + 1];
	v->dim--;
	destroy_product(el);
}

int find_elem(Array* v, TElem e) {
	for (int i = 0; i < v->dim; i++)
		if (cmp_products(e, v->elements[i]) == 1)
			return i;
	return -1;
}

void resize(Array* v) {
	int  newdim = v->dim * 2;
	TElem* new_array = malloc(sizeof(TElem) * newdim);
	for (int i = 0; i < v->dim; i++)
		new_array[i] = v->elements[i];
	TElem* elems = v->elements;
	v->elements = new_array;
	v->capacity = newdim;
	free(elems);
}

int size_array(Array* v) {
	return v->dim;
}

Array* copy_array(Array* v) {
	Array* copy = init_array(v->capacity);
	for (int i = 0; i < v->dim; i++)
		add_elem(copy, copy_product(v->elements[i]));
	return copy;
}

void destroy(Array* v) {
	for (int i = 0; i < v->dim; i++)
		destroy_product(v->elements[i]);
	free(v->elements);
	free(v);
}