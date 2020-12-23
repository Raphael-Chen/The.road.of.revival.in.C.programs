#include <stdio.h>

// Figure 7.1. Classic C program
main()
{
    printf("hello, world\n");
}


// When we compile and run the program in Figure 7.1, we see that the exit code is random. 
// If we compile the same program on different systems, we are likely to get different exit codes, 
// depending on the contents of the stack and register contents at the time that the 
// main function returns:
//
// $ cc hello.c
// $ ./a.out
// hello, world
// $ echo $?      # print the exit status
// 13


// Now if we enable the 1999 ISO C compiler extensions, we see that the exit code changes:
// $ cc -std=c99 hello.c      # enable gcc's 1999 ISO C extensions
// hello.c:4: warning: return type defaults to 'int'
// $ ./a.out
// hello, world
// $ echo $?                 # role="italicAlt"print the exit status
// 0
