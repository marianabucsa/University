#pragma once
#include "Domain.h"

typedef Product* TElem;


typedef struct {
	int dim;
	int capacity;
	TElem* elements;
}Array;

Array* init_array(int capacity);
// creates a dinamic array
// input: capacity- capacity of the array
//        a compare function
//        a destroy function
// output : returns a referece to the array


TElem get_elem(Array*, int);
// returns the element of the array
// input: an array
//        a number
// output: returns the element from the position the number represents

void add_elem(Array*, TElem);
// adds an element to the array
// input: an array
//        a TElement
// output: adds an element to the array

void modify_elem(Array*, TElem);
// modifies the element of the array
// input: an array
//        a TElement
// output: modifies the element of the array

void delete_elem(Array*, TElem);
// deletes the element from the array
// input: an array
//        a TElement
// output: deletes the element from the array


int find_elem(Array*, TElem);
// finds an element in the array
// input: an array
//        a TElement
// output: -1  - if the element is not found
//         the pozition of the element - if the element found 

void resize(Array*);
// resizes the array's capacity , makes it double
// input: an array
// output: makes the array's capacity double

int size_array(Array* v);
// returns the size of the array
// input: an array
// output: returns the size of the array

Array* copy_array(Array*);
// creates a copy of the array
// input: an array
// output: returns the copy of the array

void destroy(Array*);
// destroys the array
// input: an array
// ouput: destroys the array

