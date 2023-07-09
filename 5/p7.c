#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(STDOUT_FILENO); // Close standard output
        printf("This will not be displayed\n"); // Attempt to print

        return 0;
    } else {
        // Parent process
        // Wait for the child to finish
        wait(NULL);
        printf("Child process has finished.\n");
    }

    return 0;
}
