#include "apue.h"
#include <fcntl.h>

// Figure 4.16. Open a file and then unlink it
/********
To remove an existing directory entry, we call the unlink function.
NAME
       unlink - delete a name and possibly the file it refers to

SYNOPSIS
       #include <unistd.h>

       int unlink(const char *pathname);

    Returns: 0 if OK, 1 on error
********/

int main(void)
{
    if (open("tempfile", O_RDWR) < 0)
        err_sys("open error");
        
    if (unlink("tempfile") < 0)
        err_sys("unlink error");

    printf("file unlinked\n");
    sleep(15);
    printf("done\n");

    exit(0);
}
