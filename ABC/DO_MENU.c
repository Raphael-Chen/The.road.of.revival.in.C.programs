#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//[bug]the command CHKDSK in system function for windows!
// do ...while循环结构语句的用法，输入字母q 或 Q程序退出。
// do statement while ( expression ) ;

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

        // letter = getch();
        letter = getchar();
        letter = toupper(letter);

        if (letter == 'A')
            system("dir");
        // else if (letter == 'B')
        //     system("CHKDSK");
        else if (letter == 'C')
            system("date");
    } while (letter != 'Q');

    return 0;
}
