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

// 判断链表是否为空，返回true则为空
bool isEmpty(DLlist *pList)
{
    if (checkNull(pList))
    {
        return true;
    }
    // return pList->size == 0;
    return false;
}

// 用于给通过DoubleLinkList创建的新链表进行初始化
void init(DLlist *pList)
{
    pList->head = pList->back = NULL;
    pList->size = 0;
}

// 通过值找到指定匹配的第一个节点
DLNode *findByValue(DLlist *pList, _TYPE value)
{
    if (checkNull(pList))
    {
        return NULL;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return NULL;
    }

    DLNode *curNode = pList->head;
    while (curNode)
    {
        if (curNode->value == value)
        {
            return curNode;
        }
        curNode = curNode->pNext;
    }
    
    return NULL; // 没有找到还回空
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

// 将某个值插入到双链表的尾部,返回true插入成功
bool addToTail(DLlist *pList, _TYPE value)
{
    if ( checkNull(pList) )
    {
        return false;
    }
    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if ( checkNull(newNode) )
    {
        return false; // 创建新节点失败,则返回
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

    return true;
}

// 正向输出所有节点值
void showAll(DLlist *pList)
{
    if ( checkNull(pList) )
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

// 反向显示所有节点的值
void showAllReverse(DLlist *pList)
{
    if (checkNull(pList))
    {
        return;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return;
    }

    printf("\n[  ");
    DLNode *p = pList->back;
    while (p != NULL)
    {
        printf("%d  ", p->value);
        p = p->pPre; // 往前遍历
    }
    printf("]\n");
}

// 删除第一个指定元素的节点，返回1则删除成功
int deleteNode(DLlist *pList, _TYPE value)
{
    if (checkNull(pList))
    {
        printf("\nlog:删除节点失败\n");
        return 0;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:删除节点失败,空链表\n");
        return 0;
    }
    DLNode *findNode = findByValue(pList, value);
    if (checkNull(findNode))
    {
        printf("\nlog:要删除的节点不存在,value = %d\n", value);
        return 0;
    }
    if (value == pList->head->value) // 头节点满足
    {
        if (pList->head->pNext == NULL) // 只有head时
        {
            DLNode *curNode = pList->head;
            pList->head = pList->back = NULL; // 删除所有节点后将head与back都赋值NULL
            free(curNode);
        }
        else
        {
            DLNode *curNode = pList->head;
            pList->head = curNode->pNext; // 头节点后移
            free(curNode);
        }
        pList->size--;
        return 1;
    }
    else if (value == pList->back->value) // 尾节点满足
    {
        DLNode *curNode = pList->back;
        pList->back = curNode->pPre;
        pList->back->pNext = NULL;
        free(curNode);
        pList->size--;
        return 1;
    }
    else
    {
        DLNode *curNode = pList->head->pNext;
        while (curNode != NULL) // 下面可以调用findByValue来查找指定节点
        {
            if (curNode->value == value) // 删除满足条件的节点
            {
                DLNode *preNode = curNode->pPre;
                DLNode *nextNode = curNode->pNext;
                preNode->pNext = nextNode;
                nextNode->pPre = preNode;
                free(curNode); // 释放内存
                pList->size--;
                return 1;
            }
            curNode = curNode->pNext;
        }
    }
    return 0;
}

// 获取指定值的节点在链表中的深度
int getDepth(DLlist *pList, _TYPE value)
{
    DLNode *curNode = pList->head;
    int depth = 0;

    if (checkNull(pList))
    {
        return -1;
    }
    if (isEmpty(pList))
    {
        return 0;
    }

    while (NULL != curNode)
    {
        depth++;
        if (curNode->value == value)
        {
            return depth;
        }
        curNode = curNode->pNext;
    }

    return -1;
}

// 释放所有节点占用的内存空间，清空链表，返回1则成功
int freeAll(DLlist *pList)
{
    if (checkNull(pList))
    {
        return 0;
    }
    if (0 == isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return 0;
    }
    DLNode *curNode = pList->head->pNext;
    while (NULL != curNode) // 循环删除头节点的下一个节点
    {
        pList->head->pNext = curNode->pNext;
        free(curNode);
        curNode = pList->head->pNext;
    }

    free(pList->head); // 删除头节点
    pList->head = pList->back = NULL;
    pList->size = 0;

    return 1;
}

// 从第一个匹配值的节点开始释放,截断并丢弃从指定值节点开始到结尾的链。返回1删除成功
int freeFrom(DLlist *pList, _TYPE value)
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

    DLNode *curNode = findByValue(pList, value);
    if (curNode == NULL)
    {
        printf("\nlog: 要删除value = %d的起始节点不存在\n", value);
        return 0;
    }
    if (curNode == pList->head)
    {
        return freeAll(pList);
    }
    else
    {
        DLNode *preNode = curNode->pPre;
        int depth = getDepth(pList, preNode->value);
        DLlist *dyingList = (DLlist *)malloc(sizeof(DLlist)); // 将要被删除的链表
        if (checkNull(dyingList))
        {
            return 0;
        }
        dyingList->head = curNode;
        freeAll(dyingList); // 调用freeAll来删除
        free(dyingList);
        preNode->pNext = NULL; // 将curNode的上一个节点的pNext置NULL
        pList->back = preNode; // 重新设置尾节点
        pList->size = depth;
    }

    return 1;
}

// 删除一个范围的元素节点, 从fromValue值的节点开始删除，删除count个。返回1表示删除成功
int deleteRange(DLlist *pList, _TYPE fromValue, int count)
{
    int num = 0;
    if (checkNull(pList))
    {
        return 0;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return 0;
    }

    DLNode *curNode = findByValue(pList, fromValue);
    if (checkNull(curNode))
    {
        return 0;
    }

    if (curNode == pList->head) // 如果是头节点
    {
        while (num < count && deleteNode(pList, pList->head->value)) // 从头部开始删除count个
        {
            ++num;
        }
        return 1;
    }
    else // 非头节点
    {
        DLNode *preNode = curNode->pPre;
        while (curNode)
        {
            if (num < count)
            {
                preNode->pNext = curNode->pNext;
                curNode->pPre = preNode;
                free(curNode);
                ++num;
            }
            else
            {
                break;
            }
            curNode = preNode->pNext;
        }
    }

    if (num == count || NULL == curNode) // 如果删除了指定数量或已经是尾节点下一个了
    {
        pList->size -= (num == count) ? count : num;
        return 1;
    }
    return 0;
}

// 插入到指定值curValue的节点元素的前面,返回1则插入成功，insertBefore改进版
int insertBefore2(DLlist *pList, _TYPE curValue, _TYPE newValue)
{
    if (checkNull(pList))
    {
        return 0;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:插入指定节点后面失败,空链表\n");
        return 0;
    }

    DLNode *curNode = findByValue(pList, curValue); // 查找指定节点
    if (checkNull(pList))
    {
        // printf("\n插入失败，目标节点value=%d不存在\n", curNode);
        printf("\n插入失败，目标节点value = %p不存在\n", curNode);
        return 0;
    }

    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (checkNull(newNode))
    {
        return 0;
    }
    newNode->pNext = newNode->pPre = NULL;
    newNode->value = newValue;

    if (curNode == pList->head)
    {
        newNode->pNext = pList->head;
        pList->head->pPre = newNode;
        pList->head = newNode;
        pList->size++;
    }
    else
    {

        DLNode *preNode = curNode->pPre;
        newNode->pNext = curNode;
        newNode->pPre = preNode;
        curNode->pPre = newNode;
        preNode->pNext = newNode;
        pList->size++;
    }

    return 1;
}

// 测试1：创建、添加到头尾、修改、删除节点、显示所有
/********
int main(void)
{
    DLlist *pList = _createList(); // 创建一个双链表
    addToHead(pList, 1);           // 插入数据到头
    addToHead(pList, 2);
    addToHead(pList, 3);
    addToHead(pList, 4);
    addToHead(pList, 5);

    addToTail(pList, 11);           // 插入数据到尾
    addToTail(pList, 22);           
    addToTail(pList, 33);           
    addToTail(pList, 44);           
    addToTail(pList, 55);           

    showAll(pList);                  // 正向显示所有
    showAllReverse(pList)            // 反向显示所有

    modify(pList, 11, 66)            // 将11修改为66
    showAll(pList);                  // 正向显示所有
    printf("size = %ld\n", pList->size);

    deleteNode(pList, 33);
    showAll(pList);                      // 正向显示所有
    printf("size = %ld\n", pList->size); // 双链表的大小

    // system("pause");
    return 0;
}********/

// 测试2：删除一个范围、清空所有、截取前部分
/*********
int main(void)
{
    DLlist *pList = (DLlist *)malloc(sizeof(DLlist));
    init(pList);

    addToHead(pList, 1);
    addToHead(pList, 2);
    addToHead(pList, 3);
    addToHead(pList, 4);
    addToHead(pList, 5);
    addToHead(pList, 6);
    addToHead(pList, 7);
    addToHead(pList, 8);
    addToHead(pList, 9);
    addToHead(pList, 10);

    showAll(pList);
    printf("size = %lu\n", pList->size); // 大小

    freeFrom(pList, 3); // 从3开始，删除后面所有
    showAll(pList);
    printf("size = %lu\n", pList->size);

    deleteRange(pList, 9, 3); // 从9开始删除3个元素
    showAll(pList);
    printf("size = %lu\n", pList->size);

    freeAll(pList); // 清空链表
    showAll(pList);
    printf("size = %lu\n", pList->size);

    // system("pause");
    return 0;
}*********/

// 插入到指定值curValue的节点元素的后面,返回1则插入成功
int insertAfter(DLlist *pList, _TYPE curValue, _TYPE newValue)
{
    if (checkNull(pList))
    {
        return 0;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:插入指定节点后面失败,空链表\n");
        return 0;
    }

    // 创建新节点并赋值参数newValue
    DLNode *newNode = (DLNode *)malloc(sizeof(DLNode));
    if (checkNull(newNode))
    {
        return 0; // 创建新节点失败,则返回
    }
    newNode->pNext = newNode->pPre = NULL;
    newNode->value = newValue;

    if (pList->head->value == curValue) // 头节点满足
    {
        DLNode *next = pList->head->pNext;
        next->pPre = newNode;
        newNode->pNext = next;
        newNode->pPre = pList->head;
        pList->head->pNext = newNode;
        pList->size++;
        return 1;
    }
    else if (pList->back->value == curValue) // 尾节点满足，防止要遍历一遍，浪费时间
    {
        pList->back->pNext = newNode;
        newNode->pPre = pList->back->pNext;
        // pList->back;
        pList->size++;
        return 1;
    }
    else // 其他
    {
        DLNode *p = pList->head->pNext;
        while ( NULL != p )             //Fix logic bug
        {
            if (p->value == curValue)
            {
                DLNode *next = p->pNext;
                next->pPre   = newNode;
                newNode->pNext = next;
                newNode->pPre  = p;
                p->pNext       = newNode;
                pList->size++;
                return 1;
            }
            p = p->pNext;
        }
    }

    return 0;
}

// 删除第一个节点，并返回它
DLNode *removeFirst(DLlist *pList)
{
    if (checkNull(pList))
    {
        return NULL;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return NULL;
    }

    if (pList->head->pNext == NULL) // 只有head
    {
        DLNode *head = pList->head;
        pList->head = NULL;
        pList->size--;
        return head;
    }
    else
    {
        DLNode *head = pList->head;
        DLNode *next = head->pNext;
        head->pNext = NULL;
        next->pPre = NULL;
        pList->head = next;
        pList->size--;
        return head;
    }

    return NULL;
}

// 删除最后一个节点，并返回它
DLNode *removeLast(DLlist *pList)
{
    if (checkNull(pList))
    {
        return NULL;
    }
    if (isEmpty(pList))
    {
        printf("\nlog:空链表\n");
        return NULL;
    }

    if (pList->back == pList->head)
    {
        return removeFirst(pList);
    }
    else
    {
        DLNode *back = pList->back;
        DLNode *preNode = back->pPre;
        back->pPre = NULL;
        preNode->pNext = NULL;
        pList->back = preNode;
        pList->size--;
        return back;
    }

    return NULL;
}

// 测试3：删除头尾、查找、插入
/***********
int main(void)
{
    int ret;   // 函数保存返回值
    
    DLlist *pList = (DLlist *)malloc(sizeof(DLlist));
    init(pList);

    addToHead(pList, 1);
    addToHead(pList, 2);
    addToHead(pList, 3);
    addToHead(pList, 4);
    addToHead(pList, 5);
    addToHead(pList, 6);
    showAll(pList);
    printf("size=%ld\n", pList->size);

    //int ib = insertBefore(pList, 5, 66);
    ret = insertBefore2(pList, 5, 66); // 在5前面插入66
    if ( 0 != ret )
    {
        printf("\n前插成功\n");
        showAll(pList);
        printf("size=%ld\n", pList->size);
    }

    ret = insertAfter(pList, 3, 26); // 在3后面插入26
    if ( 0 != ret )
    {
        printf("\n后插成功\n");
        showAll(pList);
        printf("size=%ld\n", pList->size);
    }

    DLNode *find = findByValue(pList, 6); // 查找6
    if ( NULL != find )                    //If find not NULL.
    {
        printf("\nfind, value=%d, depth=%d\n", find->value, getDepth(pList, find->value));
    }

    DLNode *first = removeFirst(pList); // 删除第一个节点并返回它
    if ( NULL != first )
    {
        printf("\nfirst value=%d\n", first->value);
        showAll(pList);
        printf("size=%ld\n", pList->size);
    }

    DLNode *last = removeLast(pList); // 删除最后一个节点并返回它
    if ( NULL != last )
    {
        printf("\nlast value=%d\n", last->value);
        showAll(pList);
        printf("size=%ld\n", pList->size);
    }

    // system("pause");

    return 0;
}
**********/

// 使用可变参数来创建一个链表，需要声明头文件 #include <stdarg.h>
DLlist* _createListWithValues(int length, ...)
{
    DLlist* pList = _createList();

    va_list ap;                                  // 参数指针
    va_start( ap, length );                      // 第一个元素
    for (int i = 0; i < length; i++)
    {
        addToTail( pList, va_arg( ap, _TYPE ) ); // 返回对应类型的数据，并添加到链表
    }
    va_end(ap);

    return pList;
}

// 将一个链表插入当前链表的尾部
int addListToBack(DLlist *pList, DLlist *addingList)
{
    if (checkNull(pList) || checkNull(addingList) || isEmpty(addingList))
    {
        return 0;
    }

    DLNode *curNode = addingList->head;
    while ( NULL != curNode )
    {
        addToTail( pList, curNode->value );       // 添加到尾部
        curNode = curNode->pNext;
    }

    return 1;
}


// 测试4：使用可变参数创建链表，并向链表中添加一个链表
/****************
int main( void )
{
    DLlist* pList    = _createListWithValues(5, 2, 3, 4, 5, 6);
    DLlist* pnewList = _createListWithValues(5,11,22,33,44,55); 
    showAll(pList);
    showAll(pnewList);

    if ( !checkNull(pList) && !checkNull(pnewList) )
    {
        addListToBack(pList, pnewList);              // 将pnewList添加到pList尾部
    }

    showAll(pList);
    printf("size = %ld\n", pList->size);

    // system("pause");

    return 0;
}****************/

// 将一维数组的值添加到链表尾部, 返回1插入成功
int addToBackWithArrayValues(DLlist *pList, _TYPE array[], int length)
{
    if (checkNull(pList) || checkNull(array) || length == 0)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        // if (!addToBack(pList, array[i]))
        if ( !addToTail(pList, array[i]) )
        {
            return 0;
        }
    }

    return 1;
}

// 使用数组的元素来创建一个链表，length表示要添加到链表的个数
DLlist* _createListWithArrayValues(_TYPE* array, int length)
{
    if (checkNull(array) || 0 == length)
    {
        return NULL;
    }

    DLlist *pList = _createList();
    if (checkNull(pList))
    {
        return NULL;
    }

    if (addToBackWithArrayValues(pList, array, length))
    {
        return pList;
    }

    return NULL;
}

// 使用选择排序法对链表值进行排序, asc为0则降序序排，否则升序。可以使用_ASC(升序) ， _DESC(降序)
void sort(DLlist *pList, int asc)
{
    DLNode *pi, *pk, *pj;
    _TYPE value;
    if (checkNull(pList) || isEmpty(pList))
    {
        return;
    }

    for (pi = pList->head; pi->pNext != NULL; pi = pi->pNext)
    {
        pk = pi;
        for (pj = pi->pNext; pj != NULL; pj = pj->pNext)
        {
            if (asc && pk->value > pj->value) // 排升序
            {
                pk = pj;
            }
            if (!asc && pk->value < pj->value) // 排降序
            {
                pk = pj;
            }
        }

        if (pk != pi)
        {
            value = pk->value;
            pk->value = pi->value;
            pi->value = value;
        }
    }
}


// 测试5：对链表元素进行排序
int main( void )
{
//  DLlist* pList = _createListWithValues(5, 2 ,8 , 4, 9, 7); 


    // 创建一个包含5个元素（2 ,8 , 4, 9, 7）的链表
    int arr[5] = { 2 ,8, 4, 9, 7 };
    DLlist* pList = _createListWithArrayValues(arr, 5);

    //showAllReverse(pList);
    sort(pList, _DESC);  // 降序
    showAll(pList);

    sort(pList, _ASC);  // 升序
    showAll(pList);

    // addToBackWithArrayValues(pList, arr, 3);  // 将一个数组的值添加到链表尾部
    //showAll(pList);

    // system("pause");

    return 0;
}


