#include <stdio.h>
#include <setjmp.h>

/*
    setjmp属于C函数库，作用是分别承担非局部标号和goto作用。
    与刺激的abort()和exit()相比,goto语句看起来是处理异常的更可行方案。
    不幸的是，goto是本地的：它只能跳到所在函数内部的标号上，而不能将控制权转移到所在
    程序的任意地点（当然，除非你的所有代码都在main体中）。
    
    在 C 语言中虽然没有类似的异常处理机制，但是我们可以使用 setjmp 和 longjmp 来模拟
    实现该功能，这也是这两个函数的一个重要的应用

    https://www.cnblogs.com/hazir/p/c_setjmp_longjmp.html

*/

static jmp_buf buf;

void second(void)
{
    printf("second\n"); // 打印
    longjmp(buf, 1);    // 跳回setjmp的调用处 - 使得setjmp返回值为1
}

void first(void)
{
    second();
    printf("first\n"); // 不可能执行到此行
}

int main( void )
{
    if ( setjmp(buf) == 0 )
    {
        first();            // 进入此行前，setjmp返回0
    }
    else                    // 当longjmp跳转回，setjmp返回1，因此进入此行
    {           
        printf("main\n");   // 打印
    }

    return 0;
}

/*
    #include <setjmp.h>
    _Noreturn void longjmp(jmp_buf env, int val);

    Description
    2 The longjmp function restores the environment saved by the most recent invocation of
    the setjmp macro in the same invocation of the program with the corresponding
    jmp_buf argument. If there has been no such invocation, or if the invocation was from
    another thread of execution, or if the function containing the invocation of the setjmp
    macro has terminated execution 248) in the interim, or if the invocation of the setjmp
    macro was within the scope of an identifier with variably modified type and execution has
    left that scope in the interim, the behavior is undefined.
    3 All accessible objects have values, and all other components of the abstract machine )
    have state, as of the time the longjmp function was called, except that the values of
    objects of automatic storage duration that are local to the function containing the
    invocation of the corresponding setjmp macro that do not have volatile-qualified type
    and have been changed between the setjmp invocation and longjmp call are indeterminate.

    Returns
    4 After longjmp is completed, thread execution continues as if the corresponding
    invocation of the setjmp macro had just returned the value specified by val. The
    longjmp function cannot cause the setjmp macro to return the value 0; if val is 0,
    the setjmp macro returns the value 1.

    EXAMPLE The longjmp function that returns control back to the point of the setjmp invocation
    might cause memory associated with a variable length array object to be squandered.

*/