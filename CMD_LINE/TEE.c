#include <stdio.h>

int main(void)
{
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), stdin))
    {
        fputs(buffer, stdout);
        fputs(buffer, stderr);
    }
}
