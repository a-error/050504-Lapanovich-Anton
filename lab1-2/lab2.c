#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main() {

    setlocale(LC_ALL, "Russian");
    int** A, ** B, ** C;
    int i, j, row1, row2, col1, col2;

    do {
        printf("Задайте размеры первой матрицы: ");
        scanf_s("%d%d", &row1, &col1);
        printf("Задайте размеры второй матрицы: ");
        scanf_s("%d%d", &row2, &col2);
        system("cls");

        if ((row1 <= 0) || (row2 <= 0) || (col1 <= 0) || (col2 <=0)) {   // проверка допустимых значений
            printf("Вводимые значения должны быть больше нуля.\n");

            continue;
        }

        if (row2 != col1) {
            printf("Умножение невозможно! Задайте другие значения.");

            continue;
        }
    } while ((row2 != col1) || (row1 <= 0) || (row2 <= 0) || (col1 <= 0) || (col2 <= 0));
    A = (int**)malloc(row1 * sizeof(int*));    // выделение памяти под указатели на строки
    B = (int**)malloc(row2 * sizeof(int*));

    for (i = 0; i < row1; i++) {   // выделение памяти под хранение строк
        A[i] = (int*)malloc(col1 * sizeof(int));
        C[i] = (int*)malloc(col2 * sizeof(int));

        for (j = 0; j < row1; j++) A[i][j] = rand() % 21 - 10;  // заполнение матрицы A
    }
    
    for (i = 0; i < row2; i++) {   // заполнение матрицы B
        B[i] = (int*)malloc(col2 * sizeof(int));

        for (j = 0; j < col2; j++) B[i][j] = rand() % 10 - 0;
    }

    for (i = 0; i < row1; i++) {   // освобождение памяти хранения строк
        free(A[i]);
        free(C[i]);
    }

    for (i = 0; i < row2; i++) free(B[i]);  // освобождение памяти хранения строк
    free(A);     free(B);    free(C);   // освобождение памяти указателей на строки
    getchar();  getchar();  // убирает информацию о возвращении программой нуля

    return 0;
}
