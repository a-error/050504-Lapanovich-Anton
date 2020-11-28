#include <stdio.h>

int main() {

	char** str;
	int i, j, n, m, temp, k = 0;
	printf("Задайте количество и длину строк: ");
	scanf("%d%d", &n, &m);
	m++;
	str = (char**)malloc(n * sizeof(char*));

	for (i = 0; i < n; i++)	{
		k++;
		str[i] = (char*)malloc(m * sizeof(char));	
		printf("Задайте %d строку: ", k);
        if(k == 1) getchar();
		fgets(str[i], m, stdin);
	}
    i = 0;
	while(i < n) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < m; k++) {

				while (str[i][j] > str[i][k])
				{
					temp = str[i][j];
					str[i][j] = str[i][k];
					str[i][k] = temp;
				}
			}
		}
        i++;
	}
	printf("Результат сортировки:\n");

	for (i = 0; i < n; i++)	
	{
		fputs(str[i], stdout);
		free(str[i]);
	}
	free(str);
	
	return 0;
}
