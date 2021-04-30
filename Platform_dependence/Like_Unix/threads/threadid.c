#include "apue.h"
#include <pthread.h>

// Figure 11.2 Printing thread IDs
pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
           (unsigned long)tid, (unsigned long)tid);
}

void * thr_fn(void *arg)
{
    printids("new thread: ");                   // After main thread output.
    return ((void *)0);
}

int main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        err_exit(err, "can't create thread");
    printids("main thread:");                    // Output first.
    sleep(1);

    exit(0);
}


// NAME
//        pthread_self - obtain ID of the calling thread
//
// SYNOPSIS
//        #include <pthread.h>
//
//        pthread_t pthread_self(void);
//
//        Compile and link with -pthread.

// DESCRIPTION
//        The  pthread_self() function returns the ID of the calling thread.  This is the same value
//        that is returned in *thread in the pthread_create(3) call that created this thread.

// RETURN VALUE
//        This function always succeeds, returning the calling thread's ID.

// Running the same program on Linux gives us
// $ ./a.out
// main thread: pid 17874 tid 140693894424320 (0x7ff5d9996700)
// new thread: pid 17874 tid 140693886129920 (0x7ff5d91ad700)
