#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char string[] = "Jamsa's 1001 C & C++ Tips";

    int i;

    for (i = 0; string[i]; i++)
        putchar(tolower(string[i]));
    putchar('\n');

    for (i = 0; string[i]; i++)
        putchar(_tolower(string[i]));
    putchar('\n');
}
