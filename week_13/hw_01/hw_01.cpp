#include "111550131_hw_01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibonacci(int n) {
	//F1=1,F2=1
	if (n == 1 || n == 2) {
		printf("1\n");
		return;
	}
	//pre=>Fn-1; cur=>Fn
	int pre[2000], cur[2000], tmp[2000];
	//initialize all the digits to zero
	for (int i = 0; i < 2000; i++) {
		pre[i] = 0;
		cur[i] = 0;
		tmp[i] = 0;
	}
	//put units digit on index 1999 (the larger the digits are, the smaller the indices they're in are)
	cur[1999] = 1;
	pre[1999] = 1;
	//the outmost for loop is to count
	//starting from 3 is because F1=1,F2=1 ,and we start adding from 1+1
	for (int k = 3; k < n + 1; k++) {
		//Fn+1(new_cur) = Fn-1(pre) +Fn(cur)
		for (int i = 1999; i >= 0; i--) {
			tmp[i] = cur[i];
			cur[i] += pre[i];
			pre[i] = tmp[i];
		}
		for (int i = 1999; i >= 1; i--) {	
			//Note: cur[i] / 10 is the carry
			cur[i - 1] += cur[i] / 10;
			//Note: cur[i]%10 < 10
			cur[i] %= 10;
		}
	}
	
	//find the first num!=0
	int nonzero = 0;
	//Note: i=1999 is the smallest digit (unit digit)
	for (int i = 0; i < 2000; i++) {
		if (cur[i] != 0) {
			nonzero = i;
			break;
		}
	}
	//print the digit from the first non-zero digit
	for (int i = nonzero; i < 2000; i++) {
		printf("%d", cur[i]);
	}
	printf("\n");
	return;
}
