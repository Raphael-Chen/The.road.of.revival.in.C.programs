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

- **Uninitialized data segment**, often called the "bss" segment, named after an ancient assembler operator that stood for "block started by symbol." Data in this segment is initialized by the kernel to arithmetic 0 or null pointers before the program starts executing. The C declaration
long sum[1000];
appearing outside any function causes this variable to be stored in the uninitialized data segment.


- **Stack**, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and certain information about the caller's environment, such as some of the machine registers, are saved on the stack. The newly called function then allocates room on the stack for its automatic and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself, a new stack frame is used, so one set of variables doesn't interfere with the variables from another instance of the function.

- **Heap**, where dynamic memory allocation usually takes place. Historically, the heap has been located between the uninitialized data and the stack.

### Figure 7.6. Typical memory arrangement
![7.6](../../images/figure_7.6.png)


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





### Figure 7.8. Support for various environment list functions



### Figure 7.10. Stack frames after cmd_add has been called
![7.10](../../images/figure_7.10.png)





## 7.11. getrlimit and setrlimit Functions



### Figure 7.15. Support for resource limits

Every process has a set of resource limits, some of which can be queried and changed by the *getrlimit* and *setrlimit* functions.




Three rules govern the changing of the resource limits.
1. A process can change its soft limit to a value less than or equal to its hard limit.
2. A process can lower its hard limit to a value greater than or equal to its soft limit. This lowering of the hard limit is irreversible for normal users.
3. Only a superuser process can raise a hard limit.



## 8.1. Introduction
We now turn to the process control provided by the UNIX System. This includes the creation of new processes, program execution, and process termination. We also look at the various IDs that are the property of the processreal, effective, and saved; user and group IDs and how they're affected by the process control primitives. Interpreter files and the system function are also covered. We conclude the chapter by looking at the process accounting provided by most UNIX systems. This lets us look at the process control functions from a different perspective.

In general, we never know whether the child starts executing before the parent or vice versa. This depends on the scheduling algorithm used by the kernel.

### Figure 8.2. Sharing of open files between parent and child after fork





As we described in Section 7.3, a process can **terminate normally** in five ways:
1. Executing a return from the main function. As we saw in Section 7.3, this is equivalent to calling exit .
2. Calling the exit function. This function is defined by ISO C and includes the calling of all exit handlers that have been registered by calling atexit and closing all standard I/O streams.
Because ISO C does not deal with file descriptors, multiple processes (parents and children), and job control, the definition of this function is incomplete for a UNIX system.
3. Calling the _exit or _Exit function. ISO C defines _Exit to provide a way for a process to terminate without running exit handlers or signal handlers. Whether or not standard I/O streams are flushed depends on the implementation. On UNIX systems, _Exit and _exit are synonymous
and do not flush standard I/O streams. The _exit function is called by exit and handles the UNIX system-specific details; _exit is specified by POSIX.1. In most UNIX system implementations, exit (3) is a function in the standard C library, whereas _exit (2) is a system call.
4. Executing a return from the start routine of the last thread in the process. The return value of the thread is not used as the return value of the process, however. When the last thread returns from its start routine, the process exits with a termination status of 0.
5. Calling the pthread_exit function from the last thread in the process. As with the previous case, the exit status of the process in this situation is always 0, regardless of



The three forms of **abnormal termination** are as follows:

1. Calling abort . This is a special case of the next item, as it generates the SIGABRT signal.
2. When the process receives certain signals. (We describe signals in more detail in Chapter 10). The signal can be generated
   by the process itselffor example, by calling the abort functionby some other process, or by the kernel. Examples of signals
   generated by the kernel include the process referencing a memory location not within its address space or trying to divide by
   0.
3. The last thread responds to a cancellation request. By default, cancellation occurs in a deferred manner: one thread requests
   that another be canceled, and sometime later, the target thread terminates. We discuss cancellation requests in detail in
   Sections 11.5 and 12.7.



The function vfork has the same calling sequence and same return values as fork . But the semantics of the two functions differ.


The vfork function creates the new process, just like fork , without copying the address space of the parent into the child, as the child won't reference that address space; the child simply calls exec (or exit ) right after the vfork . Instead, while the child is running and until it calls either exec or exit , the child runs **in the address space of the parent**. This optimization provides an efficiency gain on some paged virtual-memory implementations of the UNIX System. (As we mentioned in the previous section, implementations use copy-on-write to improve the efficiency of a fork followed by an exec, but no copying is still faster than some copying.


Another difference between the two functions is that vfork guarantees that the child runs first, until the child calls exec or exit . When the child calls either of these functions, the parent resumes.



The differences between the parent and child are
- The return value from fork
- The process IDs are different
- The two processes have different parent process IDs: the parent process ID of the child is the
parent; the parent process ID of the parent doesn't change
- The child's tms_utime , tms_stime , tms_cutime , and tms_cstime values are set to 0
- File locks set by the parent are not inherited by the child
Pending alarms are cleared for the child
- The set of pending signals for the child is set to the empty set

The two main reasons for fork to fail are (a) if too many processes are already in the system, which
usually means that something else is wrong, or (b) if the total number of processes for this real user ID
exceeds the system's limit. Recall from Figure 2.10 that CHILD_MAX specifies the maximum number of
simultaneous processes per real user ID.



There are two normal cases for handling the descriptors after a fork .
1. The parent waits for the child to complete. In this case, the parent does not need to do anything
with its descriptors. When the child terminates, any of the shared descriptors that the child read
from or wrote to will have their file offsets updated accordingly.
2. Both the parent and the child go their own ways. Here, after the fork, the parent closes the
descriptors that it doesn't need, and the child does the same thing. This way, neither interferes
with the other's open descriptors. This scenario is often the case with network servers.

Besides the open files, there are numerous other properties of the parent that are inherited by the child:

- Real user ID, real group ID, effective user ID, effective group ID  
- Supplementary group IDs  
- Process group ID
- Session ID
- Controlling terminal
- The set-user-ID and set-group-ID flags
- Current working directory
- Root directory
- File mode creation mask
- Signal mask and dispositions
- The close-on-exec flag for any open file descriptors
- Environment
- Attached shared memory segments
- Memory mappings
- Resource limits

Figure 8.4. Macros to examine the termination status returned by wait and waitpid



When a process terminates, either normally or abnormally, the kernel notifies the parent by sending the SIGCHLD signal to the parent.


