#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main() {

    setlocale(LC_ALL, "Russian") ;
    int** arr ;
    int i, j, n, k = 0;
    printf_s("Задайте порядок матрицы: ") ;
    scanf_s("%d", &n) ;
    arr = (int**)malloc(n * sizeof(int*)) ;    // выделение памяти для строк

    for (i = 0; i < n; i++) {    // выделение памяти для элементов строк
        arr[i] = (int*)malloc(n * sizeof(int)) ;

        for (j = 0; j < n; j++) {    // заполнение матрицы числами
            arr[i][j] = k + 1 ;    
            k++ ;
        }
    }

    for (i = 0; i < n; i++) {    // вывод матрицы 

        for (j = 0; j < n; j++) printf_s("%5d ", arr[i][j]) ;    
        printf_s("\n") ;
    } 
    printf_s("\n") ;

    for (i = 0; i < n; i++) {    // вывод транспонированной матрицы 

        for (j = 0; j < n; j++) printf_s("%5d ", arr[j][i]) ;
        printf_s("\n") ;
    }
    printf_s("\n") ;

    for (i = 0; i < n; i++) free(arr[i]) ;
    free(arr) ;
    getchar() ;    getchar() ;    // убирает информацию о возвращении 0
    
    return 0 ;
}
