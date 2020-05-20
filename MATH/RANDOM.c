#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    printf("Values from rand()\n");
    for (i = 0; i < 100; i++)
        printf("%d ", rand());

    //    printf("\nValues from random(100)) \n");  outmoded, not C11
    //    for (i = 0; i < 100; i++)
    //      printf("%d ", random(100));

    return 0;
}
