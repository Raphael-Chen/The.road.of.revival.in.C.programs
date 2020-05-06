//在某种条件下，goto语句可以替代for循环，但不宜滥用，容易破坏程序的逻辑
#include <stdio.h>

int main(void)
{
    int count = 1;

label:
    printf("%d ", count++);

    if (count <= 100)
        goto label;
}
