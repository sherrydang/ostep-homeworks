#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("hello\n");
    } else {
        // Parent process
        sleep(1); // Sleep for 1 second to allow child process to print first
        printf("goodbye\n");
    }

    return 0;
}
