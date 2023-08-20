#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char a[21], b[21];
	int result[22], carry = 0;
	scanf("%s%s", a, b);
	//do the addition
	for (int i = 19; i >= 0; i--) {
		result[i] = (a[i] - '0') + (b[i] - '0') + carry;
		carry = result[i] / 10;
		result[i] %= 10;
	}
		if (carry == 1) {
		printf("1");
	}
	for (int i = 0; i < 20; i++) {
		printf("%d", result[i]);
	}
	return 0;
}
