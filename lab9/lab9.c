/* Variant 1
*/
#include <stdio.h>

void setArrayValue(int* array, int size);
int showAverageValue(int* array, int size);

#define SIZE 10

int main(void) {
    
    int array[SIZE];
    
    setArrayValue(array, SIZE);
    printf("Среднеарифметическое этих чисел = %d", 
        showAverageValue(array, SIZE));
    
    return 0;
}

void setArrayValue(int* array, int size) {
    
    printf("Задайте значения элементов массива: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &*(array + i));
    }
}

int showAverageValue(int* array, int size) {
    
    int AverageValue = 0;
    for (int i = 0; i < SIZE; i++) {
        AverageValue += *(array + i);
    }
    AverageValue = AverageValue / SIZE;
    
    return AverageValue;
}
