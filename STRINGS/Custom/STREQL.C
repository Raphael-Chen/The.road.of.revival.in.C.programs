#include <stdio.h>

int streql( const char *str1, const char *str2 )
{
    while ((*str1 == *str2) && (*str1))
    {
        str1++;
        str2++;
    }

    return ((*str1 == '\0') && (*str2 == '\0'));
}

int main(void)
{
    printf("Testing Abc and Abc %d\n", streql("Abc", "Abc"));
    printf("Testing abc and Abc %d\n", streql("abc", "Abc"));
    printf("Testing abcd and abc %d\n", streql("abcd", "abc"));

    return 0;
}
