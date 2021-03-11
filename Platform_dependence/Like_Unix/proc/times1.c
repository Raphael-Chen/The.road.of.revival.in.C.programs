#include "apue.h"
#include <sys/times.h>

// Figure 8.30. Time and execute all command-line arguments

// The program in Figure 8.30 executes each command-line argument as a shell 
// command string, timing the command and printing the values from the tms structure.
// If we run this program, we get

// $ ./times1 "sleep 5" "date"
//
// command: sleep 5
//   real:     5.02
//   user:     0.00
//   sys:      0.00
//   child user:     0.00
//   child sys:      0.00
// normal termination, exit status = 0
//
// command: date
// Wed Mar 10 16:25:30 CST 2021
//   real:     0.01
//   user:     0.00
//   sys:      0.00
//   child user:     0.00
//   child sys:      0.00
// normal termination, exit status = 0


static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);

int main(int argc, char *argv[])
{
    int i;

    setbuf(stdout, NULL);
    for (i = 1; i < argc; i++)
        do_cmd(argv[i]); /* once for each command-line arg */

    exit(0);
}

static void do_cmd(char *cmd) /* execute and time the "cmd" */
{
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;

    printf("\ncommand: %s\n", cmd);

    if ((start = times(&tmsstart)) == -1) /* starting values */
        err_sys("times error");

    if ((status = system(cmd)) < 0) /* execute command */
        err_sys("system() error");

    if ((end = times(&tmsend)) == -1) /* ending values */
        err_sys("times error");

    pr_times(end - start, &tmsstart, &tmsend);

    pr_exit(status);
}

static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
    static long clktck = 0;

    if (clktck == 0)               // fetch clock ticks per second first time 
        if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
            err_sys("sysconf error");

    printf( "clktck is %ld\n", clktck); // for debug

    printf("  real:  %7.2f\n", real / (double)clktck);
    printf("  user:  %7.2f\n",
           (tmsend->tms_utime - tmsstart->tms_utime) / (double)clktck);
    printf("  sys:   %7.2f\n",
           (tmsend->tms_stime - tmsstart->tms_stime) / (double)clktck);
    printf("  child user:  %7.2f\n",
           (tmsend->tms_cutime - tmsstart->tms_cutime) / (double)clktck);
    printf("  child sys:   %7.2f\n",
           (tmsend->tms_cstime - tmsstart->tms_cstime) / (double)clktck);
}

// In these two examples, all the CPU time appears in the child process, 
// which is where the shell and the command execute.
/* Structure describing CPU time used by a process and its children.  */
// struct tms
// {
//     clock_t tms_utime; /* User CPU time.  */
//     clock_t tms_stime; /* System CPU time.  */

//     clock_t tms_cutime; /* User CPU time of dead children.  */
//     clock_t tms_cstime; /* System CPU time of dead children.  */
// };
