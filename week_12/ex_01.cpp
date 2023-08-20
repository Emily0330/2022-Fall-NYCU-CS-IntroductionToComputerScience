#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _grade {
	int Chinese, English, Math, computer_science;
}grade;
typedef struct _Student {
	char name[10];
	int student_id;
	grade student_grade;
}Student;
typedef struct _queries {
	char subj[3];
	int gra;
}queries;

int main() {

	int n, attr, q;
	queries que[4];
	
	//open input file
	FILE* fptr;
	fptr = fopen("input.txt", "r");
	fscanf(fptr, "%d%d%d", &n, &attr, &q);
	Student* student = (Student*)malloc(n * sizeof(Student));
	//scan the queries
	printf("Input queries score:\n");
	for (int i = 0; i < q; i++) {
		scanf("\n");
		scanf("%s%d", que[i].subj, &que[i].gra);
	}
	//scan in the students
	fscanf(fptr, "\n");
	fscanf(fptr, "NAME       	StudentID  Chinese Math English ComputerScience");
	for (int i = 0; i < n; i++) {
		fscanf(fptr, " %s%d", student[i].name, &student[i].student_id);
		fscanf(fptr, "%d%d%d%d", &student[i].student_grade.Chinese, &student[i].student_grade.Math, &student[i].student_grade.English, &student[i].student_grade.computer_science);
	}
	//compare and print out the results
	printf("Result:\n");
	for (int i = 0; i < q; i++) {
		if (que[i].subj[0] == 'C' && que[i].subj[1] != 'S') {
			printf("Chinese :");
			for (int j = 0; j < n; j++) {
				if (student[j].student_grade.Chinese < que[i].gra) {
					printf("%d ", student[j].student_id);
				}
			}
			printf("\n");
		}
		else if (que[i].subj[0] == 'M') {
			printf("Math :");
			for (int j = 0; j < n; j++) {
				if (student[j].student_grade.Math < que[i].gra) {
					printf("%d ", student[j].student_id);
				}
			}
			printf("\n");
		}
		else if (que[i].subj[0] == 'E') {
			printf("English :");
			for (int j = 0; j < n; j++) {
				if (student[j].student_grade.English < que[i].gra) {
					printf("%d ", student[j].student_id);
				}
			}
			printf("\n");
		}
		else {//CS
			printf("ComputerScience :");
			for (int j = 0; j < n; j++) {
				if (student[j].student_grade.computer_science < que[i].gra) {
					printf("%d ", student[j].student_id);
				}
			}
			printf("\n");
		}
	}
	free(student);
	fclose(fptr);
	return 0;
}
