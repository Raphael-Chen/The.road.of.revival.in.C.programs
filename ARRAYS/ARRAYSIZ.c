#include <stdio.h>

// Output the size of the arrays with sizeof operator.

int main(void)
{
    int scores[100];
    float salaries[100];
    char string[100];

    printf("Bytes used to hold int scores[100] is %lu bytes\n",
           sizeof(scores));

    printf("Bytes used to hold float salaries[100] is %lu bytes\n",
           sizeof(salaries));

    printf("Bytes used to hold char string[100] is %lu bytes\n",
           sizeof(string));

    return 0;
}
