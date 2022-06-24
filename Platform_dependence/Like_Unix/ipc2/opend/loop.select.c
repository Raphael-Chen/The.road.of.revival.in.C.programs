#include "opend.h"
#include <sys/select.h>

// Figure 17.29 The loop function using select

// The function loop is the server’s infinite loop. We’ll show two versions of this
// function. Figure 17.29 shows one version that uses select; Figure 17.30 shows another
// version that uses poll.

void loop(void)
{
    int     i, n, maxfd, maxi, listenfd, clifd, nread;
    char    buf[MAXLINE];
    uid_t   uid;
    fd_set  rset, allset;

    FD_ZERO(&allset);

    /* obtain fd to listen for client requests on */
    listenfd = serv_listen(CS_OPEN);
    if (listenfd < 0)
        log_sys("serv_listen error");

    FD_SET(listenfd, &allset);
    maxfd = listenfd;
    maxi = -1;

    for (;;)
    {
        rset = allset;             /* rset gets modified each time around */

        n = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (n < 0)
            log_sys("select error");

        if (FD_ISSET(listenfd, &rset))
        {
            /* accept new client request */
            clifd = serv_accept(listenfd, &uid);
            if (clifd < 0)
                log_sys("serv_accept error: %d", clifd);
            i = client_add(clifd, uid);
            FD_SET(clifd, &allset);

            if (clifd > maxfd)
                maxfd = clifd;       /* max fd for select() */
            if (i > maxi)
                maxi = i;            /* max index in client[] array */
            log_msg("new connection: uid %d, fd %d", uid, clifd);
            continue;
        }

        for (i = 0; i <= maxi; i++)
        { /* go through client[] array */
            clifd = client[i].fd;
            if (clifd < 0)
                continue;
                
            if (FD_ISSET(clifd, &rset))
            {
                /* read argument buffer from client */
                nread = read(clifd, buf, MAXLINE);
                if ( nread < 0)
                {
                    log_sys("read error on fd %d", clifd);
                }
                else if (nread == 0)
                {
                    log_msg("closed: uid %d, fd %d",
                            client[i].uid, clifd);
                    client_del(clifd);            /* client has closed cxn */
                    FD_CLR(clifd, &allset);
                    close(clifd);
                }
                else  /* process client's request */
                { 
                    handle_request(buf, nread, clifd, client[i].uid);
                }
            }
        }
    }
}
