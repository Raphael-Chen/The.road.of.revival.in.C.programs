/*
       #include <string.h>

       int strcmp(const char *s1, const char *s2);
       int strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
       The  strcmp()  function  compares  the  two strings s1 and s2.  It returns an integer less
       than, equal to, or greater than zero if s1 is found, respectively, to  be  less  than,  to
       match, or be greater than s2.

       The  strncmp() function is similar, except it compares the only first (at most) n bytes of
       s1 and s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer less than,  equal  to,  or  greater
       than zero if s1 (or the first n bytes thereof) is found, respectively, to be less than, to
       match, or be greater than s2.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Comparing Abc with Abc %d\n",
            strcmp("Abc", "Abc"));
        //    stricmp("Abc", "Abc"));
    printf("Comparing abc with Abc %d\n",
            strcmp("abc", "Abc"));
        //    stricmp("abc", "Abc"));
    printf("Comparing 3 letters abcd with ABC %d\n",
            strncmp("abcd", "ABC", 3));
        //    strncmpi("abcd", "ABC", 3));
    printf("Comparing 5 letters abc with Abcd %d\n",
           strncmp("abc", "Abcd", 5));

    return 0;
}
