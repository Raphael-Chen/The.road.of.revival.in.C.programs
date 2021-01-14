#include "apue.h"
#include <setjmp.h>

// Figure 7.11. Example of setjmp and longjmp

// In C, we can't goto a label that's in another function. Instead, 
// we must use the setjmp and longjmp functions to perform this type 
// of branching.
// As we'll see, these two functions are useful for handling error 
// conditions that occur in a deeply nested function call.

#define TOK_ADD 5

jmp_buf jmpbuffer;

int main(void)
{
    char line[MAXLINE];

    if (setjmp(jmpbuffer) != 0)
        printf("error");
    while (fgets(line, MAXLINE, stdin) != NULL)
        do_line(line);

    exit(0);
}

// ...
char *tok_ptr;          /* global pointer for get_token() */

void do_line(char *ptr) /* process one line of input */
{
    int cmd;

    tok_ptr = ptr;
    while ((cmd = get_token()) > 0)
    {
        switch (cmd) /* one case for each command */
        { 
        case TOK_ADD:
            cmd_add();
            break;
        }
    }
}

int get_token(void)
{
    /* fetch next token from line pointed to by tok_ptr */
}
// ...

void cmd_add(void)
{
    int token;

    token = get_token();
    if (token < 0) /* an error has occurred */
        longjmp(jmpbuffer, 1);
    /* rest of processing for this command */
}
