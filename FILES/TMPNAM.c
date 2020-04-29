#include <stdio.h>
#include <string.h>
 
// warning: the use of `tmpnam' is dangerous, better use `mkstemp' 
int main(void)
{
    char* name1 = tmpnam(NULL);
    printf("temporary file name: %s\n", name1);
 
    char name2[L_tmpnam];
    if (tmpnam(name2))
        printf("temporary file name: %s\n", name2);
}


/*

    The tmpnam function generates a string that is a valid file name and that is not the same
    as the name of an existing file. The function is potentially capable of generating at 
    least TMP_MAX different strings, but any or all of them may already be in use by existing
    files and thus not be suitable return values.
*/