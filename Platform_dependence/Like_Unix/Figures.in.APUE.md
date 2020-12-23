# Figures in APUE





### Figure 4.2. IPC type macros in <sys/stat.h>
Macro Type of object
S_TYPEISMQ() message queue
S_TYPEISSEM() semaphore
S_TYPEISSHM() shared memory object



### Figure 4.6. The nine file access permission bits, from <sys/stat.h>

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



### Figure 4.10. The umask file access permission bits

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





### Figure 4.17. Treatment of symbolic links by various functions

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

### Figure 6.6. Similar routines for accessing system data files

| Description | Data file      | Header     | Structure | Additional keyed lookup functions |
| ----------- | -------------- | ---------- | --------- | --------------------------------- |
| passwords   | /etc/passwd    | <pwd.h>    | passwd    | getpwnam , getpwuid               |
| groups      | /etc/group     | <grp.h>    | group     | getgrnam , getgrgid               |
| shadow      | /etc/shadow    | <shadow.h> | spwd      | getspnam                          |
| hosts       | /etc/hosts     | <netdb.h>  | hostent   | gethostbyname , gethostbyaddr     |
| networks    | /etc/networks  | <netdb.h>  | netent    | getnetbyname , getnetbyaddr       |
| protocols   | /etc/protocols | <netdb.h>  | protoent  | getprotobyname , getprotobynumber |
| services    | /etc/services  | <netdb.h>  | servent   | getservbyname , getservbyport     |



### Figure 6.8 Relationship of the various time functions

![6.8](../../images/figure_6.8.png)



Figure 6.9. Conversion specifiers for strftime



## Chapter 7. Process Environment

Before looking at the process control primitives in the next chapter, we need to examine the environment of a single process. 
In this chapter, we'll see how the main function is called when the program is executed, 

- how command-line arguments are passed to the new program, 
- what the typical memory layout looks like, 
- how to allocate additional memory, 
- how the process can use environment variables, and various ways for the process to terminate. 
- Additionally, we'll look at the longjmp and setjmp functions and their interaction with the stack. We finish the chapter by examining the resource limits of a process.

There are eight ways for a process to terminate. Normal termination occurs in five ways:
1. Return from main
2. Calling exit
3. Calling _exit or _Exit
4. Return of the last thread from its start routine (Section 11.5)
5. Calling pthread_exit (Section 11.5) from the last thread
Abnormal termination occurs in three ways:
6. Calling abort (Section 10.17)
7. Receipt of a signal (Section 10.2)
8. Response of the last thread to a cancellation request (Sections 11.5 and 12.7)



### Figure 7.2. How a C program is started and how it terminates
![7.2](../../images/figure_7.2.png)


### Figure 7.5. Environment consisting of five C character strings
![7.5](../../images/figure_7.5.png)




Historically, a C program has been composed of the following pieces:
- **Text segment**, the machine instructions that the CPU executes. Usually, the text segment is sharable so that only a single copy needs to be in memory for frequently executed programs, such as text editors, the C compiler, the shells, and so on. Also, the text segment is often read-only, to prevent a program from accidentally modifying its instructions.

- **Initialized data segment**, usually called simply the data segment, containing variables that are specifically initialized in the program. For example, the C declaration
int maxcount = 99;
appearing outside any function causes this variable to be stored in the initialized data segment with its initial value.

- Uninitialized data segment, often called the "bss" segment, named after an ancient assembler operator that stood for "block started by symbol." Data in this segment is initialized by the kernel to arithmetic 0 or null pointers before the program starts executing. The C declaration
long sum[1000];
appearing outside any function causes this variable to be stored in the uninitialized data segment.


- **Stack**, where automatic variables are stored, along with information that is saved each time a function is called. Each time a
function is called, the address of where to return to and certain information about the caller's environment, such as some of
the machine registers, are saved on the stack. The newly called function then allocates room on the stack for its automatic
and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself, a new
stack frame is used, so one set of variables doesn't interfere with the variables from another instance of the function.

- Heap, where dynamic memory allocation usually takes place. Historically, the heap has been located between the uninitialized data and the stack.

