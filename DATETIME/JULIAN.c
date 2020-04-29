#include <stdio.h>
#include <time.h>

int main(void)
{
    //time_t seconds;

    struct tm time_fields;

    time_fields.tm_mday = 4;
    time_fields.tm_mon = 7;
    time_fields.tm_year = 94;

    if (mktime(&time_fields) == -1)
        printf("Error converting fields\n");
    else
        printf("Julian date for July 4, 1994 is %d\n",
               time_fields.tm_yday);   //tm_yday   The number of days since January 1, in the range 0 to 365.
}
