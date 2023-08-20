#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int trow, tcolumn, spaces;

	//this array aims to store where the spaces are
	int arr[100][100];

	//let all elements in the matrix be 0 (then we'll change the positions of spaces into 1)
	int matrix[100][100] = {0};
	FILE* fptr1;
	FILE* fptr2;
	//open files,remember to put the files in the same folder as cpp. file
	//don't forget to close the files in the end
	fptr1 = fopen("input.txt", "r");
	fptr2 = fopen("output.txt", "w");
	fscanf(fptr1, "%d %d\n", &trow, &tcolumn);
	fscanf(fptr1, "%d", &spaces);

	//store every position of spaces in arr[][]
	for (int i = 0; i < spaces; i++) {
		for (int j = 0; j < 2; j++) {
			fscanf(fptr1, "%d", &arr[i][j]);//i is not rows of matrix
		}
		//let the position of spaces in the matrix be 1
		matrix[arr[i][0]][arr[i][1]] = 1;
	}

	//write the spaces&H into the output file
	for (int i = 0; i < trow; i++) {
		for (int j = 0; j < tcolumn; j++) {

			//if the element value == 0
			if (matrix[i][j] == 0){
				fprintf(fptr2, "%c", 'H');
			}
			//if the element value == 1 => space
			else {
				fprintf(fptr2, " ");
			}
		}
		//the next row
		fprintf(fptr2, "\n");
	}

	//close the files
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
