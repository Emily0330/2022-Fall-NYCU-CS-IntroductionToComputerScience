#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
# define MAX 20

int max_value(int[], int);

int main() {
	int n, x = 0, a[MAX];

	scanf("%d", &n);

	while (x++ < n) {
		scanf("%d", &a[x - 1]);
	}

	printf("Max value is %d.\n", max_value(a, n));

	system("pause");
	return 0;
}

int max_value(int a[], int n) {
	/* if a[i]>max, then max=a[i] */
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}