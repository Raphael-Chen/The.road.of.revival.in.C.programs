#include "apue.h"

/*********
    Figure 4.12. Example of chmod function

NAME
       chmod, fchmod - change permissions of a file

SYNOPSIS
       #include <sys/stat.h>

       int chmod(const char *path, mode_t mode);
       int fchmod(int fd, mode_t mode);
*********/

int main(void)
{
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */

    if (stat("foo", &statbuf) < 0)
        err_sys("stat error for foo");
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
        err_sys("chmod error for foo");

    /* set absolute mode to "rw-r--r--" */

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        err_sys("chmod error for bar");

    exit(0);
}
