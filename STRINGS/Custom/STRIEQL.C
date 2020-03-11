#include <stdio.h>
#include <ctype.h>

int strieql( const char *str1, const char *str2 )
{
    while ((toupper(*str1) == toupper(*str2)) && (*str1 != '\0' ))
    {
        str1++;
        str2++;
    }

    return ((*str1 == '\0') && (*str2 == '\0'));
}

int main(void)
{
    printf("Testing Abc and Abc %d\n", strieql("Abc", "Abc"));
    printf("Testing abc and Abc %d\n", strieql("abc", "Abc"));
    printf("Testing abcd and abc %d\n", strieql("abcd", "abc"));
}
