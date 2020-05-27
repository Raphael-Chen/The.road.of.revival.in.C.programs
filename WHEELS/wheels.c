//

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


void caesar_encrpty( char* str, size_t len, int* mod )
{
    int i;
    for ( i = 0; i < len; i++ )
    {
        /* code */
        str[i] = (str[i] + key) % *mod;
    }
   
}