#include <stdio.h>
#include <time.h>

// Another example is what_day.c
int main(void)
{
    time_t seconds;

    struct tm time_fields;

    time_fields.tm_mday = 4;
    time_fields.tm_mon = 7;
    time_fields.tm_year = 94;
    time_fields.tm_hour = 0;
    time_fields.tm_min = 0;
    time_fields.tm_sec = 0;

    seconds = mktime(&time_fields);

    printf("The number of seconds between 7-4-94 and 1-1-70 is %ld\n",
           seconds);
           
    return 0;
}

/****************
 *   7.27.2.3 The mktime function
 *   Synopsis
 *   #include <time.h>
 *   time_t mktime(struct tm *timeptr);
 *
 *   Description
 *   The mktime function converts the broken-down time, expressed as local time, in the
 *   structure pointed to by timeptr into a calendar time value with the same encoding as
 *   that of the values returned by the time function. The original values of the tm_wday
 *   and tm_yday components of the structure are ignored, and the original values of the
 *   other components are not restricted to the ranges indicated above. 320) On successful
 *   completion, the values of the tm_wday and tm_yday components of the structure are
 *   set appropriately, and the other components are set to represent the specified calendar
 *   time, but with their values forced to the ranges indicated above; the final value of
 *   tm_mday is not set until tm_mon and tm_year are determined.
 *   
 *   Returns
 *   The mktime function returns the specified calendar time encoded as a value of type
 *   time_t. If the calendar time cannot be represented, the function returns the value
 *   (time_t)(-1).
 *****************/

