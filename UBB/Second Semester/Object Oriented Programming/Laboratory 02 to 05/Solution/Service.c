#include "Service.h"
#include "Domain.h"
#include "Validator.h"
#include "Repository.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Service* init_service(Repository* repo) {
	Service* srv = (Service*)malloc(sizeof(Service));
	srv->repo = repo;
	return srv;
}

int add_p(Service* srv, int id, char* type, char* manufacturer, char* model, float price, int amount) {
	Product* p = init_product(id, type, manufacturer, model, price, amount);
	int val = validate_product(p);
	int succes = 0;
	if (val == 1)
		succes = add_product(srv->repo, p);
	else {
		destroy_product(p);
		return val;
	}
	return 1;
}

int modify_p_p(Service* srv, int id, char* type, char* manufacturer, char* model, float price, int amount) {
	Product* p = init_product(id, type, manufacturer, model, price, amount);
	int val = validate_product(p);
	int succes = 0;
	if (val == 1)
		succes = modify_product_p(srv->repo, p);
	else {
		destroy_product(p);
		return val;
	}
	if (succes == 1)
		return 1;
	else return succes;
}

int modify_p_a(Service* srv, int id, char* type, char* manufacturer, char* model, float price, int amount) {
	Product* p = init_product(id, type, manufacturer, model, price, amount);
	int val = validate_product(p);
	int succes = 0;
	if (val == 1)
		succes = modify_product_a(srv->repo, p);
	else {
		destroy_product(p);
		return val;
	}
	if (succes == 1)
		return 1;
	else return succes;
}

int delete_p(Service* srv, int id, char* type, char* manufacturer, char* model, float price, int amount) {
	Product* p = init_product(id, type, manufacturer, model, price, amount);
	int val = validate_product(p);
	int succes;
	if (val == 1)
		succes = delete_product(srv->repo, p);
	else {
		destroy_product(p);
		return val;
	}
	if (succes == 1)
		return 1;
	else return succes;
}

Array* get_products(Service* srv) {
	return get_all_products(srv->repo);
}

Array* ordered_products(Service* srv, char* sort_field, char* mode) {
	Array* v = get_copy_array(srv->repo);
	if (strcmp(sort_field, "price") == 0) {
		if (strcmp(mode, "asc") == 0) {
			sort_array(v, cmp_price_asc, size(srv->repo));
			return v;
		}
		if (strcmp(mode, "desc") == 0) {
			sort_array(v, cmp_price_desc, size(srv->repo));
			return v;
		}
	}
	if (strcmp(sort_field, "amount") == 0) {
		if (strcmp(mode, "asc") == 0) {
			sort_array(v, cmp_amount_asc, size(srv->repo));
			return v;
		}
		if (strcmp(mode, "desc") == 0) {
			sort_array(v, cmp_amount_desc, size(srv->repo));
			return v;
		}
	}
	destroy(v);
	return NULL;
}

Array* filter_pro(Service* srv, char* filter, char* mode, char* data) {
	Array* v = get_copy_array(srv->repo);
	int i;
	if (strcmp(filter, "manufacturer") == 0) {
		for (i = 0; i < v->dim; i++) {
			Product* p = v->elements[i];
			if (strcmp(data, p->manufacturer) != 0) {
				Product* copy = copy_product(p);
				delete_elem(v, copy);
				i--;
				destroy_product(copy);
			}
		}
		return v;}

	else {
		if (strcmp(filter, "price") == 0 && strcmp(mode, "<=") == 0) {
			char* fin;
			int pr;
			pr = strtol(data, &fin, 10);
			for (i = 0; i < v->dim; i++) {
				Product* p = v->elements[i];
				if (pr < p->price) {
					Product* copy = copy_product(p);
					delete_elem(v, v->elements[i]);
					destroy_product(copy);
					i--;
				}
			}
			return v;
		}
		if (strcmp(filter, "price") == 0 && strcmp(mode, ">=") == 0) {
			char* fin;
			int pr;
			pr = strtol(data, &fin, 10);
			for (i = 0; i < v->dim; i++) {
				Product* p = v->elements[i];
				if (pr > p->price) {
					Product* copy = copy_product(p);
					delete_elem(v, v->elements[i]);
					destroy_product(copy);
					i--;
				}
			}
			return v;
		}
		if (strcmp(filter, "amount") == 0 && strcmp(mode, "<=") == 0) {
			char* fin;
			int pr;
			pr = strtol(data, &fin, 10);
			for (i = 0; i < v->dim; i++) {
				Product* p = v->elements[i];
				if (pr < p->amount) {
					Product* copy = copy_product(p);
					delete_elem(v, v->elements[i]);
					destroy_product(copy);
					i--;
				}
			}
			return v;
		}
		if (strcmp(filter, "amount") == 0 && strcmp(mode, ">=") == 0) {
			char* fin;
			int pr;
			pr = strtol(data, &fin, 10);
			for (i = 0; i < v->dim; i++) {
				Product* p = v->elements[i];
				if (pr > p->amount) {
					Product* copy = copy_product(p);
					delete_elem(v, v->elements[i]);
					destroy_product(copy);
					i--;
				}
			}
			return v;
		}
		destroy(v);
		return NULL;
	}

}

void destroy_service(Service* srv) {
	destroy_repo(srv->repo);
	free(srv);
}

