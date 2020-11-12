#include <stdio.h>

// 6.5.10 Bitwise AND operator
/********
Constraints
    Each of the operands shall have integer type.

Semantics
    The usual arithmetic conversions are performed on the operands.
    The result of the binary & operator is the bitwise AND of the operands (that is, each bit in
    the result is set if and only if each of the corresponding bits in the converted operands is
    set).
**********/

int main(void)
{
    printf("0 & 0 is %d\n", 0 & 0);
    printf("0 & 1 is %d\n", 0 & 1);
    printf("1 & 1 is %d\n", 1 & 1);
    printf("1 & 2 is %d\n", 1 & 2);
    printf("15 & 127 is %d\n", 15 & 127);

    return 0;
}
