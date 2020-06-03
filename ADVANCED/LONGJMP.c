#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

/*
    #include <setjmp.h>
    int setjmp(jmp_buf env);

    Description
    The setjmp macro saves its calling environment in its jmp_buf argument for later use
    by the longjmp function.

    Returns
    If the return is from a direct invocation, the setjmp macro returns the value zero. If the
    return is from a call to the longjmp function, the setjmp macro returns a nonzero
    value.

    Environmental limits
    An invocation of the setjmp macro shall appear only in one of the following contexts:
    — the entire controlling expression of a selection or iteration statement;
    — one operand of a relational or equality operator with the other operand an integer
    constant expression, with the resulting expression being the entire controlling
    expression of a selection or iteration statement;
    — the operand of a unary ! operator with the resulting expression being the entire
    controlling expression of a selection or iteration statement; or
    — the entire expression of an expression statement (possibly cast to void).
*/

jmp_buf location;               // Global variable

void function(void)
{
    printf("About to longjmp\n");
    longjmp(location, 1);        // Return 1
}

int main( void )
{

    if (setjmp(location) != 0) // Save the current location
    {
        printf("Returning from longjmp\n");
        exit(1);
    }

    function();

    return 0;
}
