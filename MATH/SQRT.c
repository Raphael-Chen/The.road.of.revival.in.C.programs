#include <stdio.h>
#include <math.h>  // When you compile remenber add -lm like: gcc -std=c11 -Wall -Wextra SQRT.c -lm

/*
    #include <math.h>
    double sqrt(double x);  

    The sqrt functions compute the nonnegative square root of x. A domain error occurs if
    the argument is less than zero.
*/

int main(void)
{
    double value;

    for (value = 0.0; value < 10.0; value += 0.1)
        printf("Value %f sqrt %f\n", value, sqrt(value));

    return 0;       
}
