#include <stdio.h>
#include <math.h>

/*
        #include <math.h>
        double log10(double x);
        float log10f(float x);
        long double log10l(long double x);

        Description
        The log10 functions compute the base-10 (common) logarithm of x. A domain error
        occurs if the argument is negative. A pole error may occur if the argument is zero.
        
        Returns
        The log10 functions return log 10 x.
*/

int main(void)
{
    printf("Log10 of 100 is %f\n", log10(100.0));
    printf("Log10 of 10000 is %f\n", log10(10000.0));

    return 0;
}
