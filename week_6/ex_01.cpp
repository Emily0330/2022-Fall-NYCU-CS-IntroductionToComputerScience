#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y);
int main(void) {
	
	int x, y, ans;

	/* prompt the user for the number */
	printf("Input: ");
	scanf("%d %d", &x, &y);

	/* compare the numbers */
	ans = min(x, y);

	/* print the ans */
	printf("Output: %d\n", ans);
	system("pause");
	return 0;
}

int min(int x, int y) {
	if (x <= y) {
		return x;
	}
	else {
		return y;
	}
}
