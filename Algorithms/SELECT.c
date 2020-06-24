#include <stdio.h>
#include <stdlib.h>

// 选择排序算法

void swap(int *a, int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int* arr, int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++) //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;              //紀錄最小值
        swap(&arr[min], &arr[i]);     //做交換
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

    selection_sort(values, 30);

    for (i = 0; i < 30; i++)
        printf("%d ", values[i]);

    return 0;
}
