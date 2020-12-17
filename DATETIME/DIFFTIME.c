#include <stdio.h>
#include <time.h>

/************
 *   7.27.2.2 The difftime function
 *   Synopsis
 *
 *   #include <time.h>
 *   double difftime(time_t time1, time_t time0);
 *
 *   Description
 *   The difftime function computes the difference between two calendar times: time1 -
 *   time0.
 *
 *   Returns
 *   The difftime function returns the difference expressed in seconds as a double.
**************/

int main(void)
{
    time_t start_time;
    time_t current_time;

    time(&start_time);

    printf("About to delay 5 seconds\n");

    // 优缺点与DELAY_5.c 相同
    do
    {
        time(&current_time);
    } while (difftime(current_time, start_time) < 5.0);

    printf("Done\n");

    return 0;
}
