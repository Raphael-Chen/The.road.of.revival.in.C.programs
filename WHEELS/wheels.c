#include <stdio.h>


// 获取骰子的点数
unsigned char get_dice_number(void)
{
    srand(time(0));
    int dice = rand() % 6 + 1;
    return (unsigned char)dice;
}



int encrypt(int plainText, int key)
{
    return plainText ^ key;
}

int decrypt(int cipherText, int key)
{
    return cipherText ^ key;
}

// 十进制转换为二进制，有bug么?
long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, 
        quotient,
        i = 1, 
        step = 1;

    while (n != 0)
    {
        remainder = n % 2;
        quotient = n / 2;
        printf("Step %d: %d/2, 余数 = %d, 商 = %d\n", step++, n, remainder, quotient );
        n = quotient;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}



// 凯撒加密算法
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
