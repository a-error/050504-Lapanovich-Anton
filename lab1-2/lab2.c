#include <stdio.h>

int main(void) {
    
    int** A, ** B, ** C;
    int i, j, k, row1, row2, col1, col2;

    do {
        printf("Задайте размеры первой матрицы: ");
        scanf("%d%d", &row1, &col1);
        printf("Задайте размеры второй матрицы: ");
        scanf("%d%d", &row2, &col2);

        if ((row1 <= 0) 
        || (row2 <= 0) 
        || (col1 <= 0) 
        || (col2 <= 0)) {   
            printf("Задаваемые значения должны быть больше нуля.\n");
            continue;
        }
        if (row2 != col1) { 
            printf("Умножение невозможно! Задайте другие значения.\n");
            continue;
        }
    } while ((row2 != col1) 
    || (row1 <= 0) 
    || (row2 <= 0) 
    || (col1 <= 0) 
    || (col2 <= 0));
    
    A = (int**)malloc(row1 * sizeof(int*));  
    B = (int**)malloc(row2 * sizeof(int*));
    C = (int**)malloc(row1 * sizeof(int*));

    system("clear");
    printf("Матрица 1:\n");
    for (i = 0; i < row1; i++) {   
        A[i] = (int*)malloc(col1 * sizeof(int));    
        C[i] = (int*)malloc(col2 * sizeof(int));
        for (j = 0; j < col1; j++) {
            A[i][j] = rand() % 21 - 10;
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Матрица 2:\n");
    for (i = 0; i < row2; i++) {   
        B[i] = (int*)malloc(col2 * sizeof(int));    
        for (j = 0; j < col2; j++) {
            B[i][j] = rand() % 21 - 10;
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < row1; i++) {    
        for (j = 0; j < col2; j++) {
            for (k = 0; k < col1; k++) {
                C[i][j] = A[i][k] * B[k][j];
            }
        }
    }

    printf("Полученная матрица:\n");
    for (i = 0; i < row1; i++) {   
        for (j = 0; j < col2; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < row1; i++) {
        free(A[i]);
        free(C[i]);
    }

    for (i = 0; i < row2; i++) {   
        free(B[i]);  
    }
    free(A);     free(B);    free(C);

    return 0;
}
