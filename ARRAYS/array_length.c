#include <stdio.h>

// A.02 How to get the length of array.

int main( void )
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //* size of `array` in bytes 
    size_t size = sizeof(array);

    //* number of elements in `array` 
    size_t length = sizeof(array) / sizeof(array[0]);

    printf( "size is %ld, length is %ld\n", size, length );

    return 0;
}
