#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *concat_fopen(char *s1, char *s2, char *mode)
{
    char str[strlen(s1) + strlen(s2) + 1];
    strcpy(str, s1);
    strcat(str, s2);

    return fopen(str, mode);
}

struct f1
{
    int x;
    int y[];
} f1 = {1, {2, 3, 4}};

struct f2
{
    struct f1 f1;
    int data[3];
} f2 = {{1}, {2, 3, 4}};

/* 
 * a struct with a flexible array member ( 柔性数组 )
 * 
 * Supported by GNU gcc
 *
 * Compile with: gcc test_flex.c -Wall -W -pedantic -std=c99
 */

typedef struct s_var_
{
    int size;
    double p[]; /* Incomplete array type */
} s_var;

int main(void)
{
    int i;

    /* suppose we want an array of 8 doubles in the struct: */

    int siz = 8;
    s_var *ps;

    printf("sizeof(int)   = %ld, sizeof(double) = %ld\n", sizeof(int), sizeof(double));
    printf("sizeof(s_var) = %ld\n\n", sizeof(s_var));

    ps = malloc(sizeof(s_var) + siz * sizeof(double));
    ps->size = siz;

    for (i = 0; i < siz; i++)
    { /* just put something in the array */
        ps->p[i] = 1.5 * i;
    }

    for (i = 0; i < ps->size; i++)
    {
        printf("ps->p[%d] = %9f\n", i, ps->p[i]);
    }
    printf("\n&(ps->size) = %p\n", &(ps->size));

    for (i = 0; i < ps->size; i++)
    {
        printf("&(ps->p[%d]) = %p\n", i, &(ps->p[i]));
    }

    free(ps);

    return 0;
}
