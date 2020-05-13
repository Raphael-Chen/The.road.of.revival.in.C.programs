#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double asin(double x);
       float asinf(float x);
       long double asinl(long double x);

       Link with -lm.

        Description
        The asin functions compute the principal value of the arc sine of x. A domain error
        occurs for arguments not in the interval [−1, +1].

        Returns
        The asin functions return arcsin x in the interval [− π /2, + π /2] radians.
*/


int main(void)
{
    double radians;

    for (radians = -0.5; radians <= 0.5; radians += 0.2)
        printf("%f %f\n", radians, asin(radians));

    return 0;
}
