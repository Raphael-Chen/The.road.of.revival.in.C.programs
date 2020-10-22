#include <stdio.h>

// keyword "break" 's function
int main(void)
{
    int counter;

    for (counter = 1; counter <= 100; counter++)
    {
        if (counter == 50)
            break;                       // break from current loop

        printf("%d ", counter);
    }

    printf("\nNext loop\n");

    for (counter = 100; counter >= 1; counter--)
    {
        if (counter == 50)
            break;

        printf("%d ", counter);
    }

    return 0;
}
