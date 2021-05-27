#include <sys/time.h>
#include <stdlib.h>


// We can use the clock_gettime function (Section 6.10) to get the current time
// expressed as a timespec structure. However, this function is not yet supported on all
// platforms. Alternatively, we can use the gettimeofday function to get the current
// time expressed as a timeval structure and translate it into a timespec structure. To
// obtain the absolute time for the timeout value, we can use the following function
// (assuming the maximum time blocked is expressed in minutes):

void maketimeout(struct timespec *tsp, long minutes)
{
    struct timeval now;

    /* get the current time */
    gettimeofday(&now, NULL);
    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000; /* usec to nsec */
    
    /* add the offset to get timeout value */
    tsp->tv_sec += minutes * 60;
}
