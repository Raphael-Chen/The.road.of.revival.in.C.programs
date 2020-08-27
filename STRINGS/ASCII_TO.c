#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int int_value;
    float flt_value;
    long long_value;

    int_value = atoi("12345");
    flt_value = atof("33.45");
    long_value = atol("12BAD");   //? 12
    // long_value = atol("0x12BAD");

    printf("int %d float %5.2f long %ld\n", int_value,
           flt_value, long_value);
}
