#include "apue.h"
// #include <sys/wait.h>

// Figure 8.23. Calling the system function

// NAME
//        system - execute a shell command
//
// SYNOPSIS
//        #include <stdlib.h>
//
//        int system(const char *command);
// RETURN VALUE
//        The  value  returned  is  -1 on error (e.g., fork(2) failed), and the return status of the
//        command otherwise.  This latter return status is  in  the  format  specified  in  wait(2).
//        Thus, the exit code of the command will be WEXITSTATUS(status).  In case /bin/sh could not
//        be executed, the exit status will be that of a command that does exit(127).
//
//        If the value of command is NULL, system() returns nonzero if the shell is  available,  and
//        zero if not.
//
//        system() does not affect the wait status of any other children.


int main(void)
{
    int status;

    if ((status = system("date")) < 0)
        err_sys("system() error");

    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0)
        err_sys("system() error");

    pr_exit(status);

    if ((status = system("who; exit 44")) < 0)
        err_sys("system() error");

    pr_exit(status);

    exit(0);
}


// $ ./systest1
// Tue Feb 23 16:39:08 CST 2021
// normal termination, exit status = 0
// sh: 1: nosuchcommand: not found
// normal termination, exit status = 127
// Trojan  tty8         2021-02-23 10:11 (:0)
// Trojan  pts/2        2021-02-23 16:13 (:0.0)
// Trojan  pts/7        2021-02-23 16:22 (:0.0)
// normal termination, exit status = 44

