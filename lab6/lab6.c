#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Russian");
	int** A, * arr, temp, i, j, row, col;

	do {
		printf("Задайте размеры матрицы: ");
		scanf_s("%d%d", &row, &col);
		system("cls");

		if ((row <= 0) || (col <= 0)) {	// проверка на допустимость значений
			printf("Задаваемые значения должны быть больше нуля.\n");

			continue;
		}
	} while ((row <= 0) || (col <= 0));
	A = (int**)malloc(row * sizeof(int*));	// выделение памяти под указатели на строки матрицы
	arr = (int*)calloc(row, sizeof(int));	// выделение памяти под хранение элементов массива
	printf("Заданная матрица:\n");

	for (i = 0; i < row; i++) {	// заполнение и вывод матрицы
		A[i] = (int*)malloc(col * sizeof(int));	// выделение памяти под хранение элементов матрицы

		for (j = 0; j < col; j++) {
			A[i][j] = rand() % 6 - 5;	// числа от -5 до 0
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {	// заполнение массива отрицательными числами

			if (A[i][j] >= 0) {
				continue;
			}
			arr[j] = A[i][j];
		}

		for (int k = 0; k < col; k++) {	// сортировка отрицательных чисел

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

		for (j = 0; j < col; j++) {	// заполнение строки после сортировки

			if (A[i][j] >= 0) {
				continue;
			}
			A[i][j] = arr[j];
		}

		for (j = 0; j < col; j++) {	// обнуление массива
			arr[j] = 0;
		}
	}
	printf("\nПолученная матрица:\n");

	for (i = 0; i < row; i++) {	// вывод матрицы

		for (j = 0; j < col; j++) {
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < row; i++) free(A[i]);	// освобождение памяти хранения элементов матрицы
	free(A);	free(arr);

	return 0;
}
