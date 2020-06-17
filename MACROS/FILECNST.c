#include <stdio.h>

int main( void )
{
    printf("The file %s is under Beta testing\n", __FILE__);

/* 
    FOPEN_MAX which expands to an integer constant expression that 
    is the minimum number of files that the implementation 
    guarantees can be open simultaneously;
*/
    printf( "FOPEN_MAX is %d, FILENAME_MAX is %d\n ", FOPEN_MAX, FILENAME_MAX );
    return 0;
}

/*
    FILENAME_MAX which expands to an integer constant expression that is
     the size needed for an array of char large enough to hold the longest 
     file name string that the implementation
*/