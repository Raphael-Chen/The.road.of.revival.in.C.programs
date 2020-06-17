#include <stdio.h>

// 10.1.6 不完整声明( imcomplete declaration )
struct B;   // 如不提前声明，则无法编译

struct A {
    struct B * partner; /* other declarations */
};

struct B {
    struct A * partner; /* other declarations */
};


// 10.1.4 结构成员的间接访问
struct COMPLEX {
    int f;
};

void func( struct COMPLEX * cp )
{
    printf( "%d\n", (*cp).f );
    printf( "%d\n", cp -> f );
}

// 10.1.5 结构的自引用
struct SELF_REF1 {
    int a ;
    char c;
    // struct SELF_REF1 b;  // error: field ‘b’ has incomplete type
};

struct SELF_REF2 {
    int a ;
    char c;
    struct SELF_REF2* b;  // 指向自身结构的指针，编译时即可确定结构大小，因此合法
};

int main( void )
{
    struct COMPLEX simple;
    func( &simple );

    return 0;
}

