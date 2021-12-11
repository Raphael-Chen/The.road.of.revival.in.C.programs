#include <stdio.h>

// A.01 Output all the member of array on screen.

// Declaring and initializing an array
// The general syntax for declaring a one-dimensional array is
// type arrName[size];

int main(void)
{
    int scores[5] = {80, 70, 90, 85, 80};
    int i;

    printf("Array Values\n");

    for (i = 0; i < 5; i++)
        printf("scores[%d] %d\n", i, scores[i]);

    return 0;
}
