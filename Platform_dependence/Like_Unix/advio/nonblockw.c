#include "apue.h"
#include <errno.h>
#include <fcntl.h>

// Figure 14.1 Large nonblocking write
char buf[500000];

int main(void)
{
    int ntowrite, nwrite;
    char *ptr;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK); /* set nonblocking */

    ptr = buf;
    while (ntowrite > 0)
    {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        if (nwrite > 0)
        {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }

    clr_fl(STDOUT_FILENO, O_NONBLOCK); /* clear nonblocking */

    exit(0);
}


// Let’s look at an example of nonblocking I/O. The program in Figure 14.1 reads up to
// 500,000 bytes from the standard input and attempts to write it to the standard output.
// The standard output is first set to be nonblocking. The output is in a loop, with the
// results of each write being printed on the standard error. The function clr_fl is
// similar to the function set_fl that we showed in Figure 3.12. This new function
// simply clears one or more of the flag bits.