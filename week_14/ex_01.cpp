#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* a, int size) {
	int tmp, swap = 0;
	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < size - 1; i++) { // Note that i < size -1 !!! not size
			if (a[i] > a[i + 1]) {
				swap++;
				//swap a[i] and a[i+1]
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
		//if the list is sorted
		if (swap == 0) {
			break;
		}
		swap = 0;
	}
	//print out the result
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}
void selectionSort(int* a, int size) {
	int tmp, min, min_index;// cur is the current index  need min!!!
	for (int j = 0; j < size - 1; j++) {
		min = a[j];
		min_index = j;
		for (int i = j + 1; i < size; i++) {
			if (a[i] < min) {
				min = a[i];
				min_index = i;
			}
		}
		//swap a[min_index](=min) and a[j]
		tmp = a[j];
		a[j] = min;
		a[min_index] = tmp;
	}
	
	//print out the result
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}
void insertionSort(int* a, int size) {
	int tmp;
	int index;
	for (int i = 1; i < size; i++) {
		//store the current index=> a[index] is always the number we're trying to place into the right position
		index = i;
		for (int j = i - 1; j >= 0; j--) {

			//if the a[index]<a[j], swap a[j] and a[index]
			//and then update the index
			if (a[index] < a[j]) {
				tmp = a[j];
				a[j] = a[index];
				a[index] = tmp;
				index = j;
			}
		}
	}
	//print out the result
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}
int main() {
	int a[10], which_sort = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &which_sort);
	if (which_sort == 0) {
		bubbleSort(a, 10);
	}
	else if (which_sort == 1) {
		selectionSort(a, 10);
	}
	else if (which_sort == 2) {
		insertionSort(a, 10);
	}
	return 0;
}
