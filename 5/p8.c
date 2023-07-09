#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // File descriptors for the pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe creation failed.\n");
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Fork failed for child process.\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close the read end of the pipe

        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        close(fd[1]); // Close the write end of the pipe

        printf("Hello from Child\n"); // Output to be sent to the parent

        return 0;
    }

    // Parent process
    close(fd[1]); // Close the write end of the pipe

    dup2(fd[0], STDIN_FILENO); // Redirect stdin to the read end of the pipe
    close(fd[0]); // Close the read end of the pipe

    char input[100];
    fgets(input, sizeof(input), stdin);
    printf("Parent received: %s", input); // Print the input received from the child

    // Wait for the child process to finish
    wait(NULL);

    return 0;
}
