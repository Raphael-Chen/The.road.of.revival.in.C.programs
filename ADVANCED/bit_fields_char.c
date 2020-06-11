#include <stdio.h>

struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte
    unsigned char b2 : 6;
    unsigned char b3 : 2;
};

struct myself{
    unsigned char : 1;
    unsigned char : 2;
    unsigned char : 5;

};


int main( void )
{
    // std::cout << sizeof(S) << '\n'; // usually prints 2
    
    printf( "sizeof S: %ld Byte.\n", sizeof( struct S ) );
    
    printf( "sizeof myself: %ld Byte.\n", sizeof( struct myself ) );

    return 0; 
}

// https://en.cppreference.com/w/cpp/language/bit_field
// http://www.yuan-ji.me/C-C-%E4%BD%8D%E5%9F%9F-Bit-fields-%E5%AD%A6%E4%B9%A0%E5%BF%83%E5%BE%97/


/*
    Bit field 的定义
    “ 位域 “ 或 “ 位段 “(Bit field)为一种数据结构，可以把数据以位的形式紧凑的储存，
    并允许程序员对此结构的位进行操作。这种数据结构的一个好处是它可以使数据单元节省储存空间，
    当程序需要成千上万个数据单元时，这种方法就显得尤为重要。第二个好处是位段可以很方便的访问
    一个整数值的部分内容从而可以简化程序源代码。而这种数据结构的缺点在于，位段实现依赖于具体
    的机器和系统，在不同的平台可能有不同的结果，这导致了位段在本质上是不可移植的。

*/





