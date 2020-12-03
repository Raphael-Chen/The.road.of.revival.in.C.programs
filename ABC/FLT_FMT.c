#include <stdio.h>

// 浮点数精度控制输出
int main(void)
{
    float value = 1.23456;

    printf("%8.1f\n", value);
    printf("%8.3f\n", value);
    printf("%8.5f\n", value);

    return 0;
}
