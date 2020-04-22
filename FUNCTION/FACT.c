#include <stdio.h>

// 递归函数(计算value的阶层)
int factorial(int value)
{
    if (value == 1)
        return (1);
    else
        return (value * factorial(value - 1));
}

int main(void)
{
    int i;

    for (i = 1; i <= 5; i++)
        printf("The factorial of %d is %d\n", i, factorial(i));

    return 0;    
}
