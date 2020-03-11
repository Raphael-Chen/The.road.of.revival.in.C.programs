//[Warning]判断条件不建议这样写，太晦涩
#include <stdio.h>

int main(void)
{
    int counter;

    printf("\nEven values\n");
    for (counter = 1; counter <= 100; counter++)
    {
        if (!(counter % 2)) // Even
            printf("%d ", counter);
    }

    printf("\nOdd values\n");
    counter = 0;
    while (counter <= 100)
    {
        counter++;

        if (counter % 2) // Odd
            printf("%d ", counter);
    }
}
