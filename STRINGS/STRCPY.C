#include <stdio.h>
#include <string.h>

int main(void)
{
    char title[] = "Jamsa's 1001 C/C++ Tips";
    char book[128];

    strcpy(book, title);
    printf("Book name %s\n", book);

    return 0;
}
