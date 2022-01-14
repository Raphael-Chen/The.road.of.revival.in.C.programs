#include "apue.h"
#include <sys/socket.h>

// Figure 17.2 Creating a full-duplex pipe
// Figure 17.2 shows the fd_pipe function, which uses the socketpair function to
// create a pair of connected UNIX domain stream sockets.

/*
 * Returns a full-duplex pipe (a UNIX domain socket) with
 * the two file descriptors returned in fd[0] and fd[1].
 */
int fd_pipe(int fd[2])
{
    return (socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}
