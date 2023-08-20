#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

FILE* fptr;

//check if the sprinkler can be placed
bool checkqueen(int n, int r, int c, char table[10][10]) {
	//check rows
	for (int i = 0; i <= r; i++) {
		if (table[i][c] == '*') {
			return false;
		}
	}
	//right
	for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
		if (table[i][j] == '*') {
			return false;
		}
	}
	//left
	for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
		if (table[i][j] == '*') {
			return false;
		}
	}
	return true;
}
void permute(int n, int r, char arr[10][10]) {
	//print out the result
	if (r == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fprintf(fptr, "%c", arr[i][j]);
			}
			fprintf(fptr, "\n");
		}
		fprintf(fptr, "\n");
		return;
	}
	for (int col = 0; col < n; col++) {
		if (checkqueen(n, r, col, arr)) {//is safe

			arr[r][col] = '*';

			permute(n, r + 1, arr);

			arr[r][col] = '.';
		}

	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	char filename[20] = "output-0.txt";
	filename[7] = n + '0';
	fptr = fopen(filename, "w");
	char arr[10][10];
	//initialize the elements to '.'
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			arr[k][j] = '.';
		}
	}
	permute(n, 0, arr);
	fclose(fptr);
	return 0;
}


