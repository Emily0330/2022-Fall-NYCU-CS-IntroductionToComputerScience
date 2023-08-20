//pick a number from 0 to 63 at random and present it in binary

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare the power function
int power(int power, int x);

int main(void)
{
	//to make rand() have different numbers every time
	srand(time(NULL));
	int number, temp;
	int count = 0, sum = 0;

	//pick a decimal number from 0 to 63 at random
	number = rand() % 64;
	printf("Decimal = %d\n", number);
	printf("Binary = ");

	//we can represent binary number in the decimal form!!!
	while (number >= 1)
	{
		count += 1;
		//e.g. 101000=1*100000+1*1000
		//number % 2 != 0 means we get 1 in binary
		if (number % 2 != 0)
		{
			//to represent it in decimal
			sum += power(count - 1, 10);
		}
		number /= 2;
	}
	printf("%d\n", sum);

	return 0;
}

//define the power function (because pow(?,?) accept and return doubles)
int power(int power, int x)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= x;
	}
	return result;
}
