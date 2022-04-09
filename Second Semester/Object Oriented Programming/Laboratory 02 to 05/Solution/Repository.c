#include "Repository.h"
#include <stdlib.h>
#include <stdio.h>
#include "Domain.h"



Repository* init_repo() {
	Repository* repo = (Repository*)malloc(sizeof(Repository));
	repo->array = init_array(1);
	return repo;
}

int add_product(Repository* repo, Product* p) {
	int i;
	i = find_elem(repo->array, p);
	if (i != -1) {
		Product* pr = repo->array->elements[i];
		set_amount(repo->array->elements[i], pr->amount + p->amount);
		destroy_product(p);
		return 1;
	}
	add_elem(repo->array, p);
	return 1;
}

int modify_product_p(Repository* repo, Product* n) {
	int i;
	i = find_elem(repo->array, n);
	if (i != -1) {
		set_price(repo->array->elements[i], n->price);
		destroy_product(n);
		return 1;
	}
	destroy_product(n);
	return -1;
}

int modify_product_a(Repository* repo, Product* n) {
	int i;
	i = find_elem(repo->array, n);
	if (i != -1) {
		set_amount(repo->array->elements[i], n->amount);
		destroy_product(n);
		return 1;
	}
	destroy_product(n);
	return -1;
}

int delete_product(Repository* repo, Product* p) {
	int i;
	i = find_elem(repo->array, p);
	if (i != -1) {
		delete_elem(repo->array, p);
		destroy_product(p);
		return 1;
	}
	destroy_product(p);
	return -1;
}

Array* get_all_products(Repository* repo) {
	return repo->array;
}

Array* get_copy_array(Repository* repo) {
	return(copy_array(repo->array));
}

int size(Repository* repo) {
	return repo->array->dim;
}

void destroy_repo(Repository* repo) {
	destroy(repo->array);
	free(repo);
}

