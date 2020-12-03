#include "apue.h"

// Figure 5.12. Demonstrate tmpnam and tmpfile functions
// warning: the use of `tmpnam' is dangerous, better use `mkstemp'

int main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf("%s\n", tmpnam(NULL)); /* first temp name */

    tmpnam(name);                 /* second temp name */
    printf("%s\n", name);



    if ((fp = tmpfile()) == NULL) /* create temp file */
        err_sys("tmpfile error");
        
    fputs("one line of output\n", fp); /* write to temp file */
    rewind(fp);                        /* then read it back */

    if (fgets(line, sizeof(line), fp) == NULL)
        err_sys("fgets error");
    fputs(line, stdout);               /* print the line we wrote */

    exit(0);
}


/*******************
NAME
       tmpfile - create a temporary file

SYNOPSIS
       #include <stdio.h>

       FILE *tmpfile(void);

DESCRIPTION
       The tmpfile() function opens a unique temporary file in binary read/write (w+b) mode.  The
       file will be automatically deleted when it is closed or the program terminates.

RETURN VALUE
       The tmpfile() function returns a stream descriptor, or NULL if a unique filename cannot be
       generated  or the unique file cannot be opened.  In the latter case, errno is set to indi‐
       cate the error.

NAME
       tmpnam, tmpnam_r - create a name for a temporary file

SYNOPSIS
       #include <stdio.h>

       char *tmpnam(char *s);

DESCRIPTION
       The  tmpnam()  function  returns  a pointer to a string that is a valid filename, and such
       that a file with this name did not exist at some point in time, so that naive  programmers
       may think it a suitable name for a temporary file.  If the argument s is NULL this name is
       generated in an internal static buffer and may be overwritten by the  next  call  to  tmp‐
       nam().   If  s  is not NULL, the name is copied to the character array (of length at least
       L_tmpnam) pointed to by s and the value s is returned in case of success.

       The pathname that is created,  has  a  directory  prefix  P_tmpdir.   (Both  L_tmpnam  and
       P_tmpdir are defined in <stdio.h>, just like the TMP_MAX mentioned below.)

RETURN VALUE
       The  tmpnam()  function  returns  a  pointer  to a unique temporary filename, or NULL if a
       unique name cannot be generated.
*****************/