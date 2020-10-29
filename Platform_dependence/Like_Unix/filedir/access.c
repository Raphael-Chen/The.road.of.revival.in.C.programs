#include "apue.h"
#include <fcntl.h>

// Figure 4.8. Example of access function
/*******
    NAME
        access - check real user's permissions for a file

    SYNOPSIS
        #include <unistd.h>

        int access(const char *pathname, int mode);
********/

int main(int argc, char *argv[])
{
    if (argc != 2)
        err_quit("usage: a.out <pathname>");

    if (access(argv[1], R_OK) < 0)
        err_ret("access error for %s", argv[1]);
    else
        printf("read access OK\n");

    if (open(argv[1], O_RDONLY) < 0)
        err_ret("open error for %s", argv[1]);
    else
        printf("open for reading OK\n");

    exit(0);
}

/********
    Figure 4.7. The mode constants
    for access function, from <unistd.h>
    |mode  | Description                 |
    |----  | -----------------------     |
    |R_OK  | test for read permission    | 
    |W_OK  | test for write permission   |
    |X_OK  | test for execute permission |
    |F_OK  | test for existence of file  |

$ ./access ./access
read access OK
open for reading OK
$ ls -l access
-rwxr-xr-x 1 raphael raphael 13632 Oct 28 11:43 access

$ ls -l /etc/shadow
-rw-r----- 1 root shadow 1344 Nov  8  2018 /etc/shadow
$ ./access /etc/shadow
access error for /etc/shadow: Permission denied
open error for /etc/shadow: Permission denied
$ su                           # become superuser
Password:
# chown root ./access          # change file's user ID to root
# chmod u+s ./access           # and turn on set-user-ID bit
# ls -l ./access
-rwsr-xr-x 1 root raphael 13632 10月 28 11:43 ./access
# exit
exit
$ ./access /etc/shadow
access error for /etc/shadow: Permission denied
open for reading OK

In this example, the set-user-ID program can determine that the real user cannot normally read the file,
even though the open function will succeed

*******/