#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100

/*
    在 C 语言中，程序中 malloc 等内存分配函数的使用次数一定要和 free 相等，并一一配对使用。
    绝对要避免“malloc 两次 free 一次”或者“malloc 一次 free 两次”等情况。
    这就像我们的婚姻制度，必须是“一夫一妻制”，不能够“多夫一妻”或者“一夫多妻”，这些都是不合法的。

 */

int main( void )
{
    /*内存释放标志*/
    int flag = 0;

    char * p = ( char * )malloc( MAX_BUF_SIZE );
    if (p == NULL)
    {
        /*...*/
    }
    if (flag == 0)
    {
        free( p );
    }
    free( p );  
    //*** Error in `./a.out': double free or corruption (fasttop): 0x00000000009b1010 ***
    // Aborted
    return 0;
}