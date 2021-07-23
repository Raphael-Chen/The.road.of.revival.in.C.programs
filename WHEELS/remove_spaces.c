// 实现去除字符串首尾空格
// How to remove the spaces of string in head and tail.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Method 2: Without call any system function.
char* trim2(char *strIn, char *strOut)
{
    char *start, *end, *temp;          // 定义去除空格后字符串的头尾指针和遍历指针

    temp = strIn;

    while (*temp == ' ')
    {
        ++temp;
    }

    start = temp;                      // 求得头指针

    temp = strIn + strlen(strIn) - 1;  // 得到原字符串最后一个字符的指针(不是'\0')

    // printf("%c\n", *temp);

    while (*temp == ' ')
    {
        --temp;
    }

    end = temp;                         // 求得尾指针

    strIn = start;
    while (strIn <= end )
    {
        *strOut++ = *strIn++;
    }

    *strOut = '\0';

    return strOut;
}

// Method 1
char* trim(char *strIn, char *strOut)
{
    int i = 0,
        end;
    // i = 0;

    end = strlen(strIn) - 1;

    while (strIn[i] == ' ')
        ++i;

    while (strIn[end] == ' ')
        --end;
    strncpy(strOut, strIn + i, end - i + 1);

    strOut[end - i + 1] = '\0';

    return strOut;
}

int main(void)
{
    char *strIn      = "   ak kl  p  ";
    char strOut[100] = {'\0'};

    trim2(strIn, strOut);
    printf("*%s*\n", strOut);       // 做字符串收尾参照用

    return 0;
}