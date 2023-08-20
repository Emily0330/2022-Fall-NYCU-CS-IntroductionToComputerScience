#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//article contains,.!... not just chars and spaces
int main(void)
{
	int k;
	char n;
	int i = 0, j = 0;
	char strs[10][20];
	char content[3000][20];
	FILE* fptr1;
	FILE* fptr2;
	scanf("%d", &k);
	scanf("\n");
	for (int m = 0; m < k; m++) {
		//store the string into str[], \n will be replaced with \0 automatically
		gets_s(strs[m]);
		//if we have stored the last word, we don't expect a new line(but it should also work if I don't have this 'if'?)
		if (m == k - 1) {
			break;
		}
		scanf("\n");
	}
	//open the files
	fptr1 = fopen("input.txt", "r");
	fptr2 = fopen("output.txt", "w");

	//read the content of input.txt into content[][]
	while ((n = fgetc(fptr1)) != EOF) {
		//if n is A-Z or a-z or abreviation mark(')
		if ((n >= 65 && n <= 90) ||(n >= 97 && n <= 122 || n == 39)) {
			content[i][j] = n;
			j++;
		}
		else {
			//add \0 to the finished string
			content[i][j] = '\0';
			i++;
			//let the non-(a to z)s be another string
			content[i][0] = n;
			//add \0 to the finished string
			content[i][1] = '\0';
			i++;
			j = 0;
		}
	}
	//write content to output
	for (int y = 0; y < i; y++) {
		for (int m = 0; m < 10; m++) {
			//if we encounter the input words
			if (strcmp(content[y], strs[m]) == 0) {
				//print *** instead of the word
				fprintf(fptr2, "***");
				break;
			}
			else if (m == 9){
				//fputs(content[y], fptr2); <= we can replaced the next line of code with this)
				fprintf(fptr2, "%s", content[y]);
			}
		}
	}
	//close the files
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
