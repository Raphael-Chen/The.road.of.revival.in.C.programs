#include <stdio.h>
#include <math.h>

/*
    #include <math.h>
    double fmax(double x, double y);

    #include <math.h>
    double fmin(double x, double y);
    float fminf(float x, float y);
*/

int main(void)   
{
    printf("Maximum of %f and %f is %f\n",
           10.0, 25.0, fmax(10.0, 25.0));
    printf("Minimum of %f and %f is %f\n",
           10.0, 25.0, fmin(10.0, 25.0));

    return 0;           
}
