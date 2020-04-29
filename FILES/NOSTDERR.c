#include <stdio.h>


// The freopen function opens the file whose name is the string pointed to by filename
// and associates the stream pointed to by stream with it. The mode argument is used just
// as in the fopen function. 272)

int main(void)
{
    if (freopen("STANDARD.ERR", "w", stderr))
        fputs("stderr has been redirected", stderr);
    else
        printf("Error in reopen\n");

    return 0;        
}
