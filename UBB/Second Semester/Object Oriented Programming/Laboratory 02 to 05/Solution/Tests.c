#include "Tests.h"
#include "Service.h"
#include "Validator.h"
#include <assert.h>
#include "Repository.h"
#include "Ui.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_product() {
	Product* p = init_product(12, "laptop", "lenovo", "i3", 14, 120);
	Product* p1 = init_product(14, "laptop", "lenovo", "i3", 3, 4);
	Product* p2 = init_product(13, "laptop", "lenovo", "i3", 4, 3);
	assert(cmp_price_asc(p1, p2) == 0);
	assert(cmp_price_desc(p1, p2) == 1);
	assert(cmp_amount_asc(p1, p2) == 1);
	assert(cmp_amount_desc(p1, p2) == 0);
	char type[50], manufacturer[50], model[50];
	assert(get_id(p) == 12);
	get_type(p, type);
	assert(strcmp(type, "laptop") == 0);
	get_manufacturer(p, manufacturer);
	assert(strcmp(manufacturer, "lenovo") == 0);
	get_model(p, model);
	assert(strcmp(model, "i3") == 0);
	assert(get_price(p) == 14);
	assert(get_amount(p) == 120);
	destroy_product(p);
	destroy_product(p1);
	destroy_product(p2);
}

void test_add_product() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(size(repo) == 0);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(size(repo) == 1);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(add_p(srv, -30, "leptop", "lenovo", "i3", 14, 120) == 2);
	assert(size(repo) == 1);
	destroy_service(srv);
}

void test_modify_product() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(size(repo) == 1);
	assert(modify_p_p(srv, 12, "leptop", "lenovo", "i3", 16, 120) == 1);
	assert(modify_p_p(srv, -12, "leptop", "lenovo", "i3", 16, 120) == 2);
	assert(modify_p_a(srv, 12, "leptop", "lenovo", "i3", 16, 150) == 1);
	assert(modify_p_a(srv, -12, "leptop", "lenovo", "i3", 16, 150) == 2);
	assert(modify_p_p(srv, 13, "leptop", "lenovo", "i3", 16, 120) == -1);
	assert(modify_p_a(srv, 13, "leptop", "lenovo", "i3", 16, 150) == -1);
	destroy_service(srv);
}

void test_delete_product() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(size(repo) == 1);
	assert(delete_p(srv, 12, "leptop", "lenovo", "i3", 16, 120) == 1);
	assert(size(repo) == 0);
	assert(delete_p(srv, -12, "leptop", "lenovo", "i3", 16, 120) == 2);
	assert(delete_p(srv, 13, "leptop", "lenovo", "i3", 16, 150) == -1);
	destroy_service(srv);
}

void test_get_products() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(size(repo) == 1);
	Array* v;
	v = get_products(srv);
	assert(v->elements[0]->id == 12);
	destroy_service(srv);
}

void test_copy_array() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 12, "leptop", "lenovo", "i3", 14, 120) == 1);
	assert(size(repo) == 1);
	Array* v = get_copy_array(repo);
	assert(v->elements[0]->id == 12);
	destroy_service(srv);
	destroy(v);
}

void test_validate_product() {
	Product* p1 = init_product(-12, "laptop", "lenovo", "i3", 14, 120);
	assert(validate_product(p1) == 2);
	destroy_product(p1);
	Product* p2 = init_product(12, "laptop", "lenovo", "i3", -14, 120);
	assert(validate_product(p2) == 3);
	destroy_product(p2);
	Product* p3 = init_product(12, "laptop", "lenovo", "i3", 14, -120);
	assert(validate_product(p3) == 5);
	destroy_product(p3);
}
void test_ordered_products() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 1, "leptop", "lenovo", "i3", 2, 4) == 1);
	assert(size(repo) == 1);
	assert(add_p(srv, 2, "laptop", "lenovo", "i3", 4, 3) == 1);
	assert(size(repo) == 2);
	assert(add_p(srv, 3, "laptop", "lenovo", "i3", 3, 1) == 1);
	assert(size(repo) == 3);
	assert(add_p(srv, 4, "laptop", "lenovo", "i3", 5, 7) == 1);
	assert(size(repo) == 4);
	Array* v = ordered_products(srv, "price", "asc");
	assert(v->elements[0]->id == 1);
	assert(v->elements[1]->id == 3);
	assert(v->elements[2]->id == 2);
	assert(v->elements[3]->id == 4);
	destroy(v);
	v = ordered_products(srv, "price", "desc");
	assert(v->elements[0]->id == 4);
	assert(v->elements[1]->id == 2);
	assert(v->elements[2]->id == 3);
	assert(v->elements[3]->id == 1);
	destroy(v);
	v = ordered_products(srv, "amount", "asc");
	assert(v->elements[0]->id == 3);
	assert(v->elements[1]->id == 2);
	assert(v->elements[2]->id == 1);
	assert(v->elements[3]->id == 4);
	destroy(v);
	v = ordered_products(srv, "amount", "desc");
	assert(v->elements[0]->id == 4);
	assert(v->elements[1]->id == 1);
	assert(v->elements[2]->id == 2);
	assert(v->elements[3]->id == 3);
	destroy(v);
	v = ordered_products(srv, "a", "dsc");
	destroy_service(srv);
}

