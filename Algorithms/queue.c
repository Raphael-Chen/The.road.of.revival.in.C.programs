#include <stdio.h>

//Follow first in first out rule.

int enQueue(int *array, int rear, int data)
{
    array[rear] = data;
    rear++;
    return rear;
}


void deQueue(int *array, int front, int rear)
{
    //如果 front==rear，表示队列为空
    while (front != rear)
    {
        printf("出队元素：%d\n", array[front]);
        front++;
    }
}

int main(void)
{
    int arr[100];
    int front, rear;

    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    //入队
    rear = enQueue(arr, rear, 1);
    rear = enQueue(arr, rear, 2);
    rear = enQueue(arr, rear, 3);
    rear = enQueue(arr, rear, 4);
    //出队
    deQueue(arr, front, rear);


    return 0;
}

// http://data.biancheng.net/view/173.html 顺序队列实现


struct queue
{
    /* data */
};

typedef struct queue Queue;

void create_empty_queue( Queue** head, unsigned int how_many )
{
    

}

void destroy_queue( Queue* head )
{


    
}