#include "apue.h"

// Figure 10.9 Calling sleep2 from a program that catches other signals
unsigned int sleep2(unsigned int);
static void sig_int(int);

int main(void)
{
    unsigned int unslept;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    unslept = sleep2(5);
    printf("sleep2 returned: %u\n", unslept);

    exit(0);
}

static void sig_int(int signo)
{
    int i, j;
    volatile int k;

    /*
	 * Tune these loops to run for more than 5 seconds
	 * on whatever system this test program is run.
	 */
    printf("\nsig_int starting\n");
    for (i = 0; i < 300000; i++)
        for (j = 0; j < 4000; j++)
            k += i * j;
    printf("sig_int finished\n");
}

// When we execute the program shown in Figure 10.9 and interrupt the sleep by
// typing the interrupt character, we get the following output:
// $ ./tsleep2
// ^C                 # we type the interrupt character ( Ctrl+c )
// sig_int starting
// sig_int finished
// sleep2 returned: 1
