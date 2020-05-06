#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//[bug]the command CHKDSK in system function for windows!

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

        // letter = getch();
        letter = getchar();
        letter = toupper(letter);

        if (letter == 'A')
            system("dir");
        else if (letter == 'B')
            system("CHKDSK");
        else if (letter == 'C')
            system("date");
    } while (letter != 'Q');
}
