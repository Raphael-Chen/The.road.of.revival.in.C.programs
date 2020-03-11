#include <stdio.h>

int chrcnt(const char *string, int letter)
{
    int count = 0;

    // while (*string)
    while ( string != NULL )
        if (*string == letter)
            count++;

    return (count);
}


int main( void )
{
    
    return 0;
}