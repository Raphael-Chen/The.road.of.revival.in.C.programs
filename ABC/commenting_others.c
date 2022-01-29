// Commenting using the preprocessor
#include <stdio.h>

#if 0  // Starts the "comment", anything from here on is removed by preprocessor 
// A large amount of code with multi-line comments 
int foo()
{
    // lots of code 
    // ...
        // ... some comment describing the if statement ... 
        if (someTest)
    {
        // some more comments 
        return 1;
    }
    return 0;
}
#endif // #if 0 
// code from here on is "uncommented" (included in compiled executable) 
// ...

int main(void)
{
    // 24:5: warning: implicit declaration of function ‘foo’ [-Wimplicit-function-declaration]
    foo();

    return 0;
}