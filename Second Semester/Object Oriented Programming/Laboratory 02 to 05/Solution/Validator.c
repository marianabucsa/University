#include "Domain.h"
#include "Validator.h"
#include <string.h>

int validate_product(Product* p) {
	int val = 1;
	if (get_id(p) <= 0)
		val *= 2;
	if (get_price(p) <= 0)
		val *= 3;
	if (get_amount(p) <= 0)
		val *= 5;
	return val;
}