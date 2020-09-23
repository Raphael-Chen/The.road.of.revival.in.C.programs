#include "apue.h"

// Figure 1.9. Print user ID and group ID

int main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    
    exit(0);
}

/***
    NAME
        getuid, geteuid - get user identity

    SYNOPSIS
        #include <unistd.h>
        #include <sys/types.h>

        uid_t getuid(void);
        uid_t geteuid(void);

    DESCRIPTION
        getuid() returns the real user ID of the calling process.

        geteuid() returns the effective user ID of the calling process.
***/