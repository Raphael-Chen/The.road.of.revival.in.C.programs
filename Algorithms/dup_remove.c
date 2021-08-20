#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 数值去重
// 输入描述:
// 输入多行，先输入随机整数的个数，再输入相应个数的整数。
// 
// 输出描述:
// 返回多行，处理后的结果。
// 缺陷： 排序时， 输入数值越大空间占用越多。

//完成排序+去重
int test_student(int *array, int n) 
{
    int t[1024] = {0};
    int i;

    for (i = 0; i < n; i++)
    {
        t[array[i]] = 1; //array[i] 内容作为索引。 不重复且从小到大
    }
    
    for (i = 0; i < 1024; i++)
    {
        // if (t[i])
        if ( 1 == t[i] )
            printf("%d\n", i); 
    }

    return 0;
}


int main( void )
{
    int i, count;
    // int* num = NULL;

    while (~scanf("%d", &count) && count > 0)
    { //读取 个数

        int *a = malloc(sizeof(int) * count);

        for (i = 0; i < count; i++)
        {
            scanf("%d", &a[i]); //读取 具体数
        }
        test_student(a, count);

        free(a); 
    }

    return 0;
}

