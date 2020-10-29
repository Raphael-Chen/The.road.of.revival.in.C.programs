#include "apue.h"

// Figure 4.3. Print type of file for each command-line argument
/*********
    NAME
        stat, fstat, lstat - get file status

    SYNOPSIS
        #include <sys/types.h>
        #include <sys/stat.h>
        #include <unistd.h>

        int stat(const char *path, struct stat *buf);
        int fstat(int fd, struct stat *buf);
        int lstat(const char *path, struct stat *buf);

            
*********/

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0)
        {
            err_ret("lstat error");
            continue;
        }
        
        if (S_ISREG(buf.st_mode))
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if (S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "** unknown mode **";
        printf("%s\n", ptr);
    }

    exit(0);
}

// $ ./filetype /etc/passwd /etc  /dev/input/ /dev/log /dev/tty /dev/sda
// /etc/passwd: regular
// /etc: directory
// /dev/input/: directory
// /dev/log: socket
// /dev/tty: character special
// /dev/sda: block special


/****
    We've talked about two different types of files so far: regular files and directories. Most files on a UNIX system are either regular files or directories, but there are additional types of files. The types are:

    1. Regular file. The most common type of file, which contains data of some form. There is no distinction to the UNIX kernel whether this data is text or binary. Any interpretation of the contents of a regular file is left to the application processing the file.
    One notable exception to this is with binary executable files. To execute a program, the kernel must understand its format. All binary executable files conform to a format that allows the kernel to identify where to load a program's text and data.

    2. Directory file. A file that contains the names of other files and pointers to information on these files. Any process that has read permission for a directory file can read the contents of the directory, but only the kernel can write directly to a directory file. Processes must use the functions described in this chapter to make changes to a directory.

    3. Block special file. A type of file providing buffered I/O access in fixed-size units to devices such as disk drives.

    4. Character special file. A type of file providing  unbuffered I/O access in variable-sized units to devices. All devices on a system are either block special files or  character special files.

    5. FIFO. A type of file used for communication between processes. It's sometimes called a named pipe. We describe FIFOs in Section 15.5.

    6. Socket. A type of file used for network communication between processes. A socket can also be
    used for non-network communication between processes on a single host. We use sockets for interprocess communication in Chapter 16.

    7. Symbolic link. A type of file that points to another file. We talk more about symbolic links in
    Section 4.16

***/


//    All of these system calls return a stat structure, which contains the following fields:
//        struct stat {
//            dev_t     st_dev;     /* ID of device containing file */
//            ino_t     st_ino;     /* inode number */
//            mode_t    st_mode;    /* protection */
//            nlink_t   st_nlink;   /* number of hard links */
//            uid_t     st_uid;     /* user ID of owner */
//            gid_t     st_gid;     /* group ID of owner */
//            dev_t     st_rdev;    /* device ID (if special file) */
//            off_t     st_size;    /* total size, in bytes */
//            blksize_t st_blksize; /* blocksize for filesystem I/O */
//            blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
//            time_t    st_atime;   /* time of last access */
//            time_t    st_mtime;   /* time of last modification */
//            time_t    st_ctime;   /* time of last status change */
//        };


// | Macro     | Type of file           |
// | --------- | ---------------------- |
// | S_ISREG( )| regular file           |
// | S_ISDIR( )| directory file         |
// | S_ISCHR( )| character special file |
// | S_ISBLK( )| block special file     |
// | S_ISFIFO()| pipe or FIFO           |
// | S_ISLNK( )| symbolic link          |
// | S_ISSOCK()| socket                 |