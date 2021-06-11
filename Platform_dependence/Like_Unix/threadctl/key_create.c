#include <pthread.h>
#include <stdio.h>

pthread_key_t key;
pthread_t thid1;
pthread_t thid2;

void* thread2(void* arg)
{
    printf("thread2: %lu is running\n", pthread_self());
    
    int key_va = 3 ;

    pthread_setspecific(key, ( const void*)&key_va);
    
    // 返回相同的key，证明两个线程可以共享某些资源
    printf("thread2: %lu return %p\n", pthread_self(), pthread_getspecific(key));
    
    return NULL;
}


void* thread1(void* arg)
{
    printf("thread1: %lu is running\n", pthread_self());
    
    int key_va = 5;
    
    pthread_setspecific(key, (const void*)&key_va);

    pthread_create(&thid2, NULL, thread2, NULL);     //线程中再创建一个线程

    printf("thread1: %lu return %p\n", pthread_self(), pthread_getspecific(key));

    return NULL;
}


int main( void )
{
    printf("main thread:%lu is running\n", pthread_self());

    pthread_key_create(&key, NULL);

    pthread_create(&thid1, NULL, thread1, NULL);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);

    int key_va = 1;
    pthread_setspecific(key, (const void*)&key_va);
    
    printf("thread:%lu return %p\n", pthread_self(), pthread_getspecific(key));

    pthread_key_delete(key);
        
    printf("main thread exit\n");

    return 0;
}

