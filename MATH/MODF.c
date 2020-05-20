#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double modf(double x, double *iptr);
       float modff(float x, float *iptr);
       long double modfl(long double x, long double *iptr);

       Link with -lm.

        Description
        The modf functions break the argument value into integral and fractional parts, each of
        which has the same type and sign as the argument. They store the integral part (in 
        floating-point format) in the object pointed to by iptr.

        Returns
        The modf functions return the signed fractional part of value.

*/

int main(void)
{
    double value = 1.2345;
    double int_part;
    double fraction;

    fraction = modf(value, &int_part);

    printf("Value %f Integer part %f Fraction %f\n",
           value, int_part, fraction);

    return 0;
}
