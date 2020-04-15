#include <stdio.h>
#include <stdarg.h>

// 参数个数不确定
double add_values(char *str, ...)
{
    va_list marker;

    double result = 0.0;

    va_start(marker, str);           /* mark first additional argument */

    while ( *str != NULL )            /* examine each character in the string */
    {
        if (*str == '%')             /* if not a %_ format specifier, skip it */
        {
            switch (*(++str))
            {
                case 'd':
                    result += va_arg(marker, int);
                    break;
                case 'f':
                    result += va_arg(marker, double);
                    break;
            }
        }
        str++;
    }

    va_end(marker);
    return (result);
}

int main(void)
{
    // double result;

    printf("Result %f\n", add_values("%f", 3.3));
    printf("Result %f\n", add_values("%f %f", 1.1, 2.2));
    printf("Result %f\n", add_values("%f %d %f", 1.1, 1, 2.2));
    printf("Result %f\n", add_values("%f %d %f %d", 1.1, 1, 2.2, 3));

    return 0;
}
