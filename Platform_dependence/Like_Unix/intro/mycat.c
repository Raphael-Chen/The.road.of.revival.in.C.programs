#include "apue.h"

#define BUFFSIZE 4096

// read and write function
int main(void)
{
    int n;
    char buf[BUFFSIZE];

    // STDIN_FILENO	   0 /* Standard input.  */
    // STDOUT_FILENO   1 /* Standard output.  */
    // STDERR_FILENO   2 /* Standard error output.  */

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);
}