For now, we need to be aware that a process that calls wait or waitpid can
- Block, if all of its children are still running.
- Return immediately with the termination status of a child, if a child has terminated and is waiting for its termination status to be fetched
- Return immediately with an error, if it doesn't have any child processes



### Figure 8.7. The options constants for waitpid

| Constant   | Description                                              |
| ---------- | -------------------------------------------------------- |
| WCONTINUED | If the implementation supports job control, the status of any child specified by pid that has been continued after being stopped, but whose status has not yet been reported, is returned (XSI extension to POSIX.1). WNOHANG The waitpid function will not block if a child specified by pid is not immediately available. In this case, the return value is 0. |
| WUNTRACED  | If the implementation supports job control, the status of any child specified by pid that has stopped, and whose status has not been reported since it has stopped, is returned. The WIFSTOPPED macro determines whether the return value corresponds to a stopped child process. |



The waitpid function provides three features that aren't provided by the wait function.
1. The waitpid function lets us wait for one particular process, whereas the wait function returns the status of any terminated child. We'll return to this feature when we discuss the popen function.
2. The waitpid function provides a nonblocking version of wait . There are times when we want to fetch a child's status, but we don't want to block.
3. The waitpid function provides support for job control with the WUNtrACED and WCONTINUED options.

### Figure 8.9. The idtype constants for waitid

| **CONSTANT** | Description                                                  |
| ------------ | ------------------------------------------------------------ |
| P_PID        | Wait for a particular process: id contains the process ID of the child to wait for. |
| P_PGID       | Wait for any child process in a particular process group: id contains the process group ID of the children to wait for. |
| P_ALL        | Wait for any child process: id is ignored.                   |




### Figure 8.10. The options constants for waitid

| Constant   | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| WCONTINUED | Wait for a process that has previously stopped and has been continued, and whose status has not yet been reported. |
| WEXITED    | Wait for processes that have exited.                         |
| WNOHANG    | Return immediately instead of blocking if there is no child exit status available. |
| WNOWAIT    | Don't destroy the child exit status. The child's exit status can be retrieved by a subsequent call to wait ,waitid ,or waitpid . |
| WSTOPPED   | Wait for a process that has stopped and whose status has not yet been reported. |





Figure 8.11. Arguments supported by wait functions on various systems



A process that wants to wait for a child to terminate must call one of the wait functions. If a process wants to wait for its parent to
terminate, as in the program from Figure 8.8, a loop of the following form could be used:

```c
while (getppid() != 1)
sleep(1);
```
The problem with this type of loop, called polling, is that it wastes CPU time, as the caller is awakened every second to test the condition.



## 8.9. Race Conditions
For our purposes, a race condition occurs when multiple processes are trying to do something with shared data and the final outcome depends on the order in which the processes run. The fork function is a lively breeding ground for race conditions, if any of the logic after the fork either explicitly or implicitly depends on whether the parent or child runs first after the fork . In general, we cannot predict which process runs first. Even if we knew which proce.

## 8.10. exec Functions
We mentioned in Section 8.3 that one use of the fork function is to create a new process (the child) that then causes another program to be executed by calling one of the exec functions. When a process calls one of the exec functions, that process is completely replaced by the new program, and the new program starts executing at its main function. The process ID does not change across an exec , because a new process is not created; exec merely replaces the current processits text, data, heap, and stack segmentswith a brand new program from disk.


```shell
grep getrlimit /usr/share/man/*/*
```
## 8.12. Interpreter Files
All contemporary UNIX systems support interpreter files. These files are text files that begin with a line of the form
#! pathname [ optional-argument ]

The space between the exclamation point and the pathname is optional. The most common of these interpreter files begin with the line
#!/bin/sh

## 8.13. system Function

It is convenient to execute a command string from within a program. For example, assume that we want to put a time-and-date stamp into a certain file. We could use the functions we describe in Section 6.10 to do this: call time to get the current calendar time, then call localtime to convert it to a broken-down time, and then call strftime to format the result, and write the results to the file. It is much easier, however, to say
system("date > file");



Figure 8.14. Differences among the six exec functions


To get around the limitation in argument list size, we can use the xargs (1) command to break up long argument lists. To look for all the occurrences of geTRlimit in the man pages on our system, we could use

```shell
find /usr/share/man -type f -print | xargs grep getrlimit
```

If the man pages on our system are compressed, however, we could try
find /usr/share/man -type f -print | xargs bzgrep getrlimit


```c
#include <unistd.h>
int execl(const char * pathname , const char * arg0 ,
... /* (char *)0 */ );
int execv(const char * pathname , char *const argv []);
int execle(const char * pathname , const char * arg0 , ...
/* (char *)0, char *const envp [] */ );
int execve(const char * pathname , char *const
argv [], char *const envp []);
int execlp(const char * filename , const char * arg0 ,
... /* (char *)0 */ );
int execvp(const char * filename , char *const argv []);

			All six return: 1 on error, no return on success
```


The first difference in these functions is that the first four take a pathname argument, whereas the **last two take a filename argument**.

When a filename argument is specified
- If filename contains a slash, it is taken as a pathname.
- Otherwise, the executable file is searched for in the directories specified by the PATH environment variable.
The PATH variable contains a list of directories, called path prefixes, that are separated by colons. For example, the
name=value



We've mentioned that the process ID does not change after an exec , but the new program inherits additional properties from the calling process:

- Process ID and parent process ID
- Real user ID and real group ID
- Supplementary group IDs
- Process group ID
- Session ID
- Controlling terminal
- Time left until alarm clock
- Current working directoryRoot directory
- File mode creation mask
- File locks
- Process signal mask
- Pending signals
- Resource limits
- Values for tms_utime , tms_stime , tms_cutime , and tms_cstime

### Figure 8.15. Relationship of the six exec functions（图）



## 8.11. Changing User IDs and Group IDs
In the UNIX System, privileges, such as being able to change the system's notion of the current date, and access control, such as being able to read or write a particular file, are based on user and group IDs. When our programs need additional privileges or need to gain access to resources that they currently aren't allowed to access, they need to change their user or group ID to an ID that has the appropriate privilege or access.

### Figure 8.18. Ways to change the three user IDs（表格）





## 8.14. Process Accounting

Most UNIX systems provide an option to do process accounting. When enabled, the kernel writes an accounting record each time a process terminates.

