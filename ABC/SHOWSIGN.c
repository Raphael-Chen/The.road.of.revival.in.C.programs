#include <stdio.h>

int main(void)
{
    int neg_int = -5;
    int pos_int = 5;

    float neg_flt = -100.23;
    float pos_flt = 100.23;

    printf("The integer values are %+d and %+d\n",
           neg_int, pos_int);

    printf("The floating point values are %+f %+f\n",
           neg_flt, pos_flt);

    printf("The integer values are %+d and %+d is %d\n", neg_int, pos_int, neg_int+pos_int );

    printf("The floating point values are %+f %+f is %+f\n", neg_flt, pos_flt, neg_flt+pos_flt  );
}