Figure 7.6. Typical memory arrangement



## 7.7. Shared Libraries
Most UNIX systems today support shared libraries. Arnold [1986] describes an early implementation under System V, and Gingell et al. [1987] describe a different implementation under SunOS. Shared libraries remove the common library routines from the executable file, instead maintaining a single copy of the library routine somewhere in memory that all processes reference. This reduces the size of each executable file but may add some runtime overhead, either when the program is first executed or the first time each shared library function is called. Another advantage of shared libraries is that library functions can be replaced with new versions without having to relink edit every program that uses the library. (This assumes that the number and type of arguments haven't changed.)

Different systems provide different ways for a program to say that it wants to use or not use the shared libraries. Options for the cc (1) and ld (1) commands are typical. As an example of the size differences, the following executable filethe classic hello.c programwas first
created without shared libraries:

```shell
$ gcc -static hello1.c
$ ls -l a.out
-rwxr-xr-x 1 Trojan Trojan 877148 Dec 23 15:39 a.out
$ file a.out
a.out: ELF 64-bit LSB  executable, x86-64, version 1 (GNU/Linux), statically linked, for GNU/Linux 2.6.24, BuildID[sha1]=28131fc347999c685700cb6350859baf5f7b460e, not stripped
$ ./a.out
hello, world
$ size a.out
   text    data     bss     dec     hex filename
 782035    7532    9600  799167   c31bf a.out

$ gcc hello1.c
$ ls -l hello1.c
-rw-r--r-- 1 Trojan Trojan 812 Dec 23 11:37 hello1.c
$ file a.out
a.out: ELF 64-bit LSB  executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=ff11807162029d32567a87bc734ca270564ac93b, not stripped
$ size a.out
   text    data     bss     dec     hex filename
   1199     560       8    1767     6e7 a.out
```

### Figure 7.7. Environment variables defined in the Single UNIX Specification

| Variable    | POSIX.1 | FreeBSD 5.2.1 | Linux 2.4.22 | Mac OS X 10.3 | Solaris 9 | Description                                         |
| ----------- | ------- | ------------- | ------------ | ------------- | --------- | --------------------------------------------------- |
| COLUMNS     | •       | •             | •            | •             | •         | terminal width                                      |
| DATEMSK     | XSI     |               | •            |               | •         | getdate(3) template file pathname                   |
| HOME        | •       | •             | •            | •             | •         | home directory                                      |
| LANG        | •       | •             | •            | •             | •         | name of locale                                      |
| LC_ALL      | •       | •             | •            | •             | •         | name of locale                                      |
| LC_COLLATE  | •       | •             | •            | •             | •         | name of locale for collation                        |
| LC_CTYPE    | •       | •             | •            | •             | •         | name of locale for character classification         |
| LC_MESSAGES | •       | •             | •            | •             | •         | name of locale for messages                         |
| LC_MONETARY | •       | •             | •            | •             | •         | name of locale for monetary editing                 |
| LC_NUMERIC  | •       | •             | •            | •             | •         | name of locale for numeric editing                  |
| LC_TIME     | •       | •             | •            | •             | •         | name of locale for date/time formatting             |
| LINES       | •       | •             | •            | •             | •         | terminal height                                     |
| LOGNAME     | •       | •             | •            | •             | •         | login name                                          |
| MSGVERB     | XSI     | •             |              |               | •         | fmtmsg (3) message components to process            |
| NLSPATH     | XSI     | •             | •            | •             | •         | sequence of templates for message catalogs          |
| PATH        | •       | •             | •            | •             | •         | list of path prefixes to search for executable file |
| PWD         | •       | •             | •            | •             | •         | absolute pathname of current working directory      |
| SHELL       | •       | •             | •            | •             | •         | name of user's preferred shell                      |
| TERM        | •       | •             | •            | •             | •         | terminal type                                       |
| TMPDIR      | •       | •             | •            | •             | •         | pathname of directory for creating temporary files  |
| TZ          | •       | •             | •            | •             | •         | time zone information                               |