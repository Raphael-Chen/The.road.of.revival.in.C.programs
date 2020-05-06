#include <stdio.h>
#include <stddef.h>

int main(void)
{
    printf("Variables of type short use %ld bytes\n", sizeof(short));
    printf("Variables of type int use %ld bytes\n", sizeof(int));
    printf("Variables of type float use %ld bytes\n", sizeof(float));
    printf("Variables of type double use %ld bytes\n", sizeof(double));
    printf("Variables of type unsigned use %ld bytes\n", sizeof(unsigned));
    printf("Variables of type long use %ld bytes\n", sizeof(long));
    printf("Variables of type int pointer use %ld bytes\n", sizeof(int*));
    printf("Variables of type char pointer use %ld bytes\n", sizeof(char*));
    // printf("_Alignof (int) is %ld \n", _Alignof(int) );
}
