#include <stdio.h>

int main(void)
{
    int values[5] = {80, 70, 90, 85, 80};
    int i;

    for (i = 0; i < 5; i++)
        printf("values[%d] %d \n", i, values[i]);

    return 0;        
}
