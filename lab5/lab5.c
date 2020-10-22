#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int** A, ** B, i, j, n, k = 0;

    do {
        printf("Задайте порядок матрицы: ");
        scanf_s("%d", &n);
        system("cls");
        if (n <= 0) {   
            printf("Порядок матрицы должен быть больше нуля.\n");
            continue;
        }
    } while (n <= 0);   // проверка на допустимость задаваемых значений
    A = (int**)malloc(n * sizeof(int*));    // выделение памяти под указатели строк
    B = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {   // заполнение матрицы А
        A[i] = (int*)malloc(n * sizeof(int));   // выделение памяти под хранение элементов
        B[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            A[i][j] = k;
            k++;
        }
    }
    printf("Исходная матрица:\n");

    for (i = 0; i < n; i++) {   // вывод матрицы A
        for (j = 0; j < n; j++) printf("%4d", A[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) {   // транспонирование матрицы A
        for (j = 0; j < n; j++) {
            B[j][i] = A[i][j];
        }
    }
    printf("\nТранспонированная матрица:\n");

    for (i = 0; i < n; i++) {   // вывод матрицы B
        for (j = 0; j < n; j++) printf("%4d", B[i][j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < n; i++) {   // освобождение памяти указателей строк
        free(A[i]);
        free(B[i]);
    }
    free(A);    free(B);    // освобождение памяти хранения элементов

    return 0;
}
