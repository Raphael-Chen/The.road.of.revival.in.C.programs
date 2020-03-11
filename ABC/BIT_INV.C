#include <stdio.h>

int main(void)
{
    int value = 0xFF;

    printf("The inverse of %X is %X\n", value, ~value);
}
