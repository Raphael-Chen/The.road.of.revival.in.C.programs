#include <stdio.h>

//__STDC_VERSION__

int main( void )
{
#ifdef __STDC__
    printf("ANSI C compliance\n");
#else
    printf("Not in ANSI C mode\n");
#endif
}
