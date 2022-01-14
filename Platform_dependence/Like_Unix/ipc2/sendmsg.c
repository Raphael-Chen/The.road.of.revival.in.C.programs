#include "apue.h"
#include <sys/msg.h>

// Figure 17.4 Post a message to an XSI message queue
// Well use the program shown in Figure 17.4 to send messages to our test program
// from Figure 17.3.

#define MAXMSZ 512

struct mymesg
{
    long mtype;
    char mtext[MAXMSZ];
};

int main(int argc, char *argv[])
{
    key_t key;
    long qid;
    size_t nbytes;
    struct mymesg m;

    if (argc != 3)
    {
        fprintf(stderr, "usage: sendmsg KEY message\n");
        exit(1);
    }
    key = strtol(argv[1], NULL, 0);
    if ((qid = msgget(key, 0)) < 0)
        err_sys("can't open queue key %s", argv[1]);

    memset(&m, 0, sizeof(m));
    strncpy(m.mtext, argv[2], MAXMSZ - 1);
    nbytes = strlen(m.mtext);
    m.mtype = 1;

    if (msgsnd(qid, &m, nbytes, 0) < 0)
        err_sys("can't send message");

    exit(0);
}


// $ ./pollmsg &
// [1] 5659
// $ queue ID 0 is 0
// queue ID 1 is 32769
// queue ID 2 is 65538
//
// $ ./sendmsg 0x123 "hello, world"
// queue id 0, message hello, world
// $ ./sendmsg 0x124 "just a test"
// queue id 32769, message just a test
// $ ./sendmsg 0x125 "Bye"
// queue id 65538, message Bye
// $
// $ fg
// ./pollmsg
// ^Z
// [1]+  Stopped                 ./pollmsg
// $ ./sendmsg 0x125 "Bye"
// $ ./sendmsg 0x124 "just a test"
// $ fg
// ./pollmsg
// queue id 32769, message just a test
// queue id 65538, message Bye
