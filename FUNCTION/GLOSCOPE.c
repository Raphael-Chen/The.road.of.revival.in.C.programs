#include <stdio.h>

// global variables
char title[] = "Jamsa's 1001 C/C++ Tips";

void unknown_title(void)
{
    printf("The book's title is %s\n", title);
}


int main(void)
{
    printf("Title: %s\n", title);

    return 0;
}
