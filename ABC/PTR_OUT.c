#include <stdio.h>

// How to output a address of the variable.(with %p in printf function)
int main(void)
{
    int value;

    printf("The address of the variable value is %p\n",
           &value);

    return 0;
}
