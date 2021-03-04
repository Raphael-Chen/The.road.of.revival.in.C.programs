//Keyword for static function
#include <stdio.h>

// static 修饰局部变量
int fun(void)
{
    static int count = 10; // 事实上此赋值语句只执行过最初一次

    return count--;
}

int count = 1;

int main(void)
{
    printf("global\t\tlocal static\n");
    
    for (; count <= 10; ++count)
        printf("%d\t\t%d\n", count, fun());

    return 0;
}
