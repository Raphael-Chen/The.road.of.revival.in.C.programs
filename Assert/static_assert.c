// https://stackoverflow.com/questions/3385515/static-assert-in-cggggrd
// https://zh.cppreference.com/w/c/language/_Static_assert

#include <assert.h>

int main(void)
{
    // 测试数学是否正常工作
    static_assert(2 + 2 == 4, "Whoa dude!");    // or _Static_assert(...
 
    // 这会在编译时产生错误。
    static_assert(sizeof(int) < sizeof(char),
                 "this program requires that int is less than char");

    return 0;                 
}

/***********************
 * 6.7.10 Static assertions
 * 
 * Syntax
 * static_assert-declaration:
 * _Static_assert ( constant-expression , string-literal ) ;
 * 
 * Constraints
 * The constant expression shall compare unequal to 0.
 * 
 * Semantics
 * The constant expression shall be an integer constant expression. If the value of the
 * constant expression compares unequal to 0, the declaration has no effect. Otherwise, the
 * constraint is violated and the implementation shall produce a diagnostic message that
 * includes the text of the string literal, except that characters not in the basic source
 * character set are not required to appear in the message.
 *************************/
