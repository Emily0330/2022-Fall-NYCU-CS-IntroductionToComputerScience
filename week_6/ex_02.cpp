#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int function(int a, int b);

int main(void) {
	/* prompt users to input n, common ratio, a1 */
	int n, r, a1, a;
	printf("Input: ");
	scanf("%d %d %d", &n, &r, &a1);

	a = a1;
	printf("Output: ");
	while (n--) {
		/* TODO function() */
		printf("%d ", a);
		a = function(a, r);
	}
	printf("\n");
	system("pause");
	return 0;
}
int function(int a, int b) {
	return a * b;
}
