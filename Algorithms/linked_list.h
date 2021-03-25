#include <stdio.h>
#include <stdlib.h>

/***
    A linked list is a data structure in which the objects are arranged in a linear order.
    Unlike an array, however, in which the linear order is determined by the array
    indices, the order in a linked list is determined by a pointer in each object.
 **/

#define LIST_BEGAIN    printf("\n[ ")
#define LIST_END       printf("]\n")

// 单向链表数据结构的基本实现
typedef struct Link
{
    int elem;
    // ... more elements
    
    struct Link *next;
} link;

link *create_list( int n );

//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link *insertElem(link *p, int elem, int add);

//删除结点的函数，p代表操作链表，add代表删除节点的位置
link *delElem(link *p, int add);

//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link *p, int elem);

//更新结点的函数，newElem为新的数据域的值
link *amendElem(link *p, int add, int newElem);

// 遍历并打印出所有节点的内容
void display(link *p);