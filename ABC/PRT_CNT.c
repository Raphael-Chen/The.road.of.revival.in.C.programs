#include <stdio.h>

int main(void)
{
    int first_count;
    int second_count;

    // n The argument shall be a pointer to signed integer into which is written the
    // number of characters written to the output stream so far by this call to
    // fprintf. No argument is converted, but one is consumed. If the conversion
    // specification includes any flags, a field width, or a precision, the behavior is
    // undefined.

    printf("Jamsa%n's 1001 C & C++ Tips%n\n", &first_count,
           &second_count);

    printf("First count %d Second count %d\n", first_count,
           second_count);
}
