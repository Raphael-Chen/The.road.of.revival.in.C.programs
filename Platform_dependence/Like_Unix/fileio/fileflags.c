#include "apue.h"
#include <fcntl.h>

// Figure 3.11 Print file flags for specified descriptor

int main(int argc, char *argv[])
{
    int val;

    if (argc != 2)
        err_quit("usage: a.out <descriptor#>");

    val = fcntl(atoi(argv[1]), F_GETFL, 0);  // Get/set file status flags (cmd = F_GETFL or F_SETFL)
    if ( val < 0 )
        err_sys("fcntl error for fd %d", atoi(argv[1]));

    switch (val & O_ACCMODE)
    {
        case O_RDONLY:
            printf("read only");
            break;

        case O_WRONLY:
            printf("write only");
            break;

        case O_RDWR:
            printf("read write");
            break;

        default:
            err_dump("unknown access mode");
    }

    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", nonblocking");
    if (val & O_SYNC)
        printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes");
#endif

    putchar('\n');
    return 0;
}

/******
$ ./fileflags 0 < /dev/tty
read only
$ ./fileflags 1 >temp.foo
$ cat temp.foo
write only
$ ./fileflags 2 2>>temp.foo
write only, append
$ ./fileflags 5 5<>temp.foo
read write
******/