#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    int i;

    for (i = 1; i <= 5; i++)
    {
        printf("Thread Executing : %d\n", i);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    // Create first thread
    pthread_create(&t1, NULL, thread_function, NULL);

    // Create second thread
    pthread_create(&t2, NULL, thread_function, NULL);

    // Wait for first thread
    pthread_join(t1, NULL);

    // Wait for second thread
    pthread_join(t2, NULL);

    printf("All Threads Completed\n");

    return 0;
}