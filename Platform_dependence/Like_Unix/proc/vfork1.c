#include "apue.h"

// Figure 8.3. Example of vfork function
// Here, the incrementing of the variables done by the child changes the values 
// in the parent. Because the child runs in the address space of the parent, this 
// doesn't surprise us. This behavior, however, differs from fork.

int globvar = 6; /* external variable in initialized data */

int main(void)
{
    int   var;               /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    printf("before vfork\n"); /* we don't flush stdio */
    if ( (pid = vfork()) < 0 )
    {
        err_sys("vfork error");
    }
    else if (pid == 0)         /* child */
    {            
        globvar++;            /* modify parent's variables */
        var++;
        _exit(0);             /* child terminates */
    }

    /* parent continues here */
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
           var);


    exit(0);
}
