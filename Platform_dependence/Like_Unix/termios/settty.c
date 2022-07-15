#include "apue.h"
#include <termios.h>

// Figure 18.10 Disable interrupt character and change end-of-file character

// Before describing all the special characters in detail, let’s look at a small program that
// changes them. The program in Figure 18.10 disables the interrupt character and sets the
// end-of-file character to Control-B.


int main(void)
{
    struct termios term;
    long           vdisable;

    if (isatty(STDIN_FILENO) == 0)
        err_quit("standard input is not a terminal device");

    vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE);
    if (vdisable < 0)
        err_quit("fpathconf error or _POSIX_VDISABLE not in effect");

    if (tcgetattr(STDIN_FILENO, &term) < 0)   /* fetch tty state */
        err_sys("tcgetattr error");

    term.c_cc[VINTR] = vdisable;              /* disable INTR character */
    term.c_cc[VEOF] = 2;                      /* EOF is Control-B */

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
        err_sys("tcsetattr error");

    exit(0);
}



// #include <unistd.h>
// int isatty(int fd);
// Returns: 1 (true) if terminal device, 0 (false) otherwise


// NAME
//        fpathconf, pathconf - get configuration values for files

// SYNOPSIS
//        #include <unistd.h>

//        long fpathconf(int fd, int name);
//        long pathconf(char *path, int name);
