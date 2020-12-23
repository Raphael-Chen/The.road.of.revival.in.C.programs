#include "apue.h"

// Figure 7.3. Example of exit handlers
static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
    if (atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");

    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");
    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");

    printf("main is done\n");
    return (0);
}

static void my_exit1(void)
{
    printf("first exit handler\n");
}

static void my_exit2(void)
{
    printf("second exit handler\n");
}

/***************
    7.22.4.2 The atexit function
    Synopsis
    #include <stdlib.h>
    int atexit(void (*func)(void));

    Description
    The atexit function registers the function pointed to by func, to be called without
    arguments at normal program termination. 297) It is unspecified whether a call to the
    atexit function that does not happen before the exit function is called will succeed.

    Environmental limits
    The implementation shall support the registration of at least 32 functions.

    Returns
    The atexit function returns zero if the registration succeeds, nonzero if it fails.
***************/

