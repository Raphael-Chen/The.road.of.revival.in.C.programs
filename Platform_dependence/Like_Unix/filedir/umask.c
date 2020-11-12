#include "apue.h"
#include <fcntl.h>

// Figure 4.9. Example of umask function
/*******
NAME
       umask - set file mode creation mask

SYNOPSIS
       #include <sys/types.h>
       #include <sys/stat.h>

       mode_t umask(mode_t mask);
********/


#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
    umask(0);
    if (creat("foo", RWRWRW) < 0)
        err_sys("creat error for foo");

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
        err_sys("creat error for bar");
        
    exit(0);
}

// Figure 4.10. The umask
// file access permission bits

// | Mask_bit | Meaning       |
// | -------- | ------------- |
// | 0400     | user-read     |
// | 0200     | user-write    |
// | 0100     | user-execute  |
// | 0040     | group-read    |
// | 0020     | group-write   |
// | 0010     | group-execute |
// | 0004     | other-read    |
// | 0002     | other-write   |
// | 0001     | other-execute |

