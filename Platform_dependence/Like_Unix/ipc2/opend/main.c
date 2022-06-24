#include "opend.h"
#include <syslog.h>

// Figure 17.28 The server main function, version 2
// The open server’s main function (Figure 17.28) defines the global variables,
// processes the command-line options, and calls the function loop. If we invoke the
// server with the -d option, the server runs interactively instead of as a daemon. This
// option is used when testing the server.

int      debug, oflag, client_size, log_to_stderr;
char     errmsg[MAXLINE];
char     *pathname;
Client   *client = NULL;

int main(int argc, char *argv[])
{
    int c;

    log_open("open.serv", LOG_PID, LOG_USER);

    opterr = 0;            /* don't want getopt() writing to stderr */
    while ((c = getopt(argc, argv, "d")) != EOF)
    {
        switch (c)
        {
            case 'd':      /* debug */
                debug = log_to_stderr = 1;
                break;

            case '?':
                err_quit("unrecognized option: -%c", optopt);
        }
    }

    if (debug == 0)
        daemonize("opend");

    loop();                /* never returns */
}
