#include <stdio.h>

// Function of keyword `continue`.
int main(void)
{
    int counter;

    printf("\nEven values\n");
    for (counter = 1; counter <= 100; counter++)
    {
        if (counter % 2)    // Odd
            continue;       // Over the rest code, jump to the next loop().

        printf("%d ", counter);
    }

    printf("\nOdd values\n");
    counter = 0;
    while (counter <= 100)
    {
        counter++;

        if (!(counter % 2)) // Even
            continue;       // Over the printf, jump to the while statement next time.

        printf("%d ", counter);
    }
}
