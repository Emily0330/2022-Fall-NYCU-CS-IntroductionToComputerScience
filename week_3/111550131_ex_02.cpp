//print out µÙ§Î(diamond)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number;
	printf("Input the size of the diamond: ");
	scanf("%d", &number);

	//each row of the diamond
	for (int i = 1; i < number + 1; i++)
	{
		//For the upper part, the Xth row (i=X) has (number-X) spaces
		for (int j = 1; j <= number - i; j++)
		{
			printf(" ");
		}
		//For the upper part, the Xth row (i=X) has (2 * number - 1) '*'
		for (int j = 1; j < 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for (int i = 1; i < number + 1; i++)
	{
		//For the lower part, the Xth row (i=X) has X spaces
		for (int j = 1; j <= i; j++)
		{
			printf(" ");
		}
		//For the lower part, the Xth row (i=X) has [(2 * number - 1)-2*X] '*'
		for (int j = 1; j < 2 * number - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}