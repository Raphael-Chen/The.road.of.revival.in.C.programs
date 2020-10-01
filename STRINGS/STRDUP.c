#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//strdup, strndup, strdupa, strndupa - duplicate a string

int main(void)
{
    char *title;

    if ((title = strdup("Jamsa's 1001 C/C++ Tips")))  //临时性的复制该值
        printf("Title: %s\n", title);
    else
        printf("Error duplicating string");

    printf( "Maybe system malloc the %ld Byte memory for title.\n", strlen( title ) );
    free( title );  //? Should be?

    return 0;
}
