/* Variant 3
*/
#include <stdio.h>
int divider(int a, int b, int counter);
int main(void) {
    int a, b, counter;
    counter = a;
    printf("Задайте два числа: ");
    scanf("%d%d", &a, &b);
    printf("Наибольший общий делитель = %d", divider(a, b, counter));
    return 0;
}
int divider(int a, int b, int counter) {
    if ((a % counter == 0) && (b % counter == 0)) {
    return counter;
    }
    else {
    counter--;
    divider(a, b, counter);
    }
}
