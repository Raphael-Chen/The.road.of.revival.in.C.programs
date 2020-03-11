#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[64] = "Jamsa's 1001 C/C++ Tips";
    char target[64];

    int length;

    length = strxfrm(target, buffer, sizeof(buffer)); // strxfrm = strncpy

    printf("Length %d Target %s Buffer %s\n", length,
           target, buffer);

    return 0;
}
