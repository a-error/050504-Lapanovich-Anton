#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");
	char* s;
	int* arr, i, n, temp = 0;
	printf("Задайте размер строки: ");
	scanf_s("%d", &n);
	n++;
	s = (char*)malloc(n * sizeof(char));	// выделение памяти под хранение элементов строки
	arr = (int*)calloc(n, sizeof(int));	// выделение памяти под храниние элементов массива
	printf("Задайте строку: ");
	getchar();
	fgets(s, n, stdin);

	for (i = 0; i < n; i++)	// определение длин слов в строке
	{
		if (s[i] == ' ')	// проверка на пробел
		{
			arr[i] = temp;
			temp = 0;
			continue;
		}
		else if (i == n - 1)	// проверка на окончание строки
		{
			arr[i] = temp;
			continue;
		}
		else if (s[i] == '\0')	// проверка на произвольное окончание строки
		{
			arr[i] = temp - 1;
			temp--;
			continue;
		}
		temp++;
	}

	for (i = 0; i < n; i++)	// поиск наименьшей длины слова
	{
		if ((arr[i] == 0) || (temp < arr[i]))
		{
			continue;
		}
		else temp = arr[i];
	}
	printf("Длина самого короткого слова равна %d", temp);
	free(s);	free(arr);	// освобождение памяти

	return 0;
}
