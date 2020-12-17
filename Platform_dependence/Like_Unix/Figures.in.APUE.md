# Figures in APUE





## Figure 4.2. IPC type macros in <sys/stat.h>
Macro Type of object
S_TYPEISMQ() message queue
S_TYPEISSEM() semaphore
S_TYPEISSHM() shared memory object



## Figure 4.6. The nine file access permission bits, from <sys/stat.h>

| st_mode mask | Meaning       |
| ------------ | ------------- |
| S_IRUSR      | user-read     |
| S_IWUSR      | user-write    |
| S_IXUSR      | user-execute  |
| S_IRGRP      | group-read    |
| S_IWGRP      | group-write   |
| S_IXGRP      | group-execute |
| S_IROTH      | other-read    |
| S_IWOTH      | other-write   |
| S_IXOTH      | other-execute |



## Figure 4.10. The umask file access permission bits

| Mask bit | Meaning       |
| -------- | ------------- |
| 0400     | user-read     |
| 0200     | user-write    |
| 0100     | user-execute  |
| 0040     | group-read    |
| 0020     | group-write   |
| 0010     | group-execute |
| 0004     | other-read    |
| 0002     | other-write   |
| 0001     | other-execute |


| mode    | Description                               |
| ------- | ----------------------------------------- |
| S_ISUID | set-user-ID on execution                  |
| S_ISGID | set-group-ID on execution                 |
| S_ISVTX | saved-text (sticky bit)                   |
| S_IRWXU | read, write, and execute by user (owner)  |
| S_IRUSR | read by user (owner)                      |
| S_IWUSR | write by user (owner)                     |
| S_IXUSR | execute by user (owner)                   |
| S_IRWXG | read, write, and execute by group         |
|         |                                           |
| S_IRGRP | read by group                             |
| S_IWGRP | write by group                            |
| S_IXGRP | execute by group                          |
| S_IRWXO | read, write, and execute by other (world) |
|         |                                           |
| S_IROTH | read by other (world)                     |
| S_IWOTH | write by other (world)                    |
| S_IXOTH | execute by other (world)                  |





## Figure 4.17. Treatment of symbolic links by various functions

| Function | Does not follow symbolic link | Follows symbolic link |
| -------- | ----------------------------- | --------------------- |
| access   |                               | •                     |
| chdir    |                               | •                     |
| chmod    |                               | •                     |
| chown    | •                             | •                     |
| creat    |                               | •                     |
| exec     |                               | •                     |
| lchown   | •                             |                       |
| link     |                               | •                     |
| lstat    | •                             |                       |
| open     |                               | •                     |
| opendir  |                               | •                     |
| pathconf |                               | •                     |
| readlink | •                             |                       |
| remove   | •                             |                       |
| rename   | •                             |                       |
| stat     |                               | •                     |
| truncate |                               | •                     |
| unlink   | •                             |                       |



Figure 6.1. Fields in /etc/passwd file

Figure 6.3. Fields in /etc/shadow file
Figure 6.4. Fields in /etc/group file

Figure 6.5. Account implementation differences

Figure 6.7. System identification name limits

## Figure 6.6. Similar routines for accessing system data files

| Description | Data file      | Header     | Structure | Additional keyed lookup functions |
| ----------- | -------------- | ---------- | --------- | --------------------------------- |
| passwords   | /etc/passwd    | <pwd.h>    | passwd    | getpwnam , getpwuid               |
| groups      | /etc/group     | <grp.h>    | group     | getgrnam , getgrgid               |
| shadow      | /etc/shadow    | <shadow.h> | spwd      | getspnam                          |
| hosts       | /etc/hosts     | <netdb.h>  | hostent   | gethostbyname , gethostbyaddr     |
| networks    | /etc/networks  | <netdb.h>  | netent    | getnetbyname , getnetbyaddr       |
| protocols   | /etc/protocols | <netdb.h>  | protoent  | getprotobyname , getprotobynumber |
| services    | /etc/services  | <netdb.h>  | servent   | getservbyname , getservbyport     |



## Figure 6.8 Relationship of the various time functions

![6.8](../../images/figure_6.8.png)



Figure 6.9. Conversion specifiers for strftime