Figure 8.26. Values for ac_flag from accounting record

The structure of the accounting records is defined in the header <sys/acct.h> and looks something like
```c
typedef u_short comp_t; /* 3-bit base 8 exponent; 13-bit fraction */

struct acct
{
    char ac_flag;     /* flag (see Figure 8.26) */
    char ac_stat;     /* termination status (signal & core flag only) */
    /* (Solaris only) */
    uid_t ac_uid;     /* real user ID */
    gid_t ac_gid;     /* real group ID */
    dev_t ac_tty;     /* controlling terminal */
    time_t ac_btime;  /* starting calendar time */
    comp_t ac_utime;  /* user CPU time (clock ticks) */
    comp_t ac_stime;  /* system CPU time (clock ticks) */
    comp_t ac_etime;  /* elapsed time (clock ticks) */
    comp_t ac_mem;    /* average memory usage */
    comp_t ac_io;     /* bytes transferred (by read and write) */
    /* "blocks" on BSD systems */
    comp_t ac_rw;     /* blocks read or written */

    /* (not present on BSD systems) */
    char ac_comm[8]; /* command name: [8] for Solaris, */
    /* [10] for Mac OS X, [16] for FreeBSD, and */
    /* [17] for Linux */
};
```


Figure 8.27. Process structure for accounting example(图)



Figure 8.28. Program to generate accounting data



## 8.15. User Identification


## 8.16. Process Times
In Section 1.10, we described three times that we can measure: wall clock time, user CPU time, and system CPU time. Any process can call the times function to obtain these values for itself and any terminated children.

```
NAME
       getlogin, getlogin_r, cuserid - get username

SYNOPSIS
       #include <unistd.h>
       char *getlogin(void);
       int getlogin_r(char *buf, size_t bufsize);

       #include <stdio.h>
       char *cuserid(char *string);

RETURN VALUE
       getlogin()  returns  a  pointer to the username when successful, and NULL on failure, with errno set to indicate the cause of the error.  getlogin_r() returns 0 when successful, and nonzero on failure
```



## 9 Process Relationships

本章自修，全是图，没什么代码。

We learned in the previous chapter that there are relationships between processes. First, every process has a parent process (the initial kernel-level process is usually its ownparent). The parent is notified when the child terminates, and the parent can obtain the child’s exit status. We also mentioned process groups when we described the waitpid function (Section 8.6) and explained how we can wait for any process in a process group to terminate.

In this chapter, we’ll look at process groups in more detail and the concept of
sessions that was introduced by POSIX.1. We’ll also look at the relationship between the login shell that is invoked for us when we log in and all the processes that we start from our login shell.  

It is impossible to describe these relationships without talking about signals, and to talk about signals, we need many of the concepts in this chapter. If you are unfamiliar with the UNIX System signal mechanism, you may want to skim through Chapter 10 at this point.



## 9.4 Process Groups
In addition to having a process ID, each process belongs to a process group. We’ll
encounter process groups again when we discuss signals in Chapter 10.



## 9.5 Sessions
A session is a collection of one or more process groups. For example, we could have the arrangement shown in Figure 9.6. Here we have three process groups in a single session.



## 10 Signals

## 10.1 Introduction
**Signals are software interrupts**. 
Most nontrivial application programs need to deal with signals. Signals provide a way of handling asynchronous events—for example, a user at a terminal typing the interrupt key to stop a program or the next program in a pipeline terminating prematurely.


In this chapter, we start with an overview of signals and a description of what each signal is normally used for. Then we look at the problems with earlier implementations.

## 10.2 Signal Concepts
First, every signal has a name. These names all begin with the three characters SIG. For example, SIGABRT is the abort signal that is generated when a process calls the abort function. SIGALRM is the alarm signal that is generated when the timer set by the alarm function goes off.

Signal names are all defined by positive integer constants (the signal number) in the header <signal.h>.

No signal has a signal number of 0. We’ll see in Section 10.9 that the kill function uses the signal number of 0 for a special case. POSIX.1 calls this value the null signal.


• The terminal-generated signals occur when users press certain terminal keys. Pressing the DELETE key on the terminal (or Control-C on many systems) normally causes the interrupt signal (SIGINT) to be generated. This is how to stop a runaway program. (We’ll see in Chapter 18 how this signal can be mapped to any character on the terminal.)

• Hardware exceptions generate signals: divide by 0, invalid memory reference, and the like. These conditions are usually detected by the hardware, and the kernel is notified. The kernel then generates the appropriate signal for the process that was running at the time the condition occurred. For example, SIGSEGV is generated for a process that executes an invalid memory reference.

• The kill(2) function allows a process to send any signal to another process or process group. Naturally, there are limitations: we have to be the owner of the process that we’re sending the signal to, or we have to be the superuser.

• The kill(1) command allows us to send signals to other processes. This program is just an interface to the kill function. This command is often used to terminate a runaway background process.

• Software conditions can generate signals when a process should be notified of various events. These aren’t hardware-generated conditions (as is the divide- by-0 condition), but software conditions. Examples are SIGURG (generated when out-of-band data arrives over a network connection), SIGPIPE (generated when a process writes to a pipe that has no reader), and SIGALRM (generated when an alarm clock set by the process expires).

Signals are classic examples of asynchronous events. They occur at what appear to be random times to the process. The process can’t simply test a variable (such as errno) to see whether a signal has occurred; instead, the process has to tell the kernel ‘‘if and when this signal occurs, do the following.’’

We can tell the kernel to do one of three things when a signal occurs. We call this the disposition of the signal, or the action associated with a signal.
1. Ignore the signal. This works for most signals, but two signals can never be ignored: SIGKILL and SIGSTOP. The reason these two signals can’t be ignored is to provide the kernel and the superuser with a surefire way of either killing or stopping any process. Also, if we ignore some of the signals that are generated by a hardware exception (such as illegal memory reference or divide by 0), the behavior of the process is undefined.

2. Catch the signal. To do this, we tell the kernel to call a function of ours whenever the signal occurs. In our function, we can do whatever we want to handle the condition. If we’re writing a command interpreter, for example, when the user generates the interrupt signal at the keyboard, we probably want to return to the main loop of the program, terminating whatever command we were executing for the user. If the SIGCHLD signal is caught, it means that a child process has terminated, so the signal-catching function can call waitpid to fetch the child’s process ID and termination status. As another example, if the process has created temporary files, we may want to write a signal-catching function for the SIGTERM signal (the termination signal that is the default signal sent by the kill command) to clean up the temporary files. Note that the two signals SIGKILL and SIGSTOP can’t be caught.

