#include <stdio.h>
#include <string.h>

// https://zhuanlan.zhihu.com/p/94173919


struct POINT
{
    /* data */
    int key;
    int mod;
};

void caesar_encrpty( char* output, char* str, size_t len, struct POINT* point )
{
    size_t i;
    
    for ( i = 0; i < len; i++)
    {
        output[i] = ( str[i] + ( point->key ) ) % ( point->mod );
    }
}

char* caesar_decrpty( char* decode, char* str, size_t len, struct POINT* point )
{
    char temp;
    size_t i;

    for ( i = 0; i < len; i++ )
    {
        temp = ( str[i] - ( point->key ) ) % ( point->mod );
        decode[i] = temp > 0 ? temp : temp + ( point->mod );
    }
    // printf("plain = %s\n", decode );

    return decode;
}


int main( void )
{
    char a[20] = "Hello fancy, 789";
    // char temp;
    // size_t i;

    // const int key = 500;  // 密钥
    // const int mod = 256;
    
    struct POINT P;
    P.key = 500;
    P.mod = 256;

    printf("plain = %s\n", a);

    // 加密
    char b[20];
    // for ( i = 0; i < strlen(a); i++)
    // {
    //     b[i] = (a[i] + key) % mod;
    // }

    caesar_encrpty( b, a, strlen(a), &P );
    printf("cipher = %s\n", b);

    // 解密
    char decode[20];
    caesar_decrpty( decode, b, strlen(b), &P );
    // for ( i = 0; i < strlen(b); i++ )
    // {
    //     temp = (b[i] - key) % mod;
    //     decode[i] = temp > 0 ? temp : temp + mod;
    // }
    printf("plain = %s\n", decode);
    return 0;
}
