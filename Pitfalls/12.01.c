#include <stdio.h>


// It is usually not a good idea to mix signed and unsigned integers in arithmetic operations. For
// example, what will be output of following example?

int main(void)
{
    unsigned int a = 1000;
    signed int b = -1;
    if (a > b)
        puts("a is more than b");
    else
        puts("a is less or equal than b");

    return 0;
}


// Since 1000 is more than -1 you would expect the output to be a not be the case.