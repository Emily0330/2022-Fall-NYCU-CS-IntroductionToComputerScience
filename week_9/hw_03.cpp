#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

FILE* fptr;
char plates[10];
void hanoi(int n, char src, char spare, char des) {
	if (n == 1) {
		fprintf(fptr, "Move disk 1 from %c to %c.\n", src, des);
		return;
	}
	//1. move the (n-1) plates to spare ped
	hanoi(n - 1, src, des, spare);

	//move the n-th plate from source to destination
	//think:hanoi(n,src,spare,des) is to move the n-th plate from src to des
	fprintf(fptr, "Move disk %d from %c to %c.\n", n, src, des);

	// move the (n-1)plates to des
	hanoi(n - 1, spare, src, des);
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	char filename[20] = "output-0.txt";
	filename[7] = n + '0';
	fptr = fopen(filename, "w");
	//initialize the position of every plate to 'A'
	for (int i = 0; i < n; i++) {
		plates[i] = 'A';
	}
	hanoi(n, 'A', 'B', 'C');
	fclose(fptr);
	return 0;
}

