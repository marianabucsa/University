#pragma once

typedef struct {
	int id;
	char* type;
	char* manufacturer;
	char* model;
	float price;
	int amount;
}Product;

Product* init_product(int id, char* type, char* manufacturer, char* model, float price, int amount);
// creates a new product
// input:
//       id- product id
//       type- the type of the product, can be one of(laptop, frigider, televizor etc.)
//       manufacturer- the manufacturer of the product
//       model- the model of the product
//       price- the price of the product
//       amount- the amount of product 
// output: a product 

int get_id(Product*);
// returns the id of the current product
// input: - a product
// output: - id of the product


void get_type(Product*, char* type);
// loads in type parameter the type of the current product
// input: - a product
//		  - type - a pointer to char
// output: loads in type parameter the type of the current product

void get_manufacturer(Product*, char* manufacturer);
// loads in manufacturer parameter the manufacturer of the current product
// input: - a product
//		  - manufacturer - a pointer to char
// output: loads in manufacturer parameter the manufacturer of the current product

void get_model(Product*, char* model);
// loads in model parameter the model of the product
// input: - a product
//		  - model - a pointer to char
// output: loads in model parameter the model of the current product

float get_price(Product*);
// returns the price of the current product
// input: - a product
// output: - price of the product

void set_price(Product*, float price);
// sets the price of the product to price parameter
// input: - a product
//		  - a price
// output: -  loads in the product price , the price given as a parameter

int get_amount(Product*);
// returns the amount of the current product
// input: - a product
// output: - amount of the product

void set_amount(Product*, int);
// sets the amount of the product
// input: - a product
//		  - an amount
// output: -  loads in the product amount , the amount given as a parameter


int cmp_products(Product*, Product*);
// compares two products, 2 products are equal if their id is the same
// input:- two products
// output: - 1 - if the products have the same id
//         - 0 - if the products don't have the same id

int cmp_price_asc(Product*, Product*);
// compares the products prices
// input: two products
// output: 1 - the price of the first product is greater than the price of the second product
//         0 - otherwise

int cmp_price_desc(Product*, Product*);
// compares the products prices
// input: two products
// output: 1 - the price of the first product is less than the price of the second product
//         0 - otherwise

int cmp_amount_asc(Product*, Product*);
// compares the products amounts
// input: two products
// output: 1 - the amount of the first product is greater than the amount of the second product
//         0 - otherwise

int cmp_amount_desc(Product*, Product*);
// compares the products amounts
// input: two products
// output: 1 - the amount of the first product is less than the amount of the second product
//         0 - otherwise

Product* copy_product(Product*);
// copy the product
// input: a product
// output: returns a copy of the product

void destroy_product(Product*);
//destroys the product
// input: - a product
// output: the product is destroyed
