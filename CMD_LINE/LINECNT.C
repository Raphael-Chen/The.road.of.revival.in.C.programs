#include <stdio.h>

int main(void)
{
    char line[256]; // Line of redirected input

    long line_count = 0;

    while (fgets(line, sizeof(line), stdin))  //使用方法不对
        line_count++;

    printf("The number of redirected lines: %ld\n", line_count);
}
