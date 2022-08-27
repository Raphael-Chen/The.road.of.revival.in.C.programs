#include "apue.h"

// Figure 18.16 Test the ttyname function

int main(void)
{
    char *name;
    if (isatty(0))
    {
        name = ttyname(0);
        if (name == NULL)
            name = "undefined";
    }
    else
    {
        name = "not a tty";
    }
    printf("fd 0: %s\n", name);

    if (isatty(1))
    {
        name = ttyname(1);
        if (name == NULL)
            name = "undefined";
    }
    else
    {
        name = "not a tty";
    }
    printf("fd 1: %s\n", name);

    if (isatty(2))
    {
        name = ttyname(2);
        if (name == NULL)
            name = "undefined";
    }
    else
    {
        name = "not a tty";
    }
    printf("fd 2: %s\n", name);

    exit(0);
}

// Running the program from Figure 18.16 gives us
// # ./t_ttyname < /dev/console 2> /dev/null
// fd 0: /dev/console
// fd 1: /dev/pts/3
// fd 2: not a tty
