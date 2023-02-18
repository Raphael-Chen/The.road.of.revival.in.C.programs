#include "apue.h"

// Figure 1.5 Copy standard input to standard output, using standard I/O

int main(void)
{
    int c;

    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    return 0;
}
