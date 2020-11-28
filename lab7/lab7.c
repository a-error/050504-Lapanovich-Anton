/* Variant 3
*/

#include <stdio.h>


int main() {

	char* s;
	int* arr, i, n, temp = 0;

	printf("Задайте размер строки: ");
	scanf("%d", &n);
	n++;

	s = (char*)malloc(n * sizeof(char));	
	arr = (int*)calloc(n, sizeof(int));	

	printf("Задайте строку: ");
	getchar();
	fgets(s, n, stdin);

	for (i = 0; i < n; i++)	{

		if (s[i] == ' ') {
			if (i == n - 2)	{
				continue;
			}
			arr[i] = temp;
			temp = 0;
			continue;
		}

		if (i == n - 1)	{
			arr[i] = temp;
			break;
		}

		if (s[i] == '\0') {
			temp--;
			arr[i] = temp;
			break;
		}
		temp++;
	}

	for (i = 0; i < n; i++)	{
		if ((arr[i] == 0) 
		|| (temp < arr[i])) {
			continue;
		}
		else temp = arr[i];
	}

	printf("Длина самого короткого слова равна %d", temp);
	free(s);	free(arr);	

	return 0;
}
