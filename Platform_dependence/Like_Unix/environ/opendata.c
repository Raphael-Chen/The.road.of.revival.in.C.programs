#include <stdio.h>

// Figure 7.14. Incorrect usage of an automatic variable

// Figure 7.14 shows a function called open_data that opens
// a standard I/O stream and sets the buffering for the stream.

FILE *open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZ]; /* setvbuf makes this the stdio buffer */

    if ((fp = fopen("datafile", "r")) == NULL)
        return (NULL);

    if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return (NULL);

    return (fp);           /* error */
}

/************
    The problem is that when open_data returns, the space it used on 
    the stack will be used by the stack frame for the next function 
    that is called. But the standard I/O library will still be using 
    that portion of memory for its stream buffer. Chaos is sure to result. 
    To correct this problem, the array databuf needs to be allocated 
    from global memory, either statically ( static or extern ) or
    dynamically (one of the alloc functions).
*********/

