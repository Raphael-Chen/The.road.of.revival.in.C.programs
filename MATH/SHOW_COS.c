#include <stdio.h>
#include <math.h>

/*
    #include <math.h>
    double cos(double x);
    float cosf(float x);
    long double cosl(long double x);
    
    Description
    The cos functions compute the cosine of x (measured in radians).

    Returns
    The cos functions return cos x.
*/
int main(void)
{
    printf("cosine of pi/2 is %6.4f\n", cos(3.14159 / 2.0));
    printf("cosine of pi is %6.4f\n", cos(3.14159));

    return 0;
}
