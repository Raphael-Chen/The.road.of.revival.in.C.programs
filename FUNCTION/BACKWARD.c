#include <stdio.h>

void display_backward(char *string)
{
    if (*string)
    {
        display_backward(string + 1);
        putchar(*string);
    }

}

int main(void)
{
    display_backward("ABCDE");
    putchar('\n');
    
    return 0;
}
