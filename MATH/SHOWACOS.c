#include <stdio.h>
#include <math.h>


/*
    #include <math.h>
    double acos(double x);
    float acosf(float x);
    long double acosl(long double x);

    Link with -lm.

    Description
    The acos functions compute the principal value of the arc cosine of x. A domain error
    occurs for arguments not in the interval [−1, +1].

    Returns
    The acos functions return arccos x in the interval [0, π ] radians.
*/


int main(void)
{
    double radians;

    for (radians = -0.5; radians <= 0.5; radians += 0.2)
        printf("%f %f\n", radians, acos(radians));

    return 0;        
}
