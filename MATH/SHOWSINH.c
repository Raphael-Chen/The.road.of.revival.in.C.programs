#include <stdio.h>
#include <errno.h>
#include <math.h>

/*
       #include <math.h>

       double sinh(double x);
       float sinhf(float x);
       long double sinhl(long double x);

       Link with -lm.


        Description
        The sinh functions compute the hyperbolic sine of x. A range error occurs if the
        magnitude of x is too large.

        Returns
        The sinh functions return sinh x.
*/

int main(void)
{
    double radians;
    double result;

    for (radians = 0.0; radians < 3.1; radians += 0.1)
    {
        if (((result = sinh(radians)) == HUGE_VAL) &&
            (errno == ERANGE))
            printf("Overflow error\n");
        else
            printf("Sine of %f is %f\n", radians, result);
    }

    return 0;
}
