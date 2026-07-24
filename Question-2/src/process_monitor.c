#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(void)
{
    printf("Web server process monitor started.\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process started: PID=%d\n", getpid());

        /* Simulate a long-running/unresponsive child */
        sleep(10);

        printf("Child process completed: PID=%d\n", getpid());
        return 0;
    }

    printf("Parent created child: PID=%d\n", pid);

    int status;

    /* Check child without blocking the parent */
    pid_t result = waitpid(pid, &status, WNOHANG);

    if (result == 0)
    {
        printf("Child process is still running.\n");
        printf("Waiting before terminating unresponsive child...\n");

        sleep(3);

        printf("Sending SIGTERM to child PID=%d\n", pid);

        if (kill(pid, SIGTERM) == -1)
        {
            perror("kill");
            return 1;
        }

        /* Reap terminated child to prevent zombie process */
        waitpid(pid, &status, 0);

        printf("Child process terminated and collected successfully.\n");
    }
    else if (result == pid)
    {
        printf("Child process finished and was collected.\n");
    }
    else
    {
        perror("waitpid");
        return 1;
    }

    return 0;
}