#include <stdio.h>

void setArrayValue(int* array, int size);
float showAverageValue(int* array, int size);

#define SIZE 10

int main(void) {

    int* array; 
    array = (int*)malloc(SIZE * sizeof(int));

    setArrayValue(array, SIZE);
    printf("Среднеарифметического этих чисел =  %.1f", 
        showAverageValue(array, SIZE));
    
    return 0;
}

void setArrayValue(int* array, int size) {

    printf("Задайте значения элементов массива: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &*(array+ i));
    }
}

    float showAverageValue(int* array, int size) {
    
    float AverageValue = 0;
    for (int i = 0; i < SIZE; i++) {
        AverageValue += *(array + i);
    }
    AverageValue = AverageValue / SIZE;

    return AverageValue;
}
