#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

// Figure 16.12 Initialize a socket endpoint for use by a server
// Figure 16.12 shows a function we can use to allocate and initialize a socket for use by a
// server process.
int initserver(int type, const struct sockaddr *addr, 
                socklen_t alen, int qlen)
{
    int fd;
    int err = 0;

    if ((fd = socket(addr->sa_family, type, 0)) < 0)
        return (-1);

    if (bind(fd, addr, alen) < 0)
        goto errout;

    if (type == SOCK_STREAM || type == SOCK_SEQPACKET)
    {
        if (listen(fd, qlen) < 0)
            goto errout;
    }
    return (fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return (-1);
}
