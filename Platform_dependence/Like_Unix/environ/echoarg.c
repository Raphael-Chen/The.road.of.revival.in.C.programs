#include "apue.h"


// Figure 7.4. Echo all command-line arguments to standard output

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)           /* echo all command-line args */
        printf("argv[%d]: %s\n", i, argv[i]);

    exit(0);
}


// $ ./echoarg arg1 TEST foo
// argv[0]: ./echoarg
// argv[1]: arg1
// argv[2]: TEST
// argv[3]: foo