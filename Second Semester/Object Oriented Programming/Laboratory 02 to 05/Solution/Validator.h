#pragma once
#include "Domain.h"

int validate_product(Product*);
// validates the product 
// input: a product
// output : a number: 
//                     - multiple of 2 - for invalid id
//                     - multiple of 3 - for invalid price
//                     - multiple of 5 - for invalid amount
