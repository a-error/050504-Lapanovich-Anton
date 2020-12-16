/* Variant 1
*/
#define SIZE 10
#include <stdio.h>
void setArrayValue(int* array, int size);
float showAverageValue(int* array, int size);
int main(void) {
    int array[SIZE];
    setArrayValue(array, SIZE);
    printf("Среднеарифметическое этих чисел = %.2f", 
        showAverageValue(array, SIZE));
    return 0;
}
void setArrayValue(int* array, int size) {
    printf("Задайте значения элементов массива: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &*(array + i));
    }
}
float showAverageValue(int* array, int size) {
    float AverageValue = 0;
    for (int i = 0; i < size; i++) {
        AverageValue += *(array + i);
    }
    AverageValue = AverageValue / size;  
    return AverageValue;
}
