//[Bug]为何没有溢出？
#include <stdio.h>

int main(void)
{
    // short positive = 32767;
    // short negative = -32768;

    
    short positive = 0x7FFF;
    short negative = -32768;

    printf("%d + 1 is %d\n", positive, positive + 1);
    printf("%d - 1 is %d\n", negative, negative - 1);
}
