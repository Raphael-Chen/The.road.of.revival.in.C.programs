#include "apue.h"
#include <sys/socket.h>

// Figure 16.10 Connect with retry
// Figure 16.10 shows one way to handle transient connect errors. These errors are likely
// with a server that is running on a heavily loaded system.
// There is a problem with the code shown in Figure 16.10: it isn’t portable.
// This technique works on Linux and Solaris, but doesn’t work as expected on FreeBSD and
// Mac OS X. If the first connection attempt fails, BSD-based socket implementations
// continue to fail successive connection attempts when the same socket descriptor is used
// with TCP.

#define MAXSLEEP 128

int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
    int numsec;

    /*
	 * Try to connect with exponential backoff.
	 */
    for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
    {
        if (connect(sockfd, addr, alen) == 0)
        {
            /*
			 * Connection accepted.
			 */
            return (0);
        }

        /*
		 * Delay before trying again.
		 */
        if (numsec <= MAXSLEEP / 2)
            sleep(numsec);
    }
    
    return (-1);
}
