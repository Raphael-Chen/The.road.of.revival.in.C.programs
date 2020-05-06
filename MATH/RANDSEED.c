#include <stdio.h>
#include <stdlib.h>

/*
    #include <stdlib.h>
    void srand(unsigned int seed);

    The srand function uses the argument as a seed for a new sequence of pseudo-random
    numbers to be returned by subsequent calls to rand. If srand is then called with the
    same seed value, the sequence of pseudo-random numbers shall be repeated. If rand is
    called before any calls to srand have been made, the same sequence shall be generated
    as when srand is first called with a seed value of 1.
*/

int main(void)
{
    int i;

    srand(100);
    printf("Values from rand\n");
    for (i = 0; i < 5; i++)
        printf("%d ", rand());

    printf("\nSame 5 numbers\n");
    srand(100);
    for (i = 0; i < 5; i++)
        printf("%d ", rand());

    // randomize();                        // outmoded, not C11
    // printf("\nDifferent 5 numbers\n");
    // for (i = 0; i < 5; i++)
    //     printf("%d ", rand());

    return 0;
}
