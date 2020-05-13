#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double ceil(double x);
       float ceilf(float x);
       long double ceill(long double x);

       Link with -lm.

        Description
        The ceil functions compute the smallest integer value not less than x.

        Returns
        The ceil functions return ⎡ x ⎤ , expressed as a floating-point number.
*/

int main(void)
{
    printf("The value %f ceil %f\n", 1.9, ceil(1.9));
    printf("The value %f ceil %f\n", 2.1, ceil(2.1));

    return 0;
}
