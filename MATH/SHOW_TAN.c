#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double tan(double x);
       float tanf(float x);
       long double tanl(long double x);

       Link with -lm.

       The tan functions return the tangent of x (measured in radians).
*/


int main(void)
{
    double pi = 3.14159265;

    printf("Tangent of pi is %f\n", tan(pi));
    printf("Tangent of pi/4 is %f\n", tan(pi / 4.0));

    return 0;
}
