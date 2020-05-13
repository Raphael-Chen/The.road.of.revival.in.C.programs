#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double atan(double x);
       float atanf(float x);
       long double atanl( long double x);

       Link with -lm.


        Description
        The atan functions compute the principal value of the arc tangent of x.

        Returns
        The atan functions return arctan x in the interval [− π /2, + π /2] radians.
*/

int main(void)
{
    double radians;

    for (radians = -0.5; radians <= 0.5; radians += 0.2)
        printf("%f %f\n", radians, atan(radians));

    return 0;        
}
