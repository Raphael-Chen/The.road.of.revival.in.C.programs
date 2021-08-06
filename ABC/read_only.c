#include <stdio.h>

// Usage of const keyword

// const int func(void);
// {
//     const int a = 0;
//     return a;
// };

int main( void )
{
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}

// 请注意，把常量定义为大写字母形式，是一个很好的编程习惯。
// https://www.runoob.com/cprogramming/c-constants.html