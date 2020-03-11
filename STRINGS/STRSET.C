#include <stdio.h>


char *strset(char *string, int letter)
{
    char *original = string;

    while (*string != '\0' )
        *string++ = letter;

    return (original);
}

int main(void)
{
    char name[] = "22222";

    printf( "strset is %s\n", strset(name, '1') );
}
