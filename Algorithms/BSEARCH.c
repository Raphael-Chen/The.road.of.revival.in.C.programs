#include <stdlib.h>
#include <stdio.h>

/*
    #include <stdlib.h>
    void *bsearch(const void *key, const void *base,
                    size_t nmemb, size_t size,
                    int (*compar)(const void *, const void *));
    Description
    2 The bsearch function searches an array of nmemb objects, the initial element of which
    is pointed to by base, for an element that matches the object pointed to by key. The
    size of each element of the array is specified by size.

    3 The comparison function pointed to by compar is called with two arguments that point
    to the key object and to an array element, in that order. The function shall return an
    integer less than, equal to, or greater than zero if the key object is considered,
    respectively, to be less than, to match, or to be greater than the array element. The array
    shall consist of: all the elements that compare less than, all the elements that compare
    equal to, and all the elements that compare greater than the key object, in that order. 303)

    Returns
    The bsearch function returns a pointer to a matching element of the array, or a null
    pointer if no match is found. If two elements compare as equal, which element is
    matched is unspecified.
*/

int compare_int( const void *a, const void *b )
{
    return ( *( int* )a - *( int* )b );
}

int compare_float( const void *a, const void *b)
{
    return (( *(float*)a == *(float*)b ) ? 0 : 1);
}

int main(void)
{
    int int_values[] = {1, 3, 2, 4, 5};
    float float_values[] = {1.1, 3.3, 2.2, 4.4, 5.5};

    int *int_ptr = NULL, 
        int_value = 2, 
        elements = 5;

    float *float_ptr = NULL, 
          float_value = 33.3;

    int_ptr = ( int* )bsearch(&int_value, int_values, elements, sizeof(int), compare_int );

    if ( int_ptr != NULL )
        printf("Value %d found\n", int_value);
    else
        printf("Value %d not found\n", int_value);

    float_ptr = ( float* )bsearch(&float_value, float_values,
                        elements, sizeof(float),
                        compare_float);

    if ( float_ptr != NULL )
        printf("Value %3.1f found\n", float_value);
    else
        printf("Value %3.1f not found\n", float_value);

    return 0;
}
