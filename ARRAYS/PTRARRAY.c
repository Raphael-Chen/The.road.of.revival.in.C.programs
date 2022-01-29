#include <stdio.h>

// Iterating through an array using pointers

int main(void)
{
    int values[5] = {1, 2, 3, 4, 5};
    int counter;
    int *iptr;

    iptr = values;

    for (counter = 0; counter < 5; counter++)
    {
        printf("%d\n", *iptr);
        iptr++;
    }

    return 0;
}
