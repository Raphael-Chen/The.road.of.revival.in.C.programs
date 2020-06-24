#include <stdio.h>
#include <stdlib.h>

// 冒泡排序算法


void bubble_sort(int* arr, int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main(void)
{
    int values[30], i;

    for (i = 0; i < 30; i++)
    {
        values[i] = rand() % 130;
        printf("%d ", values[i]);
    }
    printf("\n");

    bubble_sort(values, 30);

    for (i = 0; i < 30; i++)
        printf("%d ", values[i]);

    return 0;
}
