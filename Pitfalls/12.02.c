#include <stdlib.h>
#include <stdio.h>

/*******
NAME
       getline, getdelim - delimited string input

SYNOPSIS
       #include <stdio.h>

       ssize_t getline(char **lineptr, size_t *n, FILE *stream);
       ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

CONFORMING TO
       Both getline() and getdelim() were originally GNU extensions.  
       They were standardized in POSIX.1-2008, not ISO.

*******/

// The following infinite loop is an example of a leak that will eventually exhaust 
// available memory leak by calling getline(), a function that implicitly allocates 
// new memory, without freeing that memory.

int main(void)
{
    char *line = NULL;
    size_t size = 0;

    // The loop below leaks memory as fast as it can
    for (;;)
    {
        getline(&line, &size, stdin); // New memory implicitly allocated 
        /* <do whatever> */

        free( line );                 // What happend if no free function?
        line = NULL;
    }

    return 0;
}
