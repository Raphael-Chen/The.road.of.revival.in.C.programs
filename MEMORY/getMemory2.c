#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 指针参数是如何传递内存的
void GetMemory2(char **p, int num)
{
    *p = (char *)malloc(sizeof(char) * num);
}

void Test2(void)
{
    char *str = NULL;
    GetMemory2(&str, 100); // 注意参数是 &str,而不是 str
    strcpy(str, "hello");
    // cout << str << endl;
    printf("str2 is: %s\n", str);
    free(str);
}

char *GetMemory3(int num)
{
    char *p = (char *)malloc(sizeof(char) * num);
    return p;
}

void Test3(void)
{
    char *str = NULL;
    str = GetMemory3(100);
    strcpy(str, "hello");
    
    printf("str3 is: %s\n", str);
    free(str);
}

int main(void)
{
    Test2();
    Test3();
    return 0;
}