#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool x = true;  /* equivalent to bool x = 1; */
    bool y = false; /* equivalent to bool y = 0; */

    if (x)          /* Functionally equivalent to if (x != 0) or if (x != false) */
    {
        puts("This will print!");
    }
    
    if (!y) /* Functionally equivalent to if (y == 0) or if (y == false) */
    {
        puts("This will also print!");
    }

    return 0;
}

/*
bool is just a nice spelling for the data type _Bool . It has special rules when numbers or pointers
are converted to it.
*/
