#include "apue.h"


// Figure 8.25. Print real and effective user IDs

int main(void)
{
    printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());

    exit(0);
}


// NAME
//        getuid, geteuid - get user identity
//
// SYNOPSIS
//        #include <unistd.h>
//        #include <sys/types.h>
//
//        uid_t getuid(void);
//        uid_t geteuid(void);
//
// DESCRIPTION
//        getuid() returns the real user ID of the calling process.
//
//        geteuid() returns the effective user ID of the calling process.

// ERRORS
//        These functions are always successful.
