/* Variant 13
*/
#include <stdio.h>
int main(void) {
	int** A, * arr, temp, i, j, row, col;
	do {
		printf("Задайте размеры матрицы: ");
		scanf("%d%d", &row, &col);
		system("clear");
		if ((row <= 0) 
		|| (col <= 0)) {
			printf("Задаваемые значения должны быть больше нуля.\n");
			continue;
		}
	} while ((row <= 0) 
	|| (col <= 0)); 
	A = (int**)malloc(row * sizeof(int*));
	arr = (int*)calloc(row, sizeof(int));	
	
	printf("Заданная матрица:\n");
	for (i = 0; i < row; i++) {	
		A[i] = (int*)malloc(col * sizeof(int));	
		for (j = 0; j < col; j++) {
			A[i][j] = rand() % 6 - 5;	
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {	
			if (A[i][j] >= 0) {
				continue;
			}
			arr[j] = A[i][j];
		}
		for (int k = 0; k < col; k++) {	
			for (j = 0; j < col; j++) {
				if (arr[j] >= 0) {
					continue;
				}
				do {
					temp = arr[k];
					arr[k] = arr[j];
					arr[j] = temp;
				} while (arr[k] < arr[j]);
			}
		}
		for (j = 0; j < col; j++) {	
			if (A[i][j] >= 0) {
				continue;
			}
			A[i][j] = arr[j];
			arr[j] = 0;	
		}
	}
	printf("\nПолученная матрица:\n");
	for (i = 0; i < row; i++) {	
		for (j = 0; j < col; j++) {
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < row; i++) {	
		free(A[i]);
	}
	free(A);	free(arr);
	return 0;
}