3. Let the default action apply. Every signal has a default action, shown in Figure 10.1. Note that the default action for most signals is to terminate the process.


### Figure 10.1 UNIX System signals(表)

## 10.3 signal Function
The simplest interface to the signal features of the UNIX System is the signal function.
#include <signal.h>
void (*signal(int signo, void (*func)(int)))(int);
Returns: previous disposition of signal (see following) if OK, SIG_ERR on error

```C
NAME
       signal - ANSI C signal handling

SYNOPSIS
       #include <signal.h>

       typedef void (*sighandler_t)(int);
    
       sighandler_t signal(int signum, sighandler_t handler);
```

## 10.4 Unreliable Signals
In earlier versions of the UNIX System (such as Version 7), signals were unreliable. By this we mean that signals could get lost: a signal could occur and the process would never know about it.

Figure 10.4 Reentrant functions that may be called from a signal handler



Figure 10.3 Features provided by various signal implementations(表格)



## 10.7 SIGCLD Semantics
Two signals that continually generate confusion are SIGCLD and SIGCHLD.



Figure 10.6 System V SIGCLD handler that doesn’t work

## 10.8 Reliable-Signal Terminology and Semantics

We need to define some of the terms used throughout our discussion of signals. First, a signal is generated for a process (or sent to a process) when the event that causes the signal occurs. The event could be a hardware exception (e.g., divide by 0), a software condition (e.g., an alarm timer expiring), a terminal-generated signal, or a call to the kill function. When the signal is generated, the kernel usually sets a flag of some form in the process table.

## 10.9 kill and raise Functions
The kill function sends a signal to a process or a group of processes. The raise function allows a process to send a signal to itself.

```c
#include <signal.h>
int kill(pid_t pid, int signo);
int raise(int signo);
// Both return: 0 if OK, −1 on error

The call
	raise(signo);
is equivalent to the call
	kill(getpid(), signo);
```

There are four different conditions for the pid argument to kill.

| pid       |                                                              |
| --------- | ------------------------------------------------------------ |
| pid > 0   | The signal is sent to the process whose process ID is pid.   |
| pid == 0  | The signal is sent to all processes whose process group ID equals the process group ID of the sender and for which the sender has permission to send the signal. Note that the term all processes excludes an implementation-defined set of system processes. For most UNIX ystems, this set of system processes includes the kernel processes and init (pid 1). |
| pid < 0   | The signal is sent to all processes whose process group ID equals the absolute value of pid and for which the sender has permission to send the signal. Again, the set of all processes excludes certain system processes, as described earlier. |
| pid == −1 | The signal is sent to all processes on the system for which the sender has permission to send the signal. As before, the set of processes excludes certain system processes. |



## 10.10 alarm and pause Functions

The alarm function allows us to set a timer that will expire at a specified time in the future. When the timer expires, the SIGALRM signal is generated. If we ignore or don’t catch this signal, its default action is to terminate the process. 

```c
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
// Returns: 0 or number of seconds until previously set alarm
```
The seconds value is the number of clock seconds in the future when the signal should be generated. When that time occurs, the signal is generated by the kernel, although additional time could elapse before the process gets control to handle the signal, because of processor scheduling delays.


The pause function suspends the calling process until a signal is caught.
```c
#include <unistd.h>
int pause(void);
// Returns: −1 with errno set to EINTR
```


Figure 10.7 Simple, incomplete implementation of sleep

This function looks like the sleep function, which we describe in Section 10.19, but this simple implementation has three problems.
1. If the caller already has an alarm set, that alarm is erased by the first call to alarm. We can correct this by looking at alarm’s return value. If the number of seconds until some previously set alarm is less than the argument, then we should wait only until the existing alarm expires. If the previously set alarm will go off after ours, then before returning we should reset this alarm to occur at its designated time in the future.

2. We have modified the disposition for SIGALRM. If we’re writing a function for others to call, we should save the disposition when our function is called and restore it when we’re done. We can correct this by saving the return value from signal and resetting the disposition before our function returns.

3. There is a race condition between the first call to alarm and the call to pause. On a busy system, it’s possible for the alarm to go off and the signal handler to be called before we call pause. If that happens, the caller is suspended forever in the call to pause (assuming that some other signal isn’t caught).

## 10.11 Signal Sets
We need a data type to represent multiple signals—a signal set. We’ll use this data type with such functions as sigprocmask (in the next section) to tell the kernel not to allow any of the signals in the set to occur.


If the implementation has fewer signals than bits in an integer, a signal set can be implemented using one bit per signal. For the remainder of this section, assume that an implementation has 31 signals and 32-bit integers.

## 10.12 sigprocmask Function
Recall from Section 10.8 that the signal mask of a process is the set of signals currently blocked from delivery to that process. A process can examine its signal mask, change its signal mask, or perform both operations in one step by calling the following function.


Figure 10.13 Ways to change the current signal mask using sigprocmask

```
NAME
       sigprocmask - examine and change blocked signals

SYNOPSIS
       #include <signal.h>

       int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       sigprocmask(): _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE

DESCRIPTION
       sigprocmask()  is  used to fetch and/or change the signal mask of the calling thread.  The
       signal mask is the set of signals whose delivery is currently blocked for the caller  (see
       also signal(7) for more details).

       The behavior of the call is dependent on the value of how, as follows.
    
       SIG_BLOCK
              The set of blocked signals is the union of the current set and the set argument.
    
       SIG_UNBLOCK
              The signals in set are removed from the current set of blocked signals.  It is per‐
              missible to attempt to unblock a signal which is not blocked.
    
       SIG_SETMASK
              The set of blocked signals is set to the argument set.
    
       If oldset is non-NULL, the previous value of the signal mask is stored in oldset.
    
       If set is NULL, then the signal mask is unchanged (i.e., how is ignored), but the  current
       value of the signal mask is nevertheless returned in oldset (if it is not NULL).
    
       The  use  of  sigprocmask()  is  unspecified  in a multithreaded process; see pthread_sig‐
       mask(3).

RETURN VALUE
       sigprocmask() returns 0 on success and -1 on error.  In the event of an  error,  errno  is set to indicate the cause.
```

