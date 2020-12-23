#include <stdio.h>
#include <time.h>

/************************ 
 *   struct timespec
 *   which holds an interval specified in seconds and nanoseconds (which may represent a
 *   calendar time based on a particular epoch)
 * 
 *  7.27.2.5 The timespec_get function
 *  Synopsis
 *  #include <time.h>
 *  int timespec_get(struct timespec *ts, int base);
 *
 *  Description
 *   The timespec_get function sets the interval pointed to by ts to hold the current
 *   calendar time based on the specified time base.
 *
 *   If base is TIME_UTC, the tv_sec member is set to the number of seconds since an
 *   implementation defined epoch, truncated to a whole value and the tv_nsec member is
 *   set to the integral number of nanoseconds, rounded to the resolution of the system
 *   clock. 321)
 
 * 
 ***********************/
int main(void)
{
    char buff[100];
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);  // nanoseconds — [0, 999999999]
    // printf("Current time: %s. %ld \n", buff, ts.tv_nsec);

    return 0;
}




/*
#include<stdio.h>
#include<time.h>
#include<sys/time.h>

void nowtime_ns()
{
    printf("---------------------------struct timespec---------------------------------------\n"); 
    printf("[time(NULL)]     :     %ld\n", time(NULL)); 
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    printf("clock_gettime : tv_sec=%ld, tv_nsec=%ld\n", ts.tv_sec, ts.tv_nsec);
    
    struct tm t;
    char date_time[64];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&ts.tv_sec, &t));
    printf("clock_gettime : date_time=%s, tv_nsec=%ld\n", date_time, ts.tv_nsec);
}
void nowtime_us()
{
    printf("---------------------------struct timeval----------------------------------------\n"); 
    printf("[time(NULL)]    :    %ld\n", time(NULL)); 
    struct timeval us;
    gettimeofday(&us,NULL);
    printf("gettimeofday: tv_sec=%ld, tv_usec=%ld\n", us.tv_sec, us.tv_usec);
    
    struct tm t;
    char date_time[64];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&us.tv_sec, &t));
    printf("gettimeofday: date_time=%s, tv_usec=%ld\n", date_time, us.tv_usec);
}

int main( void )
{
    nowtime_ns();
    printf("\n");
    nowtime_us();
    printf("\n");
    return 0;
}*/

/*
#include <stdio.h>
#include <time.h>

// 返回自系统开机以来的毫秒数（tick）
unsigned long GetTickCount()
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}


int main()
{
    struct timespec time1 = { 0, 0 };

    clock_gettime(CLOCK_REALTIME, &time1);
    printf("CLOCK_REALTIME: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &time1);
    printf("CLOCK_MONOTONIC: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC_RAW, &time1);
    printf("CLOCK_MONOTONIC_RAW: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", time1.tv_sec,
           time1.tv_nsec);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
    printf("CLOCK_THREAD_CPUTIME_ID: %ld, %ld\n", time1.tv_sec,
           time1.tv_nsec);

    printf("\n%ld\n", time(NULL));

    printf("tick count in ms: %lu\n", GetTickCount());

    return 0;
} */
