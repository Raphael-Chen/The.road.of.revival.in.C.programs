#include "apue.h"

// The program in Figure 1.6 prints its process ID.

int main(void)
{
    printf("hello world from process ID %ld\n", (long)getpid());

    exit(0);
}

// If we compile this program into the file a.out and execute it, we have
// $ ./a.out
// hello world from process ID 851
// $ ./a.out
// hello world from process ID 854

