#include <stdio.h>
#include <time.h>

/***********
    7.27.3.2 The ctime function

    Synopsis
    #include <time.h>
    char *ctime(const time_t *timer);

    Description
    The ctime function converts the calendar time pointed to by timer to local time in the
    form of a string. It is equivalent to
    asctime(localtime(timer))

    Returns
    The ctime function returns the pointer returned by the asctime function with that
    broken-down time as argument.
***********/

int main(void)
{
    time_t current_time;

    time(&current_time);          // Get the time in seconds;

    printf("The current date and time: %s",
           ctime(&current_time));

    return 0;
}
