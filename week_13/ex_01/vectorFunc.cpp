#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector* vector_construct(int length) {
    /* You need to implement */
    vector* ptr_vec = (vector*)malloc(1 * sizeof(vector));
    ptr_vec->length = length;
    ptr_vec->vec = (int*)calloc(1, sizeof(int));
    return ptr_vec;
}