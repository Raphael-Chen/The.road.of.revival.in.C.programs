#include <stdio.h>


//在for循环中使用一个以上的变量
int main(void)
{
    int i, j;

    for (i = 0, j = 100; i <= 100; i++, j++)
        printf("i = %d j = %d\n", i, j);

    return 0;
}
