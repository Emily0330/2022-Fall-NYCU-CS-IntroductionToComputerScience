#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mainmm(void)
{
	int m, n, p, element;
	int A[10][10], B[10][10];

	scanf("%d %d %d", &m, &n, &p);
	scanf("\n");

	//scan by rows
	for (int i = 0; i < m; i++) {
		//scan by columns
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
		//scan \n
		scanf("\n");

		//if it's the last row of the matrix, scan one more row
		if (i == m - 1) {
			scanf("\n");
		}
	}
	//scan by rows
	for (int i = 0; i < n; i++) {
		//scan by columns
		for (int j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
		//scan \n if it's not the last row
		if (i != n - 1) {
			scanf("\n");
		}
	}
	//calculate the multiplication
	//i -> rows, j -> columns, k -> 0 ~ n - 1
	for (int i = 0; i < m; i++) {
		//
		for (int j = 0; j < p; j++) {
			//set element to 0
			element = 0;
			for (int k = 0; k < n; k++) {
				element += A[i][k] * B[k][j];
			}
			printf("%d ", element);

			//if we get to the last column of a row
			if (j == p - 1) {
				printf("\n");
			}
		}
	}
	
	return 0;
}
