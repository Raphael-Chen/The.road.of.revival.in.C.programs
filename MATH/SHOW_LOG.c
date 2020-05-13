#include <stdio.h>
#include <math.h>

/*
       #include <math.h>

       double log(double x);
       float logf(float x);
       long double logl(long double x);

       Link with -lm.

        Description
        The log functions compute the base-e (natural) logarithm of x. A domain error occurs if
        the argument is negative. A pole error may occur if the argument is zero.

        Returns
        The log functions return log e x.
*/

int main(void)
{
    printf("Natural log of 256.0 is %f\n", log(256.0));

    return 0;
}
