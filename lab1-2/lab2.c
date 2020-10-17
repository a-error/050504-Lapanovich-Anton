#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Russian");
	int** A, ** B, ** C;
	int i, j, k, row1, row2, col1, col2;
error:
    printf("Задайте количество строк и столбцов первой матрицы: ");
    scanf_s("%d%d", &row1, &col1);
    printf("Задайте количество строк и столбцов второй матрицы: ");
    scanf_s("%d%d", &row2, &col2);
	system("cls");

	if (col1 != row2) {		// проверка возможности умножения
		printf("Умножение невозможно! Задайте другие значения.\n");

		goto error;
	}

	else if ((row1 <= 0) || (row2 <= 0) || (col1 <= 0) || (col2 <= 0)) {	// проверка допустимых значений размеров матрицы
		printf("Размеры матрицы должны быть больше нуля, задайте другие значения.\n");

		goto error;;
	}
	A = (int**)malloc(row1 * sizeof(int*));		// выделение памяти для массивов
	B = (int**)malloc(row2 * sizeof(int*));
	C = (int**)malloc(row1 * sizeof(int*));

	for (i = 0; i < row1; i++) {	// заполнение А матрицы
		A[i] = (int*)malloc(col1 * sizeof(int));	// выделение памяти для строк

		for (j = 0; j < col1; j++) A[i][j] = rand() % 21 - 10;		
	}

	for (i = 0; i < row2; i++) {	// заполнение B матрицы
		B[i] = (int*)malloc(col2 * sizeof(int));	// выделение памяти для строк

		for (j = 0; j < col1; j++) B[i][j] = rand() % 21 - 10;		
	}

	for (i = 0; i < row1; i++) {	// заполнение C матрицы
		C[i] = (int*)malloc(col2 * sizeof(int));	// выделение памяти для строк

		for (j = 0; j < col2; j++) {

			for (k = 0; k < col1; k++) C[i][j] = A[i][k] * B[k][j];		// произведение матриц
		}
	}
	printf("Произведение матриц равно:\n");

	for (i = 0; i < row1; i++) {	// вывод матрицы С

		for (j = 0; j < col2; j++) printf("%5d", C[i][j]);
		printf("\n");
	}

	for (i = 0; i < row1; i++) {	// очистка памяти строк 
		free(A[i]);
		free(C[i]);
	}
	free(A);	// очистка памяти массивов
	free(B);
	free(C);
	getchar();		getchar();

	return 0;
}