## 10.13 sigpending Function
The sigpending function returns the set of signals that are blocked from delivery and currently pending for the calling process. The set of signals is returned through the set argument.



## 10.14 sigaction Function
The sigaction function allows us to examine or modify (or both) the action associated with a particular signal. This function supersedes the signal function from earlier releases of the UNIX System.

#include <signal.h>
int sigaction(int signo, const struct sigaction *restrict act,
struct sigaction *restrict oact);
Returns: 0 if OK, −1 on error

Figure 10.17 siginfo_t code values（表格）


```shell
$ ./mask &
[1] 4603
starting main:
$ kill -USR1 4603
starting sig_usr1:  SIGUSR1
$ in sig_alrm:  SIGUSR1 SIGALRM
finishing sig_usr1:  SIGUSR1
ending main:
# just press Enter
[1]+  Done                    ./mask
```

10.16 sigsuspend Function
We have seen how we can change the signal mask for a process to block and unblock selected signals.



Figure 10.21 Timeline for example program handling two signals



The nanosleep function is similar to the sleep function, but provides nanosecond-level granularity.
```c
#include <time.h>
int nanosleep(const struct timespec *reqtp, struct timespec *remtp);
// Returns: 0 if slept for requested time or −1 on error
```

With the introduction of multiple system clocks (recall Section 6.10), we need a way to suspend the calling thread using a delay time relative to a particular clock. The clock_nanosleep function provides us with this capability.
```c
#include <time.h>
int clock_nanosleep(clockid_t clock_id, int flags,
const struct timespec *reqtp, struct timespec *remtp);
// Returns: 0 if slept for requested time or error number on failure
```

## 10.20 sigqueue Function
In Section 10.8 we said that most UNIX systems don’t queue signals. With the real-time extensions to POSIX.1, some systems began adding support for queueing signals. With SUSv4, the queued signal functionality has moved from the real-time extensions to the base specification.

To use queued signals we have to do the following:
1. Specify the SA_SIGINFO flag when we install a signal handler using the sigaction function. If we don’t specify this flag, the signal will be posted, but it is left up to the implementation whether the signal is queued.
2. Provide a signal handler in the sa_sigaction member of the sigaction structure instead of using the usual sa_handler field. Implementations might allow us to use the sa_handler field, but we won’t be able to obtain the extra information sent with the sigqueue function.
3. Use the sigqueue function to send signals.  
```c
#include <signal.h>
int sigqueue(pid_t pid, int signo, const union sigval value)
// Returns: 0 if OK, −1 on error
```

Figure 10.30 Behavior of queued signals on various platforms(表格)

## 10.21 Job-Control Signals
Of the signals shown in Figure 10.1, POSIX.1 considers six to be job-control signals:
SIGCHLD Child process has stopped or terminated.
SIGCONT Continue process, if stopped.
SIGSTOP Stop signal (can’t be caught or ignored).
SIGTSTP Interactive stop signal.
SIGTTIN Read from controlling terminal by background process group member.
SIGTTOU Write to controlling terminal by a background process group member.

## 10.22 Signal Names and Numbers
In this section, we describe how to map between signal numbers and names. Some systems provide the array
extern char *sys_siglist[];
The array index is the signal number, giving a pointer to the character string name of the signal.





## Threads
## 11.1 Introduction
We discussed processes in earlier chapters. We learned about the environment of a UNIX process, the relationships between processes, and ways to control processes. We saw that a limited amount of sharing can occur between related processes.
In this chapter, we’ll look inside a process further to see how we can use multiple threads of control (or simply threads) to perform multiple tasks within the environment of a single process. All threads within a single process have access to the same process components, such as file descriptors and memory.
Anytime you try to share a single resource among multiple users, you have to deal with consistency. We’ll conclude this chapter with a look at the synchronization mechanisms available to prevent multiple threads from viewing inconsistencies in their shared resources. 

## 11.2 Thread Concepts
A typical UNIX process can be thought of as having a single thread of control: each process is doing only one thing at a time. With multiple threads of control, we can design our programs to do more than one thing at a time within a single process, with each thread handling a separate task. This approach can have several benefits.
- We can simplify code that deals with asynchronous events by assigning a separate thread to handle each event type. Each thread can then handle its event using a synchronous programming model. A synchronous programming model
is much simpler than an asynchronous one.
- Multiple processes have to use complex mechanisms provided by the operating system to share memory and file descriptors, as we will see in Chapters 15 and 17. Threads, in contrast, automatically have access to the same memory address space and file descriptors.
- Some problems can be partitioned so that overall program throughput can be improved. A single-threaded process with multiple tasks to perform implicitly serializes those tasks, because there is only one thread of control. With multiple
threads of control, the processing of independent tasks can be interleaved by assigning a separate thread per task. Two tasks can be interleaved only if they don’t depend on the processing performed by each other.
- Similarly, interactive programs can realize improved response time by using multiple threads to separate the portions of the program that deal with user input and output from the other parts of the program.



## 11.3 Thread Identification
Just as every process has a process ID, every thread has a thread ID. Unlike the process ID, which is unique in the system, the thread ID has significance only within the context of the process to which it belongs.
Recall that a process ID, represented by the pid_t data type, is a non-negative integer. A thread ID is represented by the pthread_t data type. Implementations are allowed to use a structure to represent the pthread_t data type, so portable implementations can’t treat them as integers. Therefore, a function must be used to compare two thread IDs.
```c
#include <pthread.h>
int pthread_equal(pthread_t tid1, pthread_t tid2);
// Returns: nonzero if equal, 0 otherwise
```

A thread can obtain its own thread ID by calling the pthread_self function.
```c
#include <pthread.h>
pthread_t pthread_self(void);
// Returns: the thread ID of the calling thread
```
This function can be used with pthread_equal when a thread needs to identify data structures that are tagged with its thread ID.

### Figure 11.1 Work queue example(图    )

This example has two oddities, which are necessary to handle races between the main thread and the new thread. (We’ll learn better ways to deal with these conditions later in this chapter.) 

- The first is the need to sleep in the main thread. If it doesn’t sleep, the main thread might exit, thereby terminating the entire process before the new thread gets a chance to run. This behavior is dependent on the operating system’s threads implementation and scheduling algorithms.

## 11.5 Thread Termination
If any thread within a process calls exit, _Exit, or _exit, then the entire process terminates.

