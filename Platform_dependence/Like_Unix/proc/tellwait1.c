#include "apue.h"

// // Figure 8.12. Program with a race condition
// The program in Figure 8.12 outputs two strings: one from the child and one from the parent. 
// The program contains a race condition because the output depends on the order in which 
// the processes are run by the kernel and for how long each process runs.

static void charatatime( char * str );

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    
    exit(0);
}

static void charatatime(char *str)
{
    char *ptr;
    int  c;

    setbuf(stdout, NULL);        // set unbuffered 
    for (ptr = str; (c = *ptr++) != 0;)
        putc(c, stdout);

}

// # The program output:
// $ ./tellwait1
// oouuttppuutt  ffrroomm  pcahrielndt
//
// $ ./tellwait1
// ooutuptuptu tf rformo mc hpialrde
// nt
// $ ./tellwait1
// output from parent
// output from child


