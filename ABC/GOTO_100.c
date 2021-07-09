#include <stdio.h>

/*************************
 * 6.8.6.1 The goto statement
 * 
 * Constraints
 *   The identifier in a goto statement shall name a label located somewhere in the enclosing
 * function. A goto statement shall not jump from outside the scope of an identifier having
 * a variably modified type to inside the scope of that identifier.
 * 
 * Semantics
 *   A goto statement causes an unconditional jump to the statement prefixed by the named
 * label in the enclosing function.
 * 
 ********************/

// 在某种条件下，goto语句可以替代for,while循环，但不宜滥用，容易破坏程序的逻辑
// 在异常处理中经常被用到
int main(void)
{
    int count = 1;

label:
    printf("%d ", count++);

    if (count <= 100)
        goto label;        // Back to the "label:" and go on 

    return 0;
}
