#include "apue.h"
#include <termios.h>
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

// Figure 18.22 Print window size

static void pr_winsize(int fd)
{
    struct winsize size;

    if (ioctl(fd, TIOCGWINSZ, (char *)&size) < 0)
        err_sys("TIOCGWINSZ error");
    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}

static void sig_winch(int signo)
{
    printf("SIGWINCH received\n");
    pr_winsize(STDIN_FILENO);
}

int main(void)
{
    if (isatty(STDIN_FILENO) == 0)
        exit(1);

    if (signal(SIGWINCH, sig_winch) == SIG_ERR)
        err_sys("signal error");

    pr_winsize(STDIN_FILENO); /* print initial size */
    for (;;)                  /* and sleep forever */
        pause();
}

// Figure 18.22 shows a program that prints the current window size and goes to sleep.
// Each time the window size changes, SIGWINCH is caught and the new size is printed.
// We have to terminate this program with a signal.


// $ ./winch 
// 24 rows, 80 columns
// SIGWINCH received
// 43 rows, 80 columns
// SIGWINCH received
// 24 rows, 132 columns
// ^C
