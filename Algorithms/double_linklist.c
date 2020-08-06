#include "double_linklist.h"
#include <stdlib.h>

// 检查指针是否为空
int checkNull(void* p)
{
    if (NULL == p)
    {
        printf("\nlog: null pointer\n");
        return 1;
    }
    return 0;
}


// 快速创建一个双链表
DLlist *_createList()
{
    DLlist *pList = (DLlist *)malloc(sizeof(DLlist));
    pList->head = pList->back = NULL;
    pList->size = 0;
    return pList;
}

// 插入双链表的头部,返回1则表示插入成功
int addToHead(DLlist *pList, _TYPE value)
{
    if (checkNull(pList))
    {
        return 0;
    }

    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (checkNull(newNode))
    {
        return 0; // 创建新节点失败,则返回
    }
    newNode->pNext = newNode->pPre = NULL;
    newNode->value = value;

    if (pList->head == NULL) // 若头节点为空，则新节点置为头节点
    {
        pList->head = newNode;
        pList->back = newNode;
        pList->size++;
    }
    else // 添加到头部
    {
        newNode->pNext = pList->head;
        pList->head->pPre = newNode;
        pList->head = newNode; // 将链表的头部设为新节点
        pList->size++;
    }
    return 1;
}

int main( void )
{
    DLlist *pList = _createList(); // 创建一个双链表
    addToHead(pList, 1);           // 插入数据到头
    addToHead(pList, 2);
    addToHead(pList, 3);
    addToHead(pList, 4);
    addToHead(pList, 5);

    addToBack(pList, 11); // 插入数据到尾
    addToBack(pList, 22);
    addToBack(pList, 33);
    addToBack(pList, 44);
    addToBack(pList, 55);

    showAll(pList);        // 正向显示所有
    showAllReverse(pList); // 反向显示所有

    modify(pList, 11, 66); // 将11修改为66
    showAll(pList);        // 正向显示所有
    printf("size = %ld\n", pList->size);

    deleteNode(pList, 33);
    showAll(pList);                   // 正向显示所有
    printf("size = %ld\n", pList->size); // 双链表的大小

    // system("pause");
    return 0;
}

// int main(void)
// {

//     DLlist *pList = _createList();
//     pList->addToHead(pList, 1); // 插入数据到头
//     pList->addToHead(pList, 2);
//     pList->addToHead(pList, 3);
//     pList->addToHead(pList, 4);
//     pList->addToHead(pList, 5);

//     pList->addToBack(pList, 11); // 插入数据到尾
//     pList->addToBack(pList, 22);
//     pList->addToBack(pList, 33);
//     pList->addToBack(pList, 44);
//     pList->addToBack(pList, 55);

//     pList->showAll(pList);        // 正向显示所有
//     pList->showAllReverse(pList); // 反向显示所有

//     pList->modify(pList, 11, 66); // 将11修改为66
//     pList->showAll(pList);        // 正向显示所有
//     printf("size=%d\n", pList->size);

//     pList->deleteNode(pList, 33);
//     pList->showAll(pList);            // 正向显示所有
//     printf("size=%d\n", pList->size); // 双链表的大小

//     // system("pause");
//     return 0;
// }