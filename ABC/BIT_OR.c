#include <stdio.h>

/********
 * 
 * 6.5.12 Bitwise inclusive OR operator 
 * 
Constraints
    Each of the operands shall have integer type.

Semantics
    The usual arithmetic conversions are performed on the operands.
    The result of the | operator is the bitwise inclusive OR of the operands (that is, each bit in
    the result is set if and only if at least one of the corresponding bits in the converted
    operands is set).

**********/

int main(void)
{
    printf("0 | 0 is %d\n", 0 | 0);
    printf("0 | 1 is %d\n", 0 | 1);
    printf("1 | 1 is %d\n", 1 | 1);
    printf("1 | 2 is %d\n", 1 | 2);
    printf("128 | 127 is %d\n", 128 | 127);

    return 0;
}
