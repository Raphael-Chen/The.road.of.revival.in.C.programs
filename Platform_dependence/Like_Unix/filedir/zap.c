#include "apue.h"
#include <fcntl.h>
//[DANGEROUS] Truncate file size to zero !!!

/***********
    NAME
        utimensat, futimens - change file timestamps with nanosecond precision

    SYNOPSIS
        #include <fcntl.h> // Definition of AT_* constants 
        #include <sys/stat.h>

        int utimensat(int dirfd, const char *pathname,
                        const struct timespec times[2], int flags);

        int futimens(int fd, const struct timespec times[2]);
************/

void output_time( struct timespec * now )
{
    for (size_t i = 0; i < 2; i++, now++)
    {
        printf( "[%lu] nsec:%lu.\n", i, now->tv_nsec );
        printf( "[%lu] sec :%lu.\n", i, now->tv_sec );
    }
}

int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0)                   //首先取出这个文件(argv[i])的所有状态
        { /* fetch current times */
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)    //然后打开这个文件(argv[i])获取文件描述符fd
        { /* truncate */
            err_ret("%s: open error", argv[i]);
            continue;
        }
        times[0] = statbuf.st_atim;                  // 取出的文件信息保存在在这个结构体数组中
        times[1] = statbuf.st_mtim;
        output_time( times );

        if (futimens(fd, times) < 0) /* reset times */  // 最后又TM给它写回到这个文件属性中去？？？R u kidding me??????
            err_ret("%s: futimens error", argv[i]);
        close(fd);
    }
    
    exit(0);
}


