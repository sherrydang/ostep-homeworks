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
        char* args[] = { "/bin/ls", "-l", NULL };
        char *env[] = { "HOME=/home", "USER=testuser", NULL };
        // execl("/bin/ls", "ls", "-l", NULL);
        // execle("/bin/ls", "ls", "-l", NULL, env);
        // execlp("ls", "ls", "-l", NULL);
        // execv("/bin/ls", args);
        execvp("ls", args);
        // execvpe("ls", args, env);?


        // If execvp() is successful, this line will not be reached
        fprintf(stderr, "execvp() failed.\n");
        return 1;
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("Child process finished.\n");
    }

    return 0;
}
