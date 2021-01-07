#include <stdio.h>
#include <time.h>

/*******************
    7.27.3.4 The localtime function
    Synopsis
    #include <time.h>
    struct tm *localtime(const time_t *timer);

    Description
    The localtime function converts the calendar time pointed to by timer into a
    broken-down time, expressed as local time.

    Returns
    The localtime function returns a pointer to the broken-down time, or a null pointer if
    the specified time cannot be converted to local time.
***********/

int main(void)
{
    struct tm *current_date;
    time_t seconds;

    time(&seconds);

    current_date = localtime(&seconds);

    printf("Current date: %d-%d-%d\n", current_date->tm_mon + 1,
           current_date->tm_mday, current_date->tm_year + 1900);
    printf("Current time: %02d:%02d\n", current_date->tm_hour,
           current_date->tm_min);

    return 0;           
}
