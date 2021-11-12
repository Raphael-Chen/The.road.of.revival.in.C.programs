#include "apue.h"
#include <sys/socket.h>

// Figure 16.11 Portable connect with retry

// Because of this, portable applications need to close the socket if connect fails. If
// we want to retry, we have to open a new socket.

#define MAXSLEEP 128

int connect_retry(int domain, int type, int protocol,
                  const struct sockaddr *addr, socklen_t alen)
{
    int numsec, fd;

    /*
	 * Try to connect with exponential backoff.
	 */
    for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
    {
        if ((fd = socket(domain, type, protocol)) < 0)
            return (-1);

        if (connect(fd, addr, alen) == 0)
        {
            /*
			 * Connection accepted.
			 */
            return (fd);
        }
        close(fd);

        /*
		 * Delay before trying again.
		 */
        if (numsec <= MAXSLEEP / 2)
            sleep(numsec);
    }

    return (-1);
}
