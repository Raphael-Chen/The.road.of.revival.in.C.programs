#include <stdio.h>

// 比较运算符——等号与不等号的展示
int main(void)
{
    int age = 21;
    int height = 73;

    if (age == 21)
        printf("User's age is 21\n");

    if (age != 21)
        printf("User's age is not 21\n");

    if (height == 73)
        printf("User's height is 73\n");

    if (height != 73)
        printf("User's height is not 73\n");

    return 0;
}

/*********************************************
 * 
 * 6.5.9 Equality operators
 * Syntax
 * 
 *     equality-expression:
 *         relational-expression
 *         equality-expression == relational-expression
 *         equality-expression != relational-expression
 * 
 * Constraints
 * One of the following shall hold:
 * — both operands have arithmetic type;
 * — both operands are pointers to qualified or unqualified versions of compatible types;
 * — one operand is a pointer to an object type and the other is a pointer to a qualified 
 * or unqualified version of void; or
 * — one operand is a pointer and the other is a null pointer constant.
 * 
 * Semantics
 * 3 The == (equal to) and != (not equal to) operators are analogous to the relational 
 * operators except for their lower precedence. 108) Each of the operators yields 1 if 
 * the specified relation is true and 0 if it is false. The result has type int. For 
 * any pair of operands, exactly one of the relations is true.
 * 
 * 4 If both of the operands have arithmetic type, the usual arithmetic conversions are 
 * performed. Values of complex types are equal if and only if both their real parts are equal
 * and also their imaginary parts are equal. Any two values of arithmetic types from 
 * different type domains are equal if and only if the results of their conversions to 
 * the (complex) result type determined by the usual arithmetic conversions are equal.
 * 
 * 5 Otherwise, at least one operand is a pointer. If one operand is a pointer and the other
 *  is a null pointer constant, the null pointer constant is converted to the type of the 
 *  pointer. If one operand is a pointer to an object type and the other is a pointer to a 
 *  qualified or unqualified version of void, the former is converted to the type of the latter. 
 * 
 * 6 Two pointers compare equal if and only if both are null pointers, both are pointers 
 * to the same object (including a pointer to an object and a subobject at its beginning) 
 * or function, both are pointers to one past the last element of the same array object, 
 * or one is a pointer to one past the end of one array object and the other is a pointer 
 * to the start of a different array object that happens to immediately follow the first 
 * array object in the address space. 109)
 * 
 * 7 For the purposes of these operators, a pointer to an object that is not an element of 
 * an array behaves the same as a pointer to the first element of an array of length one 
 * with the type of the object as its element type.
 * 
 * ******************/