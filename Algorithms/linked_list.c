#include "linked_list.h"

// 线性表的链式存储相比于顺序存储，有两大优势：
// - 链式存储的数据元素在物理结构没有限制，当内存空间中没有足够大的连续的内存空间供顺序表使用时，
// 可能使用链表能解决问题。（链表每次申请的都是单个数据元素的存储空间，可以利用上一些内存碎片）
// - 链表中结点之间采用指针进行链接，当对链表中的数据元素实行插入或者删除操作时，只需要改变指针的
// 指向，无需像顺序表那样移动插入或删除位置的后续元素，简单快捷。

//
link* init_empty( link* head )
{
    head ->elem = 0;
    //  ... more elements init
    head ->next = NULL;

    return head;
}

link *create_list(_TYPE n)
{
    link *list = (link *)malloc(sizeof(link)); //创建一个头结点
    link *temp = list;                         //声明一个指针指向头结点，用于遍历链表
    _TYPE i;

    //生成链表
    for ( i = 1; i < n + 1; i++ )
    {
        link *a    = (link *)malloc(sizeof(link));
        a->elem    = i;
        a->next    = NULL;
        temp->next = a;
        temp = temp->next;
    }

    return list;
}

link *insertElem(link *list, _TYPE elem, _TYPE add)
{
    link *temp = list; //创建临时结点temp
    _TYPE i;

    //首先找到要插入位置的上一个结点
    for ( i = 1; i < add; i++ )
    {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return list;
        }
        temp = temp->next;
    }

    //创建插入结点c
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;

    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;

    return list;
}

/** fake code
     LIST-DELETE( L, x )
    1 if x.pre != NIL
    2   x.pre.next != x.next
    3 else L.head = x.next
    4 if x.next != NIL
    5   x.next.pre = x.pre
**/

link *delElem(link *list, _TYPE add)
{
    link *temp = list;
    _TYPE i;

    //遍历到被删除结点的上一个结点
    for ( i = 1; i < add; i++ )
    {
        temp = temp->next;
    }
    link *del = temp->next;        //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     //手动释放该结点，防止内存泄漏

    return list;
}

// 链表中查找某结点
_TYPE selectElem(link *list, _TYPE elem)
{
    link *shadow = list;
    _TYPE i = 1;

    while (shadow->next)
    {
        shadow = shadow->next;
        if (shadow->elem == elem)
        {
            return i;
        }
        i++;
    }
    
    return -1;
}


link *amendElem(link *list, _TYPE add, _TYPE newElem)
{
    link *temp = list;
    temp = temp->next;          //temp指向首元结点
    //temp指向被删除结点
    for (_TYPE i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;

    return list;
}


// 打印出链表中所有的元素
bool display(link *list)
{
    if ( NULL == list )
    {
        printf( "链表为空，停止打印\n" );
        return false;
    }

    link *temp = list; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。

    LIST_BEGAIN;
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    LIST_END;
    // printf("\n");

    return true;
}

// http.//data.biancheng.net/view/5.html

int main(void)
{
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *list = create_list(4);
    display(list);

    printf("在第4的位置插入元素5：\n");
    list = insertElem(list, 5, 4);
    display(list);

    printf("删除元素3.\n");
    list = delElem(list, 3);
    display(list);

    printf("查找元素2的位置为：\n");
    _TYPE address = selectElem(list, 2);
    if (address == -1)
    {
        printf("没有该元素");
    }
    else
    {
        printf("元素2的位置为：%d\n", address);
    }
    printf("更改第3的位置的数据为7.\n");
    list = amendElem(list, 3, 7);
    display(list);

    return 0;
}
