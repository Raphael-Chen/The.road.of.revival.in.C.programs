#include <stdio.h>
#include <string.h>
//strcat, strncat - concatenate two strings


int main(void)
{
    char name[64] = "Bill";

    strncat(name, " and Hillary", 4);

    printf("Did you vote for %s?\n", name);

    return 0;
}
