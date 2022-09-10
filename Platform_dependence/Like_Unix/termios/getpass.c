#include <signal.h>
#include <stdio.h>
#include <termios.h>

// Figure 18.17 Implementation of getpass function

#define MAX_PASS_LEN 8 /* max #chars for user to enter */

char *getpass(const char *prompt)
{
    static char buf[MAX_PASS_LEN + 1]; /* null byte at end */
    char              *ptr;
    sigset_t          sig, osig;
    struct termios    ts, ots;
    FILE              *fp;
    int               c;

    fp = fopen(ctermid(NULL), "r+");
    if (fp == NULL)
        return (NULL);
    setbuf(fp, NULL);

    // We block the two signals SIGINT and SIGTSTP.
    sigemptyset(&sig);
    sigaddset(&sig, SIGINT);                        /* block SIGINT */
    sigaddset(&sig, SIGTSTP);                       /* block SIGTSTP */
    sigprocmask(SIG_BLOCK, &sig, &osig);            /* and save mask */
           
    tcgetattr(fileno(fp), &ts);                     /* save tty state */
    ots = ts;                                       /* structure copy */
    ts.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
    tcsetattr(fileno(fp), TCSAFLUSH, &ts);
    fputs(prompt, fp);


    // We store only up to eight characters as the password. 
    // Any additional characters that are entered are ignored.
    ptr = buf;
    while ((c = getc(fp)) != EOF && c != '\n')
        if (ptr < &buf[MAX_PASS_LEN])
            *ptr++ = c;
    *ptr = 0;                               /* null terminate */
    putc('\n', fp);                         /* we echo a newline */

    tcsetattr(fileno(fp), TCSAFLUSH, &ots); /* restore TTY state */
    sigprocmask(SIG_SETMASK, &osig, NULL);  /* restore mask */
    fclose(fp);                             /* done with /dev/tty */

    return (buf);
}
