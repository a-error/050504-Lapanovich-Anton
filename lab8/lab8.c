#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");
	char** str;
	int i, j, n, m, temp, k = 0;
	printf("Задайте количество и длину строк: ");
	scanf_s("%d%d", &n, &m);
	m++;
	str = (char**)malloc(n * sizeof(char*));	// выделение памяти под укзатели на строки

	for (i = 0; i < n; i++)	// заполнение строк
	{
		k++;
		str[i] = (char*)malloc(m * sizeof(char));	// выделение памяти под хранение элементов
		printf("Задайте %d строку: ", k);
		getchar();
		fgets(str[i], m, stdin);
	}

	for (i = 0; i < n; i++)	// сортировка цифр по убыванию
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < m; k++)
			{
				while (str[i][j] > str[i][k])
				{
					temp = str[i][j];
					str[i][j] = str[i][k];
					str[i][k] = temp;
				}
			}
		}
	}
	printf("Результат сортировки:\n");

	for (i = 0; i < n; i++)	// вывод строк после сортировки
	{
		printf("%s\n", str[i]);
		free(str[i]);	// освобождение памяти указателей на строки
	}
	free(str);
	
	return 0;
}
