#include "apue.h"

char *getpass(const char *);

// Figure 18.18 Call the getpass function
// The program in Figure 18.18 calls getpass and prints what we enter to let us verify
// that the ERASE and KILL characters work (as they should in canonical mode).

int main(void)
{
    char *ptr;

    if ((ptr = getpass("Enter password:")) == NULL)
        err_sys("getpass error");
    printf("password: %s\n", ptr);

    /* now use password (probably encrypt it) ... */

    while (*ptr != 0)
        *ptr++ = 0;           /* zero it out when we're done with it */

    exit(0);
}
