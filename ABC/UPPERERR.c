#include <stdio.h>

// 编译错误：main首字母大写，C语言大小写严格
// (.text+0x20): undefined reference to `main'
int Main( void )
{
    printf("This program does not compile.");

    return 0;
}
