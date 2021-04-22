#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***
    A linked list is a data structure in which the objects are arranged in a linear order.
    Unlike an array, however, in which the linear order is determined by the array
    indices, the order in a linked list is determined by a pointer in each object.
 **/

#define LIST_BEGAIN    printf("\n[ ")
#define LIST_END       printf("]\n\n")
typedef int _TYPE;     // 抽象出元素数据类型


// 单向链表数据结构的基本实现
typedef struct Link
{
    _TYPE elem;
    // ... more elements
    
    struct Link *next;
} link;

link *create_list( _TYPE n );

//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link *insertElem(link *list, _TYPE elem, _TYPE add);

//删除结点的函数，p代表操作链表，add代表删除节点的位置
link *delElem(link *list, _TYPE add);

//查找结点的函数，elem为目标结点的数据域的值
_TYPE selectElem(link *list, _TYPE elem);

//更新结点的函数，newElem为新的数据域的值
link *amendElem(link *list, _TYPE add, _TYPE newElem);

// 遍历并打印出所有节点的内容
bool display(link *list);

