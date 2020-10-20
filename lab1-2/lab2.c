#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Russian");
	int** A, ** B, ** C;
	int i, j, k, row1, row2, col1, col2;

	do {
		printf("Задайте количество строк и столбцов первой матрицы: ");
		scanf_s("%d%d", &row1, &col1);
		printf("Задайте количество строк и столбцов второй матрицы: ");
		scanf_s("%d%d", &row2, &col2);
		system("cls");

		if ((row1 <= 0) || (row2 <= 0) || (col1 <= 0) || (col2 <= 0)) {	// проверка на допустимость введёных размеров матрицы
			printf("Задаваемые размеры матрицы должны быть больше нуля.\n");

			continue;
		}

		if (col1 != row2) {	// проверка на возможность умножения матриц
			printf("Умножение невозможно! Недопустимые размеры матриц.\n");

			continue;
		}
	} while ((row1 <= 0) || (row2 <= 0) || (col1 <= 0) || (col2 <= 0) || (col1 != row2));
	A = (int**)malloc(row1 * sizeof(int*));	// выделение памяти под указатели на строки
	B = (int**)malloc(row2 * sizeof(int*));
	C = (int**)malloc(row1 * sizeof(int*));

	for (i = 0; i < row1; i++) {	// заполнение матрицы A
		A[i] = (int*)malloc(col1 * sizeof(int));	// выделение памяти под хранение строк

		for (j = 0; j < col1; j++) A[i][j] = rand() % 21 - 10;
	}

	for (i = 0; i < row2; i++) {	// заполнение матрицы B
		B[i] = (int*)malloc(col2 * sizeof(int));	// выделение памяти под хранение строк

		for (j = 0; j < col2; j++) B[i][j] = rand() % 21 - 10;
	}

	for (i = 0; i < row1; i++) {	// заполнение матрицы С
		C[i] = (int*)malloc(col2 * sizeof(int));	// выделение памяти под хранение строк

		for (j = 0; j < col2; j++) {

			for (k = 0; k < col1; k++) C[i][j] = A[i][k] * B[k][j];	// произведение матриц
		}
	}
	printf("Произведение матриц равно:\n");

	for (i = 0; i < row1; i++) {	// вывод матрицы С

		for (j = 0; j < col2; j++) printf("%5d", C[i][j]);
		printf("\n");
	}

	for (i = 0; i < row2; i++) free(B[i]);	//	освобождение памяти под строку 

	for (i = 0; i < row1; i++) {	// освобождение памяти хранения строк
		free(A[i]);
		free(C[i]);
	}
	free(A);	free(B);	free(C);	// освобождение памяти указателей на строки
	getchar();	getchar();	// убирает информацию о возвращении программой нуля

	return 0;
}
