#include "Domain.h"
#include "String.h"
#include <stdlib.h>
#include "DynamicArray.h"

Product* init_product(int id, char* type, char* manufacturer, char* model, float price, int amount) {
	Product* p = (Product*)malloc(sizeof(Product));
	p->id = id;
	p->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(p->type, type);
	p->manufacturer = (char*)malloc(sizeof(char) * (strlen(manufacturer) + 1));
	strcpy(p->manufacturer, manufacturer);
	p->model = (char*)malloc(sizeof(char) * (strlen(model) + 1));
	strcpy(p->model, model);
	p->price = price;
	p->amount = amount;
	return p;
}

int get_id(Product* p) {
	return p->id;
}

void get_type(Product* p, char* type) {
	strcpy(type, p->type);
}

void get_manufacturer(Product* p, char* manufacturer) {
	strcpy(manufacturer, p->manufacturer);
}

void get_model(Product* p, char* model) {
	strcpy(model, p->model);
}

float get_price(Product* p) {
	return p->price;
}

void set_price(Product* p, float price) {
	p->price = price;
}

int get_amount(Product* p) {
	return p->amount;
}

void set_amount(Product* p, int amount) {
	p->amount = amount;
}

int cmp_products(Product* p1, Product* p2) {
	return get_id(p1) == get_id(p2);
}

int cmp_price_asc(Product* p1, Product* p2) {
	return p1->price > p2->price;
}

int cmp_price_desc(Product* p1, Product* p2) {
	return p1->price < p2->price;
}

int cmp_amount_asc(Product* p1, Product* p2) {
	return p1->amount > p2->amount;
}

int cmp_amount_desc(Product* p1, Product* p2) {
	return p1->amount < p2->amount;
}

Product* copy_product(Product* p) {
	return init_product(p->id, p->type, p->manufacturer, p->model, p->price, p->amount);
}

void destroy_product(Product* p) {

	free(p->type);
	free(p->manufacturer);
	free(p->model);
	free(p);
}