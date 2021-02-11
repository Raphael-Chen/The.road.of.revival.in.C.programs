#include "apue.h"
#include <sys/wait.h>

// Figure 8.20. A program that exec s an interpreter file
// The program echoarg (the interpreter) just echoes each of its 
// command-line arguments. (This is the program from Figure 7.4.)
// "/home/sar/bin/testinterp"
#define PATH "./testinterp"

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)              /* child */
    { 
        if (execl( PATH, //"/home/sar/bin/testinterp",
                  "testinterp", "myarg1", "MY ARG2", (char *)0) < 0)
            err_sys("execl error");
    }
    if (waitpid(pid, NULL, 0) < 0) /* parent */
        err_sys("waitpid error");

    exit(0);
}


// $ ./testinterp
// argv[0]: ./echoarg
// argv[1]: foo
// argv[2]: ./testinterp

// $ ./exec2
// argv[0]: ./echoarg
// argv[1]: foo
// argv[2]: ./testinterp
// argv[3]: myarg1
// argv[4]: MY ARG2


