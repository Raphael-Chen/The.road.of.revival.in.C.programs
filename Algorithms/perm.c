#include <stdio.h>

// 排列数：仅包含自然数范围排列，不不包含小数，复数等
// 公式：  p(n,m) = n!/(n-m)! =n(n-1)(n-2)……(n-m+1)

#define N 4

int a[N];

void perm(int); // 求数组的全排列
void output_all( int* array );
void swap( int* array, int i, int offset);

int main( void )
{
    int i;
    for (i = 0; i < N; ++i)
    {
        a[i] = i + 1;
    }

    perm(0);

    return 0;
}

void perm(int offset)
{
    int i;
    static int times = 1;
    if (offset == N - 1)
    { // BaseCase
        output_all( a );
        // printf( "%d times.\n", times );
        return;
    }
    else
    {
        for (i = offset; i < N; ++i)
        {
            swap( NULL, i, offset);  //交换前缀
            perm(offset + 1);        //递归
            swap( NULL, i, offset);  //将前缀换回来，继续做前一次排列
            times++;
        }
    }
}

void output_all( int* array )
{
    int i;
    for (i = 0; i < N; ++i)
        printf(" %d ", array[i]);
    printf("\n");
}

void swap( int* array, int i, int offset)
{
    int temp;
    temp = a[offset];
    a[offset] = a[i];
    a[i] = temp;
}
