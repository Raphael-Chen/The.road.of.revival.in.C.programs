#include "apue.h"

// Figure 3.1. Test whether standard input is capable of seeking

int main(void)
{
    off_t currpos = lseek(STDIN_FILENO, 0, SEEK_CUR);
    if ( currpos == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");

    // exit(0);
    return 0;
}


/********
 * 
 * #include <unistd.h>

    off_t lseek ( int filedes, off_t offset, int whence);
    Returns: new file offset if OK, 1 on error
    
    The interpretation of the offset depends on the value of the whence argument.
    If whence is SEEK_SET , the file's offset is set to offset bytes from the beginning of the file.

    If whence is SEEK_CUR , the file's offset is set to its current value plus the offset. The offset can
    be positive or negative.

    If whence is SEEK_END , the file's offset is set to the size of the file plus the offset. The offset can
    be positive or negative.
*********/