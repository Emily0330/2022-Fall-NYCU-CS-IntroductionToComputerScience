#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix2D* matrix2D_construct(int m, int n) {
    /* You need to implement */
    matrix2D* ptr_mat = (matrix2D*)malloc(1 * sizeof(matrix2D));
    ptr_mat->row = m;
    ptr_mat->column = n;
    ptr_mat->mat = NULL;
    return ptr_mat;
}

void matrix2D_fillwith(matrix2D* A, int num) {
    /* You need to implement */
    //do I need to malloc for vector?
    //No, I've malloced it in vector_construct--> use vector_construct!!
    A->mat = vector_construct(A->row);
    *(A->mat->vec) = num;
    return;
}

matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
    /* You need to implement */
    if (A->column != B->row) {
        printf("Shape Error\n");
        exit(0);
    }
    matrix2D* result = (matrix2D*)malloc(1 * sizeof(matrix2D));
    result->row = A->row;
    result->column = B->column;
    //*(result->mat->vec) = *(A->mat->vec) * *(B->mat->vec);
    int element;
    element = *(A->mat->vec) * *(B->mat->vec) * A->column;
    matrix2D_fillwith(result, element);
    return result;
}

void print_matrix(matrix2D* A) {
    /* You need to implement */
    for (int i = 0; i < A->row; i++) {
        for (int j = 0; j < A->column; j++) {
            printf("%d ", *(A->mat->vec));
        }
        printf("\n");
    }
    return;
}