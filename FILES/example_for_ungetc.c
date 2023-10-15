#include <stdio.h>
#include <string.h>

// Replace the '+' with '!'
int main( void )  // gcc -std=c11 -Wall -Wextra example_for_ungetc.c
{
    FILE *fp;
    int  c;
    char buffer [256] = {'\0'};

    fp = fopen("test_ungetc.txt", "r");
    if( fp == NULL ) 
    {
        perror("Open error");
        return(-1);
    }

    // while(!feof(fp)) 
    // The feof function returns nonzero if and only if 
    // the end-of-file indicator is set for stream.
    while ( 0 == feof(fp) ) 
    {
        c = getc (fp);
        /* 把 ! 替换为 + */
        if( c == '!' ) 
        {
           ungetc ('+', fp);
        }
        else 
        {
           ungetc(c, fp);
        }
        fgets(buffer, sizeof( buffer ), fp);
        fputs(buffer, stdout);
        memset( buffer, '\0', sizeof(buffer) ); // Clear all the charactors in buffer.
    }

    return(0);
}
