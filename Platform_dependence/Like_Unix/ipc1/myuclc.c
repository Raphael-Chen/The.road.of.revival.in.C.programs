#include "apue.h"
#include <ctype.h>


// Figure 15.14 Filter to convert uppercase characters to lowercase
// We compile this filter into the executable file myuclc, which we then invoke from
// the program in Figure 15.15 using popen.

int main( void )
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (isupper(c))
            c = tolower(c);

        if (putchar(c) == EOF)
            err_sys("output error");

        if (c == '\n')
            fflush(stdout);
    }

    exit(0);
}
