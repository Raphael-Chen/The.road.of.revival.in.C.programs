//在for循环中使用一个以上的变量
#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0, j = 100; i <= 100; i++, j++)
        printf("i = %d j = %d\n", i, j);
}
