
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int mod;
}node;
int cmpfunc(const void* a, const void* b) {
	//declare and casting (necessary for compare function of qsort)
	node* ptr1 = (node*)a;
	node* ptr2 = (node*)b;
	printf("%d-\n", ptr1->mod);
	printf("%d-\n", ptr2->mod);
	if (ptr1->mod < ptr2->mod) {
		return -1;
	}
	else if (ptr1->mod > ptr2->mod) {
		return 1;
	}
	else { //if their mods equal
		if (ptr1->num % 2 != 0 && ptr2->num % 2 != 0) { //they're both odd
			return ptr2->num - ptr1->num; //larger one precedes
		}
		else if (ptr1->num % 2 == 0 && ptr2->num % 2 == 0) { //they're both even
			return ptr1->num - ptr2->num; //smaller one precedes
		}
		else if (ptr1->num % 2 == 0){ //ptr1->num is even, ptr2->num is odd
			return 1; //ptr2->num precedes
		}
		else { //ptr1->num is odd, ptr2->num is even
			return -1; //ptr1->num precedes
		}
	}
	return 0;
}
int main() {
	int n, m;
	//allocate the memory for nodes
	node* arr=(node*)malloc(10000 * sizeof(node));

	scanf("%d%d", &n, &m);

	//store data into array
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].num);
		arr[i].mod = arr[i].num % m;
	}
	//sort the array
	qsort(arr, n, sizeof(node), cmpfunc);

	printf("%d %d\n", n, m);
	//print out the sorted array
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i].num);
	}
	printf("0 0\n");

	//free the memories
	free(arr);
	return 0;
}
