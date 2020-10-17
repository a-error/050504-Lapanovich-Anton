#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main() {

    setlocale(LC_ALL, "Russian");
    int** arr;
    int i, j, n, k = 0;
error:
    printf(" Задайте порядок матрицы: ");
    scanf_s("%d", &n);
    system("cls");

    if (n <= 0) {    // проверка допустимых значений
        printf("Порядок матрицы должен быть больше нуля, пропробуйте ещё раз!\n");

        goto error;
    }
    arr = (int**)malloc(n * sizeof(int*));    // выделение памяти для строк

    for (i = 0; i < n; i++) {    // выделение памяти для элементов строк
        arr[i] = (int*)malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {    // заполнение матрицы
            arr[i][j] = k;    
            k++;
        }
    }
    printf(" Ваша матрица: \n");
    for (i = 0; i < n; i++) {    // вывод матрицы 

        for (j = 0; j < n; j++) printf("%5d ", arr[i][j]);
        printf("\n");
    }
    printf("\n Транспонированная матрица: \n");

    for (i = 0; i < n; i++) {    // вывод транспонированной матрицы 

        for (j = 0; j < n; j++) printf("%5d ", arr[j][i]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < n; i++) free(arr[i]);
    free(arr);
    getchar();    getchar();    // убирает информацию о возвращении 0

    return 0;
}
