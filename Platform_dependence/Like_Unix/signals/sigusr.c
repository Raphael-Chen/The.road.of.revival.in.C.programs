#include "apue.h"

// Figure 10.2 Simple program to catch SIGUSR1 and SIGUSR2
// Figure 10.2 shows a simple signal handler that catches either of the two user-defined
// signals and prints the signal number. In Section 10.10, we describe the pause function,
// which simply suspends the calling process until a signal is received.

static void sig_usr(int); /* one handler for both signals */

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("can't catch SIGUSR1");
        
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("can't catch SIGUSR2");

    for (;;)
        pause();

    return 0;
}

static void sig_usr(int signo) /* argument is signal number */
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        err_dump("received signal %d\n", signo);
}


// $ ./sigusr &                         # start process in background
// [1] 5354                             # job-control shell prints job number and process ID
// $ kill -USR1 7216
// bash: kill: (7216) - No such process
// $ kill -USR1 5354                    # send process ID SIGUSR1
// received SIGUSR1
// $ kill -USR2 5354                    # send it SIGUSR2
// received SIGUSR2                     
// $ kill 5354                          # now send it SIGTERM
// [1]+  Terminated              ./sigusr

