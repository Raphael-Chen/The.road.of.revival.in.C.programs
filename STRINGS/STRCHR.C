#include <stdio.h>
#include <string.h>

int main(void)
{
    char title[64] = "1001 C/C++ Tips!";
    char *ptr = NULL ;

    //strchr, strrchr, strchrnul- locate character in string
    if ( ( ptr = strchr(title, 'C') ) != NULL )  
        printf("First occurrence of C is at offset %ld\n",
               ptr - title);
    else
        printf("Character not found\n");
}
