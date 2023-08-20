#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	//to keep track of whether we've found a combination
	int count = 0;
	scanf("%d", &a);

	// a = i + (a - i)
	//start from i=2 because there's no combination of a=1+(a-1)
	for (int i = 2; i < (a + 1) / 2; i++) {
		//check int from 2~less than i
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) {
				//make sure i is not a prime number
				break;
			}
			else if(i % j != 0 && j == i - 1) {
				//check int from 2~less than i
				for (int k = 2; k < a - i; k++) {
					if ((a - i) % k == 0) {
						break;
					}
					else if ((a - i) % k != 0 && k == (a - i) - 1) {
						printf("%d can be written as %d + %d.\n", a, i, a - i);
						count += 1;
					}
				}
			}
		}
	}
	//can't be express as sum of two prime numbers
	if (count == 0) {
		printf("The number can¡¦t be express as sum of two prime numbers.\n");
	}
	return 0;
}