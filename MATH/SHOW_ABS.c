#include <stdio.h>
#include <stdlib.h>

/*
    #include <stdlib.h>
    int abs(int j);
    long int labs(long int j);
    long long int llabs(long long int j);


    Description
    The abs, labs, and llabs functions compute the absolute value of an integer j. If the
    result cannot be represented, the behavior is undefined. 
*/

int main(void)
{
    printf("The absolute value of %d is %d\n", 5, abs(5));
    printf("The absolute value of %d is %d\n", 0, abs(0));
    printf("The absolute value of %d is %d\n", -5, abs(-5));

    return 0;
}
 