#include <stdio.h>
#include <string.h>

static char ctermid_name[L_ctermid];

// Figure 18.12 shows an implementation of the POSIX.1 ctermid function.

char *ctermid(char *str)
{
    if (str == NULL)
        str = ctermid_name;

    return (strcpy(str, "/dev/tty"));    /* strcpy() returns str */
}
