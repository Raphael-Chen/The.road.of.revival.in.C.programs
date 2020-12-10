#include "apue.h"

// Figure 5.5. Copy standard input to standard output using fgets and fputs

int main(void)
{
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL)
        if (fputs(buf, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    exit(0);
}



// | Function                  | User CPU (seconds) | System CPU (seconds) | Clock time (seconds) | Bytes of program Text |
// | ------------------------- | ------------------ | -------------------- | -------------------- | --------------------- |
// | best time from Figure 3.5 | 0.01               | 0.18                 | 6.67                 |                       |
// | fgets , fputs             | 2.59               | 0.19                 | 7.15                 | 139                   |
// | getc , putc               | 10.84              | 0.27                 | 12.07                | 120                   |
// | fgetc , fputc             | 10.44              | 0.27                 | 11.42                | 120                   |
