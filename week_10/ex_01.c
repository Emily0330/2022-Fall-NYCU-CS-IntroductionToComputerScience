#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
int* resize(int* ptr, int cnt, int size) {
	int* q = (int*)realloc(ptr, 2 * cnt * sizeof(int));
	size *= 2;
	ptr = q; // will there be some problems?
	q = NULL;
	return ptr;
}
*/

int main() {
	int c, cnt = 0, k = 0;
	int* ptr = (int*)calloc(1, sizeof(int));
	int size = sizeof(int);
	printf("action = ");
	scanf("%d", &c);

	while (true) {
	
		if (c == 1) {

			//rearrange the size of array
			if (size == cnt * sizeof(int)) {

				int* q = (int*)realloc(ptr, 2 * cnt * sizeof(int));
				size *= 2;

				ptr = q; // will there be some problems?
				q = NULL;
			}
			else if (cnt * sizeof(int) <= size / 2 && k != 0) {

				int* q = (int*)realloc(ptr, size / 2);
				ptr = q; // will there be some problems?
				q = NULL;
				size = size / 2;
			}

			printf("element to add = ");
			scanf("%d", &ptr[cnt++]);

			//print out the whole array
			printf("whole array = ");

			for (int i = 0; i < size / sizeof(int); i++) {
				printf("%d ", ptr[i]);
			}
			k++;
		} 
		else { // c==2
			ptr[cnt - 1] = -7777;
			cnt--;
			//rearrange the size of array
			if (size == cnt * sizeof(int)) {

				int* q = (int*)realloc(ptr, 2 * cnt * sizeof(int));
				size *= 2;
				ptr = q; // will there be some problems?
				q = NULL;
			}
			else if (cnt * sizeof(int) <= size / 2) {
				int* q = (int*)realloc(ptr, size / 2);
				size /= 2;
				ptr = q; // will there be some problems?
				q = NULL;
			}
			

			//print out the whole array

			printf("whole array = ");

			for (int i = 0; i < size / sizeof(int); i++) {
				printf("%d ", ptr[i]);
			}
			
		}

		printf("\naction = ");
		scanf("%d", &c);
		if (c == 0) {
			return 0;
		}
	}
	free(ptr);
	return 0;
}
