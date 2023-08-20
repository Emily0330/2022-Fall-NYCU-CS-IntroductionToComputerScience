#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct _person {
	int id;
	int money;
	struct _person* next;
};
typedef _person person;
person* append(person* next, int id, int money) {
	person* appe = (person*)malloc(1 * sizeof(person));
	appe->id = id;
	appe->money = money;
	//insert
	if (next != NULL) {
		appe->next = next;
	}
	//add
	else {
		appe->next = NULL;
	}
	return appe;
}
int main() {
	
	int n;
	FILE* fptr;
	fptr = fopen("input.txt", "r");
	fscanf(fptr, "%d", &n);
	int co = n, size;
	//person a;
	person* first = (person*)malloc(1 * sizeof(person));
	person* previous = NULL;
	fscanf(fptr, "\nsize  id 	money   position");
	fscanf(fptr, "%d", &size);
	if (size == 2) {
		fscanf(fptr, "%d%d", &first->id, &first->money);
	}
	else {//size==3
		int temp;
		fscanf(fptr, "%d%d%d", &first->id, &first->money, &temp);
	}
	//printf("%d", n);
	first->next = NULL;
	previous = first;
	co--;
	while (co--) {
		fscanf(fptr, "%d", &size);
		
		if (size == 1) {//leave
			
			int index;
			fscanf(fptr, "%d", &index);
			person* cur = first;
			person* ptr = first;
			if (index == 0) {
				//free(ptr);
				first = first->next;
			}
			else {
				for (int co1 = 0; co1 <= index; co1++) {
					if (co1 == index) {
						cur->next = ptr->next;//ptr is now pointing to the exact person that is leaving
						//free(ptr);
						break;
					}
					cur = ptr;
					ptr = ptr->next;
				}
			}
		}
		else if (size == 2) {//join
			int id, money;
			fscanf(fptr, "%d%d", &id, &money);
			previous->next = append(NULL, id, money);
			previous = previous->next;
		}
		else {//insert, size==3
			int id, money, index;
			fscanf(fptr, "%d%d%d", &id, &money, &index);
			
			if (index == 0) {
				person* new_person = (person*)malloc(1 * sizeof(person));
				new_person->next = first;
				new_person->id = id;
				new_person->money = money;
				first = new_person;
			}
			else {
				person* ptr = first, * pre = NULL;
				for (int i = 0; i < n; i++) {
					if (i == index) {
						pre->next = append(ptr, id, money);
						break;
					}
					if (ptr == NULL) {
						break;
					}
					pre = ptr;
					ptr = ptr->next;
				}
			}
		}
	}
	//print out the result

	for (person* ptr = first; ; ptr = ptr->next) {
		if (ptr == NULL) {
			break;
		}
		printf("ID money : %d %d\n", ptr->id, ptr->money);
	}

	person* tmp = NULL;

	for (person* ptr = first; ptr != NULL;) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	
	fclose(fptr);
	return 0;
}