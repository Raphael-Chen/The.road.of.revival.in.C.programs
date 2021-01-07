#include "apue.h"
#include <sys/resource.h>

// Figure 7.16. Print the current resource limits
/**************
NAME
       getrlimit, setrlimit, prlimit - get/set resource limits

SYNOPSIS
       #include <sys/time.h>
       #include <sys/resource.h>

       int getrlimit(int resource, struct rlimit *rlim);
       int setrlimit(int resource, const struct rlimit *rlim);

       int prlimit(pid_t pid, int resource, const struct rlimit *new_limit,
                   struct rlimit *old_limit);

DESCRIPTION
       The  getrlimit()  and  setrlimit()  system calls get and set resource limits respectively.
       Each resource has an associated soft and hard limit, as defined by the rlimit structure:

           struct rlimit {
               rlim_t rlim_cur;  // Soft limit 
               rlim_t rlim_max;  // Hard limit (ceiling for rlim_cur) 
           };
*************/

#define doit(name) pr_limits(#name, name)

static void pr_limits(char *, int);

int main(void)
{
#ifdef RLIMIT_AS           // The maximum size of the process's virtual memory (address space) in bytes.
    doit(RLIMIT_AS);
#endif

    doit(RLIMIT_CORE);    // The maximum size in bytes of a core file
    doit(RLIMIT_CPU);     // The maximum amount of CPU time in seconds.
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);

#ifdef RLIMIT_MEMLOCK
    doit(RLIMIT_MEMLOCK); // The maximum number of bytes of memory that may be locked into RAM.
#endif

#ifdef RLIMIT_MSGQUEUE
    doit(RLIMIT_MSGQUEUE);   // 消息队列
#endif

#ifdef RLIMIT_NICE
    doit(RLIMIT_NICE);
#endif

    doit(RLIMIT_NOFILE);  // Specifies a value one greater than the maximum file descriptor number
                          //  that can be opened by this process.

#ifdef RLIMIT_NPROC
    doit(RLIMIT_NPROC);    // The maximum number of child processes per real user ID.
#endif

#ifdef RLIMIT_NPTS
    doit(RLIMIT_NPTS);
#endif

#ifdef RLIMIT_RSS
    doit(RLIMIT_RSS);
#endif

#ifdef RLIMIT_SBSIZE
    doit(RLIMIT_SBSIZE);
#endif

#ifdef RLIMIT_SIGPENDING
    doit(RLIMIT_SIGPENDING);
#endif

    doit(RLIMIT_STACK);

#ifdef RLIMIT_SWAP
    doit(RLIMIT_SWAP);
#endif

#ifdef RLIMIT_VMEM
    doit(RLIMIT_VMEM);
#endif

    exit(0);
}

static void pr_limits(char *name, int resource)
{
    struct rlimit limit;
    unsigned long long lim;

    if (getrlimit(resource, &limit) < 0)
        err_sys("getrlimit error for %s", name);
    printf("%-14s  ", name);

    if (limit.rlim_cur == RLIM_INFINITY)
    {
        printf("(infinite)  ");
    }
    else
    {
        lim = limit.rlim_cur;
        printf("%10lld  ", lim);
    }

    if (limit.rlim_max == RLIM_INFINITY)
    {
        printf("(infinite)");
    }
    else
    {
        lim = limit.rlim_max;
        printf("%10lld", lim);
    }

    putchar((int)'\n');
}
