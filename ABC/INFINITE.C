//永远也不满足跳出循环的条件，导致无限循环
#include <stdio.h>

int main(void)
{
    int i;
    int result = 0;
    int value = 1;

    for (i = 0; i < 100; i++)
    {
        printf("%d ", i);
        result = value * --i;
    }

    printf("Result %d\n", result);
}
