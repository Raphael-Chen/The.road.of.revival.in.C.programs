#include <stdio.h>
#include <math.h>


/*
    #include <math.h>
    double exp(double x);
    float expf(float x);
    long double expl(long double x);
    
    Description
    The exp functions compute the base-e exponential of x. A range error occurs if the
    magnitude of x is too large.
*/
// 该函数返回 e 的 x 次幂。

int main(void)
{
    double value;

    for (value = 0.0; value <= 1.0; value += 0.1)
        printf("exp(%f) is %f\n", value, exp(value));

    return 0;        
}
