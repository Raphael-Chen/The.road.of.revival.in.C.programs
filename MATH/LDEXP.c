#include <stdio.h>
#include <math.h>


/*
        #include <math.h>
        double ldexp(double x, int exp);
        float ldexpf(float x, int exp);
        long double ldexpl(long double x, int exp);

        Description
        The ldexp functions multiply a floating-point number by an integral power of 2. A
        range error may occur.

        Returns
        The ldexp functions return x × 2 exp .
*/


int main(void)
{
    printf("3 * 2 raised to the 4 is %f\n",    // 3 * ( 2 * 2 * 2 * 2)
           ldexp(3.0, 4));

    return 0;           
}
