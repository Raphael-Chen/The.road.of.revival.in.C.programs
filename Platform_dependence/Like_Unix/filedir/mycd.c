#include "apue.h"

/*************
 * 
 *  NAME
 *      chdir, fchdir - change working directory
 * 
 *  SYNOPSIS
 *      #include <unistd.h>
 * 
 *      int chdir(const char *path);
 *      int fchdir(int fd);
 **********/

int main(void)
{
    if (chdir("/tmp") < 0)
        err_sys("chdir failed");
    printf("chdir to /tmp succeeded\n");
    
    exit(0);
}
