#include <stdio.h>

//提前声明函数原型合法 
int i_cube(int);
float f_cube(float);

int main(void)
{
    printf("The cube of 3 is %d\n", i_cube(3));
    printf("The cube of 3.7 is %f\n", f_cube(3.7));

    return 0;
}

int i_cube(int value)
{
    return (value * value * value);
}

float f_cube(float value)
{
    return (value * value * value);
}
