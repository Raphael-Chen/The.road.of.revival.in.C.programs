#include "apue.h"
#include <sys/wait.h>

// Figure 8.8. Avoid zombie processes by calling fork twice

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)        /* first child */
    { 
        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid > 0)
            exit(0);          /* parent from second fork == first child */

        /*
		 * We're the second child; our parent becomes init as soon
		 * as our real parent calls exit() in the statement above.
		 * Here's where we'd continue executing, knowing that when
		 * we're done, init will reap our status.
		 */
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid()); // pid: 1

        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid)   /* wait for first child */
        err_sys("waitpid error");

    /*
	 * We're the parent (the original process); we continue executing,
	 * knowing that we're not the parent of the second child.
	 */
    exit(0);
}


// Recall our discussion in Section 8.5 about zombie processes. If we want to write 
// a process so that it fork s a child but we don't want to wait for the child to 
// complete and we don't want the child to become a zombie until we terminate, the 
// trick is to call fork twice. The program in Figure 8.8 does this.
// We call sleep in the second child to ensure that the first child terminates before 
// printing the parent process ID. After a fork , either the parent or the child can 
// continue executing; we never know which will resume execution first. If we didn't 
// put the second child to sleep, and if it resumed execution after the fork before its 
// parent, the parent process ID that it printed would be that of its parent, not process ID 1.









