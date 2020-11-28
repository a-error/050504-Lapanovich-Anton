#include <stdio.h>

int main(void) {
	
	int* arr, n, i, sum1, sum2, k, k1, k2;
	sum1 = sum2 = k = k1 = k2 = 0;

	do {
		printf("Задайте количество натуральных чисел: ");
		scanf("%d", &n);
		system("clear");
		if (n <= 0) {
			printf("Задаваемое значение должно быть больше нуля.\n");
			continue;
		}
	} while (n <= 0); 
    
	printf("Исходные числа:\n");
	arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {	
		arr[i] = rand() % 21 - 10;
		printf("%3d ", arr[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}

	for (i = 0; i < n; i++) {
		if (arr[i] > 0) {	
			k++;	
			sum1 += arr[i];
		}
		else if (arr[i] < 0) {
			sum2 += arr[i];
			k1++;	
		}
		else k2++;
	}
	free(arr);
	printf("\nСумма положительных чисел: %d\nСумма отрицательных чисел: %d\n", sum1, sum2);
	printf("Количество положительных чисел: %d\nКоличество отрицательных чисел: %d\nКоличество нулей: %d", k, k1, k2);

	return 0;
}
