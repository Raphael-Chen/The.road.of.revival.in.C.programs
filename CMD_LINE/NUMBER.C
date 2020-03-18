//bug
#include <stdio.h>

int main(void)
{
    char line[255]; // Line of input

    long line_number = 0; // Current line number

    while (fgets(line, sizeof(line), stdin))
        printf("%ld %s", ++line_number, line);
}
