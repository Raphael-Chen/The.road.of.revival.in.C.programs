#include <termios.h>

// Figure 18.13 Implementation of POSIX.1 isatty function

int isatty(int fd)
{
    struct termios ts;

    return (tcgetattr(fd, &ts) != -1); /* true if no error (is a tty) */
}
