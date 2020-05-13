#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double fabs(double x);
       float fabsf(float x);
       long double fabsl(long double x);

       Link with -lm.

        Description
        The fabs functions compute the absolute value of a floating-point number x.

        Returns
        The fabs functions return | x |.
*/

int main(void)
{
    float value;

    for (value = -1.0; value <= 1.0; value += 0.1)
        printf("Value %f fabs %f\n", value, fabs(value));

    return 0;        
}
