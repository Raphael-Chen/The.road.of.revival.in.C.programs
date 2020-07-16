#include <stdio.h>

typedef int (*fun_ptr)(int, int); // 声明一个指向同样参数、返回值的函数指针类型
// 实例
// 以下实例声明了函数指针变量 p，指向函数 max：


int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    /* p 是函数指针 */
    int (*p)(int, int) = &max; // &可以省略
    int a, b, c, d;

    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c);

    printf("最大的数字是: %d\n", d);

    return 0;
}
