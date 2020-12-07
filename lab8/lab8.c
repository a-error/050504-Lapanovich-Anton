/* Variant 4
*/

#include <stdio.h>

int main(void) {

	char** array;
	int amount, length, temp, number = 0;

	printf("Задайте количество и длину строк: ");
	scanf("%d%d", &amount, &length);
	length += 2;;
	getchar();
	
	array = (char**)malloc(amount * sizeof(char*));

	for (int i = 0; i < amount; i++)    {

		number++;
		*(array + i) = (char*)malloc(length * sizeof(char));

		printf("Задайте %d строку: ", number);
		fgets(*(array + i), length, stdin);
	}

	for (int i = 0; i < amount; i++) {

		for (int j = 0; j < length; j++) {

			number = 0;

				while (*(*(array + i) + j) > *(*(array + i) + number)) {

					temp = *(*(array + i) + j);
					*(*(array + i) + j) = *(*(array + i) + number);
					*(*(array + i) + number) = temp;
					number++;
				}
				number = 0;
		}
	}

	printf("Результат сортировки:\n");
	for (int i  = 0; i < amount; i++) {
		
		fputs(*(array + i), stdout);
		free(*(array + i));
	}
	free(array);
	
	return 0;
}
