#include <stdio.h>


// 传值与传址的区别
void display_and_change(int first, int second, int third)
{
    printf("Original function values %d %d %d\n",
           first, second, third);

    first += 100;
    second += 100;
    third += 100;

    printf("Ending function values %d %d %d\n",
           first, second, third);
}

int main(void)
{
    int a = 1, b = 2, c = 3;

    display_and_change(a, b, c);  // 不影响变量原值，只修改副本

    printf("Ending values in main %d %d %d\n", a, b, c);
}
