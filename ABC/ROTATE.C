#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned value = 1;

    printf("%u rotated right once is %u\n", value,
           _rotr(value, 1));  //out of time _rotr function

    value = 5;
    printf("%u rotated right twice is %u\n", value,
           _rotr(value, 2));

    value = 65534;
    printf("%u rotated left twice is %u\n", value,
           _rotl(value, 2));
}
