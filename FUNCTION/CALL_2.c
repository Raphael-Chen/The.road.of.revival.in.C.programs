#include <stdio.h>

// 底层
void hello_world(void)
{
    printf("Hello, world!\n");
}

// 中间层
void three_hellos(void)
{
    int counter;

    for (counter = 1; counter <= 3; counter++)
        hello_world();
}

// 顶层调用
int main(void)
{
    three_hellos();
    return 0;
}
