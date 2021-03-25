#include "apue.h"
#include <sys/wait.h>

// Figure 10.6 System V SIGCLD handler that doesn’t work
static void sig_cld(int);

int main( void )
{
    pid_t pid;

    if (signal(SIGCLD, sig_cld) == SIG_ERR)
        perror("signal error");
    if ((pid = fork()) < 0)
    {
        perror("fork error");
    }
    else if (pid == 0)
    { /* child */
        sleep(2);
        _exit(0);
    }

    pause(); /* parent */

    exit(0);
}

static void sig_cld(int signo)               /* interrupts pause() */
{
    pid_t pid;
    int status;

    printf("SIGCLD received\n");

    if (signal(SIGCLD, sig_cld) == SIG_ERR) /* reestablish handler */
        perror("signal error");

    if ((pid = wait(&status)) < 0)          /* fetch child status */
        perror("wait error");

    printf("pid = %d\n", pid);
}

/************
NAME
       pause - wait for signal

SYNOPSIS
       #include <unistd.h>
       int pause(void);

DESCRIPTION
       pause()  causes the calling process (or thread) to sleep until a signal is delivered that
       either terminates the process or causes the invocation of a signal-catching function.

RETURN VALUE
       pause() returns only when a signal was caught and the signal-catching  function  returned.
       In this case pause() returns -1, and errno is set to EINTR.

ERRORS
       EINTR  a signal was caught and the signal-catching function returned.
************/

