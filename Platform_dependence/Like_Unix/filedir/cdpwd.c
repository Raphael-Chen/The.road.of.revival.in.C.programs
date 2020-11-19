#include "apue.h"

/***************
 *   Figure 4.24. Example of getcwd function
 * 
 *   NAME
 *       getcwd, getwd, get_current_dir_name - get current working directory
 *
 *   SYNOPSIS
 *       #include <unistd.h>
 *
 *       char *getcwd(char *buf, size_t size);
 *       char *getwd(char *buf);
 *       char *get_current_dir_name(void);
 * 
 *       Returns: buf if OK, NULL on error
 * 
 ****************/

// #define PATH "/usr/spool/uucppublic"
#define PATH "/usr/bin"

int main(void)
{
    char *ptr;
    size_t size;

    if (chdir( PATH ) < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size);            /* our own function */
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
    
    exit(0);
}

