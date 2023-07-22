#include "apue.h"
#include <fcntl.h>

// Figure 3.2. Create a file with a hole in it

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    fd = creat("file.hole", FILE_MODE);
    if ( fd < 0 )
        err_sys("creat error");

    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */

    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    /* offset now = 16384 */

    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */

    return 0;
}

/***
    A new file can also be created by calling the creat function.
    #include <fcntl.h>
    int creat ( const char * pathname, mode_t mode );
    Returns: 
    file descriptor opened for write-only if OK, 1 on error

    Note that this function is equivalent to
    open ( pathname, O_WRONLY | O_CREAT | O_TRUNC , mode);


    $ ls -l file.hole  # check its size
    -rw-r--r-- 1 raphael raphael 16394 Sep 30 11:24 file.hole

    $ od -c file.hole  # let's look at the actual contents
    0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
    0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
    *
    0040000   A   B   C   D   E   F   G   H   I   J
    0040012
***/



