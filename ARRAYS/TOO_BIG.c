int main(void)
{
    char string[66000L]; // 66,000 bytes

    // TOO_BIG.c:5:16: warning: integer constant is too large for its type [enabled by default]
    // TOO_BIG.c:5:9: error: size of array ‘values’ is negative
    int values[33000330003300033000L]; // 33,000 * 2 = 66,000 bytes

    float numbers[17000]; // 17,000 * 4 = 68,000 bytes

    return 0;
}
