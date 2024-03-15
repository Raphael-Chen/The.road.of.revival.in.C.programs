#include "apue.h"
#include <fcntl.h>

// Figure 3.12 Turn on one or more of the file status flags for a descriptor

/* flags are file status flags to turn on */
void set_fl(int fd, int flags) 
{
    int val;

    val = fcntl(fd, F_GETFL, 0);
    if ( val < 0 )
        err_sys("fcntl F_GETFL error");

    /* turn on flags */
    val |= flags;
    // val &= ~flags; /* turn flags off */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}
