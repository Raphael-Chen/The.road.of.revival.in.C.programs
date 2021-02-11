#include "apue.h"
#include <sys/wait.h>

// Figure 8.16. Example of exec functions
char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};


// Remember to change your user name in the path.
#define PATH "/home/YOUR_USERNAME/The.road.of.revival.in.C.programs/Platform_dependence/Like_Unix/proc/echoall"

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    { 
        /* specify pathname, specify environment */
        // if (execle("/home/sar/bin/echoall", "echoall", "myarg1",
        //            "MY ARG2", (char *)0, env_init) < 0)
        if (execle( PATH, "echoall", "myarg1",          // same directory echoall.c
                   "MY ARG2", (char *)0, env_init) < 0)
            err_sys("execle error");
    }

    if (waitpid(pid, NULL, 0) < 0)
        err_sys("wait error");

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    { 
        /* specify filename, inherit environment */
        // if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
        if (execlp( PATH, "echoall", "only 1 arg", (char *)0 ) < 0)
            err_sys("execlp error");
    }

    exit(0);
}
// https://zhuanlan.zhihu.com/p/136107808

// $ ./exec1
// argv[0]: echoall
// argv[1]: myarg1
// argv[2]: MY ARG2
// USER=unknown
// PATH=/tmp
// $ argv[0]: echoall
// argv[1]: only 1 arg
// USER=sar
// LOGNAME=sar
// SHELL=/bin/bash
// # ... 47 more lines that aren't shown
// HOME=/home/sar




