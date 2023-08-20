#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void permute(int length, int arr[], int lengthOfArray, int start, int n);
int maincc() {
	int n, k, arr[9];
	scanf("%d %d", &n, &k);
	permute(k, arr, 0, 1, n);
	return 0;
}
//length is the total length of the array,langthOfArray is where we are
void permute(int length, int arr[], int lengthOfArray, int start, int n) {
	if (lengthOfArray != length) {
		int i = start;
		for (; i < n + 1; i++) {
			arr[lengthOfArray] = i;
			permute(length, arr, lengthOfArray + 1, i + 1, n);
		}
	}
	else {
		for (int i = 0; i < length; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
	}
}
