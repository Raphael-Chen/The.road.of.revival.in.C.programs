#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>

// Figure 17.5 Binding an address to a UNIX domain socket
// The program in Figure 17.5 shows an example of binding an
//  address to a UNIX domain socket.

int main(void)
{
    int fd, size;
    struct sockaddr_un un;

    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, "foo.socket");

    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if ( fd < 0 )
        err_sys("socket failed");

    size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    if (bind(fd, (struct sockaddr *)&un, size) < 0)
        err_sys("bind failed");

    printf("UNIX domain socket bound\n");


    exit(0);
}


// $ ./bindunix
// UNIX domain socket bound
// $ ls
// bindunix    foo.socket  open   opend.fe  pollmsg    recvfd2.c  sendfd2.c  sendmsg
// bindunix.c  Makefile    opend  open.fe   pollmsg.c  recvfd2.o  sendfd2.o  sendmsg.c
// $ ls -l foo.socket
// srwxr-xr-x 1 user user 0 Mar  2 17:03 foo.socket
// $ ./bindunix
// bind failed: Address already in use
// $ rm foo.socket
// $ ./bindunix
// UNIX domain socket bound
