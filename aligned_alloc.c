#include <stdio.h>
#include <stdlib.h>
 
/*
    Return value
    On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().

    On failure, returns a null pointer.
*/

int main(void)
{
    int *p1 = malloc(10*sizeof *p1);
    printf("default-aligned addr:   %p\n", (void*)p1);
    free(p1);
 
    int *p2 = aligned_alloc(1024, 1024*sizeof *p2);
    printf("1024-byte aligned addr: %p\n", (void*)p2);
    free(p2);
    
    return 0;
}


