#include <stdio.h>
#include <time.h>

/*****************

    7.27.2.4 The time function
    Synopsis

    #include <time.h>
    time_t time(time_t *timer);

    Description
    The time function determines the current calendar time. The encoding of the value is
    unspecified.

    Returns
    The time function returns the implementation’s best approximation to the current
    calendar time. The value (time_t)(-1) is returned if the calendar time is not available. 
    If timer is not a null pointer, the return value is also assigned to the object it
    points to.
******************/

int main(void)
{
    time_t current_time;
    time_t start_time;

    printf("About to delay 5 seconds\n");

    time(&start_time); // Get starting time in seconds

    // 优点：算法简单，可移植性好
    // 缺点：不停轮询cpu占用过高，一秒钟可执行百万次（依据硬件配置），随着时间的延长，硬件功耗进一步增加。
    do
    {
        time(&current_time);
    } while ((current_time - start_time) < 5);

    printf("Done\n");

    return 0;
}

