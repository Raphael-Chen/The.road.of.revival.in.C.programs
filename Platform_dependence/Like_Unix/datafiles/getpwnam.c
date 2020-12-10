#include <pwd.h>
#include <stddef.h>
#include <string.h>


// Figure 6.2. The getpwnam function
// Figure 6.2 shows an implementation of the function getpwnam.
// The call to setpwent at the beginning is self-defense: we ensure that the files are rewound, 
// in case the caller has already opened them by calling getpwent . The call to endpwent when 
// we're done is because neither getpwnam nor getpwuid should leave any of the files open.

struct passwd * getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break; /* found a match */
    endpwent();


    return (ptr); /* ptr is NULL if no match found */
}

/*************
NAME
       getpwent, setpwent, endpwent - get password file entry

SYNOPSIS
       #include <sys/types.h>
       #include <pwd.h>

       struct passwd *getpwent(void);

       void setpwent(void);

       void endpwent(void);
***************/

//  The passwd structure is defined in <pwd.h> as follows:

// struct passwd {
//     char   *pw_name;       /* username */
//     char   *pw_passwd;     /* user password */
//     uid_t   pw_uid;        /* user ID */
//     gid_t   pw_gid;        /* group ID */
//     char   *pw_gecos;      /* user information */
//     char   *pw_dir;        /* home directory */
//     char   *pw_shell;      /* shell program */
// };
