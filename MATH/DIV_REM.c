#include <stdio.h>
#include <stdlib.h>

/*
       #include <stdlib.h>

       div_t div(int numerator, int denominator);
       ldiv_t ldiv(long numerator, long denominator);
       lldiv_t lldiv(long long numerator, long long denominator);

       #include <inttypes.h>

       imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator);

        Description
        The div, ldiv, and lldiv, functions compute numer / denom and numer %
        denom in a single operation.

        Returns
        The div, ldiv, and lldiv functions return a structure of type div_t, ldiv_t, and
        lldiv_t, respectively, comprising both the quotient and the remainder. The structures
        shall contain (in either order) the members quot (the quotient) and rem (the remainder),
        each of which has the same type as the arguments numer and denom. If either part of
        the result cannot be represented, the behavior is undefined.

*/

int main(void)
{
    div_t result;

    result = div(11, 3);

    printf("11 divided by 3 is %d Remainder %d\n",
           result.quot, result.rem);

    return 0;
}
