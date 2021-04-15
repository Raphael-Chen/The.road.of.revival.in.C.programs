#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// 6.8.1 Labeled statements
// Syntax
//
// labeled-statement:
//     identifier : statement
//     case constant-expression : statement
//     default : statement

int main(void)
{
    char letter;

    do
    {
        printf("A Display directory listing\n");
        // printf("B Display disk information\n");
        printf("C Change system date\n");
        printf("Q Quit\n");
        printf("Choice: ");

        letter = getchar();
        letter = toupper(letter);

        switch (letter)
        {
            case 'A':
                system("dir");
                break;
            // case 'B':
            //     system("CHKDSK");
            //     break;
            case 'C':
                system("date");
                break;
            default:                   // Don't forget it.
                ;// do something  
        };
    } while (letter != 'Q');

    return 0;
}