A single thread can exit in three ways, thereby stopping its flow of control, without terminating the entire process.
1. The thread can simply return from the start routine. The return value is the thread’s exit code.
2. The thread can be canceled by another thread in the same process.
3. The thread can call pthread_exit.



The program in Figure 11.4 shows the problem with using an automatic variablen(allocated on the stack) as the argument to pthread_exit.


As we can see, the contents of the structure (allocated on the stack of thread tid1) have changed by the time the main thread can access the structure. Note how the stack of the second thread (tid2) has overwritten the first thread’s stack. To solve this problem, we can either use a global structure or allocate the structure using malloc.


One thread can request that another in the same process be canceled by calling the pthread_cancel function.
#include <pthread.h>
int pthread_cancel(pthread_t tid);
Returns: 0 if OK, error number on failure

In the default circumstances, pthread_cancel will cause the thread specified by tid to behave as if it had called pthread_exit with an argument of PTHREAD_CANCELED.
However, a thread can elect to ignore or otherwise control how it is canceled. We will discuss this in detail in Section 12.7. Note that pthread_cancel doesn’t wait for the thread to terminate; it merely makes the request.

A thread can arrange for functions to be called when it exits, similar to the way that the atexit function (Section 7.3) can be used by a process to arrange that functions are to be called when the process exits. The functions are known as thread cleanup handlers.
More than one cleanup handler can be established for a thread. The handlers are recorded in a stack, which means that they are executed in the reverse order from that with which they were registered.
#include <pthread.h>
void pthread_cleanup_push(void (*rtn)(void *), void *arg);
void pthread_cleanup_pop(int execute);

The pthread_cleanup_push function schedules the cleanup function, rtn, to be called with the single argument, arg, when the thread performs one of the following actions:
- Makes a call to pthread_exit
- Responds to a cancellation request
- Makes a call to pthread_cleanup_pop with a nonzero execute argument



Figure 11.5 shows how to use thread cleanup handlers. Although the example is somewhat contrived, it illustrates the mechanics involved. Note that although we never intend to pass zero as an argument to the thread start-up routines, we still need to match calls to pthread_cleanup_pop with the calls to pthread_cleanup_push; otherwise, the program might not compile.



By now, you should begin to see similarities between the thread functions and the process functions. Figure 11.6 summarizes the similar functions.

Figure 11.6 Comparison of process and thread primitives

| Process primitive | Thread primitive     | Description                                                 |
| ----------------- | -------------------- | ----------------------------------------------------------- |
| fork              | pthread_create       | create a new flow of control                                |
| exit              | pthread_exit         | exit from an existing flow of control                       |
| waitpid           | pthread_join         | get exit status from flow of control                        |
| atexit            | pthread_cleanup_push | register function to be called at exit from flow of control |
| getpid            | pthread_self         | get ID for flow of control                                  |
| abort             | pthread_cancel       | request abnormal termination of flow of control             |


### 11.6.4 Reader–Writer Locks
Reader–writer locks are similar to mutexes, except that they allow for higher degrees of parallelism. With a mutex, the state is either locked or unlocked, and only one thread can lock it at a time. Three states are possible with a reader–writer lock: locked in read mode, locked in write mode, and unlocked. Only one thread at a time can hold a reader–writer lock in write mode, but multiple threads can hold a reader–writer lock in read mode at the same time.


As with mutexes, reader–writer locks must be initialized before use and destroyed before freeing their underlying memory.
```c
#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
const pthread_rwlockattr_t *restrict attr);
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
// Both return: 0 if OK, error number on failure
```

To lock a reader–writer lock in read mode, we call pthread_rwlock_rdlock. To write lock a reader–writer lock, we call pthread_rwlock_wrlock. Regardless of how we lock a reader–writer lock, we can unlock it by calling pthread_rwlock_unlock.
```c
#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
// All return: 0 if OK, error number on failure
```

### 11.6.5 Reader–Writer Locking with Timeouts
Just as with mutexes, the Single UNIX Specification provides functions to lock reader–writer locks with a timeout to give applications a way to avoid blocking indefinitely while trying to acquire a reader–writer lock. These functions are pthread_rwlock_timedrdlock and pthread_rwlock_timedwrlock.
```c
#include <pthread.h>
#include <time.h>
int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict tsptr);
int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict tsptr);
// Both return: 0 if OK, error number on failure
```

### 11.6.6 Condition Variables
Condition variables are another synchronization mechanism available to threads. These synchronization objects provide a place for threads to rendezvous. When used with mutexes, condition variables allow threads to wait in a race-free way for arbitrary conditions to occur.



### 11.6.3 pthread_mutex_timedlock Function
One additional mutex primitive allows us to bound the time that a thread blocks when a mutex it is trying to acquire is already locked. The pthread_mutex_timedlock function is equivalent to pthread_mutex_lock, but if the timeout value is reached, pthread_mutex_timedlock will return the error code ETIMEDOUT without locking the mutex.
```c
#include <pthread.h>
#include <time.h>
int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,
const struct timespec *restrict tsptr);
// Returns: 0 if OK, error number on failure
```

### 11.6.4 Reader–Writer Locks
Reader–writer locks are similar to mutexes, except that they allow for higher degrees of parallelism. With a mutex, the state is either locked or unlocked, and only one thread can lock it at a time. Three states are possible with a reader–writer lock: locked in read mode, locked in write mode, and unlocked. Only one thread at a time can hold a reader–writer lock in write mode, but multiple threads can hold a reader–writer lock in read mode at the same time.

As with mutexes, reader–writer locks must be initialized before use and destroyed before freeing their underlying memory.
```c
#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
const pthread_rwlockattr_t *restrict attr);

int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
// Both return: 0 if OK, error number on failure
```

### 11.6.7 Spin Locks
A spin lock is like a mutex, except that instead of blocking a process by sleeping, the process is blocked by busy-waiting (spinning) until the lock can be acquired. A spin lock could be used in situations where locks are held for short periods of times and threads don’t want to incur the cost of being descheduled.

### 11.6.8 Barriers
Barriers are a synchronization mechanism that can be used to coordinate multiple threads working in parallel. A barrier allows each thread to wait until all cooperating threads have reached the same point, and then continue executing from there. We’ve already seen one form of barrier—the pthread_join function acts as a barrier to allow one thread to wait until another thread exits.

