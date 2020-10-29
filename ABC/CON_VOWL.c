#include <stdio.h>

// 26个英文字母中，元音字母和非元音字母的统计
int main(void)
{
    char letter;

    int vowel_count = 0;
    int consonant_count = 0;

    for (letter = 'A'; letter <= 'Z'; letter++)
        switch (letter)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vowel_count++;
            break;
        default:
            consonant_count++;
        };

    printf("The number of vowels is %d\n", vowel_count);
    printf("The number of not vowels is %d\n", consonant_count);

    return 0;
}
