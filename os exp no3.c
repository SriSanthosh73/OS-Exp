#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0)
    {
        // Fork failed
        printf("Fork Failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        printf("\nCHILD PROCESS");
        printf("\nChild PID : %d", getpid());
        printf("\nParent PID : %d\n", getppid());

        exit(0);
    }
    else
    {
        // Parent process waits for child
        wait(NULL);

        printf("\nPARENT PROCESS");
        printf("\nParent PID : %d", getpid());
        printf("\nParent's Parent PID : %d\n", getppid());
    }

    return 0;
}