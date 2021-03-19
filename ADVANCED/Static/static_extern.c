#include "static_extern.h"

// static 修饰全局变量
char i = 'A';           // global variable
static char c = 'B';    // Now, c is local variable

void msg(void)
{
    printf("%c \n", c);         //    
    printf("I Love my family! I Love my parents!\n");
}
