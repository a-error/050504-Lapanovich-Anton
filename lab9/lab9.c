#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");
	char*** matrix;
	int n, row, length, i, j, k = 0;
	printf("Задайте количество матриц: ");
	scanf_s("%d", &n);
	matrix = (char***)malloc(n * sizeof(char**));
	printf("Задайте количество и длину строк: ");
	scanf_s("%d%d", &row, &length);
	length++;

	for (i = 0; i < n; i++)
	{
		matrix[i] = (char**)malloc(row * sizeof(char*));
		for (j = 0; j < row; j++)
		{
			k++;
			matrix[i][j] = (char*)malloc(length * sizeof(char));
			printf("Задайте %d строку: ", k);
			getchar();
			gets(matrix[i][j]);
		}
		k = 0;
	}

	for (i = 0; i < n; i++)
	{
		k++;
		printf("Матрица %d\n", k);
		for (j = 0; j < row; j++)
		{
			puts(matrix[i][j]);
		}
	}

	return 0;
}
