//accept only int???
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mainaaa(void)
{
	int size, search;
	int count = 0;
	printf("Input size of array:");
	scanf("%d", &size);

	//make the pointer point to NULL
	int* arr = NULL;

	//malloc memory for array
	arr = (int*)malloc(size * sizeof(int));
	printf("Input elements in array:");

	//scan the input one at a time
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	//ask the users what they're searching for
	printf("Element to search: ");
	scanf("%d", &search);

	//search for the element
	for (int j = 0; j < size; j++) {
		if (arr[j] == search) {
			printf("Element found at index: %d\n", j);
			count += 1;
		}
		else if (j == size - 1 && count == 0) {
			printf("%d is not found in the array.\n", search);
		}
	}

	//free the memory
	free(arr);
	return 0;
}
