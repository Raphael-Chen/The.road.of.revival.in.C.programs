#include "apue.h"
#include <fcntl.h>

// Figure 13.9 Set close-on-exec flag
int set_cloexec(int fd)
{
    int val;

    if ((val = fcntl(fd, F_GETFD, 0)) < 0)
        return (-1);

    val |= FD_CLOEXEC;                 // enable close-on-exec 

    return (fcntl(fd, F_SETFD, val));  // F_SETFD: Set file descriptor flags.
}
