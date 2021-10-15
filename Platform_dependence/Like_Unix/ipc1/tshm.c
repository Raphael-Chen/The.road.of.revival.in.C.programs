#include "apue.h"
#include <sys/shm.h>

#define ARRAY_SIZE  40000
#define MALLOC_SIZE 100000
#define SHM_SIZE    100000
#define SHM_MODE    0600     /* user read/write */

char array[ARRAY_SIZE]; /* uninitialized data = bss */

// Figure 15.31 Print where various types of data are stored
// Figure 15.32 shows a picture of this, similar to what we said was a typical memory
// layout in Figure 7.6. Note that the shared memory segment is placed well below the
// stack.

int main(void)
{
    int shmid;
    char *ptr, *shmptr;

    printf("array[] from %p to %p\n", (void *)&array[0],
           (void *)&array[ARRAY_SIZE]);
    printf("stack around %p\n", (void *)&shmid);

    if ((ptr = malloc(MALLOC_SIZE)) == NULL)
        err_sys("malloc error");
    printf("malloced from %p to %p\n", (void *)ptr,
           (void *)ptr + MALLOC_SIZE);

    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)
        err_sys("shmget error");
    if ((shmptr = shmat(shmid, 0, 0)) == (void *)-1)
        err_sys("shmat error");
    printf("shared memory attached from %p to %p\n", (void *)shmptr,
           (void *)shmptr + SHM_SIZE);

    if (shmctl(shmid, IPC_RMID, 0) < 0)
        err_sys("shmctl error");

    exit(0);
}

// $ ./tshm
// array[] from 0x6020e0 to 0x60bd20
// stack around 0x7fff5fb1a96c
// malloced from 0xc2d010 to 0xc456b0
// shared memory attached from 0x7f8865f47000 to 0x7f8865f5f6a0
