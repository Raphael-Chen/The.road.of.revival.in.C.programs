#include "double_linklist.h"

// 检查指针是否为空
bool checkNull(void *p)
{
    if (NULL == p)
    {
        printf("\nlog: NULL pointer\n");
        return true;
    }
    return false;
}

// 判断链表是否为空，返回1则为空
int isEmpty(DLlist *pList)
{
    if (checkNull(pList))
    {
        return 1;
    }
    return pList->size == 0;
}

// 修改指定的值的节点,返回1表示修改成功
int modify(DLlist *pList, _TYPE oldValue, _TYPE newValue)
{
    if (checkNull(pList))
    {
        return 0;
    }

    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return 0;
    }
    DLNode *curNode = pList->head;
    while (curNode)
    {
        if (curNode->value == oldValue)
        {
            curNode->value = newValue;
            return 1;
        }
        curNode = curNode->pNext;
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
    if (true == checkNull(pList))
    {
        return 0;
    }

    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (true == checkNull(newNode))
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

// 插入到双链表的尾部,返回1插入成功
int addToTail(DLlist *pList, _TYPE value)
{
    if (true == checkNull(pList))
    {
        return 0;
    }
    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (true == checkNull(newNode))
    {
        return 0; // 创建新节点失败,则返回
    }
    newNode->pNext = newNode->pPre = NULL;
    newNode->value = value;

    if (NULL == pList->head) // 若头节点为空，则新节点置为头节点
    {
        pList->head = newNode;
        pList->back = newNode;
        pList->head->pNext = pList->back->pNext = NULL;
        pList->size++;
    }
    else if (pList->size == 1) // 只有一个元素，头尾都指向它，链接好头部与下一个节点
    {
        newNode->pPre = pList->head;
        pList->head->pNext = newNode;
        pList->back = newNode;
        pList->size++;
    }
    else // 添加到尾部
    {
        newNode->pPre = pList->back;
        pList->back->pNext = newNode;
        pList->back = newNode;
        pList->size++;
    }

    return 1;
}

// 正向输出所有节点值
void showAll(DLlist *pList)
{
    if (true == checkNull(pList))
    {
        return;
    }
    else
    {
        if (isEmpty(pList))
        {
            printf("\nlog:showAll 空链表\n");
            return;
        }
        printf("\n[  ");
        DLNode *p = pList->head;
        while (p != NULL)
        {
            printf("%d  ", p->value);
            p = p->pNext; // 往后遍历
        }
        printf("]\n");
    }
}

int main(void)
{
    DLlist *pList = _createList(); // 创建一个双链表
    addToHead(pList, 1);           // 插入数据到头
    addToHead(pList, 2);
    addToHead(pList, 3);
    addToHead(pList, 4);
    addToHead(pList, 5);

    addToTail(pList, 11); // 插入数据到尾
    addToTail(pList, 22);
    addToTail(pList, 33);
    addToTail(pList, 44);
    addToTail(pList, 55);

    showAll(pList);        // 正向显示所有
    showAllReverse(pList); // 反向显示所有

    modify(pList, 11, 66); // 将11修改为66
    showAll(pList);        // 正向显示所有
    printf("size = %ld\n", pList->size);

    deleteNode(pList, 33);
    showAll(pList);                      // 正向显示所有
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

//     pList->addToTail(pList, 11); // 插入数据到尾
//     pList->addToTail(pList, 22);
//     pList->addToTail(pList, 33);
//     pList->addToTail(pList, 44);
//     pList->addToTail(pList, 55);

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