#include <string.h>
#include <stdio.h>

int main( void )
{
    static char str[] = "?a???b,,,#c";
    char *t;

    t = strtok(str, "?");      //t points to the token "a"
    printf( "\"?\" is %s\n", t );

    t = strtok(NULL, ",");     //t points to the token "??b"
    printf( "\"NULL | ,\" is %s\n", t );

    t = strtok(NULL, "#,");    //t points to the token "c"
    printf( "\"NULL | #\" is %s\n", t );

    t = strtok(NULL, "?");     //t is a null pointer
    printf( "\"NULL | ?\" is %s\n", t );

    return 0;
}


/*******************************************
  7.24.5.8 The strtok function
  Synopsis
  #include <string.h>
  char *strtok(char * restrict s1, const char * restrict s2);  

  Description
  A sequence of calls to the strtok function breaks the string pointed to by 
  s1 into a sequence of tokens, each of which is delimited by a character from 
  the string pointed to by s2. The first call in the sequence has a non-null 
  first argument; subsequent calls in the sequence have a null first argument. 
  The separator string pointed to by s2 may be different from call to call.  

  Returns
  The strtok function returns a pointer to the first character of a token, 
  or a null pointer if there is no token.
********************************************/