#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process executing.\n");
        return 42;
    } else {
        // Parent process
        printf("Parent process waiting for the child to finish.\n");
        int status;
        pid_t terminatedChild = waitpid(pid, &status, 0);
        printf("Child process with PID %d has finished.\n", terminatedChild);

        if (WIFEXITED(status)) {
            printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child exited due to signal: %d\n", WTERMSIG(status));
        } else {
            printf("Child process did not exit normally.\n");
        }
    }

    return 0;
}
