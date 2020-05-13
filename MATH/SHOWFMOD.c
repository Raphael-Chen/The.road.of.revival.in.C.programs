#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double fmod(double x, double y);
       float fmodf(float x, float y);
       long double fmodl(long double x, long double y);

       Link with -lm.

        Description
        The fmod functions compute the floating-point remainder of x/y.

        Returns
        The fmod functions return the value x − ny, for some integer n such that, if y is nonzero,
        the result has the same sign as x and magnitude less than the magnitude of y. If y is zero,
        whether a domain error occurs or the fmod functions return zero is implementation-defined.
*/

int main(void)
{
    double numerator = 10.0;
    double denominator = 3.0;

    printf("fmod(10, 3) is %f\n", fmod(numerator, denominator));

    return 0;
}
