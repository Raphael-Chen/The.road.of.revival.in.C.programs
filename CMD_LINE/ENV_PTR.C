#include <stdio.h>


//What is env?
int main(int argc, char **argv, char **env)
{
    while (*env)
        printf("%s\n", *env++);
}
