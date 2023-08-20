//just print out the first or all of the elements searched?(now I search for all)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mainaa(void)
{
	//set the length of str to be 127(largest,>127 will have overflow??) so it's not easy to exceed, another way?
	char str[127], search, size;

	//ask user to type in the string
	printf("Enter any string: ");
	gets_s(str);

	//ask users to type in what they're searching for
	printf("Enter character to be searched: ");
	scanf("%c", &search);
	size = sizeof(str);
	for (int i = 0; i < size; i++) {
		//search for the elements
		if (str[i] == search) {
			printf("'%c' is found at index %d.\n", str[i], i);
		}
		//break after reaching the end of the string(!=NULL)
		else if (str[i] == NULL) {
			break;
		}
	}
	return 0;
}