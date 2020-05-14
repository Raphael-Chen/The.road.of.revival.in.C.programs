#include <stdio.h>
// #include <conio.h>
#include <unistd.h> //For unix system
#include <string.h>

int main(void)
{
    char *password;

    password = getpass("Enter Password:");

    if (strcmp(password, "1001"))
        printf("Password Incorrect\n");
    else
        printf("Password OK\n");
}
