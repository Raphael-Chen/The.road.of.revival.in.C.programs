//https://www.cnblogs.com/rookiefly/p/3451310.html
// 单向循环列表的实现

#include <stdio.h>
#include <stdlib.h>

struct LNode
{
    int data;
    // ......
    struct LNode *next;
};
typedef struct LNode * Linklist;

// 初始化链表
void InitList(Linklist p_list) //改变尾指针
{
    p_list = (Linklist)malloc(sizeof(struct LNode)); //分配头结点
    if (p_list == NULL)                              //分配失败
        exit(0);
    p_list ->next = p_list; //指针域指向它本身
}

// 保留头节点，释放其他节点空间，清除数据
void ClearList(Linklist p_list) //改变尾指针
{
    Linklist temp_p, q;
    p_list = (p_list)->next; //先令尾指针指向头结点，不然释放最后一个结点时尾指针，无法指向头结点
    temp_p = (p_list)->next; //p指向第一个结点

    while (temp_p != p_list) //p未到表头时
    {
        q = temp_p->next;
        free(temp_p);
        temp_p = q;
    }
    p_list->next = p_list; //头结点指针域指向其本身
}

// 销毁整个列表，包括头节点
void DestroyList(Linklist p_list)
{
    ClearList(p_list);

    free(p_list); //释放头结点
    p_list = NULL;
}

int ListEmpty(Linklist p_list)
{
    if (p_list->next == p_list) //指针域指向它本身，肯定就是空了，该结点即为头结点
        return 0;
    else
        return 1; //非空为1
}

int ListLength(Linklist p_list)
{
    Linklist temp_p = p_list->next->next; //p指向第一个结点
    int index = 0;

    while (temp_p != p_list->next) //p未到表头时
    {
        ++index;
        temp_p = temp_p->next;
    }

    return index;
}

void GetElem(Linklist p_list, int i, int *e)
{
    Linklist temp_p = p_list->next; //p指向头结点
    int index = 0;
    if (i < 1 || i > ListLength(p_list)) //位置不合理
        exit(0);

    while (index < i) //位置合理，找到第i个结点
    {
        ++index;
        temp_p = temp_p->next;
    }
    *e = temp_p->data;
}

int LocateElem(Linklist p_list, int e)
{
    Linklist temp_p = p_list->next->next; //p指向链表第一个元素
    int index = 0;

    while (temp_p != p_list->next) //p未到表头时
    {
        ++index;
        if (temp_p->data == e)
            return index;
        temp_p = temp_p->next;
    }
    return -1; //未找到，返回-1
}

int PriorElem(Linklist p_list, int cur_e, int *pri_e)
{
    Linklist temp_p = p_list->next->next; //p指向链表第一个元素
    Linklist q;

    while (temp_p != p_list->next)
    {
        q = temp_p->next; //q指向p的后继
        if (q != p_list->next && q->data == cur_e)
        {
            *pri_e = temp_p->data;
            return 0;
        }
        temp_p = q;
    }
    return 0;
}

int NextElem(Linklist p_list, int cur_e, int *Nex_e) //最后一个元素无后继
{
    Linklist temp_p = p_list->next->next; //p指向第一个结点
    Linklist q;

    while (temp_p != p_list->next)
    {
        q = temp_p->next;
        if (q != p_list->next && temp_p->data == cur_e)
        {
            *Nex_e = q->data;
            return 0;
        }
        temp_p = q;
    }
    return 0;
}

int ListInsert(Linklist p_list, int i, int e) //在表尾插入改变尾指针
{
    Linklist temp_p = (p_list)->next;          //p指向表头
    Linklist q, s;
    int index = 0;

    if (i < 1 || i > ListLength(p_list) + 1) //插入位置不合理
        exit(0);

    while (index < i - 1)                   //位置合理，找到第i-1个结点
    {
        ++index;
        temp_p = temp_p->next;
    }
    q = temp_p->next;                       //q指向第i个结点
    s = (Linklist)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = q;
    q->next = s;
    if (temp_p == p_list)
        p_list = s;

    return 0;
}

// 删除第i个节点？
int ListDeletei(Linklist *p_list, int i, int *e)
{
    Linklist temp_p = (*p_list)->next;
    Linklist q;
    int index = 0;
    if (i < 1 || i > ListLength(*p_list))
        exit(0);

    while (index < i - 1)     //找到第i-1个结点
    {
        ++index;
        temp_p = temp_p->next;
    }
    q = temp_p->next;          //q指向第i个结点
    *e = q->data;
    temp_p->next = q->next;
    
    if (q == *p_list)          //删除的是表尾元素，表尾指针发生改变
        *p_list = temp_p;
    free(q);

    return 0;
}

// 遍历整个列表
void TravelList(Linklist p_list)
{
    Linklist temp_p = p_list->next->next; //p指向第一个结点
    int index = 0;

    while (temp_p != p_list->next)        //p未到表头
    {
        ++index;
        printf("第%d个元素为：%d\n", index, temp_p->data);
        temp_p = temp_p->next;
    }
}

int main(void)
{

    return 0;
}

// http://data.biancheng.net/view/7.html 约瑟夫环
