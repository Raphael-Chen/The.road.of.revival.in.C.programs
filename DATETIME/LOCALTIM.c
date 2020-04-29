#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm *current_date;

    time_t seconds;

    time(&seconds);

    current_date = localtime(&seconds);

    printf("Current date: %d-%d-%d\n", current_date->tm_mon + 1,
           current_date->tm_mday, current_date->tm_year + 1900 );
    printf("Current time: %02d:%02d\n", current_date->tm_hour,
           current_date->tm_min);
}
