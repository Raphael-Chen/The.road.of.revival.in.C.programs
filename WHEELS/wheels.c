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
