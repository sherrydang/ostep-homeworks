#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        fprintf(stderr, "Failed to open the file.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        close(fd);
        return 1;
    } else if (pid == 0) {
        // Child process
        char* childMsg = "This is the child process writing to the file.\n";
        write(fd, childMsg, strlen(childMsg));
        printf("Child process wrote to the file.\n");
    } else {
        // Parent process
        char* parentMsg = "This is the parent process writing to the file.\n";
        write(fd, parentMsg, strlen(parentMsg));
        printf("Parent process wrote to the file.\n");
    }

    close(fd);

    return 0;
}
