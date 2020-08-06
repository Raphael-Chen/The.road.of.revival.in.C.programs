#pragma once

#define _ASC 1     // 升序排序
#define _DESC 0    // 降序排序
typedef int _TYPE; // 数据类型

#include <stdio.h>

typedef struct DoubleLinkListNode
{
    struct DoubleLinkListNode *pPre;  // 前一个节点指针
    struct DoubleLinkListNode *pNext; // 后一个节点指针
    _TYPE value;
} DLNode; // 节点

typedef struct DoubleLinkList
{
    DLNode *head; // 链表头
    DLNode *back; // 链表尾
    size_t size;  //链表包含的元素的个数 typedef unsigned int   size_t;
} DLlist;         // 双链表

// 对一个新链表进行初始化
void init(DLlist *pList);

// 快速创建一个空的双链表
DLlist *_createList();

// 使用可变参数来创建一个链表
DLlist *_createListWithValues(int length, ...);

// 使用数组来创建一个链表
DLlist *_createListWithArrayValues(_TYPE array[], int length);

// 插入到头部,返回1插入成功
int addToHead(DLlist *pList, _TYPE value);

// 插入到尾部,返回1插入成功
int addToBack(DLlist *pList, _TYPE value);

// 将一维数组的值添加到链表头部,返回1插入成功
int addToHeadWithArrayValues(DLlist *pList, _TYPE array[], int length);

// 将一维数组的值添加到链表尾部,返回1插入成功
int addToBackWithArrayValues(DLlist *pList, _TYPE array[], int length);

// 插入到指定元素的后面,返回1插入成功
int insertAfter(DLlist *pList, _TYPE curValue, _TYPE newValue);

// 插入到指定元素的后面,返回1插入成功,改进版
int insertAfter2(DLlist *pList, _TYPE curValue, _TYPE newValue);

// 插入到指定元素的前面,返回1插入成功
int insertBefore(DLlist *pList, _TYPE curValue, _TYPE newValue);

// 插入到指定元素的前面,返回1插入成功,改进版
int insertBefore2(DLlist *pList, _TYPE curValue, _TYPE newValue);

// 删除第一个节点，并返回它
DLNode *removeFirst(DLlist *pList);

// 删除最后一个节点，并返回它
DLNode *removeLast(DLlist *pList);

// 正向显示所有
void showAll(DLlist *pList);

// 使用递归正向显示所有
void showAllWithRecursion(DLNode *head);

// 反向显示所有
void showAllReverse(DLlist *pList);

// 使用递归反向显示所有
void showAllReverseWithRecursion(DLNode *back);

// 删除指定元素，返回1删除成功
int deleteNode(DLlist *pList, _TYPE value);

// 删除指定元素，返回1删除成功，deleteNode改进版
int deleteNode2(DLlist *pList, _TYPE value);

// 删除一个范围的元素,从fromValue的节点开始删除，删除count个
int deleteRange(DLlist *pList, _TYPE fromValue, int count);

// 检查是否为空
int checkNull(void *p);

// 修改指定的值,返回1修改成功
int modify(DLlist *pList, _TYPE oldValue, _TYPE newValue);

// 释放所有元素，清空链表，返回1则成功
int freeAll(DLlist *pList);

// 从第一个匹配元素开始释放,返回1删除成功
int freeFrom(DLlist *pList, _TYPE value);

// 通过值找到指定匹配的第一个节点
DLNode *findByValue(DLlist *pList, _TYPE value);

// 将一个链表插入当前链表的尾部
int addListToBack(DLlist *pList, DLlist *addingList);

// 获取指定值的节点在链表中的深度
int getDepth(DLlist *pList, _TYPE value);

// 是否为空，返回1则为空
int isEmpty(DLlist *pList);

// 对链表值进行排序,asc为0则降序序排，否则升序。可以使用_ASC(升序) ， _DESC(降序)
void sort(DLlist *pList, int asc);