void test_filter_products() {
	Repository* repo = init_repo();
	Service* srv = init_service(repo);
	assert(add_p(srv, 1, "leptop", "lenovo", "i3", 2, 4) == 1);
	assert(size(repo) == 1);
	assert(add_p(srv, 2, "laptop", "lenovo", "i3", 4, 3) == 1);
	assert(size(repo) == 2);
	assert(add_p(srv, 3, "laptop", "lenovo", "i3", 3, 1) == 1);
	assert(size(repo) == 3);
	assert(add_p(srv, 4, "laptop", "lenovo", "i3", 5, 7) == 1);
	assert(size(repo) == 4);
	assert(add_p(srv, 5, "laptop", "apple", "i3", 6, 8) == 1);
	assert(size(repo) == 5);
	assert(add_p(srv, 6, "laptop", "apple", "i3", 6, 8) == 1);
	assert(size(repo) == 6);
	Array* v;
	char filter[50], mode[50], data[50];
	strcpy(filter, "manufacturer");
	strcpy(mode, "default");
	strcpy(data, "lenovo");
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 4);
	strcpy(filter, "manufacturer");
	strcpy(mode, "default");
	strcpy(data, "apple");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 2);
	strcpy(filter, "price");
	strcpy(mode, "<=");
	strcpy(data, "4");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 3);
	strcpy(filter, "price");
	strcpy(mode, ">=");
	strcpy(data, "4");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 4);
	strcpy(filter, "amount");
	strcpy(mode, "<=");
	strcpy(data, "4");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 3);
	strcpy(filter, "amount");
	strcpy(mode, ">=");
	strcpy(data, "4");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	assert(v->dim == 4);
	strcpy(filter, "m");
	strcpy(mode, "default");
	strcpy(data, "apple");
	destroy(v);
	v = filter_pro(srv, filter, mode, data);
	destroy_service(srv);
}

void test_dynamic_array() {
	Array* v = init_array(1);
	Product* p1 = init_product(12, "laptop", "lenovo", "i3", 14, 120);
	Product* p2 = init_product(12, "calculator", "lenovo", "i6", 12, 12);
	add_elem(v, p1);
	assert(size_array(v) == 1);
	modify_elem(v, p2);
	assert(size_array(v) == 1);
	assert(get_price(v->elements[0]) == 12);
	assert(get_amount(v->elements[0]) == 12);
	delete_elem(v, p2);
	assert(size_array(v) == 0);
	Product* p4 = init_product(12, "laptop", "lenovo", "i3", 14, 120);
	add_elem(v, p4);
	assert(size_array(v) == 1);
	int i = find_elem(v, p4);
	assert(i == 0);
	Product* p3 = init_product(13, "calculator", "lenovo", "i6", 12, 12);
	i = find_elem(v, p3);
	assert(i == -1);
	Array* copy = copy_array(v);
	for (i = 0; i < v->dim; i++)
		assert(copy->elements[i]->id == v->elements[i]->id);
	assert(copy->dim == v->dim);
	assert(copy->capacity == v->capacity);
	Product* p5 = get_elem(v, 0);
	assert(p5->id == 12);
	destroy(v);
	destroy(copy);
	destroy_product(p3);
}

void run_tests() {
	test_create_product();
	test_add_product();
	test_delete_product();
	test_modify_product();
	test_get_products();
	test_validate_product();
	test_copy_array();
	test_ordered_products();
	test_filter_products();
	test_dynamic_array();
}