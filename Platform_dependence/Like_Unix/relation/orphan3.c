#include "apue.h"
#include <errno.h>

// Figure 9.12 Creating an orphaned process group

static void sig_hup(int signo)
{
    printf("SIGHUP received, pid = %ld\n", (long)getpid());
}

static void pr_ids(char *name)
{
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n",
           name, (long)getpid(), (long)getppid(), (long)getpgrp(),
           (long)tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}

int main(void)
{
    char c;
    pid_t pid;

    pr_ids("parent");
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid > 0)     /* parent */
    {             
        sleep(5);         /* sleep to let child stop itself */
    }
    else                  /* child */
    { 
        pr_ids("child");
        signal(SIGHUP, sig_hup);                   /* establish signal handler */
        kill(getpid(), SIGTSTP);                   /* stop ourself */
        pr_ids("child");                           /* prints only if we're continued */
        if (read(STDIN_FILENO, &c, 1) != 1)
            printf("read error %d on controlling TTY\n", errno);
    }

    exit(0);
}


// NAME
//        tcgetpgrp, tcsetpgrp - get and set terminal foreground process group

// SYNOPSIS
//        #include <unistd.h>

//        pid_t tcgetpgrp(int fd);
//        int tcsetpgrp(int fd, pid_t pgrp);

// DESCRIPTION
//        The  function  tcgetpgrp() returns the process group ID of the foreground process group on
//        the terminal associated to fd, which must be  the  controlling  terminal  of  the  calling
//        process.

//        The function tcsetpgrp() makes the process group with process group ID pgrp the foreground
//        process group on the terminal associated to fd, which must be the controlling terminal  of
//        the  calling  process, and still be associated with its session.  Moreover, pgrp must be a
//        (nonempty) process group belonging to the same session as the calling process.

//        If tcsetpgrp() is called by a member of a background process group in its session, and the
//        calling  process is not blocking or ignoring SIGTTOU, a SIGTTOU signal is sent to all mem‐
//        bers of this background process group.

// RETURN VALUE
//        When fd refers to the controlling terminal of the calling process,  the  function  tcgetp‐
//        grp()  will  return  the foreground process group ID of that terminal if there is one, and
//        some value larger than 1 that is not presently a process group ID otherwise.  When fd does
//        not refer to the controlling terminal of the calling process, -1 is returned, and errno

//        When successful, tcsetpgrp() returns 0.  Otherwise, it returns -1, and errno
