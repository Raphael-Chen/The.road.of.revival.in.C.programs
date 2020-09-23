#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES)); //#define EACCES 13	/* Permission denied */
    errno = ENOENT;                                    //#define ENOENT 2 /* No such file or directory */
    perror(argv[0]);

    exit(0);
}
