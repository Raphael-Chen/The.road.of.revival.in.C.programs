#include <stdio.h>

int main(void)
{
    int value = 1;

    printf("Using postfix %d\n", value--);
    printf("Value after decrement %d\n", value);

    value = 1;

    printf("Using prefix %d\n", --value);
    printf("Value after decrement %d\n", value);
}
