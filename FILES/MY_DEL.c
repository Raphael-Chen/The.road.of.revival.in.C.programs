#include <stdio.h>


/*
 *   The remove function causes the file whose name is the string pointed to by filename
 *   to be no longer accessible by that name. A subsequent attempt to open that file using that
 *   name will fail, unless it is created anew. If the file is open, the behavior of the remove
 *   function is implementation-defined.
 */
int main(int argc, char *argv[])
{
    int ret;
    while (*++argv)
        ret = remove(*argv);
        // The remove function returns zero if the operation succeeds, nonzero if it fails.
        if ( 0 != ret )       
            printf("Error removing %s\n", *argv);

    return 0;            
}
