#include <stdio.h>
// #include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char letter;

    do
    {
        printf("A Display directory listing\n");
        printf("B Display disk information\n");
        printf("C Change system date\n");
        printf("Q Quit\n");
        printf("Choice: ");

        letter = getchar();
        letter = toupper(letter);

        switch (letter)
        {
        case 'A':
            system("DIR");
            break;
        case 'B':
            system("CHKDSK");
            break;
        case 'C':
            system("DATE");
            break;
        };
    } while (letter != 'Q');
}
