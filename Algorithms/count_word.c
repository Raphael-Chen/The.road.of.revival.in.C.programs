#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX 50

struct tnode
{
    char word[MAX];
    int count;
    struct tnode *left, *right;
};

typedef struct sort
{
    int num;
    char w[50];
} List;

List list[1000000];
struct tnode *arr[1000000];
int curr = 0;

int cmp(const void *a, const void *b)
{
    List *p1 = (List *)a;
    List *p2 = (List *)b;
    if (p1->num != p2->num)
        return p2->num - p1->num;
    else
        return strcmp(p1->w, p2->w);
}

// struct tnode *treewords(struct tnode *, char *);
// void treeprint(struct tnode *);

struct tnode *treewords(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL)
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        strcpy(p->word, w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = treewords(p->left, w);
    }
    else
        p->right = treewords(p->right, w);

    return (p);
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        arr[curr++] = p;
        treeprint(p->right);
    }
}
#define READ_FILE "./count_words.txt" 

int main( void )
{
    char word[MAX];
    FILE *bfp;
    FILE *out;
    char c;
    int i, k, n;
    struct tnode *root;
    root = NULL;

    bfp = fopen( READ_FILE, "r");
    if ( NULL == bfp )
    {
        perror( "File open " );
        exit(1);
    }
    
    while ((c = fgetc(bfp)) != EOF)
    {
        ungetc(c, bfp);
        for (i = 0; (c = fgetc(bfp)) != ' ' && c != '\n' && c != EOF; i++)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            {
                c = tolower(c);
                word[i] = c;
            }
            else
                break;
        }
        word[i] = '\0';
        if (strlen(word) > 0)
            root = treewords(root, word);
    }

    treeprint(root);
    for (i = 0; i < curr; i++)
    {
        list[i].num = arr[i]->count;
        strcpy(list[i].w, arr[i]->word);
    }
    n = curr;
    qsort(list, n + 1, sizeof(list[0]), cmp);


    out = fopen("wordfreq.txt", "w");
    for (k = 0; k < curr; k++)
    {
        fprintf(out, "%s %d\n", list[k].w, list[k].num);
    }
    for (k = 0; k < 100; k++)                       //out put first 100 on screen
    {
        printf("%s %d\n", list[k].w, list[k].num);
    }
    fclose(bfp);
    fclose(out);

    return 0;
}

