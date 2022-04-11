#pragma once
#include "Domain.h"
#include "DynamicArray.h"

typedef struct {
	Array* array;
}Repository;

Repository* init_repo();
//creates a repository
// input: a compare function
//        a destroy function

int add_product(Repository*, Product* p);
// adds a product in the list
// input: - repository - a repository with products
//        - p - a product
// output: - 1 - if the product is added
//          if the product already exists, the amount of product increases by the amount of the product
//          if the product doesn't exist, it is added at the end 

int modify_product_p(Repository*, Product* n);
// modifies the product price with the id of n, with the price of n 
// input: - repository - a repository with products
//        - p - a product
// output: 1 - if the product is found and modified
//         -1 - if the product isn't found

int modify_product_a(Repository*, Product* n);
// modifies the product amount with the id of n, with the amount of n 
// input: - repository - a repository with products
//        - p - a product
// output: 1 - if the product is found and modified
//         -1 - if the product isn't found

int delete_product(Repository*, Product* p);
// deletes the product p from the list
// input: - repository - a repository with products
//        - p - a product
// output: 1 - if the product is found and deleted
//         -1 - if the product isn't found

int size(Repository*);
// returns the number of products
// input: - a repository
// output:- the number of products in the repository

void destroy_repo(Repository*);
// destroys the repository
// input: - a repository
// output: - the repo is destroyed

Array* get_all_products(Repository*);
// returns all the products in the repository
// input: - a repository
// output: - returns the repository

Array* get_copy_array(Repository* repo);
// creates a copy of the array
// input: a repository
// output: returns a copy of the array
