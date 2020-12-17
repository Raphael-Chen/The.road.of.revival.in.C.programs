// EXAMPLE What day of the week is July 4, 2001?

#include <stdio.h>
#include <time.h>

int main( void )
{
    static const char *const wday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "-unknown-"};

    struct tm time_str;
    /* ... */
    time_str.tm_year = 2001 - 1900;
    time_str.tm_mon = 7 - 1;
    time_str.tm_mday = 4;
    time_str.tm_hour = 0;
    time_str.tm_min = 0;
    time_str.tm_sec = 1;
    time_str.tm_isdst = -1;

    if ( mktime(&time_str) == (time_t)(-1) )
        time_str.tm_wday = 7;

    printf("%d-%s\n", time_str.tm_wday, wday[time_str.tm_wday]);

    return 0;
}