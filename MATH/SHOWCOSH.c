#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double cosh(double x);
       float coshf(float x);
       long double coshl(long double x);

       Link with -lm.

        Description
        The cosh functions compute the hyperbolic cosine of x. A range error occurs if the
        magnitude of x is too large.

        Returns
        The cosh functions return cosh x.
*/

int main(void)
{
    double radians;

    for (radians = -0.5; radians <= 0.5; radians += 0.2)
        printf("%f %f\n", radians, cosh(radians));

    return 0;        
}
