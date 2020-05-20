#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double frexp(double x, int *exp);
       float frexpf(float x, int *exp);
       long double frexpl(long double x, int *exp);

       Link with -lm.

       Description
        The frexp functions break a floating-point number into a normalized fraction and an
        integral power of 2. They store the integer in the int object pointed to by exp.

        Returns
        If value is not a floating-point number or if the integral power of 2 is outside the range
        of int, the results are unspecified. Otherwise, the frexp functions return the value x,
        such that x has a magnitude in the interval [1/2, 1) or zero, and value equals x × 2 *exp .
        If value is zero, both parts of the result are zero.
       
*/

int main(void)
{
    double value = 1.2345;

    double mantissa;
    int exponent;

    mantissa = frexp(value, &exponent);

    printf("Mantissa %f Exponent %d Value %f\n",
           mantissa, exponent, mantissa * pow(2.0, 1.0 * exponent));

    return 0;
}
