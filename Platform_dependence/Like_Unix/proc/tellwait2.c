#include "apue.h"

// Figure 8.13. Modification of Figure 8.12 to avoid race condition
// We need to change the program in Figure 8.12 to use the TELL and WAIT functions. 
// The program in Figure 8.13 does this. The lines preceded by a plus sign are new lines.
// When we run this program, the output is as we expect; there is no intermixing of output 
// from the two processes.
// In the program shown in Figure 8.13, the parent goes first. The child goes first if we 
// change the lines following the fork to be

static void charatatime( char *str );

int main(void)
{
    pid_t pid;

    TELL_WAIT();

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        WAIT_PARENT();            // parent goes first 
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
        TELL_CHILD(pid);
    }

    exit(0);
}

static void charatatime(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);         // set unbuffered 
    for (ptr = str; (c = *ptr++) != 0;)
        putc(c, stdout);
}
