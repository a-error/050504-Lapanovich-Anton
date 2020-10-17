#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main() {

    setlocale(LC_ALL, "Russian");
    int** A, ** B;
    int i, j, n, k = 0;
error:
    printf(" Задайте порядок матрицы: ");
    scanf_s("%d", &n);
    system("cls");

    if (n <= 0) {    // проверка допустимых значений
        printf("Порядок матрицы должен быть больше нуля, пропробуйте ещё раз!\n");

        goto error;
    }
    A = (int**)malloc(n * sizeof(int*));    // выделение памяти для строк
    B = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {    // выделение памяти для элементов строк
        A[i] = (int*)malloc(n * sizeof(int));
        B[i] = (int*)malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {    // заполнение матрицы
            A[i][j] = k;
            k++;
        }
    }
    printf(" Ваша матрица: \n");
    for (i = 0; i < n; i++) {    // вывод матрицы 

        for (j = 0; j < n; j++) printf("%5d ", A[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) {     // транспонирование матрицы

        for (j = 0; j < n; j++) B[j][i] = A[i][j];
    }
    printf("\n Транспонированная матрица: \n");

    for (i = 0; i < n; i++) {    // вывод транспонированной матрицы 

        for (j = 0; j < n; j++) printf("%5d ", B[i][j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);
    getchar();    getchar();    // убирает информацию о возвращении 0

    return 0;
}
