#include <stdio.h>

// #define __cplusplus  //CHK_CPP.C:3:0: warning: "__cplusplus" redefined [enabled by default]
/*
 *
 *   The implementation shall not predefine the macro _ _cplusplus, nor shall it define it
 *   in any standard header. P175
 */

int main( void )
{
#ifdef __cplusplus  //
    printf("Using C++\n");
#else
    printf("Using C\n");
#endif
}
