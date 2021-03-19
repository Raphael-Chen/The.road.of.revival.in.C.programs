#include "static_extern.h"

// gcc -std=c11 -Wall -Wextra static_extern.c static_main.c

int main(void)
{
    extern char i;      // extern variable must be declared before to use
    // char  i;         // if undeclared with extern keyword ?
    
    printf("%c \n", i);
    // printf("%c \n", c); // Can you output the c?

    msg();

    return 0;
}
