#include "apue.h"

// Figure 10.10 Calling read with a timeout
static void sig_alrm(int);

int main(void)
{
    int n;
    char line[MAXLINE];

    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        err_sys("signal(SIGALRM) error");

    alarm(10);
    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
        err_sys("read error");
    alarm(0);

    write(STDOUT_FILENO, line, n);
    
    exit(0);
}

static void sig_alrm(int signo)
{
    /* nothing to do, just return to interrupt the read */
}

// A common use for alarm, in addition to implementing the sleep function, is to put an
// upper time limit on operations that can block. For example, if we have a read
// operation on a device that can block (a ‘‘slow’’ device, as described in Section 10.5), we
// might want the read to time out after some amount of time. The program in
// Figure 10.10 does this, reading one line from standard input and writing it to standard
// output.