#include <stdio.h>

// The difference bettwen x++ and ++x

int main(void)
{
    int value = 1;

    printf("Using postfix %d\n", value++);
    printf("Value after increment %d\n", value);

    value = 1;

    printf("Using prefix %d\n", ++value);
    printf("Value after increment %d\n", value);

    return 0;
}
