#include "apue.h"
#include <dirent.h>

// Chapter 1. UNIX System Overview
// Figure 1.3 List all the files in a directory

int main(int argc, char *argv[])
{
    // This is the data type of directory stream objects.
    // The actual structure is opaque to users.  
    DIR           *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");

    dp = opendir(argv[1]);
    if ( dp == NULL )
        err_sys("can't open %s", argv[1]);

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);

    return 0;
}
