#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int* arr, n, i, j;

	do {
		printf("Задайте количество чисел: ");
		scanf_s("%d", &n);
		system("cls");
		if (n <= 0) printf("Задаваемое значение должно быть больше нуля.\n");	
	} while (n <= 0);	// проверка на допустимость значения
	arr = (int*)malloc(n * sizeof(int));	// выделение памяти под хранение элементов
	printf("Простые числа:");

	for (i = 0; i < n; i++) {	// заполнение и вывод массива
		arr[i] = i;
		if (i % 10 == 0) printf("\n");
		printf("%4d", arr[i]);
	}
	arr[1] = 0;	// замена на простое число
	printf("\n\nМеньшие n-простые числа:");

	for (i = 0; i < n; i++) {	// отбор чисел согласно Решето Эратосфена
		if (arr[i] == 0) continue;
		for (j = 0; j < n; j++) {
			if (arr[j] == 0) continue;
			else if (j <= i) continue;
			else if (arr[j] % arr[i] == 0) arr[j] = 0;	
		}
	}

	for (i = 0; i < n; i++) {	// вывод массива
		if (i % 10 == 0) printf("\n");
		printf("%4d", arr[i]);
	}
	free(arr);	// освобождение памяти хранения элементов

	return 0;
}
