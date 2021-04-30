#include "apue.h"
#include <pthread.h>

// Figure 11.3 Fetching the thread exit status
// As we can see, when a thread exits by calling pthread_exit or by simply returning
// from the start routine, the exit status can be obtained by another thread by calling
// pthread_join.

void *thr_fn1(void *arg)
{
    printf("thread 1 returning\n");
    return ((void *)1);
}

void *thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
}

int main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
        err_exit(err, "can't create thread 1");

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0)
        err_exit(err, "can't create thread 2");

    err = pthread_join(tid1, &tret);
    if (err != 0)
        err_exit(err, "can't join with thread 1");
    printf("thread 1 exit code %ld\n", (long)tret);
    
    err = pthread_join(tid2, &tret);
    if (err != 0)
        err_exit(err, "can't join with thread 2");
    printf("thread 2 exit code %ld\n", (long)tret);

    exit(0);
}


// NAME
//        pthread_create - create a new thread
//
// SYNOPSIS
//        #include <pthread.h>
//
//        int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                           void *(*start_routine) (void *), void *arg);
//
//        Compile and link with -pthread.
//
// RETURN VALUE
//        On success, pthread_create() returns 0; on error, it returns an error number, and the con‐
//        tents of *thread are undefined.
