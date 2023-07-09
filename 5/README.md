# 5. Interlude: Process API
link: https://pages.cs.wisc.edu/~remzi/Classes/537/Spring2018/Book/cpu-api.pdf

Q1.
- the fork() call creates a new process that is a copy of the parent, including the memory. 
- However, the memory spaces are separate, and any modifications to variables in parent process doesn't affect child's process

Q2.
- A file descriptor is a unique identifier that is used to access files or other input/output (I/O) resources, such as sockets or pipes. 
- e.g. int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
- Parent and child process both can access the file descriptor, the sequence is up to the os schedular

Q3.
- use sleep(1) in parent execution for the child process to finish

Q4
- e – An array of pointers to environment variables is explicitly passed to the new process image.
- l – Command-line arguments are passed individually (a list) to the function.
- p – Uses the PATH environment variable to find the file named in the file argument to be executed.
- v – Command-line arguments are passed to the function as an array (vector) of pointers.

Q5.
- Child process will return -1 when 'wait()' is used.

Q6.
- waitpid() is useful when you want to specify which child process to wait for.

Q7.
- the child process calls to close the standard output file descriptor (stdout). Then, call printf() won't print.
- the parent process still can print normally since the standard output is still open in the parent process.

Q8.
- The pipe consists of two file descriptors: fd[0] for reading and fd[1] for writing.
- In child, redirect the standard output (stdout) to the write end of the pipe (fd[1]) using dup2(). 
- In parent, redirect the standard input (stdin) to the read end of the pipe (fd[0]) using dup2().