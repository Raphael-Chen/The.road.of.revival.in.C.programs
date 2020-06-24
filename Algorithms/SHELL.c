#include <stdio.h>
#include <stdlib.h>

// 希尔排序
void shell_sort(int* array, int size)
{
    int temp, gap, i, exchange_occurred;

    gap = size / 2;

    do
    {
        do
        {
            exchange_occurred = 0;

            for (i = 0; i < size - gap; i++)
                if (array[i] > array[i + gap])
                {
                    temp = array[i];
                    array[i] = array[i + gap];
                    array[i + gap] = temp;
                    exchange_occurred = 1;
                }
        } while (exchange_occurred);
    } while (gap = gap / 2);
}

#define SIZE 50

int main(void)
{
    int values[SIZE], 
        i;

    for (i = 0; i < SIZE; i++) {
        values[i] = rand() % 120;
        printf("%d ", values[i]);
    }
    printf("\n");

    shell_sort( values, SIZE );

    for (i = 0; i < SIZE; i++)
        printf("%d ", values[i]);

    return 0;
}
