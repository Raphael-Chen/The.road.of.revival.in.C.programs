#include <stdio.h>

// 在某种条件下，goto语句可以替代for,while循环，但不宜滥用，容易破坏程序的逻辑
// 在异常处理中经常被用到
int main(void)
{
    int count = 1;

label:
    printf("%d ", count++);

    if (count <= 100)
        goto label;        // Back to the label: and go on 

    return 0;
}
