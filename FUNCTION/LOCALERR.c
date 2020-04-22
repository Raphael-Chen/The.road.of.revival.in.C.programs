#include <stdio.h>

void local_values(void)
{
    int a = 1, b = 2, c = 3;

    printf("a contains %d b contains %d c contains %d\n", a, b, c);
}

int main(void)
{
    // error:  a, b, c undeclared (first use in this function)
    printf("a contains %d b contains %d c contains %d\n", a, b, c);  

    return 0;
}
