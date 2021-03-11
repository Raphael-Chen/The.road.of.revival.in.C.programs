#include <stdio.h>

/********
    static的第N个作用是默认初始化为0。其实全局变量也具备这一属性，
    因为全局变量也存储在静态数据区。在静态数据区，内存中所有的字节默
    认值都是0x00，某些时候这一特点可以减少程序员的工作量。
********/
int a;

int main(void)
{
    static char str[10];
    char non_static[10];

    printf("integer: %d;  string: (begin)%s(end)\n", a, str);
    printf("string: (begin)%s(end)\n", non_static);

    return 0;
}


