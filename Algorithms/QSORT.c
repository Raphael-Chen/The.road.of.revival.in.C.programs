#include <stdlib.h>
#include <stdio.h>



int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int compare_float( const void * a,  const void * b )
{
    if ( *( float* )a < *( float* )b )
        return (-1);
    else if ( *( float* )a == *( float* )b )
        return (0);
    else
        return (1);
}



int main(void)
{
    int int_values[] = {51, 23, 2, 37, 45};
    float float_values[] = {21.1, 13.3, 22.2, 34.4, 15.5};

    int elements = 5, 
        i;

    qsort( int_values, elements, sizeof(int), cmpfunc );

    for (i = 0; i < elements; i++)
        printf("%d ", int_values[i]);

    putchar('\n');

    qsort(float_values, elements, sizeof(float), compare_float);

    for (i = 0; i < elements; i++)
        printf("%4.1f ", float_values[i]);

    return 0;       
}


/*

    #include <stdlib.h>
    void qsort(void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *));

    Description
    2 The qsort function sorts an array of nmemb objects, the initial element of which is
    pointed to by base. The size of each object is specified by size.

    3 The contents of the array are sorted into ascending order according to a comparison
    function pointed to by compar, which is called with two arguments that point to the
    objects being compared. The function shall return an integer less than, equal to, or
    greater than zero if the first argument is considered to be respectively less than, equal to,
    or greater than the second.

    4
    If two elements compare as equal, their order in the resulting sorted array is unspecified.

    Returns
    The qsort function returns no value.
*/

/*
int compare_int(int *a, int *b)
{
    return (*a - *b);
}

int compare_float(float *a, float *b)
{
    if (*a < *b)
        return (-1);
    else if (*a == *b)
        return (0);
    else
        return (1);
}

*/