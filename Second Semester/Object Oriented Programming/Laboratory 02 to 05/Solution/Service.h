#pragma once
#include "Repository.h"
#include "Validator.h"

typedef struct {
	Repository* repo;
}Service;

Service* init_service(Repository*);
// creates the service
// input: a repository
// output: returns a service

int add_p(Service*, int, char* type, char* manufacturer, char* model, float, int);
// creates a product and adds it in the list
// input :
//			id- product id
//			type- the type of the product, can be one of(laptop, frigider, televizor etc.)
//			manufacturer- the manufacturer of the product
//			model- the model of the product
//			price- the price of the product
//			amount- the amount of product 
// output :
//			1- if the product, with the product id, has been successfully added
//          a number : - invalid data
//                     - multiple of 2 - for invalid id
//                     - multiple of 3 - for invalid price
//                     - multiple of 5 - for invalid amount

int modify_p_p(Service*, int, char* type, char* manufacturer, char* model, float, int);
// creates a product and it replaces the product with the same id in the list
// input :
//			id- product id
//			type- the type of the product, can be one of(laptop, frigider, televizor etc.)
//			manufacturer- the manufacturer of the product
//			model- the model of the product
//			price- the price of the product
//			amount- the amount of product 
// output :
//			1- if the product, with the product id, has been successfully modified 
//		   -1- if the product has not been successfully modified because the product does not exist
//          a number : - invalid data
//                     - multiple of 2 - for invalid id
//                     - multiple of 3 - for invalid price
//                     - multiple of 5 - for invalid amount


int modify_p_a(Service*, int, char* type, char* manufacturer, char* model, float, int);
// creates a product and it replaces the product with the same id in the list
// input :
//			id- product id
//			type- the type of the product, can be one of(laptop, frigider, televizor etc.)
//			manufacturer- the manufacturer of the product
//			model- the model of the product
//			price- the price of the product
//			amount- the amount of product 
// output :
//			1- if the product, with the product id, has been successfully modified 
//		   -1- if the product has not been successfully modified because the product does not exist
//          a number : - invalid data
//                     - multiple of 2 - for invalid id
//                     - multiple of 3 - for invalid price
//                     - multiple of 5 - for invalid amount

int delete_p(Service*, int, char* type, char* manufacturer, char* model, float, int);
// creates a product and deletes it from the list
// input :
//			id- product id
//			type- the type of the product, can be one of(laptop, frigider, televizor etc.)
//			manufacturer- the manufacturer of the product
//			model- the model of the product
//			price- the price of the product
//			amount- the amount of product 
// output :
//			1- if the product, with the product id, has been successfully deleted
//		   -1- if the product has not been successfully deleted because the product does not exist
//          a number : - invalid data
//                     - multiple of 2 - for invalid id
//                     - multiple of 3 - for invalid price
//                     - multiple of 5 - for invalid amount

Array* ordered_products(Service* srv, char* sort_field, char* mode);
// orders a copy of the array
// input: a service
//        the field the products will be sorted by, can be "price", "amount"
//        the mode the products will be sorted by, can be "asc", "desc"
// output: - returns a ordered array of products, if the sort field and mode are correct
//         - NULL , if the sort field or mode are not correct

Array* filter_pro(Service* srv, char* filter, char* mode, char* data);
// filters the products
// input : a service
//         the filter for the products, can be "manufacturer", "price", "amount" 
//         the mode in which the products will be sorted , can be "<=", ">="
//         the data used for the filter
// output: - returns a filtered array, if the filter and mode are corect
//         - NULL,  if the filter or mode are not corect 

Array* get_products(Service*);
// retruns all the products
// input:  a service
// output: the repository of the service 

void destroy_service(Service*);
// destroys the service
// input - a service
// output: the service is destroyed