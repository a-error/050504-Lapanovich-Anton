/* Variant 10
*/

#include <stdio.h>

int main() {
   
    int** A, ** B, i, j, n, k = 0;

    do {
        printf("Задайте порядок матрицы: ");
        scanf("%d", &n);
        system("clear");
        if (n <= 0) {
            printf("Порядок матрицы должен быть больше нуля.\n");
            continue;
        }
    } while (n <= 0); 

    A = (int**)malloc(n * sizeof(int*));    
    B = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {  
        A[i] = (int*)malloc(n * sizeof(int));  
        B[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            A[i][j] = k;
            k++;
        }
    }

    printf("Исходная матрица:\n");
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {  
        for (j = 0; j < n; j++) {
            B[j][i] = A[i][j];
        }
    }

    printf("\nТранспонированная матрица:\n");
    for (i = 0; i < n; i++) {   
        for (j = 0; j < n; j++) {
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) { 
        free(A[i]);
        free(B[i]);
    }
    free(A);    free(B);    

    return 0;
}
