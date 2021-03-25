#include <signal.h>
#include <unistd.h>

// Figure 10.7 Simple, incomplete implementation of sleep

static void sig_alrm(int signo)
{
    /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return (seconds);
    alarm(seconds);             /* start the timer */
    pause();                    /* next caught signal wakes us up */
       
    return (alarm(0));          /* turn off timer, return unslept time */
}



// NAME
//        alarm - set an alarm clock for delivery of a signal

// SYNOPSIS
//        #include <unistd.h>

//        unsigned int alarm(unsigned int seconds);

// DESCRIPTION
//        alarm()  arranges  for  a SIGALRM signal to be delivered to the calling process in seconds
//        seconds.

//        If seconds is zero, any pending alarm is canceled.

//        In any event any previously set alarm() is canceled.

// RETURN VALUE
//        alarm() returns the number of seconds remaining until any previously scheduled  alarm  was
//        due to be delivered, or zero if there was no previously scheduled alarm.
