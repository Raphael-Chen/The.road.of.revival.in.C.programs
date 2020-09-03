#include <stdio.h>

int main(void)
{
    char string[256];

    int i;

    for (i = 0; i < 26; i++)
        string[i] = 'A' + i;

    // string[10] = NULL;
    string[10] = '\0';     //strings ending with a charactor '\0'

    printf("The string contains %s\n", string);
}
