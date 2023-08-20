//Pascal Triangle
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int rows, test;
	scanf("%d", &rows);

	//make the pointer point to NULL
	int **arr = NULL;
	arr = (int**)malloc(rows * sizeof(int*));

	//malloc the memory of second array
	for (int i = 0; i < rows; i++) {
		arr[i] = (int*)malloc(rows * sizeof(int));
	}

	for (int i = 0; i < rows; i++) {

		//print spaces 
		for (int j = 0; j < 3 * (rows - (i + 1)); j++) {
			printf(" ");
		}
		
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				arr[i][j] = 1;
				printf("%6d", arr[i][j]);
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				printf("%6d", arr[i][j]);
			}
		}
		printf("\n");
	}
	//release array
	for (int i = 0; i < rows; i++) {
		free(arr[i]);
	}
	//release the pointer
	free(arr);
	return 0;
}
