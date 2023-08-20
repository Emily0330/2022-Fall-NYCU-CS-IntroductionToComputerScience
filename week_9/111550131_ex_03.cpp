#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int board[5][5];
void sudoku(int r, int c);
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &board[i][0], &board[i][1], &board[i][2], &board[i][3]);
	}
	sudoku(0, 0);
	return 0;
}
void sudoku(int r, int c) {
	if (r == 4) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		return;
	}
	else if (board[r][c] != 0) {
		if (c != 3) {
			sudoku(r, c+1); 
		}
		else {
			sudoku(r+1, 0);
		}
		return;
	}
	else {
		for (int i = 1; i < 5; i++) {
			//printf("%d %d %d\n", r, c, i);
			int a = 0;//keep track of if there's same number on the same row
			//check horizontal
			for (int j = 0; j < 4; j++) {
				if (board[r][j] == i) {
					a++;
					break;
				}
			}
			if (a != 0) { // if the num is already on the same row, try next num 
				continue;
			}
			//check vertical
			for (int j = 0; j < 4; j++) {
				if (board[j][c] == i) {
					a++;
					break;
				}
			}
			if (a != 0) {
				continue;
			}
			//2*2
			//lu

			if ((r == 0 || r == 2) && (c == 0 || c == 2)) {
				if (i == board[r + 1][c + 1]) {
					continue;
				}
			}
			//ru
			else if ((r == 0 || r == 2) && (c == 1 || c == 3)) {
				if (i == board[r + 1][c - 1]) {
					continue;
				}
			}
			//rb
			else if ((r == 1 || r == 3) && (c == 1 || c == 3)) {
				if (i == board[r - 1][c - 1]) {
					continue;
				}
			}
			//lb
			else {
				if (i == board[r - 1][c + 1]) {
					continue;
				}
			}
			board[r][c] = i;
			if (c != 3) {
				sudoku(r, c+1);
			}
			else {
				//printf("k\n");
				sudoku(r+1, 0);
			}
		}
		return;
	}
}