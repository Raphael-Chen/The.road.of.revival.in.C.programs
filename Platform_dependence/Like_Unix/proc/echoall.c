#include "apue.h"

// Figure 8.17. Echo all command-line arguments and all environment strings
// The program echoall that is executed twice in the program in Figure 8.16 is 
// shown in Figure 8.17. It is a trivial program that echoes all its
// command-line arguments and its entire environment list.

int main(int argc, char *argv[])
{
    int i;
    char **ptr;
    extern char **environ;

    for (i = 0; i < argc; i++)              /* echo all command-line args */
        printf("argv[%d]: %s\n", i, argv[i]);

    for (ptr = environ; *ptr != 0; ptr++)   /* and all env strings */
        printf("%s\n", *ptr);

    exit(0);
}
