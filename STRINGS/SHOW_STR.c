#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[256]; // String input by user

    int i;            // Index into the string
    FILE* fp = NULL;
    printf("Type a string of characters and press Enter:\n");
    fgets(string, sizeof(string), 0 );  //?

    // Display each string character until NULL is found
    // for (i = 0; string[i] != NULL; i++)
    for (i = 0; string[i] != '\0'; i++)
        putchar(string[i]);

    printf("\nThe number of characters in the string is %d\n", i);

    return 0;
}
