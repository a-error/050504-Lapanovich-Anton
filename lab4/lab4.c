/* Variant 1
*/

#include <stdio.h>

int main(void) {
	
	int* arr, n, i, j;

	do {
		printf("Задайте количество чисел: ");
		scanf("%d", &n);
		system("cls");
		if (n <= 0) {
			printf("Задаваемое значение должно быть больше нуля.\n");
		}
	} while (n <= 0);	

	arr = (int*)malloc(n * sizeof(int));	
	printf("Простые числа:");
	for (i = 0; i < n; i++) {	
		arr[i] = i;
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%4d", arr[i]);
	}

	arr[1] = 0;	
	printf("\n\nМеньшие n-простые числа:");
	for (i = 0; i < n; i++) {	
		if (arr[i] == 0) {
			continue;
		}
		for (j = 0; j < n; j++) {
			if (arr[j] == 0) {
				continue;
			}
			else if (j <= i) {
				continue;
			}
			else if (arr[j] % arr[i] == 0) {
				arr[j] = 0;
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%4d", arr[i]);
	}
	free(arr);	

	return 0;
}
