// Precondition and Postcondition
// One use case for assertion is precondition and postcondition. This can be very useful to maintain
// invariant and design by contract. For a example a length is always zero or positive so this function
// must return a zero or positive value.


#include <stdio.h>
// Uncomment to disable `assert()` 
// #define NDEBUG 
#include <assert.h>
#define COUNT 3

int length2(int *a, int count)
{
    int i, result = 0;

    // Precondition: 
    // NULL is an invalid vector 
    assert(a != NULL);

    // Number of dimensions can not be negative.
    assert(count >= 0);

    // Calculation 
    for (i = 0; i < count; ++i)
    {
        result = result + (a[i] * a[i]);
    }

    // Postcondition: 
    // Resulting length can not be negative. 
    assert(result >= 0);

    return result;
}

int main(void)
{
    int a[COUNT] = {1, 2, 3};
    int *b       = NULL;
    int r;

    r = length2(a, COUNT);
    printf("r = %i\n", r);

    r = length2(b, COUNT);
    printf("r = %i\n", r);

    return 0;
}

// $ ./a.out
// r = 14
// a.out: pre_and_post.c:18: length2: Assertion `a != ((void *)0)' failed.
// Aborted
