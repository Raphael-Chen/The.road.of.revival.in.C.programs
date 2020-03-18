#include <stdio.h>
/*
 $ ./a.out 1 2 abc @#
 5 args is ./a.out
 5 args is 1
 5 args is 2
 5 args is abc
 5 args is @#
*/

//int main(int argc, char **argv)
int main(int argc, char *argv[])
{
    while (*argv)
        printf(" %d args is %s\n", argc, *argv++);

    return 0;
}
