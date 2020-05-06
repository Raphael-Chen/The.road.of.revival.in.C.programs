#include <stdio.h>

long long convertDecimalToBinary(int n);

int main(void)
{
    int n;
    printf("输入一个十进制数: ");
    scanf("%d", &n);
    printf("十进制数- %d 转换为二进制位: %lld \n", n, convertDecimalToBinary(n));
    return 0;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder,
        quotient,
        i = 1,
        step = 1;

    while (n != 0)
    {
        remainder = n % 2;
        quotient = n / 2;
        printf("Step %d: %d/2, 余数 = %d, 商 = %d\n", step++, n, remainder, quotient);
        n = quotient;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}
