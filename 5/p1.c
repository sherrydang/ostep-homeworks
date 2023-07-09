#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;

    pid_t pid = fork();

    if (pid == -1) {
        // Error occurred during fork
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child: x = %d\n", x);
        x = 200;  // Change the value of x in the child process
        printf("Child: Updated x = %d\n", x);
    } else {
        // Parent process
        printf("Parent: x = %d\n", x);
        x = 300;  // Change the value of x in the parent process
        printf("Parent: Updated x = %d\n", x);
    }

    return 0;
}
