#pragma once
#include "Domain.h"
#include "DynamicArray.h"

typedef int(*cmp_f)(Product*, Product*);

void sort_array(Array*, cmp_f, int);
// sorts the array
// input: an array
//        comparison function
//        array size
// output: the array will be sorted
