#include <stdio.h>
 
struct
{
  unsigned int age : 3;
} Age;
 
int main( void )
{
   Age.age = 4;
   printf( "Sizeof( Age ) : %ld\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 8; // 二进制表示为 1000 有四位，超出
   printf( "Age.age : %d\n", Age.age );
 
   return 0;
}


