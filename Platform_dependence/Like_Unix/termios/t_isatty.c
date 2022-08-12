#include "apue.h"

// Figure 18.14 Test the isatty function

int main(void)
{
    printf("fd 0: %s\n", isatty(0) ? "tty" : "not a tty");
    printf("fd 1: %s\n", isatty(1) ? "tty" : "not a tty");
    printf("fd 2: %s\n", isatty(2) ? "tty" : "not a tty");

    return 0;
}


// $ ./t_isatty
// fd 0: tty
// fd 1: tty
// fd 2: tty
// 
// $ ./t_isatty </etc/passwd 2>/dev/null
// fd 0: not a tty
// fd 1: tty
// fd 2: not a tty