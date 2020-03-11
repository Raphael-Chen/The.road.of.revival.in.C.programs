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
        /* code */
    }else
    {
        perror("Set time fail: ");  //Operation not permitted
    }
    
    
}
