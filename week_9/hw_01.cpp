/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

FILE* fptr;
int arr[10];

void permute(int n, int start, int length, int lengthOfArray) { // length is the length of that row
	if (start == n + 'a') {
		return;
	}
	int i = start;

	for (; i < n + 'a'; i++) {
		arr[lengthOfArray] = i;
		if (lengthOfArray + 1 == length) { // arrive the end of the row
			for (int k = 0; k < length; k++) {
				fprintf(fptr, "%c", arr[k]);
			}
			fprintf(fptr, "\n");
			permute(n, i + 1, length + 1, lengthOfArray + 1);
		}
		else {
			permute(n, i + 1, length, lengthOfArray + 1);
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
	permute(n, 'a', 1, 0);
	fclose(fptr);
	return 0;
}
*/

