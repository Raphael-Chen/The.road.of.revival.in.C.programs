#include <stdio.h>

char *strcpy(char *destination, const char *source)
{
    char *start = destination;

    // while ( *destination++ = *source++)
    while ( *source != '\0' )
    {
       *destination++ = *source++ ;
    }

    return start;
}

int main(void)
{
    char title[64];

    strcpy(title, "Jamsa's 1001 C/C++ Tips");  
    printf( "%s\n", title);

    return 0;
}
