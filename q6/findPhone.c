
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>      // pid_t
#include <sys/wait.h>       // wait()

#define FILENAME "phonebook.txt"
#define MAX_LINE_LENGTH 256     // 2^8

size_t strlen(const char* str){
    size_t len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}

int main (int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: findPhone <name>\n");
        exit(EXIT_FAILURE);
    }

    // vars to store pipe and process id
    int pipefd[2];
    pid_t pid;

    // create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // fork a child process - pipe is inherited
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {     // Child process
        // no need to read from the pipe - close read end
        close(pipefd[0]);

        // Deal with a full name - space separated
        size_t total_length = 0;
        for (int i = 1; i < argc; i++){
            total_length += strlen(argv[i]) + 1; // +1 for the space
        }

        // var to store the full name
        char full_name[total_length];
        size_t index = 0;
        for (int i = 1; i < argc; i++) {
            // copy each letter of the name to the full name
            char *arg = argv[i];
            while (*arg != '\0') {
                full_name[index++] = *arg++;
            }
            full_name[index++] = ' ';  // Add a space between words
        }

        full_name[index-1] = '\0';

        // redirect stdout to the write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            // close pipe completely
            close(pipefd[1]);
            exit(EXIT_FAILURE);
        }

        // grep command to find the the number in the phonebook
        // -i makes grep case insensitive
        if (execlp("grep", "grep", "-i", full_name, FILENAME, NULL) == -1){
            perror("execlp");
            // close pipe completely
            close(pipefd[1]);
            exit(EXIT_FAILURE);
        }

        // close pipe completely
        close(pipefd[1]);
    } 
    else {  // Parent process
        // no need to write to the pipe - close write end
        close(pipefd[1]);

        // vars to store data read from pipe
        char buffer[MAX_LINE_LENGTH];
        ssize_t nbytes;

        // read from the pipe and write to stdout
        while ((nbytes = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            // write and check for errors
            if (write(STDOUT_FILENO, buffer, nbytes) == -1) {
                perror("write");
                // close pipe completely
                close(pipefd[0]);
                exit(EXIT_FAILURE);
            }
        }
        // make sure it read correctly
        if (nbytes == -1) {
            perror("read");
            // close pipe completely
            close(pipefd[0]);
            exit(EXIT_FAILURE);
        }

        // wait for child process to finish
        wait(NULL);

        // close read end of pipe
        close(pipefd[0]);

        // pipe is completely closed now
        return EXIT_SUCCESS;
    }
}
