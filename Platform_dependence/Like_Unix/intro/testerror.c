#include "apue.h"
#include <errno.h>

// Figure 1.8 Demonstrate strerror and perror

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES)); //#define EACCES 13	/* Permission denied */
    errno = ENOENT;                                    //#define ENOENT 2 /* No such file or directory */
    perror(argv[0]);

    return 0;
}

// Figure 1.8 shows the use of these two error functions.
