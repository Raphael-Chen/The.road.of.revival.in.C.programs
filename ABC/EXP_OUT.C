#include <stdio.h>

int main(void)
{
    float pi = 3.14159;
    float radius = 2.0031;

    printf("The circle's area is %e\n", 2 * pi * radius);
    printf("The circle's area is %E\n", 2 * pi * radius);
}
