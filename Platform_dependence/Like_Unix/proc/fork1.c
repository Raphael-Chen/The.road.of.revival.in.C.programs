#include "apue.h"

// Figure 8.1. Example of fork function
// Every process has a unique process ID, a non-negative integer. Because the process ID is the 
// only well-known identifier of a process that is always unique, it is often used as a piece 
// of other identifiers, to guarantee uniqueness. For example, applications sometimes
// include the process ID as part of a filename in an attempt to generate unique filenames

int  globvar = 6;                   /* external variable in initialized data */
char buf[]   = "a write to stdout\n";

int main(void)
{
    int   var;                  /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    if ( write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1 )
        err_sys("write error");
    printf("before fork\n"); /* we don't flush stdout */


    // The new process created by fork is called the child process. This function is called 
    // once but returns twice. The only difference in the returns is that the return value 
    // in the child is 0, whereas the return value in the parent is the process ID of the 
    // new child.
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {                     /* child */
        globvar++;        /* modify variables */
        var++;
    }
    else
    {
        sleep(2);         /* parent */
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}


// The program in Figure 8.1 demonstrates the fork function, showing how changes to variables 
// in a child process do not affect the value of the variables in the parent process.

// If we execute this program, we get
// $ ./fork1
// a write to stdout
// before fork
// pid = 4501, glob = 7, var = 89   # child's variables were changed
// pid = 4500, glob = 6, var = 88   # parent's copy was not changed

// $ ./fork1 >  temp.out
// $ cat temp.out
// a write to stdout
// before fork
// pid = 4521, glob = 7, var = 89
// before fork
// pid = 4520, glob = 6, var = 88



