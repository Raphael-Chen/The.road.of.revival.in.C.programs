#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double sin(double x);
       float sinf(float x);
       long double sinl(long double x);

       Link with -lm.
*/

int main(void)
{
    double radians;

    for (radians = 0.0; radians < 3.1; radians += 0.1)
        printf("Sine of %f is %f\n", radians, sin(radians));

    return 0;        
}
