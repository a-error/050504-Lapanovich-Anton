/* Variant 3
*/

#include <stdio.h>

int main(void) {

	char* string;
	int* array, i, length, temp = 0;

	printf("Задайте длину строки: ");
	scanf("%d", &length);
	length++;

	string = (char*)malloc(length * sizeof(char));	
	array = (int*)calloc(length, sizeof(int));	

	printf("Задайте строку: ");
	getchar();

	fgets(string, length, stdin);
	for (i = 0; i < length; i++)	{
		if (*(string + i) == ' ') {
			if (i == length - 2)	{

				continue;
			}
			*(array + i) = temp;
			temp = 0;

			continue;
		}
		if (i == length - 1)	{

			*(array + i) = temp;

			break;
		}
		if (*(string + i) == '\0') {

			temp--;
			*(array + i) = temp;

			break;
		}
		temp++;
	}

	for (i = 0; i < length; i++)	{
		if ((*(array + i) == 0) || (temp < *(array + i))) {

			continue;
		}
		else temp = *(array + i);
	}

	printf("Длина самого короткого слова равна %d", temp);
	free(string);	
        free(array);	

	return 0;
}
