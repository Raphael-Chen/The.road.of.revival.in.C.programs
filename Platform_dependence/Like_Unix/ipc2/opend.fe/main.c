#include "opend.h"

char  errmsg[MAXLINE];
int   oflag;
char  *pathname;

// Figure 17.21 The server main function, version 1
// The main function (Figure 17.21) reads the requests from the client on the fd-pipe
// (its standard input) and calls the function handle_request.

int main(void)
{
    int  nread;
    char buf[MAXLINE];

    for (;;)  /* read arg buffer from client, process request */
    { 
        if ((nread = read(STDIN_FILENO, buf, MAXLINE)) < 0)
            err_sys("read error on stream pipe");
        else if (nread == 0)
            break; /* client has closed the stream pipe */

        handle_request(buf, nread, STDOUT_FILENO);
    }

    exit(0);
}
