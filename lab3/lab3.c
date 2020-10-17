#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Russian");
	int* arr, n, i, sum1, sum2, k, k1, k2;
	sum1 = sum2 = k = k1 = k2 = 0;
error:
	printf("Задайте количество натуральных чисел: ");
	scanf_s("%d", &n);
	system("cls");

	if (n < 0) {	// проверка допустимого значения количества чисел
		printf("Задаваемое значение должно быть больше нуля.\n");

		goto error;
	}
	printf("Исходные числа:\n");
	arr = (int*)malloc(n * sizeof(int));	// выделение памяти для массива

	for (i = 0; i < n; i++) {	// вывод массива
		arr[i] = rand() % 21 - 10;	// заполнение массива
		printf("%3d ", arr[i]);

		if ((i + 1) % 10 == 0) printf_s("\n");	// вывод матрицей
	}

	for (i = 0; i < n; i++) {

		if (arr[i] > 0) {	// проверка на положительность
			k++;	// подсчёт количества положительных чисел
			sum1 += arr[i];	// подсчёт суммы положительных чисел
		}

		else if (arr[i] < 0) {	//проверка на отрицательность
			sum2 += arr[i];	// подсчёт суммы отрицательных чисел
			k1++;	// подсчёт количества отрицательных чисел
		}

		else k2++;	// подсчёт количества нулей
	}
	printf("\nСумма положительных чисел: %d\nСумма отрицательных чисел: %d\n", sum1, sum2);
	printf("Количество положительных чисел: %d\nКоличество отрицательных чисел: %d\nКоличество нулей: %d", k, k1, k2);
	getchar();	getchar();	// убирает информацию о возвращении программой 0

	return 0;
}
