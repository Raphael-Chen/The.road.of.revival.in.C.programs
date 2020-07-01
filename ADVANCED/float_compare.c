#include <stdio.h>

/*
    4.3.3 浮点变量与零值比较
    【规则4-3-3】不可将浮点变量用“==”或“！=”与任何数字比较。
    千万要留意，无论是float还是double类型的变量，都有精度限制。
    所以一定要避免将浮点变量用“==”或“！=”与数字比较，应该设法转化成“>=”或“<=”形式。
*/
int main( void )
{
    float d1, d2, d3, d4;

    d1 = 194268.02;
    d2 = 194268;
    d4 = 0.02;

    d3 = d1 - d2;
    if (d3 > d4)
        printf(">0.02\n");
    else if (d3 < d4)
        printf("<0.02\n");
    else
        printf("=0.02\n");

    printf("%f - %f = %f \n", d1, d2, d3);

    return 0;
}