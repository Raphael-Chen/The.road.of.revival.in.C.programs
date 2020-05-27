#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int *int_values;
    int i;

    int_values = ( int * )malloc( 100 * sizeof(int) ) ;

    if ( int_values == NULL )
        printf("Error allocating the array\n");
    else
    {
        for (i = 0; i < 100; i++)
            int_values[i] = i;

        for (i = 0; i < 100; i++)
            printf("%d ", int_values[i]);

        free(int_values);
    }

    return 0;
}
