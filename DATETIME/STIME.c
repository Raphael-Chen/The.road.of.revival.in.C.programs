#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t seconds;

    time(&seconds); // Get current time

    seconds += (time_t)60 * 60 * 24;     //set forward one day 

    // stime(&seconds);
    if ( -1 != stime(&seconds))
    {
        printf( "stime is success~\n" );
    }
    else
    {
        perror("Set time fail: ");  //Operation not permitted
    }
    
}

/****************
    NAME
        stime - set time  // Not belong to ISO C

    SYNOPSIS
        #include <time.h>

        int stime(time_t *t);

    Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

        stime(): _SVID_SOURCE

    DESCRIPTION
        stime()  sets  the system's idea of the time and date.  The time, pointed to by t, is mea‐
        sured in seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).  stime()  may  be  exe‐
        cuted only by the superuser.

    RETURN VALUE
        On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

    ERRORS
        EFAULT Error in getting information from user space.

        EPERM  The calling process has insufficient privilege.  Under Linux the CAP_SYS_TIME priv‐
                ilege is required.
*****************/