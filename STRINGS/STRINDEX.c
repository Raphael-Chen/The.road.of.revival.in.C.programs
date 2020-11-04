#include <stdio.h>

int str_index(const char *string, int letter)
{
    const char *original = string;

    while ((*string != letter) && ( *string != '\0' ))
        string++;

    if ( *string == letter )
        return (string - original);  
    return -1;
}

int main(void)
{
    printf("Location of C is %d\n", str_index("1001 C/C++", 'C'));

    printf("Location of x is %d\n", str_index("1001 C/C++", 'x'));

    return 0;
}
