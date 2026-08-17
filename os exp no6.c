#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main()
{
    sem_t *sem;

    // Create shared memory for semaphore
    sem = mmap(NULL,
               sizeof(sem_t),
               PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS,
               -1,
               0);

    if (sem == MAP_FAILED)
    {
        perror("mmap failed");
        return 1;
    }

    // Initialize semaphore
    // 1 = Shared between processes
    // 1 = Initial semaphore value
    sem_init(sem, 1, 1);

    // Create child process
    if (fork() == 0)
    {
        // Wait for semaphore
        sem_wait(sem);

        printf("Child Process Entering Critical Section\n");

        sleep(3);

        printf("Child Process Leaving Critical Section\n");

        // Release semaphore
        sem_post(sem);

        exit(0);
    }

    // Parent process
    sem_wait(sem);

    printf("Parent Process Entering Critical Section\n");

    sleep(3);

    printf("Parent Process Leaving Critical Section\n");

    // Release semaphore
    sem_post(sem);

    // Wait for child process
    wait(NULL);

    // Destroy semaphore
    sem_destroy(sem);

    // Unmap shared memory
    munmap(sem, sizeof(sem_t));

    return 0;
}