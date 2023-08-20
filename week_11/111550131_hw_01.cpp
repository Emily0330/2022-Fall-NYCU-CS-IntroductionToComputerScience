/*

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m, n, p;
char** A, ** B;
void add_book() {
	int x, y, s;
	scanf("%d%d%d", &x, &y, &s);
	if (x == 0 && y < m) {
		if (A[y][0] == '\0') {
			//printf("1\n");
			A[y] = (char*)realloc(A[y], (s + 1) * sizeof(char));
			memset(A[y], '\0', (s + 1));
			scanf("\n");
			//printf("1\n");
			for (int i = 0; i < s; i++) {
				scanf("%c", &A[y][i]); //remember to clear the whitespaces
			}
		}
	}
	else if (x == 1 && y < n) { //choose array B
		if (B[y][0] == '\0') {
			B[y] = (char*)realloc(B[y], (s + 1) * sizeof(char));
			memset(B[y], '\0', s + 1);
			scanf("\n");
			for (int i = 0; i < s; i++) {
				scanf("%c", &B[y][i]); //remember to clear the whitespaces
			}
		}
	}
	return;

}
void delete_book() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == 0 && y < m) {
		char* tmp = A[y];
		for (int i = y; (i + 1) < m; i++) {
			A[i] = A[i + 1];
		}
		free(tmp);
	}
	else if (x == 1 && y < n) {
		char* tmp = B[y];
		for (int i = y; (i + 1) < n; i++) {
			B[i] = B[i + 1];
		}
		free(tmp);
	}
	return;
}
void exchange_book() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x < m && y < n) {
		char* tmp;
		tmp = A[x];
		A[x] = B[y];
		B[y] = tmp;
	}
	return;
}
int main() {
	printf("set the size of array A and B:");
	scanf("%d%d", &m, &n);
	A = (char**)malloc(m * sizeof(char*));
	B = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < m; i++) {
		A[i] = (char*)malloc(1 * sizeof(char));
		A[i][0] = '\0';
	}
	for (int i = 0; i < n; i++) {
		B[i] = (char*)malloc(1 * sizeof(char));
		B[i][0] = '\0';
	}
	while (1) {
		printf("0: add a book, 1: delete a book, 2: exchange the books\n");
		scanf("%d", &p);
		if (p == 0) {
			add_book();
		}
		else if (p == 1) {
			delete_book();
		}
		else { //if p==2
			exchange_book();
		}
		printf("A:\n");
		for (int i = 0; i < m; i++) {
			if (A[i][0] == '\0') {
				printf("(null)\n");
				continue;
			}
			printf("%s\n", A[i]);
		}
		printf("B:\n");
		for (int i = 0; i < n; i++) {
			if (B[i][0] == '\0') {
				printf("(null)\n");
				continue;
			}
			printf("%s\n", B[i]);
		}
	}
	return 0;
}

*/