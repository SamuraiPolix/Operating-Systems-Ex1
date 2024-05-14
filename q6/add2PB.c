// This program adds a new entry the phonebook

#include <stdio.h>
#include <unistd.h>     //
#include <stdlib.h>
#include <fcntl.h>      // open() for files

size_t strlen(const char* str){
    size_t len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: ./add2PB <name>,<phone_number>\n");
        exit(EXIT_FAILURE);
    }

    // TODO - make sure input is good
    

    // open file in append mode
    int fd = open("phonebook.txt", O_CREAT | O_WRONLY | O_APPEND);
    if (fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    // line break before writing
    if (write(fd, "\n", sizeof(char)) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

    // write name to file
    for (int i = 1; i < argc-1; i++){
        printf("Writing %s to file\n", argv[i]);
        // write name (argv[1] to argv[argc-1] : the one before the number)
        if (write(fd, argv[i], strlen(argv[i])) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }
        // space between names, not in the last one
        if (i < argc - 2 && write(fd, " ", sizeof(char)) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // write phone number to file
    if (write(fd, argv[argc-1], strlen(argv[argc-1])) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

    // add a line break at the end of the line
    if (write(fd, "\\n", 2*sizeof(char)) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

    // close file
    close(fd);

    return 0;
}