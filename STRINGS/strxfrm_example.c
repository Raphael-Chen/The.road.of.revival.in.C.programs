#include <stdio.h>
#include <string.h>
#include <locale.h>
// https://stackmirror.com/questions/51943128

int main(void)
{
    char str1[512] = { 0x68, 0x6c, 0x61, 0x76, 0x61, 0x00 }; //"hlava";
    char str2[512] = { 0xc4, 0x8d, 0xc3, 0xad, 0xc5, 0xa1, 0x6e, 0xc3, 0xad, 0x6b, 0x00 }; //"číšník";
    char xfm1[512] = { '\0', };
    char xfm2[512] = { '\0', };
    char * result = NULL;
    size_t lxfm1 = 0;
    size_t lxfm2 = 0;

    result = setlocale(LC_ALL, "en_US.UTF-8");
    lxfm1 = strxfrm(xfm1, str1, sizeof xfm1);
    lxfm2 = strxfrm(xfm2, str2, sizeof xfm2);

    printf("<en-US>\n");
    printf("setlocale = \"%s\"\n", (result == NULL) ? "NULL" : result);
    printf("str1: \"%s\" --> \"%s\"\n", str1, xfm1);
    printf("str2: \"%s\" --> \"%s\"\n", str2, xfm2);
    printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
    printf("strcmp(xfm1, xfm2) = %d\n", strcmp(xfm1, xfm2));
    printf("strcoll(xfm1, xfm2) = %d\n", strcoll(str1, str2));
    printf("returns of strxfrm: %zu / %zu\n\n", lxfm1, lxfm2);

    result = setlocale(LC_ALL, "cs_CZ.UTF-8");
    if ( NULL == result )
    {
        perror("Set fail");
    }
    else
    {
        lxfm1 = strxfrm(xfm1, str1, sizeof xfm1);
        lxfm2 = strxfrm(xfm2, str2, sizeof xfm2);
        printf("<cs-CZ>\n");
        printf("setlocale = \"%s\"\n", result);
        printf("str1: \"%s\" --> \"%s\"\n", str1, xfm1);
        printf("str2: \"%s\" --> \"%s\"\n", str2, xfm2);
        printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
        printf("strcmp(xfm1, xfm2) = %d\n", strcmp(xfm1, xfm2));
        printf("strcoll(xfm1, xfm2) = %d\n", strcoll(str1, str2));
        printf("returns of strxfrm: %zu / %zu\n", lxfm1, lxfm2);
    }


    return 0;
}

/******
int main(void)
{
    setlocale(LC_COLLATE, "cs_CZ.iso88592");
 
    const char *in1 = "hrnec";
    char out1[1+strxfrm(NULL, in1, 0)];
    strxfrm(out1, in1, sizeof out1);
 
    const char *in2 = "chrt";
    char out2[1+strxfrm(NULL, in2, 0)];
    strxfrm(out2, in2, sizeof out2);
 
    printf("In the Czech locale: ");
    if(strcmp(out1, out2) < 0)
         printf("%s before %s\n",in1, in2);
    else
         printf("%s before %s\n",in2, in1);
 
    printf("In lexicographical comparison: ");
    if(strcmp(in1, in2)<0)
         printf("%s before %s\n",in1, in2);
    else
         printf("%s before %s\n",in2, in1);
 
}******/

// https://en.cppreference.com/w/c/string/byte/strxfrm