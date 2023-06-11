#include <stdio.h>
#include <time.h>
#include "comm_file.h"

void convert_to_date( time_t* t )
{
    printf("%ld convert to date and time is : %s", *t, ctime(t));
}

// 将未来某天的时间戳转化为time_t
// Someday in future convert to seconds (time_t)
int main(void)
{
    time_t seconds;
    struct tm time_fields;  
    // +catch ex

    time_fields.tm_year = 2023 - BASE_YEAR;
    time_fields.tm_mon  = 6    - BASE_MONTH;
    time_fields.tm_mday = 19;

    // time_fields.tm_hour = 8;
    time_fields.tm_hour = 0;
    time_fields.tm_min  = 0;
    time_fields.tm_sec  = 0;

    seconds = mktime(&time_fields);

    printf("The number of seconds is %ld\n", seconds);

    convert_to_date( &seconds );

    return 0;
}

//atoi atol atoll
// int main(void)
// {
//     time_t passed_time;

//     passed_time = 1624057200;
                  

//     // time(&current_time);          // Get the time in seconds;

//     printf("The date and time is : %s",
//            ctime(&passed_time));

//     return 0;
// }

