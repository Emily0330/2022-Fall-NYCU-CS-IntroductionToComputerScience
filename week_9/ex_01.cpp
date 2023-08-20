//fibonacci number
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int mainaa() {
	int n;
	scanf("%d", &n);
	printf("%d", fibonacci(n));
	return 0;
}
