#include <stdio.h>

int main( void )
{
    printf("File %s: Successfully reached line %d\n",
           __FILE__, __LINE__);

    // Other statements here

#line 100 "FILENAME.C"  //? Change the line and file name with Macro define

    printf("File %s: Successfully reached line %d\n",
           __FILE__, __LINE__);
}
