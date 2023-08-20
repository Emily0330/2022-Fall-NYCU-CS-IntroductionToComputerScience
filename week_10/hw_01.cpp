#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//use const char so that s&t will not be changed in compare function
int* compare(const char* s, const char* t, int n) {
	int* cmp = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			cmp[i] = 1;
		}
		else {
			cmp[i] = 0;
		}
	}
	return cmp;
}
int main() {
	int n;
	printf("input n:");
	scanf("%d", &n);
	char* a = NULL, * b = NULL;
	int* result = NULL;
	//remember to malloc memories for NULL characters!
	//scanf("%s", a); will add \0 for you automatically
	a = (char*)malloc((n + 1) * sizeof(char));
	b = (char*)malloc((n + 1) * sizeof(char));
	printf("input a:");
	scanf("%s", a);
	printf("input b:");
	scanf("%s", b);
	result = compare(a, b, n);
	//print out the result
	for (int i = 0; i < n; i++) {
		printf("%d", result[i]);
	}
	printf("\n");
	//free the memory we malloc
	free(a);
	free(b);
	free(result);
	system("pause");
	return 0;
}
