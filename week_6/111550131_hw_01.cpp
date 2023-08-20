#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int COUNT = 0; //to deal with the \n after the first input number

void morse_code_decoder() {
	/* decode the morse_code */
	if (COUNT == 0) { //to deal with the \n after the first input number
		scanf("\n");
	}
	COUNT += 1;
	char morse_code[101] = { '\0' };
	int result[50], count = 0; //count is used to keep track of where we are in result[]
	for (int i = 0; i < 101; i++) {
		scanf("%c", &morse_code[i]);
		if (morse_code[i] == '\n') {
			break;
		}
	}

	int j = 0, co = 0;// co is used to count up the . or -
	for (j = 0; j < 101; j += 6) {
		if (morse_code[j] == '\0') {
			break;
		}
		co = 0;
		if (morse_code[j] == '.') {
			for (int k = j; k < j + 5; k++) {
				if (morse_code[k] == '.') {
					co += 1;
				}
			}
			//check 1~5
			result[count] = co;
		}
		else if (morse_code[j] == '-') {
			for (int k = j; k < j + 5; k++) {
				if (morse_code[k] == '-') {
					co += 1;
				}
			}
			//check 6~9¡B0
			if (co == 5) {
				result[count] = 0;
			}
			else {
				result[count] = co + 5;
			}
		}
		else if (morse_code[j] == '/') {
			result[count] = ' ';
			j -= 4;
		}
		count += 1;
	}
	for (int k = 0; k < count; k++) {
		if (result[k] == ' ') {
			printf(" ");
		}
		else {
			printf("%d", result[k]);
		}
	}
	printf("'\\n'\n");
}

int main() {

	int n;
	scanf("%d", &n);

	while (n--) {
		morse_code_decoder();
	}
	system("pause");
	return 0;
}
/*
.---- ....- ..--- ---.. ..... --...

.---- ....- ----- / .---- .---- ...-- / ---.. --... / ---.. --...
..... ..--- .---- .---- ...-- / .---- .---- ....- ---.. ---..
..... ..--- ----- / .---- ...-- .---- ....- / ..--- .---- ----. ----.

*/