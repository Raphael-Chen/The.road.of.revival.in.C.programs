#include "open.h"
#include <fcntl.h>

#define BUFFSIZE 8192

// Figure 17.18 The client main function, version 1
// The main function (Figure 17.18) is a loop that reads a pathname from standard
// input and copies the file to standard output. The function calls csopen to contact the
// open server and return an open descriptor.

int main(int argc, char *argv[])
{
    int n, fd;
    char buf[BUFFSIZE], line[MAXLINE];

    /* read filename to cat from stdin */
    while (fgets(line, MAXLINE, stdin) != NULL)
    {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;            /* replace newline with null */

        /* open the file */
        if ((fd = csopen(line, O_RDONLY)) < 0)
            continue;                              /* csopen() prints error from server */

        /* and cat to stdout */
        while ((n = read(fd, buf, BUFFSIZE)) > 0)
            if (write(STDOUT_FILENO, buf, n) != n)
                err_sys("write error");

        if (n < 0)
            err_sys("read error");

        close(fd);
    }

    exit(0);
}
