#include <stdio.h>

// 比较运算符——等号与不等号的展示
int main(void)
{
    int age = 21;
    int height = 73;

    if (age == 21)
        printf("User's age is 21\n");

    if (age != 21)
        printf("User's age is not 21\n");

    if (height == 73)
        printf("User's height is 73\n");

    if (height != 73)
        printf("User's height is not 73\n");

    return 0;
}
