#include <stdio.h>
#include <math.h>


/*
       #include <math.h>

       double pow(double x, double y);
       float powf(float x, float y);
       long double powl(long double x, long double y);

       Link with -lm.
*/

int main(void)
{
    int power;

    for (power = -2; power <= 2; power++)
        printf("10 raised to %d is %f\n", power,
               pow(10.0, power));

    return 0;               
}