## 11.7 Summary
In this chapter, we introduced the concept of threads and discussed the POSIX.1 primitives available to create and destroy them. We also introduced the problem of thread synchronization.
We discussed five fundamental synchronization mechanisms — mutexes, reader–writer locks, condition variables, spin locks, and barriers — and we saw how to use them to protect shared resources.



## Thread Control
### 12.1 Introduction

In Chapter 11, we learned the basics about threads and thread synchronization. In this chapter, we will learn the details of controlling thread behavior. We will look at thread attributes and synchronization primitive attributes, which we ignored in the previous chapter in favor of the default  behavior.
We will follow this with a look at how threads can keep data private from other threads in the same process. Then we will wrap up the chapter with a look at how some process-based system calls interact with threads.



### 12.2 Thread Limits
We discussed the sysconf function in Section 2.5.4. The Single UNIX Specification defines several limits associated with the operation of threads, which we didn’t show in Figure 2.11. As with other system limits, the thread limits can be queried using sysconf. Figure 12.1 summarizes these limits.

As with the other limits reported by sysconf, use of these limits is intended to promote application portability among different operating system implementations. For example, if your application requires that you create four threads for every file you manage, you might have to limit the number of files you can manage concurrently if the system won’t let you create enough threads.

We can manage the stack attributes using the pthread_attr_getstack and pthread_attr_setstack functions.
```c
#include <pthread.h>
int pthread_attr_getstack(const pthread_attr_t *restrict attr,
void **restrict stackaddr,
size_t *restrict stacksize);
int pthread_attr_setstack(pthread_attr_t *attr,
					void *stackaddr, size_t stacksize);
// Both return: 0 if OK, error number on failure
```

If we know that we don’t need the thread’s termination status at the time we create the thread, we can arrange for the thread to start out in the detached state by modifying the detachstate thread attribute in the pthread_attr_t structure. We can use the pthread_attr_setdetachstate function to set the detachstate thread attribute to one of two legal values: PTHREAD_CREATE_DETACHED to start the thread in the detached state or PTHREAD_CREATE_JOINABLE to start the thread normally, so its termination status can be retrieved by the application.
```c
#include <pthread.h>
int pthread_attr_getdetachstate(const pthread_attr_t 						*restrict attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int 									detachstate);
// Both return: 0 if OK, error number on failure
```

#### 12.4.1 Mutex Attributes
Mutex attributes are represented by a pthread_mutexattr_t structure. Whenever we initialized a mutex in Chapter 11, we accepted the default attributes by using the PTHREAD_MUTEX_INITIALIZER constant or by calling the pthread_mutex_init function with a null pointer for the argument that points to the mutex attribute structure.

### 12.6 Thread-Specific Data
Thread-specific data, also known as thread-private data, is a mechanism for storing and finding data associated with a particular thread. The reason we call the data thread-specific, or thread-private, is that we’d like each thread to access its own separate copy of the data, without worrying about synchronizing access with other threads.

Before allocating thread-specific data, we need to create a key to associate with the data. The key will be used to gain access to the thread-specific data. We use
pthread_key_create to create such a key.

```c
#include <pthread.h>
int pthread_key_create(pthread_key_t *keyp, void (*destructor)(void *));
// Returns: 0 if OK, error number on failure


// We can break the association of a key with the thread-specific data values for all threads by calling pthread_key_delete.

#include <pthread.h>
int pthread_key_delete(pthread_key_t key);
// Returns: 0 if OK, error number on failure
```
The key created is stored in the memory location pointed to by keyp. The same key can be used by all threads in the process, but each thread will associate a different thread-specific data address with the key. When the key is created, the data address for each thread is set to a null value.



#### Figure 12.2 Examples of thread configuration limits

| Limit                         | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |
| ----------------------------- | ----------- | ----------- | --------------- | ---------- |
| PTHREAD_DESTRUCTOR_ITERATIONS | 4           | 4           | 4               | no limit   |
| PTHREAD_KEYS_MAX              | 256         | 1024        | 512             | no limit   |
| PTHREAD_STACK_MIN             | 2048        | 16384       | 8192            | 8192       |
| PTHREAD_THREADS_MAX           | no limit    | no limit    | no limit        | no limit   |



#### Figure 12.9 Functions not guaranteed to be thread-safe by POSIX.1


| ------------- | ---------------- | ----------- | ---------------- |
| ------------- | ---------------- | ----------- | ---------------- |
| basename      | getchar_unlocked | getservent  | putc_unlocked    |
| catgets       | getdate          | getutxent   | putchar_unlocked |
| crypt         | getenv           | getutxid    | putenv           |
| dbm_clearerr  | getgrent         | getutxline  | pututxline       |
| dbm_close     | getgrgid         | gmtime      | rand             |
| dbm_delete    | getgrnam         | hcreate     | readdir          |
| dbm_error     | gethostent       | hdestroy    | setenv           |
| dbm_fetch     | getlogin         | hsearch     | setgrent         |
| dbm_firstkey  | getnetbyaddr     | inet_ntoa   | setkey           |
| dbm_nextkey   | getnetbyname     | l64a        | setpwent         |
| dbm_open      | getnetent        | lgamma      | setutxent        |
| dbm_store     | getopt           | lgammaf     | strerror         |
| dirname       | getprotobyname   | lgammal     | strsignal        |
| dlerror       | getprotobynumber | localeconv  | strtok           |
| drand48       | getprotoent      | localtime   | system           |
| encrypt       | getpwent         | lrand48     | ttyname          |
| endgrent      | getpwnam         | mrand48     | unsetenv         |
| endpwent      | getpwuid         | nftw        | wcstombs         |
| endutxent     | getservbyname    | nl_langinfo | wctomb           |
| getc_unlocked | getservbyport    | ptsname     |                  |







We could have used a reader–writer lock to allow multiple concurrent calls to getenv_r, but the added concurrency probably wouldn’t improve the performance of our program by very much, for two reasons. First, the environment list usually isn’t very long, so we won’t hold the mutex for too long while we scan the list. Second, calls to getenv and putenv are infrequent, so if we improve their performance, we won’t affect the overall performance of the program very much.


### 12.7 Cancel Options

Two thread attributes that are not included in the pthread_attr_t structure are the cancelability state and the cancelability type. These attributes affect the behavior of a thread in response to a call to pthread_cancel (Section 11.5).
The cancelability state attribute can be either PTHREAD_CANCEL_ENABLE or PTHREAD_CANCEL_DISABLE. A thread can change its cancelability state by calling pthread_setcancelstate.

