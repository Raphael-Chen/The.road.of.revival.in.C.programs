// An assertion is a predicate that the presented condition must be true at 
// the moment the assertion is encountered by the software. Most common are simple 
// assertions, which are validated at execution time. However, static assertions 
// are checked at compile time.


#include <stdio.h>
// Uncomment to disable `assert()` 
// #define NDEBUG 
#include <assert.h>


int main(void)
{
    int x = -1;

    assert(x >= 0);
    printf("x = %d\n", x);

    return 0;
}


// $ ./a.out
// a.out: simple_assertion.c:11: main: Assertion `x >= 0' failed.
// Aborted

