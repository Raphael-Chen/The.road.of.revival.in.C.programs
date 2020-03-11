#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

int main(void)
{
    printf("The square of 2 is %d\n", SQUARE(2));
    printf("The cube of 100 is %f\n", CUBE(100.0));
}
