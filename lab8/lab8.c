/* Variant 4
*/

#include <stdio.h>

int main(void) {

	char** str;
	int amount, length, temp, number = 0;

	printf("Задайте количество и длину строк: ");
	scanf("%d%d", &amount, &length);
	length++;

	str = (char**)malloc(amount * sizeof(char*));

	for (int i = 0; i < amount; i++)    {

		number++;
		str[i] = (char*)malloc(length * sizeof(char));

		printf("Задайте %d строку: ", number);
		getchar();
		fgets(str[i], length, stdin);
	}

	for (int i = 0; i < amount; i++) {

		for (int j = 0; j < length; j++) {

			number = 0;

				while (str[i][j] > str[i][number]) {

					temp = str[i][j];
					str[i][j] = str[i][number];
					str[i][number] = temp;
					number++;
				}
				number = 0;
		}
	}

	printf("Результат сортировки:\n");
	for (int i  = 0; i < amount; i++) {
		
		fputs(str[i], stdout);
		if (str[i][length - 1 != ' ']) printf("\n");
		free(str[i]);
	}
	free(str);
	
	return 0;
}
