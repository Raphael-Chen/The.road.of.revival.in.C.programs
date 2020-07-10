#include <stdio.h>
#include <string.h>

// Difference between struct and union
// This illustrates that union members shares memory and that struct members does not share memory.

union My_Union {
    int variable_1;
    int variable_2;
};

struct My_Struct
{
    int variable_1;
    int variable_2;
};

int main(void)
{
    union My_Union u;
    struct My_Struct s;

    u.variable_1 = 1;
    u.variable_2 = 2;

    s.variable_1 = 1;
    s.variable_2 = 2;

    printf("u.variable_1: %i\n", u.variable_1);
    printf("u.variable_2: %i\n", u.variable_2);

    printf("s.variable_1: %i\n", s.variable_1);
    printf("s.variable_2: %i\n", s.variable_2);

    printf("sizeof (union My_Union): %lu\n", sizeof(union My_Union));
    printf("sizeof (struct My_Struct): %lu\n", sizeof(struct My_Struct));

    return 0;
}

