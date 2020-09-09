#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char string[] = "Jamsa's 1001 c & c++ Tips";

    int i;

    for (i = 0; string[i]; i++)
        putchar(toupper(string[i]));
    putchar('\n');

    for (i = 0; string[i]; i++)
        putchar(_toupper(string[i]));
    putchar('\n');
}
