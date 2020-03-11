#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[64] = "Triggerhill's I'm so";
    strcat(name, " Happy");
    printf("Happy's full name is %s\n", name);

    return 0;
}
