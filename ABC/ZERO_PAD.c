#include <stdio.h>

// Pad with zero from left of value
int main(void)
{
    int value = 5;

    printf("%01d\n", value);
    printf("%02d\n", value);
    printf("%03d\n", value);
    printf("%04d\n", value);
    printf("%15d\n", value); // 15 space to fill

    return 0;
}
