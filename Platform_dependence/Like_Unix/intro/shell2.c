#include "apue.h"
#include <sys/wait.h>

// Figure 1.10. Read commands from standard input and execute them

static void sig_int(int); /* our signal-catching function */

int main(void)
{
    char buf[MAXLINE]; /* from apue.h */
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% "); /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        pid = fork();
        if ( pid < 0 )
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        { /* child */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        pid = waitpid(pid, &status, 0);
        if ( pid < 0 )
            err_sys("waitpid error");
        printf("%% ");
    }
    
    return 0;
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}
