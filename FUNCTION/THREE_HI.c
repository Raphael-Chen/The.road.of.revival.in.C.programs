#include <stdio.h>

void three_hellos(void)
{
    int counter; // Variable

    for (counter = 1; counter <= 3; counter++)
        printf("Hello, world!\n");
}

int main(void) 
{
    three_hellos();

    return 0;
}