```c
#include <pthread.h>
int pthread_setcancelstate(int state, int *oldstate);
// Returns: 0 if OK, error number on failure
```



Figure 12.14 Cancellation points defined by POSIX.1



#### Figure 12.10 Alternative thread-safe functions

getgrgid_r
getgrnam_r
getlogin_r
getpwnam_r
getpwuid_r
gmtime_r
localtime_r
readdir_r
strerror_r
strtok_r
ttyname_r



Dealing with signals can be complicated even with a process-based paradigm. Introducing threads into the picture makes things even more complicated.
Each thread has its own signal mask, but the signal disposition is shared by all threads in the process. As a consequence, individual threads can block signals, but when a thread modifies the action associated with a given signal, all threads share the action. Thus, if one thread chooses to ignore a given signal, another thread can undo that choice by restoring the default disposition or installing a signal handler for that signal.
Signals are delivered to a single thread in the process. If the signal is related to a hardware fault, the signal is usually sent to the thread whose action caused the event. Other signals, on the other hand, are delivered to an arbitrary thread.


For example, assume that module A calls functions from module B and that each module has its own set of locks. If the locking hierarchy is A before B, module B must install its fork handlers before module A. When the parent calls fork, the following steps are taken, assuming that the child process runs before the parent:
1. The prepare fork handler from module A is called to acquire all of module A’s locks.
2. The prepare fork handler from module B is called to acquire all of module B’s locks.
3. A child process is created.
4. The child fork handler from module B is called to release all of module B’s locks in the child process.
5. The child fork handler from module A is called to release all of module A’s locks in the child process.
6. The fork function returns to the child.
7. The parent fork handler from module B is called to release all of module B’s locks in the parent process.
8. The parent fork handler from module A is called to release all of module A’s locks in the parent process.
9. The fork function returns to the parent.

### 12.11 Summary
Threads provide an alternative model for partitioning concurrent tasks in UNIX systems. They promote sharing among separate threads of control, but present unique synchronization problems. In this chapter, we looked at how we can fine-tune our threads and their synchronization primitives. We discussed reentrancy with threads. We also looked at how threads interact with some of the process-oriented system calls.



13.1 Introduction

Daemons are processes that live for a long time. They are often started when the system is bootstrapped and terminate only when the system is shut down. Because they don’t have a controlling terminal, we say that they run in the background. UNIX systems have numerous daemons that perform day-to-day activities.

In this chapter, we look at the process structure of daemons and explore how to write a daemon. Since a daemon does not have a controlling terminal, we need to see how a daemon can report error conditions when something goes wrong.



13.3  Coding Rules

Some basic rules to coding a daemon prevent unwanted interactions from happening. We state these rules here and then show a function, daemonize, that implements them.

1. **Call umask to set the file mode creation mask to a known value, usually 0**. The inherited file mode creation mask could be set to deny certain permissions. If the daemon process creates files, it may want to set specific permissions. For example, if it creates files with group-read and group-write enabled, a file mode creation mask that turns off either of these permissions would undo its efforts.On the other hand, if the daemon calls library functions that result in files being created, then it might make sense to set the file mode create mask to a more restrictive value (such as 007), since the library functions might not allow the caller to specify the permissions through an explicit argument.

2. **Call fork and have the parent exit**. This does several things. First, if the daemon was started as a simple shell command, having the parent terminate makes the shell think that the command is done. Second, the child inherits the process group ID of the parent but gets a new process ID, so we’re guaranteed that the child is not a process group leader. This is a prerequisite for the call to setsid that is done next.
3. **Call setsid to create a new session**. The three steps listed in Section 9.5 occur. The process (a) becomes the leader of a new session, (b) becomes the leader of a new process group, and (c) is disassociated from its controlling terminal.

4. **Change the current working directory to the root directory**. The current working directory inherited from the parent could be on a mounted file system. Since daemons normally exist until the system is rebooted, if the daemon stays on a mounted file system, that file system cannot be unmounted. 
Alternatively, some daemons might change the current working directory to a specific location where they will do all their work. For example, a line printer spooling daemon might change its working directory to its spool directory.

5. Unneeded file descriptors should be closed. This prevents the daemon from holding open any descriptors that it may have inherited from its parent (which could be a shell or some other process). We can use our open_max function (Figure 2.17) or the getrlimit function (Section 7.11) to determine the highest descriptor and close all descriptors up to that value.

6. Some daemons open file descriptors 0, 1, and 2 to /dev/null so that any library routines that try to read from standard input or write to standard output or standard error will have no effect. Since the daemon is not associated with a terminal device, there is nowhere for output to be displayed, nor is there anywhere to receive input from an interactive user. Even if the daemon was started from an interactive session, the daemon runs in the background, and the login session can terminate without affecting the daemon. If other users log in on the same terminal device, we wouldn’t want output from the daemon showing up on the terminal, and the users wouldn’t expect their input to be read by the daemon.


Figure 13.2 The BSD syslog facility

One problem a daemon has is how to handle error messages. It can’t simply write to standard error, since it shouldn’t have a controlling terminal. We don’t want all the daemons writing to the console device, because on many workstations the console device runs a windowing system. We also don’t want each daemon writing its own error messages into a separate file. It would be a headache for anyone administering the system to keep up with which daemon writes to which log file and to check these files on a regular basis. A central daemon error-logging facility is required.



There are three ways to generate log messages:

1. Kernel routines can call the log function. These messages can be read by any user process that opens and reads the /dev/klog device. We won’t describe this function any further, since we’re not interested in writing kernel routines.
2. Most user processes (daemons) call the syslog(3) function to generate log messages. We describe its calling sequence later. This causes the message to be sent to the UNIX domain datagram socket /dev/log.
3. A user process on this host, or on some other host that is connected to this host by a TCP/IP network, can send log messages to UDP port 514. Note that the syslog function never generates these UDP datagrams: they require explicit network programming by the process generating the log message.



Our interface to this facility is through the syslog function.
#include <syslog.h>
void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);
void closelog(void);
int setlogmask(int maskpri);
Returns: previous log priority mask value


Figure 13.3 The option argument for openlog(表格)

Figure 13.4 The facility argument for openlog（表格）

Figure 13.5 The syslog levels (ordered)（表格）