#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Only for English text.
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

struct tnode *treewords(struct tnode *p, const char *string)
{
    int cond;  // for what?
    if (p == NULL)
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        strncpy( p->word, string, strlen( string ) );
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(string, p->word)) == 0) // if the word exist already.
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = treewords(p->left, string);
    }
    else
        p->right = treewords(p->right, string);

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
#define FILE_TO_READ "./count_words.txt" 

int main( void )
{
    char word[MAX];
    FILE *in_fp;
    FILE *out_fp;
    char c;
    int i, k, n;
    struct tnode *root;
    root = NULL;

    in_fp = fopen( FILE_TO_READ, "r");
    if ( NULL == in_fp )
    {
        perror( "File open " );
        exit(1);
    }
    
    // while ((c = fgetc(in_fp)) != EOF)
    while ( 0 == feof(in_fp) ) 
    {
        ungetc(c, in_fp);
        for (i = 0; (c = fgetc(in_fp)) != ' ' && c != '\n' && c != EOF; i++)
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


    out_fp = fopen("wordfreq.txt", "w");
    for (k = 0; k < curr; k++)
    {
        fprintf(out_fp, "%s %d\n", list[k].w, list[k].num);
    }
    for (k = 0; k < 100; k++)                       //out_fp put first 100 on screen
    {
        printf("%s %d\n", list[k].w, list[k].num);
    }
    fclose(in_fp);
    fclose(out_fp);

    return 0;
}

