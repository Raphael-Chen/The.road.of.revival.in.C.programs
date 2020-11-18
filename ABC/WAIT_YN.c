#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char letter; // Letter typed by the user

    printf("Do you want to continue? (Y/N): ");

    letter = getchar();             // Get the letter
    letter = toupper(letter);       // Convert letter to uppercase

    while ((letter != 'Y') && (letter != 'N'))
    {
        putchar(7);                 // Beep the speaker
        letter = getchar();         // Get the letter
        letter = toupper(letter);   // Convert letter to uppercase
    }

    printf("\nYour response was %c\n", letter);

    return 0;
}
