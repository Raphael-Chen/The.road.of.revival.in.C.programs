#include <stdio.h>
#include <stdlib.h>

/*树节点*/
typedef struct node
{
    int data;
    // ......
    struct node *left;  /*节点左边的树枝*/
    struct node *right; /*节点右边的树枝*/
} Node;

/*树根*/
typedef struct tree
{
    Node *root;
} Tree;

/*插入函数 向一个树里面插入数据*/
void insert(Tree *tree, int value)
{
    /*创建一个节点*/
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    /*判断树是不是空树*/
    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else /*不是空树*/
    {
        Node *temp = tree->root; /*从树根开始*/
        while (temp != NULL)
        {
            if (value < temp->data) /*小于就进左儿子*/
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else /*继续判断*/
                {
                    temp = temp->left;
                }
            }
            else /*否则进右儿子*/
            {
                if (temp->right == NULL)
                {
                    temp->right = node;
                    return;
                }
                else /*继续判断*/
                {
                    temp = temp->right;
                }
            }
        }
    }
}

/*
 遍历一整颗树
 中序遍历:先左后根再右
 */
void traverse(Node *node)
{
    if (node != NULL)
    {
        traverse(node->left);
        printf("%d ", node->data);
        traverse(node->right);
    }
}

/*销毁一棵树*/
void distory_tree(Node *node)
{
    if (node != NULL)
    {
        distory_tree(node->left);
        distory_tree(node->right);
        printf("\nfree node:%d\n", node->data);
        free(node);
        node = NULL;
    }
}


int main( void )
{
    short          i = 0;
    unsigned short int n;   //确保不为负数

    Tree tree;
    tree.root = NULL; /*创建一个空树*/

    printf("input total num: ");   /*输入n个数并创建这个树*/
    scanf("%hd\n", &n);


    for (i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        insert(&tree, temp);
    }

    traverse(tree.root);

    distory_tree(tree.root);

    return 0;
}