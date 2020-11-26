#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

// Figure 4.25. Print st_dev and st_rdev values
// The program in Figure 4.25 prints the device number for each command-line argument. Additionally, if the argument refers to a character
// special file or a block special file, the st_rdev value for the special file is also printed.
// Running this program gives us the following output:
// $ ./a.out / /home/sar /dev/tty[01]
// /: dev = 3/3
// /home/sar: dev = 3/4
// /dev/tty0: dev = 0/7 (character) rdev = 4/0
// /dev/tty1: dev = 0/7 (character) rdev = 4/1
// $ mount
// which directories are mounted on which devices?
// /dev/hda3 on / type ext2 (rw,noatime)
// /dev/hda4 on /home type ext2 (rw,noatime)
// $ ls -lL /dev/tty[01] /dev/hda[34]
// brw------- 1 root 3, 3 Dec 31 1969 /dev/hda3
// brw------- 1 root 3, 4 Dec 31 1969 /dev/hda4
// crw------- 1 root 4, 0 Dec 31 1969 /dev/tty0
// crw------- 1 root 4, 1 Jan 18 15:36 /dev/tty1




int main(int argc, char *argv[])
{
    int i;
    struct stat buf;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if (stat(argv[i], &buf) < 0)
        {
            err_ret("stat error");
            continue;
        }

        printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));

        if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
        {
            printf(" (%s) rdev = %d/%d",
                   (S_ISCHR(buf.st_mode)) ? "character" : "block",
                   major(buf.st_rdev), minor(buf.st_rdev));
        }
        printf("\n");
    }

    exit(0);
}

/***********
NAME
       makedev, major, minor - manage a device number

SYNOPSIS
       #define _BSD_SOURCE            // See feature_test_macros(7) 
       #include <sys/types.h>

       dev_t makedev(int maj, int min);

       unsigned int major(dev_t dev);
       unsigned int minor(dev_t dev);

DESCRIPTION
       A  device ID consists of two parts: a major ID, identifying the class of the device, and a
       minor ID, identifying a specific instance of a device in that class.  A device ID is  rep‐
       resented using the type dev_t.

       Given  major  and  minor  device  IDs,  makedev()  combines  these to produce a device ID,
       returned as the function result.  This device ID can be given to mknod(2), for example.

       The major() and minor() functions perform the converse  task:  given  a  device  ID,  they
       return,  respectively, the major and minor components.  These macros can be useful to, for
       example, decompose the device IDs in the structure returned by stat(2).
************/