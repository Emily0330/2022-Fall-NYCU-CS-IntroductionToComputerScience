//1+11+111+1111+11111+...
//depends on the input number

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//declare the power function
int power(int power, int x);

int main(void)
{
	int number;
	int sum = 0, temp = 0;
	printf("Input the number of terms: ");
	scanf("%d", &number);
	//rows of triangles
	for (int i = 1; i < number + 1; i++)
	{
		//set the temp to 0 for every i
		temp = 0;
		//e.g. 1111=1+10+100+1000
		for (int j = 0; j < i; j++)
		{
			temp += power(j, 10);
		}
		//e.g. 1+11+111+...
		sum += temp;
		printf(" %d", temp);
		
		//Behind  the last number doesn't need a '+'
		if (i == number)
		{
			break;
		}
		printf(" +");
	}
	printf("\nThe Sum is: %d\n", sum);

	return 0;
}

//define the power function (because pow(?,?) accept and return double)
int power(int power, int x)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= x;
	}
	return result;
}
