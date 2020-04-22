#include <stdio.h>

// 传入实参地址，可以直接修改实参的值
void display_and_change(int *first, int *second, int *third)
{
    printf("Original function values %d %d %d\n",
           *first, *second, *third);

    *first  += 100;   // *first = *first + 100
    *second += 100;
    *third  += 100;

    printf("Ending function values %d %d %d\n",
           *first, *second, *third);
}

int main(void)
{
    int a = 1, b = 2, c = 3;

    display_and_change(&a, &b, &c);
    printf("Ending values in main %d %d %d\n", a, b, c);

    return 0;
}
