#include <stdio.h>

int main(void)
{
    int result;

    // The printf function returns the number of characters transmitted, or a negative value if
    // an output or encoding error occurred.
    result = printf("Jamsa's 1001 C & C++ Tips!\n");
    printf("The result output %d.\n", result );

    //EOF which expands to an integer constant expression, with type int and a negative value, 
    //that is returned by several functions to indicate end-of-file, that is, no more input 
    //from a stream;
    if (result == EOF)
        fprintf(stderr, "Error within printf\n");
}
