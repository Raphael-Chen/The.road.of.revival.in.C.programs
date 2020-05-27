#include <stdio.h>
#include <stdlib.h>

/********
 *  WARNING: DANGEROUS!
 *  DO NOT run this program in your real matchine!
 *  
 *****/


int main( void )
{
    int* ptr = NULL;

    while ( 1 )
    {
        /* If you keep applying and don’t release the memory, you ’ll be soon in trouble */
        ptr = ( int* )malloc( 1024 );
    }
    

    return 0;
}