#include <stdio.h>
#include <stdlib.h> /* for EXIT_SUCCESS */

// Sometimes it's necessary to set an array to zero, after the initialization has been done.

#define ARRLEN (10)

int main(void)
{
    int array[ARRLEN]; // * Allocated but not initialised, as not defined static or global.
    size_t i;

    for (i = 0; i < ARRLEN; ++i)
    {
        array[i] = 0;
    }

    return EXIT_SUCCESS;
}

