#include "apue.h"
#include <sys/wait.h>


// Figure 8.6. Demonstrate various exit statuses
int main(void)
{
    pid_t pid;
    int   status;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)           /* child */
        exit(7);

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status. To read Figure 8.5 */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)          /* child */
        abort();                /* generates SIGABRT */

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)          /* child */
        status /= 0;            /* divide by 0 generates SIGFPE - 6 */

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* and print its status - 8 */

    exit(0);
}

/*****************************
NAME
       wait, waitpid, waitid - wait for process to change state

SYNOPSIS
       #include <sys/types.h>
       #include <sys/wait.h>

       pid_t wait(int *status);

       pid_t waitpid(pid_t pid, int *status, int options);

       int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
                       // This is the glibc and POSIX interface; see
                       //  NOTES for information on the raw system call.

RETURN VALUE
       wait(): on success, returns the process ID of the terminated child;  on error,  -1 is
       returned.

       waitpid():  on success,  returns the process ID of the child whose state has changed; if
       WNOHANG was specified and one or more child(ren) specified by pid exist, but have not  yet
       changed state, then 0 is returned.  On error, -1 is returned.

       waitid():  returns 0 on success or if WNOHANG was specified and no child(ren) specified by
       id has yet changed state; on error, -1 is returned.  Each of these calls sets errno to  an
       appropriate value in the case of an error.

***********************/





