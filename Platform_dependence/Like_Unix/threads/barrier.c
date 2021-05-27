#include "apue.h"
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

// Figure 11.16 shows how a barrier can be used to synchronize threads cooperating on a
// single task.

#define NTHR   8				/* number of threads */
// #define NTHR   4				/* number of threads */
#define NUMNUM 8000000L			/* number of numbers to sort */
#define TNUM   (NUMNUM/NTHR)	/* number to sort per thread */

long nums[NUMNUM];
long snums[NUMNUM];

pthread_barrier_t b;

#ifdef SOLARIS
#define heapsort qsort
#else
extern int heapsort(void *, size_t, size_t,
                    int (*)(const void *, const void *));
#endif

/*
 * Compare two long integers (helper function for heapsort)
 */
int complong(const void *arg1, const void *arg2)
{
    long l1 = *(long *)arg1;
    long l2 = *(long *)arg2;

    if (l1 == l2)
        return 0;
    else if (l1 < l2)
        return -1;
    else
        return 1;
}

/*
 * Worker thread to sort a portion of the set of numbers.
 */
void *thr_fn(void *arg)
{
    long idx = (long)arg;

    heapsort(&nums[idx], TNUM, sizeof(long), complong);
    pthread_barrier_wait(&b);

    /*
	 * Go off and perform more work ...
	 */
    return ((void *)0);
}

/*
 * Merge the results of the individual sorted ranges.
 */
void merge()
{
    long idx[NTHR];
    long i, minidx, sidx, num;

    for (i = 0; i < NTHR; i++)
        idx[i] = i * TNUM;
    for (sidx = 0; sidx < NUMNUM; sidx++)
    {
        num = LONG_MAX;
        for (i = 0; i < NTHR; i++)
        {
            if ((idx[i] < (i + 1) * TNUM) && (nums[idx[i]] < num))
            {
                num = nums[idx[i]];
                minidx = i;
            }
        }
        snums[sidx] = nums[idx[minidx]];
        idx[minidx]++;
    }
}

int main( void )
{
    unsigned long i;
    struct timeval start, end;
    long long startusec, endusec;
    double elapsed;
    int err;
    pthread_t tid;

    /*
	 * Create the initial set of numbers to sort.
	 */
    srandom(1);
    for (i = 0; i < NUMNUM; i++)
        nums[i] = random();

    /*
	 * Create 8 threads to sort the numbers.
	 */
    gettimeofday(&start, NULL);
    pthread_barrier_init(&b, NULL, NTHR + 1);
    for (i = 0; i < NTHR; i++)
    {
        err = pthread_create(&tid, NULL, thr_fn, (void *)(i * TNUM));
        if (err != 0)
            err_exit(err, "can't create thread");
    }
    pthread_barrier_wait(&b);

    merge();
    gettimeofday(&end, NULL);

    /*
	 * Print the sorted list.
	 */
    startusec = start.tv_sec * 1000000 + start.tv_usec;
    endusec = end.tv_sec * 1000000 + end.tv_usec;
    elapsed = (double)(endusec - startusec) / 1000000.0;
    printf("sort took %.4f seconds\n", elapsed);
    sleep(10);

    for (i = 0; i < NUMNUM; i++)
        printf("%ld\n", snums[i]);

    exit(0);
}

// This example shows the use of a barrier in a simplified situation where the threads
// perform only one task. In more realistic situations, the worker threads will continue
// with other activities after the call to pthread_barrier_wait returns.
// In the example, we use eight threads to divide the job of sorting 8 million numbers.
// Each thread sorts 1 million numbers using the heapsort algorithm (see Knuth [1998] for
// details). Then the main thread calls a function to merge the results.

// There are 4 core CPU in my computer.
// 4 thread / 800 0000L
// $ ./barrier
// sort took 0.3120 seconds

// 8 thread / 800 0000L
// $ ./barrier
// sort took 4.0221 seconds