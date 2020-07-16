#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int acnt;
int cnt;

int f(void *thr_data)
{
    // __STDC_NO_ATOMICS__;
    for (int n = 0; n < 1000; ++n)
    {
        ++cnt;
        ++acnt;
        // for this example, relaxed memory order is sufficient, e.g.
        // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);
    }
    return 0;
}

int main(void)
{
    thrd_t thr[10];
    for (int n = 0; n < 10; ++n)
        thrd_create(&thr[n], f, NULL);
    for (int n = 0; n < 10; ++n)
        thrd_join(thr[n], NULL);

    printf("The atomic counter is %u\n", acnt);
    printf("The non-atomic counter is %u\n", cnt);

    return 0;
}
