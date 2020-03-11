#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int int_result;
    float float_result;
    long long_result;

    int_result   = atoi("1234");
    float_result = atof("12345.678");  //? 12345.677734
    long_result  = atol("1234567L");

    printf("%d %f %ld\n", int_result, float_result, long_result);
}
