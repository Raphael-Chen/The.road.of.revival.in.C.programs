#include "apue.h"
#include <pwd.h>

// Figure 10.5 Call a nonreentrant function from a signal handler
// Figure 10.5 shows a program that calls the nonreentrant function getpwnam from a
// signal handler that is called every second. We describe the alarm function in
// Section 10.10. We use it here to generate a SIGALRM signal every second.

static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
        err_sys("getpwnam(root) error");

    alarm(1);
}

int main(void)
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for (;;)
    {
        if ((ptr = getpwnam("sar")) == NULL)
        // if ((ptr = getpwnam("raphael")) == NULL)
            err_sys("getpwnam error");
        if (strcmp(ptr->pw_name, "sar") != 0)
            printf("return value corrupted!, pw_name = %s\n",
                   ptr->pw_name);
    }

    return 0;
}
