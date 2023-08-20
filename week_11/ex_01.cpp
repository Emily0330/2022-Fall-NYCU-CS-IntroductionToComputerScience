#define _CRE_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print_arr(int step, int len, int size[], int* A[]) {
	printf("step %d:\n", step);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < size[i]; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return;
}
int main() {
	int** A = (int**)malloc(3 * sizeof(int*));

	//step 1
	int size[10] = { 5,4,7 };
	int len = 3;
	A[0] = (int*)calloc(size[0], sizeof(int));
	A[1] = (int*)calloc(size[1], sizeof(int));
	A[2] = (int*)calloc(size[2], sizeof(int));

	//print out the result of step 1
	print_arr(1, len, size, A);

	//step 2
	size[1] = 9;
	A[1] = (int*)realloc(A[1], size[1] * sizeof(int));

	//fill the new elements with 1
	for (int i = 4; i < size[1]; i++) {
		A[1][i] = 1;
	}
	//print out the result of step 2
	print_arr(2, len, size, A);

	//step 3
	len = 4;
	A = (int**)realloc(A, 4 * sizeof(int*));
	A[3] = (int*)calloc(2, sizeof(int));
	size[3] = 2;
	//fill the new elements with 1
	for (int i = 0; i < size[3]; i++) {
		A[3][i] = 2;
	}
	//print out the result of step 3
	print_arr(3, len, size, A);

	//step 4
	len = 3;
	size[1] = size[2];
	size[2] = size[3];
	int* tmp = NULL;
	tmp = A[1]; // in order to free the original A[1]
	A[1] = A[2];//why can use sth. like *(a+1)=*(a+2)?
	A[2] = A[3];
	A = (int**)realloc(A, 3 * sizeof(int*));
	//print out the result of step 4
	print_arr(4, len, size, A);

	//free memory
	for (int i = 0; i < 3; i++) {
		free(A[i]);
	}
	free(tmp);
	return 0;
}
