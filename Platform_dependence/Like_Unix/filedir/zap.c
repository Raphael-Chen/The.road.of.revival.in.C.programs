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

// void output_time( struct timespec * now )
// {
//     for (size_t i = 0; i < 2; i++, now++)
//     {
//         printf( "[%lu] nsec:%lu.\n", i, now->tv_nsec );
//         printf( "[%lu] sec :%lu.\n", i, now->tv_sec );
//     }
// }

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

        if (futimens(fd, times) < 0)                   /* reset times */  
            err_ret("%s: futimens error", argv[i]);
        close(fd);
    }
    
    exit(0);
}

/*****************
 * 
    The program shown in Figure 4.21 truncates files to zero length using the O_TRUNC option of the 
    open function, but does not change their access time or modification time. To do this, the program 
    first obtains the times with the stat function, truncates the file, and then resets the times 
    with the utime function.
    遵循以下指令操作可以重现实验结果

    $ ls -l changemod mycd
    -rwxr-xr-x 1 trojan trojan 13647 12月  3 15:41 changemod
    -rwxr-xr-x 1 trojan trojan 13579 12月  3 15:41 mycd
    $ ls -lu changemod mycd
    -rwxr-xr-x 1 trojan trojan 13647 12月  8 11:08 changemod
    -rwxr-xr-x 1 trojan trojan 13579 12月  8 11:08 mycd
    $ 
    $ date 
    2020年 12月 09日 星期三 10:43:15 CST
    $ ./zap changemod mycd 
    [0] nsec:157388400.
    [0] sec :1607396933.
    [1] nsec:33095269.
    [1] sec :1606981293.
    [0] nsec:177388401.
    [0] sec :1607396933.
    [1] nsec:421095275.
    [1] sec :1606981293.
    $ ls -l changemod mycd
    -rwxr-xr-x 1 trojan trojan 0 12月  3 15:41 changemod
    -rwxr-xr-x 1 trojan trojan 0 12月  3 15:41 mycd
    $ ls -lu changemod mycd
    -rwxr-xr-x 1 trojan trojan 0 12月  8 11:08 changemod
    -rwxr-xr-x 1 trojan trojan 0 12月  8 11:08 mycd
    $ ls -lc changemod mycd
    -rwxr-xr-x 1 trojan trojan 0 12月  9 10:44 changemod
    -rwxr-xr-x 1 trojan trojan 0 12月  9 10:44 mycd

    -c     with -lt: sort by, and show, ctime (time of last modification of file status infor‐
                mation) with -l: show ctime and sort by name otherwise: sort by ctime, newest first


    As we expect, the last-modification times and the last-access times are not changed. 
    The changed-status times, however, are changed to the time that the program was run.
***************/


//    struct stat {
//        dev_t     st_dev;     /* ID of device containing file */
//        ino_t     st_ino;     /* inode number */
//        mode_t    st_mode;    /* protection */
//        nlink_t   st_nlink;   /* number of hard links */
//        uid_t     st_uid;     /* user ID of owner */
//        gid_t     st_gid;     /* group ID of owner */
//        dev_t     st_rdev;    /* device ID (if special file) */
//        off_t     st_size;    /* total size, in bytes */
//        blksize_t st_blksize; /* blocksize for filesystem I/O */
//        blkcnt_t  st_blocks;  /* number of 512B blocks allocated */

//        time_t    st_atime;   /* time of last access */
//        time_t    st_mtime;   /* time of last modification */

//        time_t    st_ctime;   /* time of last status change */
//    };