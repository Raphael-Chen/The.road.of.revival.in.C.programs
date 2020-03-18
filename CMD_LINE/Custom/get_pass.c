//Bug
#include <stdio.h>
#include <string.h>

#define BACKSPACE '\b'



char *get_password(const char *prompt)
{
    // static char buffer[128];
    char buffer[128];
    int i = 0;
    char letter = '\0';

    printf( "%s", prompt );

    while ((i < 127) && (letter != '\r'))
    {
        letter = getchar();

        if (letter == BACKSPACE)
        {
            if (i > 0)
            {
                buffer[--i] = '\0'; // Erase previous *
                putchar(BACKSPACE);
                putchar(' ');
                putchar(BACKSPACE);
            }
            else
                putchar(7); // BELL
        }
        else if (letter != '\r')
        {
            buffer[i++] = letter;
            putchar('*');
        }
        printf("Before out of loop, buffer is %s\n", buffer);
    }
    buffer[i] = '\0';
    // printf("Before return, buffer is %s\n", buffer);
    return (buffer);
}

int main(void)
{
    char *password;

    password = get_password("Enter Password: ");

    if (strcmp(password, "1001"))
        printf("\nPassword Incorrect\n");
    else
        printf("\nPassword OK\n");
}
