#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Russian");
	int** A, * arr, temp, i, j, k, row1, col1;

	do {
		printf("Задайте размеры матрицы: ");
		scanf_s("%d%d", &row1, &col1);
		system("cls");

		if ((row1 <= 0) || (col1 <= 0)) {	// проверка на допустимость значений
			printf("Задаваемые значения должны быть больше нуля.\n");

			continue;
		}
	} while ((row1 <= 0) || (col1 <= 0));
	A = (int**)malloc(row1 * sizeof(int*));	// выделение памяти под указатели на строки матрицы
	arr = (int*)calloc(row1, sizeof(int));	// выделение памяти под хранение элементов массива
	printf("Заданная матрица:\n");

	for (i = 0; i < row1; i++) {	// заполнение и вывод матрицы
		A[i] = (int*)malloc(col1 * sizeof(int));	// выделение памяти под хранение элементов матрицы

		for (j = 0; j < col1; j++) {
			A[i][j] = rand() % 21 - 10;	// числа от -10 до 10
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < row1; i++) {

		for (j = 0; j < col1; j++) {	// отбор отрицательных чисел

			if (A[i][j] >= 0) {
				continue;
			}
			arr[j] = A[i][j];
		}

		for (int k = 0; k < col1; k++) {

			for (j = 0; j < col1; j++) {

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

		for (j = 0; j < col1; j++) {	// отбор отрицательных чисел

			if (A[i][j] >= 0) {
				continue;
			}
			A[i][j] = arr[j];
		}

		for (j = 0; j < col1; j++) {
			arr[j] = 0;
		}
	}
	printf("\nПолученная матрица:\n");

	for (i = 0; i < row1; i++) {

		for (j = 0; j < col1; j++) {
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < row1; i++) free(A[i]);	// освобождение памяти хранения элементов матрицы
	free(A);	free(arr);

    return 0;
}
