//https://www.cnblogs.com/rookiefly/p/3451310.html
// 单向循环列表的实现

struct LNode
{
    int data;
    struct LNode *next;
};
typedef struct LNode *linklist;

void InitList(linklist *L) //改变尾指针
{
    *L = (linklist)malloc(sizeof(struct LNode)); //分配头结点
    if (*L == NULL)                              //分配失败
        exit(0);
    (*L)->next = *L; //指针域指向它本身
}

void ClearList(linklist *L) //改变尾指针
{
    linklist p, q;
    *L = (*L)->next; //先令尾指针指向头结点，不然释放最后一个结点时尾指针，无法指向头结点
    p = (*L)->next;  //p指向第一个结点

    while (p != *L) //p未到表头时
    {
        q = p->next;
        free(p);
        p = q;
    }
    *L->next = *L; //头结点指针域指向其本身
}

void DestroyList(linklist *L)
{
    ClearList(&L);
    free(*L); //释放头结点
    *L = NULL;
}

int ListEmpty(linklist L)
{
    if (L->next == L) //指针域指向它本身，肯定就是空了，该结点即为头结点
        return 0;
    else
        return 1; //非空为1
}

int ListLength(linklist L)
{
    linklist p = L->next->next; //p指向第一个结点
    int j = 0;

    while (p != L->next) //p未到表头时
    {
        ++j;
        p = p->next;
    }
    return j;
}

void GetElem(linklist L, int i, int *e)
{
    linklist p = L->next; //p指向头结点
    int j = 0;
    if (i < 1 || i > ListLength(L)) //位置不合理
        exit(0);

    while (j < i) //位置合理，找到第i个结点
    {
        ++j;
        p = p->next;
    }
    *e = p->data;
}

int LocateElem(linklist L, int e)
{
    linklist p = L->next->next; //p指向链表第一个元素
    int j = 0;

    while (p != L->next) //p未到表头时
    {
        ++j;
        if (p->data == e)
            return j;
        p = p->next;
    }
    return -1; //未找到，返回-1
}

int PriorElem(linklist L, int cur_e, int *pri_e)
{
    linklist p = L->next->next; //p指向链表第一个元素
    linklist q;

    while (p != L->next)
    {
        q = p->next; //q指向p的后继
        if (q != L->next && q->data == cur_e)
        {
            *pri_e = p->data;
            return 0;
        }
        p = q;
    }
    return 0;
}

int NextElem(linklist L, int cur_e, int *Nex_e) //最后一个元素无后继
{
    linklist p = L->next->next; //p指向第一个结点
    linklist q;

    while (p != L->next)
    {
        q = p->next;
        if (q != L->next && p->data == cur_e)
        {
            *Nex_e = q->data;
            return 0;
        }
        p = q;
    }
    return 0;
}

int ListInsert(Linklist *L, int i, int e) //在表尾插入改变尾指针
{
    linklist p = (*L)->next; //p指向表头
    linklist q, s;
    int j = 0;

    if (i < 1 || i > ListLength(L) + 1) //插入位置不合理
        exit(0);

    while (j < i - 1) //位置合理，找到第i-1个结点
    {
        ++j;
        p = p->next;
    }
    q = p->next; //q指向第i个结点
    s = (linklist)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = q;
    q->next = s;
    if (p == *L)
        *L = s;
}

// http://data.biancheng.net/view/7.html 约瑟夫环
