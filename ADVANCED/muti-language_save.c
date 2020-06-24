#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <wchar.h>

//https://www.jianshu.com/p/d757f29d3acd

int main( void )
{

    wchar_t a = L'A'; //英文字符（基本拉丁字符）

    wchar_t b = L'9'; //英文数字（阿拉伯数字）

    wchar_t c = L'中'; //中文汉字

    wchar_t d = L'国'; //中文汉字

    wchar_t e = L'。'; //中文标点

    wchar_t f = L'ヅ'; //日文片假名

    wchar_t g = L'♥'; //特殊符号

    wchar_t h = L'༄'; //藏文

    //将本地环境设置为简体中文

    // setlocale(LC_ALL, "zh_CN");
    
    // printf( "setlocale is  %s\n", setlocale(LC_ALL, "") );   // env | grep LANG
    setlocale(LC_ALL, "zh_CN.UTF-8");


/*
    #include <locale.h>
    char *setlocale(int category, const char *locale);

        A null pointer for locale causes the setlocale function to return a pointer to the
    string associated with the category for the program’s current locale; the program’s
    locale is not changed.
*/

    //使用专门的 putwchar 输出宽字符

    putwchar(a);
    putwchar(b);
    putwchar(c);
    putwchar(d);

    putwchar(e);
    putwchar(f);
    putwchar(g);
    putwchar(h);

    putwchar(L'\n'); //只能使用宽字符

    //使用通用的 wprintf 输出宽字符

    wprintf( L"Wide chars: %lc %lc %lc %lc %lc %lc %lc %lc\n", //必须使用宽字符串
            a, b, c, d, e, f, g, h );

    return 0;
}
/*

*/									